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

#include "gtest/gtest.h"

#include "Netflix.hpp"

using namespace std;

// ----------------
// max_cycle_length
// ----------------

TEST(NetflixFixture, rmsetest1) {
   PredictionCalculator p;
   vector<double> preds = {3 , 4, 5};
   vector<double> scores = {6, 8, 10};
   p.rmadd(preds, scores);
   ASSERT_EQ(p.rmse(), 4.08248);
}

TEST(NetflixFixture, rmsetest2) {
   PredictionCalculator p;
   vector<double> preds = {2 , 12, 11};
   vector<double> scores = {4, 1, 2};
   p.rmadd(preds, scores);
   ASSERT_EQ(p.rmse(), 8.28654);
}
TEST(NetflixFixture, rmsetest3) {
   PredictionCalculator p;
   vector<double> preds = {18 , 32, 1};
   vector<double> scores = {9, 91, 122};
   p.rmadd(preds, scores);
   ASSERT_EQ(p.rmse(), 77.8952);
}
TEST(NetflixFixture, rmsetest4) {
   PredictionCalculator p;
   vector<double> preds = {800 , 322, 10};
   vector<double> scores = {93, 101, 12};
   p.rmadd(preds, scores);
   ASSERT_EQ(p.rmse(), 427.666);
}TEST(NetflixFixture, rmsetest5) {
   PredictionCalculator p;
   vector<double> preds = {85 , 26, 140, 605};
   vector<double> scores = {9, 11, 12, 604};
   p.rmadd(preds, scores);
   ASSERT_EQ(p.rmse(), 74.8098);
}TEST(NetflixFixture, rmsetest6) {
   PredictionCalculator p;
   vector<double> preds = {843 , 23, 10, 1, 2};
   vector<double> scores = {9, 115, 2, 3, 5};
   p.rmadd(preds, scores);
   ASSERT_EQ(p.rmse(), 375.259);
}TEST(NetflixFixture, rmsetest7) {
   PredictionCalculator p;
   vector<double> preds = {45 , 62, 14, 65};
   vector<double> scores = {19, 15, 16, 56};
   p.rmadd(preds, scores);
   ASSERT_EQ(p.rmse(), 27.2489);
}TEST(NetflixFixture, rmsetest8) {
   PredictionCalculator p;
   vector<double> preds = {81 , 342, 36};
   vector<double> scores = {93, 114, 125};
   p.rmadd(preds, scores);
   ASSERT_EQ(p.rmse(), 141.479);
}TEST(NetflixFixture, rmsetest9) {
   PredictionCalculator p;
   vector<double> preds = {84332, 342, 60, 75};
   vector<double> scores = {9, 11, 12, 65};
   p.rmadd(preds, scores);
   ASSERT_EQ(p.rmse(), 42161.8);
}TEST(NetflixFixture, rmsetest10) {
   PredictionCalculator p;
   vector<double> preds = {84 , 28, 14};
   vector<double> scores = {91, 151, 128};
   p.rmadd(preds, scores);
   ASSERT_EQ(p.rmse(), 96.9089);
}
/*
TEST(NetflixFixture, pred1) {
   PredictionCalculator p;
   
   ASSERT_EQ(p.prediction(30878, 1), 3.8);
}
TEST(NetflixFixture, pred2) {
   PredictionCalculator p;
   
   ASSERT_EQ(p.prediction(2647871, 1), 3.4);
}
TEST(NetflixFixture, pred3) {
   PredictionCalculator p;
   
   ASSERT_EQ(p.prediction(1283744, 1), 3.7);
}

TEST(NetflixFixture, pred4) {
   PredictionCalculator p;
   
   ASSERT_EQ(p.prediction(248812, 1), 4);
}

TEST(NetflixFixture, pred5) {
   PredictionCalculator p;
   
   ASSERT_EQ(p.prediction(317050, 1), 3.7);
}

TEST(NetflixFixture, pred6) {
   PredictionCalculator p;
   
   ASSERT_EQ(p.prediction(1904905, 1), 4.0);
}

TEST(NetflixFixture, pred7) {
   PredictionCalculator p;
   
   ASSERT_EQ(p.prediction(1989766, 1), 4.2);
}

TEST(NetflixFixture, pred8) {
   PredictionCalculator p;
   
   ASSERT_EQ(p.prediction(14756, 1), 3.8);
}
TEST(NetflixFixture, pred9) {
   PredictionCalculator p;
   
   ASSERT_EQ(p.prediction(1027056, 1), 4.2);
}
TEST(NetflixFixture, pred10) {
   PredictionCalculator p;
   
   ASSERT_EQ(p.prediction(1149588, 1), 3.6);
}

*/
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

