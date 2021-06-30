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

#include "Netflix.hpp"

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
double prediction(int userid, short movieid) {
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
void rmadd(vector<double> p, vector<double> s) {
    pred = p;
    score = s;
}


// tests the RMSE
TEST(NetflixFixture, rmsetest1) {
    pred = {3, 4, 5};
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
    pred = {2, 12, 11};
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
    pred  = {18, 32, 1};
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
    pred  = {800, 322, 10};
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
    pred = {85, 26, 140, 605};
    score = {9, 11, 12, 604};
    rmadd(pred, score);
    rm = rmse();
    ss << setprecision(4) << rm;
    ss >> str;

    ASSERT_EQ(str, "74.81");
}
TEST(NetflixFixture, rmsetest6) {
    ss.str("");
    ss.clear();
    pred  = {843, 23, 10, 1, 2};
    score = {9, 115, 2, 3, 5};
    rm = rmse();
    ss << setprecision(4) << rm;
    ss >> str;

    ASSERT_EQ(str, "375.3");
}
TEST(NetflixFixture, rmsetest7) {
    ss.str("");
    ss.clear();
    pred = {45, 62, 14, 65};
    score = {19, 15, 16, 56};
    rm = rmse();
    ss << setprecision(4) << rm;
    ss >> str;
    ASSERT_EQ(str, "27.25");

}

TEST(NetflixFixture, rmsetest8) {
    ss.str("");
    ss.clear();
    pred  = {81, 342, 36};
    score = {93, 114, 125};
    rm = rmse();
    ss << setprecision(4) << rm;
    ss >> str;;
}
TEST(NetflixFixture, rmsetest9) {
    ss.str("");
    ss.clear();
    pred = {84332, 342, 60, 75};
    score= {9, 11, 12, 65};
    rm = rmse();
    ss << setprecision(4) << rm;
    ss >> str;

    ASSERT_EQ(str, "4.216e+04");
}
TEST(NetflixFixture, rmsetest10) {
    ss.str("");
    ss.clear();
    pred = {84, 28, 14};
    score = {91, 151, 128};
    rm = rmse();
    ss << setprecision(4) << rm;
    ss >> str;

    ASSERT_EQ(str, "96.91");
}
// tests Netflix prediction
TEST(NetflixFixture, pred1) {
    avgcustomerratin[30878] = 3.6324;
    avgmovieratin[1] = 3.72901;
    answercach[1][30878] = 4;
    ASSERT_EQ(prediction(30878, 1), 3.8);
}
TEST(NetflixFixture, pred2) {
    avgcustomerratin[2647871] = 3.23069;
    avgmovieratin[1] = 3.72901;
    answercach[1][2647871] = 4;
    ASSERT_EQ(prediction(2647871, 1), 3.4);
}
TEST(NetflixFixture, pred3) {
    avgcustomerratin[1283744] = 3.53448;
    avgmovieratin[1] = 3.72901;
    answercach[1][1283744] = 3;
    ASSERT_EQ(prediction(1283744, 1), 3.7);
}
TEST(NetflixFixture, pred4) {
    avgcustomerratin[248812] = 3.8617;
    avgmovieratin[1] = 3.72901;
    answercach[1][248812] = 0;
    ASSERT_EQ(prediction(248812, 1), 4);
}
TEST(NetflixFixture, pred5) {
    avgcustomerratin[317050] = 3.53448;
    avgmovieratin[1] = 3.72901;
    answercach[1][317050] = 5;
    ASSERT_EQ(prediction(317050, 1), 3.7);
}
TEST(NetflixFixture, pred6) {
    avgcustomerratin[1904905] = 3.83654;
    avgmovieratin[1] = 3.72901;
    answercach[1][1904905] = 4;
    ASSERT_EQ(prediction(1904905, 1), 4.0);
}
TEST(NetflixFixture, pred7) {
    avgcustomerratin[1989766] = 4;
    avgmovieratin[1] = 3.72901;
    answercach[1][1989766] = 4;
    ASSERT_EQ(prediction(1989766, 1), 4.2);
}
TEST(NetflixFixture, pred8) {
    avgcustomerratin[14756] = 3.64424;
    avgmovieratin[1] = 3.72901;
    answercach[1][14756] = 4;
    ASSERT_EQ(prediction(14756, 1), 3.8);
}
TEST(NetflixFixture, pred9) {
    avgcustomerratin[1027056] = 4;
    avgmovieratin[1] = 3.72901;
    answercach[1][1027056] = 4;
    ASSERT_EQ(prediction(1027056, 1), 4.2);
}
TEST(NetflixFixture, pred10) {
    avgcustomerratin[1149588] = 3.4636;
    avgmovieratin[1] = 3.72901;
    answercach[1][1149588] = 4;
    ASSERT_EQ(prediction(1149588, 1), 3.6);
}
