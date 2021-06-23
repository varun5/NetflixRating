.DEFAULT_GOAL := all
MAKEFLAGS     += --no-builtin-rules
SHELL         := bash

ASTYLE        := astyle
CHECKTESTDATA := checktestdata
CPPCHECK      := cppcheck
DOXYGEN       := doxygen

ifeq ($(shell uname -s), Darwin)
    BOOST    := /usr/local/include/boost
    CXX      := g++-11
    CXXFLAGS := --coverage -pedantic -std=c++17 -O3 -I/usr/local/include -Wall -Wextra
    GCOV     := gcov-11
    GTEST    := /usr/local/include/gtest
    LDFLAGS  := -lgtest -lgtest_main
    LIB      := /usr/local/lib
    VALGRIND :=
else ifeq ($(shell uname -p), unknown)
    BOOST    := /usr/include/boost
    CXX      := g++
    CXXFLAGS := --coverage -pedantic -std=c++17 -O3 -Wall -Wextra
    GCOV     := gcov
    GTEST    := /usr/src/gtest
    LDFLAGS  := -lgtest -lgtest_main -pthread
    LIB      := /usr/lib
    VALGRIND := valgrind
else
    BOOST    := /usr/include/boost
    CXX      := g++-9
    CXXFLAGS := --coverage -pedantic -std=c++17 -O3 -Wall -Wextra
    GCOV     := gcov-9
    GTEST    := /usr/local/include/gtest
    LDFLAGS  := -lgtest -lgtest_main -pthread
    LIB      := /usr/local/lib
    VALGRIND := valgrind
endif

# run docker
docker:
	docker run -it -v $(PWD):/usr/gcc -w /usr/gcc gpdowning/gcc

# get git config
config:
	git config -l

# get git log
Netflix.log:
	git log > Netflix.log

# get git status
status:
	make clean
	@echo
	git branch
	git remote -v
	git status

# download files from the Netflix code repo
pull:
	make clean
	@echo
	git pull
	git status

# upload files to the Netflix code repo
push:
	make clean
	@echo
	git add .gitignore
	git add .gitlab-ci.yml
	git add Netflix.cpp
	git add Netflix.hpp
	-git add Netflix.log
	-git add html
	git add makefile
	git add README.md
	git add RunNetflix.cpp
	git add RunNetflix.ctd
	git add TestNetflix.cpp
	git commit -m "another commit"
	git push
	git status

# compile run harness
RunNetflix: Netflix.hpp Netflix.cpp RunNetflix.cpp
	-$(CPPCHECK) Netflix.cpp
	-$(CPPCHECK) RunNetflix.cpp
	$(CXX) $(CXXFLAGS) Netflix.cpp RunNetflix.cpp -o RunNetflix

# compile test harness
TestNetflix: Netflix.hpp Netflix.cpp TestNetflix.cpp
	-$(CPPCHECK) Netflix.cpp
	-$(CPPCHECK) TestNetflix.cpp
	$(CXX) $(CXXFLAGS) Netflix.cpp TestNetflix.cpp -o TestNetflix $(LDFLAGS)

# run/test files, compile with make all
FILES :=                                  \
    RunNetflix                            \
    TestNetflix

# compile all
all: $(FILES)

# execute test harness
test: TestNetflix
	$(VALGRIND) ./TestNetflix
ifeq ($(shell uname -s), Darwin)
	$(GCOV) TestNetflix-Netflix.cpp | grep -B 2 "cpp.gcov"
else ifeq ($(shell uname -p), unknown)
	$(GCOV) TestNetflix-Netflix.cpp | grep -B 2 "cpp.gcov"
else
	$(GCOV) Netflix.cpp | grep -B 2 "cpp.gcov"
endif

# test files in the Netflix test repo
T_FILES := `ls Netflix-tests/*.in`

# check integrity of test files in the Netflix test repo
ctd-check:
	-for v in $(T_FILES); do echo $(CHECKTESTDATA) RunNetflix.ctd $$v; $(CHECKTESTDATA) RunNetflix.ctd $$v; done

# generate a random input file
ctd-generate:
	$(CHECKTESTDATA) -g RunNetflix.ctd > RunNetflix.gen

# clone the Netflix test repo
Netflix-tests:
	git clone https://gitlab.com/gpdowning/cs371g-Netflix-tests.git Netflix-tests

# execute run harness against a test in Netflix test repo and diff with expected output
Netflix-tests/%: RunNetflix
	$(CHECKTESTDATA) RunNetflix.ctd $@.in
	./RunNetflix < $@.in > RunNetflix.tmp
	-diff RunNetflix.tmp $@.out

# execute run harness against all tests in Netflix test repo and diff with expected output
run: Netflix-tests RunNetflix
	-for v in $(T_FILES); do make $${v/.in/}; done

# auto format the code
format:
	$(ASTYLE) Netflix.cpp
	$(ASTYLE) Netflix.hpp
	$(ASTYLE) RunNetflix.cpp
	$(ASTYLE) TestNetflix.cpp

# you must edit Doxyfile and
# set EXTRACT_ALL     to YES
# set EXTRACT_PRIVATE to YES
# set EXTRACT_STATIC  to YES
# create Doxfile
Doxyfile:
	$(DOXYGEN) -g

# create html directory
html: Doxyfile
	$(DOXYGEN) Doxyfile

# check files, check their existence with make check
C_FILES :=                           \
    .gitignore                       \
    .gitlab-ci.yml                   \
    Netflix.log                      \
    html

# check the existence of check files
check: $(C_FILES)

# remove executables and temporary files
clean:
	rm -f *.gcda
	rm -f *.gcno
	rm -f *.gcov
	rm -f *.gen
	rm -f *.plist
	rm -f *.tmp
	rm -f RunNetflix
	rm -f TestNetflix

# remove executables, temporary files, and generated files
scrub:
	make clean
	rm -f  Netflix.log
	rm -f  Doxyfile
	rm -rf Netflix-tests
	rm -rf html
	rm -rf latex

# output versions of all tools
versions:
	@echo "% which $(ASTYLE)"
	@which $(ASTYLE)
	@echo
	@echo "% $(ASTYLE) --version"
	@$(ASTYLE) --version

	@echo
	@echo "% which $(CHECKTESTDATA)"
	@which $(CHECKTESTDATA)
	@echo
	@echo "% $(CHECKTESTDATA) --version"
	@$(CHECKTESTDATA) --version

	@echo
	@echo "% which cmake"
	@which cmake
	@echo
	@echo "% cmake --version"
	@cmake --version

	@echo
	@echo "% which $(CPPCHECK)"
	@which $(CPPCHECK)
	@echo
	@echo "% $(CPPCHECK) --version"
	@$(CPPCHECK) --version

	@echo
	@echo "% which $(DOXYGEN)"
	@which $(DOXYGEN)
	@echo
	@echo "% $(DOXYGEN) --version"
	@$(DOXYGEN) --version

	@echo
	@echo "% which $(CXX)"
	@which $(CXX)
	@echo
	@echo "% $(CXX) --version"
	@$(CXX) --version

	@echo
	@echo "% which $(GCOV)"
	@which $(GCOV)
	@echo
	@echo "% $(GCOV) --version"
	@$(GCOV) --version

	@echo
	@echo "% which git"
	@which git
	@echo
	@echo "% git --version"
	@git --version

	@echo
	@echo "% which make"
	@which make
	@echo
	@echo "% make --version"
	@make --version

ifneq ($(shell uname -s), Darwin)
	@echo
	@echo "% which $(VALGRIND)"
	@which $(VALGRIND)
	@echo
	@echo "% $(VALGRIND) --version"
	@$(VALGRIND) --version
endif

	@echo "% which vim"
	@which vim
	@echo
	@echo "% vim --version"
	@vim --version

	@echo
	@echo "% grep \"#define BOOST_LIB_VERSION \" $(BOOST)/version.hpp"
	@grep "#define BOOST_LIB_VERSION " $(BOOST)/version.hpp

	@echo
	@echo "% grep \"set(GOOGLETEST_VERSION\" $(GTEST)/CMakeLists.txt"
	@grep "set(GOOGLETEST_VERSION" $(GTEST)/CMakeLists.txt
	@echo
	@echo "% ls -al $(LIB)/libgtest*.a"
	@ls -al $(LIB)/libgtest*.a
