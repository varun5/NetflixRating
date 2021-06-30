// ---------------
// TestCollatz.cpp
// ---------------

// https://code.google.com/p/googletest/wiki/V1_7_Primer#Basic_Assertions

// --------
// includes
// --------

#include <sstream>  // istringtstream, ostringstream
#include <tuple>    // make_tuple, tuple
#include <utility>  // make_pair, pair
#include <cassert>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>
#include "gtest/gtest.h"

//#include "Netflix.hpp"

using namespace std;

// ----------------
// max_cycle_length
// ----------------
vector<double> score;
vector<double> pred;
unordered_map<int, double> avgcustomerratin;
// stores the average score of the movie ratings
unordered_map<short, double> avgmovieratin;
// stores the actual score provided by the customer
unordered_map<short, unordered_map<int, char>> answercach;
string str;
stringstream ss;
double rm;
double prediction(int userid, short movieid){
  const double allavg = 3.22473 * 1.085;
  // get the key value for user and movie from maps
  double usercurr = avgcustomerratin.at(userid);
 
  double movcurr = avgmovieratin.at(movieid);
 
  usercurr -= allavg;
  movcurr -= allavg;
  double result = 0;
  result += allavg;
  result += usercurr;
  result += movcurr;
  // calculate prediction
  double pre = floor((result) * 10)/10;
 
  score.push_back(answercach[movieid][userid]);
  pred.push_back(min(max(pre, 1.0), 5.0));
 
 
  return pre;
}
// calculates the RMSE
double rmse() {
 // ensure that predictions and scores are not empty
 assert(!score.empty());
 assert(!pred.empty());
 // track sum
 double sum = 0;
 int N = score.size();
 int curr = N;
 // loop through, finding squares and adding to sum
 while (curr-- > 0) {
  sum += (score[curr] - pred[curr]) * (score[curr] - pred[curr]);
 }
 sum /= N;
 double result = std::pow(sum, 0.5);
 assert(result >= 0);
 return result;
}
void rmadd(vector<double> p, vector<double> s){
   pred = p;
   score = s;
}



TEST(NetflixFixture, rmsetest1) {
   pred = {3 , 4, 5};
   score = {6, 8, 10};
   rmadd(pred, score);
   rm = rmse();
   ss << setprecision(4) << rm;
   ss >> str;

   ASSERT_EQ(str, "4.082");
}


TEST(NetflixFixture, rmsetest2) {
   ss.str("");
   ss.clear();
   pred = {2 , 12, 11};
   score = {4, 1, 2};
   rmadd(pred, score);
   rm = rmse();
   ss << setprecision(4) << rm;
   ss >> str;

   ASSERT_EQ(str, "8.287");
}

TEST(NetflixFixture, rmsetest3) {
   ss.str("");
ss.clear();
    pred  = {18 , 32, 1};
    score = {9, 91, 122};
    rmadd(pred, score);
   rm = rmse();
   ss << setprecision(4) << rm;
   ss >> str;

   ASSERT_EQ(str, "77.9");
}
TEST(NetflixFixture, rmsetest4) {
   ss.str("");
ss.clear();
   pred  = {800 , 322, 10};
   score = {93, 101, 12};
   rmadd(pred, score);
   rm = rmse();
   ss << setprecision(4) << rm;
   ss >> str;
   ASSERT_EQ(str, "427.7");

}

TEST(NetflixFixture, rmsetest5) {
   ss.str("");
ss.clear();
   pred = {85 , 26, 140, 605};
   score = {9, 11, 12, 604};
   rmadd(pred, score);
   rm = rmse();
   ss << setprecision(4) << rm;
   ss >> str;

   ASSERT_EQ(str, "74.81");
}TEST(NetflixFixture, rmsetest6) {
   ss.str("");
ss.clear();
   pred  = {843 , 23, 10, 1, 2};
   score = {9, 115, 2, 3, 5};
   rm = rmse();
   ss << setprecision(4) << rm;
   ss >> str;

   ASSERT_EQ(str, "375.3");
}TEST(NetflixFixture, rmsetest7) {
   ss.str("");
ss.clear();
   pred = {45 , 62, 14, 65};
   score = {19, 15, 16, 56};
   rm = rmse();
   ss << setprecision(4) << rm;
   ss >> str;
   ASSERT_EQ(str, "27.25");

}
/*
TEST(NetflixFixture, rmsetest8) {
   ss.str("");
ss.clear();
   pred  = {81 , 342, 36};
   score = {93, 114, 125};
   rm = rmse();
   ss << setprecision(4) << rm;
   ss >> str;;
}TEST(NetflixFixture, rmsetest9) {
   ss.str("");
ss.clear();
   pred = {84332, 342, 60, 75};
   score= {9, 11, 12, 65};
   rm = rmse();
   ss << setprecision(4) << rm;
   ss >> str;

   ASSERT_EQ(str, "4.216e+04");
}TEST(NetflixFixture, rmsetest10) {
   ss.str("");
ss.clear();
   pred = {84 , 28, 14};
   score = {91, 151, 128};
   rm = rmse();
   ss << setprecision(4) << rm;
   ss >> str;

   ASSERT_EQ(str, "96.91");
}





TEST(NetflixFixture, solve) {
   //PredictionCalculator p;
   ASSERT_EQ(2, 2);
   // ASSERT_EQ(solve(), 20u);}
}
// TEST(CollatzFixture, max_cycle_length_1) {
//     ASSERT_EQ(max_cycle_length(100, 200), 125u);}

// TEST(CollatzFixture, max_cycle_length_2) {
//     ASSERT_EQ(max_cycle_length(201, 210), 89u);}

// TEST(CollatzFixture, max_cycle_length_3) {
//     ASSERT_EQ(max_cycle_length(900, 1000), 174u);}

// // my unit tests

// TEST(CollatzFixture, max_cycle_length_4) {
//     ASSERT_EQ(max_cycle_length(999998, 999999), 259u);}

// TEST(CollatzFixture, max_cycle_length_5) {
//     ASSERT_EQ(max_cycle_length(999999, 999998), 259u);}

// TEST(CollatzFixture, max_cycle_length_6) {
//     ASSERT_EQ(max_cycle_length(1, 1), 1u);}

// TEST(CollatzFixture, max_cycle_length_7) {
//     ASSERT_EQ(max_cycle_length(1, 2), 2u);}

// TEST(CollatzFixture, max_cycle_length_8) {
//     ASSERT_EQ(max_cycle_length(2, 1), 2u);}

// TEST(CollatzFixture, max_cycle_length_9) {
//     ASSERT_EQ(max_cycle_length(100, 50), 119u);}

// TEST(CollatzFixture, max_cycle_length_10) {
//     ASSERT_EQ(max_cycle_length(100, 100), 26u);}

// TEST(CollatzFixture, max_cycle_length_11) {
//     ASSERT_EQ(max_cycle_length(99, 100), 26u);}

// TEST(CollatzFixture, max_cycle_length_12) {
//     ASSERT_EQ(max_cycle_length(100000, 100001), 129u);}

// TEST(CollatzFixture, max_cycle_length_13) {
//     ASSERT_EQ(max_cycle_length(17, 117), 119u);}

// TEST(CollatzFixture, max_cycle_length_14) {
//     ASSERT_EQ(max_cycle_length(17, 1017), 179u);}

// TEST(CollatzFixture, max_cycle_length_15) {
//     ASSERT_EQ(max_cycle_length(17, 10017), 262u);}

// TEST(CollatzFixture, max_cycle_length_16) {
//     ASSERT_EQ(max_cycle_length(17, 100017), 351u);}

// TEST(CollatzFixture, max_cycle_length_17) {
//     ASSERT_EQ(max_cycle_length(9, 99), 119u);}

// TEST(CollatzFixture, max_cycle_length_18) {
//     ASSERT_EQ(max_cycle_length(9, 999), 179u);}

// TEST(CollatzFixture, max_cycle_length_19) {
//     ASSERT_EQ(max_cycle_length(9, 9999), 262u);}

// TEST(CollatzFixture, max_cycle_length_20) {
//     ASSERT_EQ(max_cycle_length(9, 9909), 262u);}

// TEST(CollatzFixture, max_cycle_length_21) {
//     ASSERT_EQ(max_cycle_length(9, 909), 179u);}

// TEST(CollatzFixture, max_cycle_length_22) {
//     ASSERT_EQ(max_cycle_length(3, 333), 144u);}

// TEST(CollatzFixture, max_cycle_length_23) {
//     ASSERT_EQ(max_cycle_length(3, 3333), 217u);}

*/