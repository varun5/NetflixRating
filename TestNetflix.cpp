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


TEST(NetflixFixture, solve) {
   // ASSERT_EQ(solve(), 20u);}
}
/*
TEST(NetflixFixture, rmsetest1) {
   PredictionCalculator p;
   vector<double> preds = {3 , 4, 5};
   vector<double> scores = {6, 8, 10};
   p.rmadd(preds, scores);
   string str;
   stringstream ss;
   double rm = p.rmse();
   ss << setprecision(4) << rm;
   ss >> str;

   ASSERT_EQ(str, "4.082");
}
*/
/*
TEST(NetflixFixture, rmsetest2) {
   PredictionCalculator p;
   vector<double> preds = {2 , 12, 11};
   vector<double> scores = {4, 1, 2};
   p.rmadd(preds, scores);
   string str;
   stringstream ss;
   double rm = p.rmse();
   ss << setprecision(4) << rm;
   ss >> str;

   ASSERT_EQ(str, "8.287");
}
TEST(NetflixFixture, rmsetest3) {
   PredictionCalculator p;
   vector<double> preds = {18 , 32, 1};
   vector<double> scores = {9, 91, 122};
    p.rmadd(preds, scores);
   string str;
   stringstream ss;
   double rm = p.rmse();
   ss << setprecision(4) << rm;
   ss >> str;

   ASSERT_EQ(str, "77.9");
}
TEST(NetflixFixture, rmsetest4) {
   PredictionCalculator p;
   vector<double> preds = {800 , 322, 10};
   vector<double> scores = {93, 101, 12};
   p.rmadd(preds, scores);
   string str;
   stringstream ss;
   double rm = p.rmse();
   ss << setprecision(4) << rm;
   ss >> str;

   ASSERT_EQ(str, "427.7");
}TEST(NetflixFixture, rmsetest5) {
   PredictionCalculator p;
   vector<double> preds = {85 , 26, 140, 605};
   vector<double> scores = {9, 11, 12, 604};
   p.rmadd(preds, scores);
   string str;
   stringstream ss;
   double rm = p.rmse();
   ss << setprecision(4) << rm;
   ss >> str;

   ASSERT_EQ(str, "74.81");
}TEST(NetflixFixture, rmsetest6) {
   PredictionCalculator p;
   vector<double> preds = {843 , 23, 10, 1, 2};
   vector<double> scores = {9, 115, 2, 3, 5};
      p.rmadd(preds, scores);
   string str;
   stringstream ss;
   double rm = p.rmse();
   ss << setprecision(4) << rm;
   ss >> str;

   ASSERT_EQ(str, "375.3");
}TEST(NetflixFixture, rmsetest7) {
   PredictionCalculator p;
   vector<double> preds = {45 , 62, 14, 65};
   vector<double> scores = {19, 15, 16, 56};
   p.rmadd(preds, scores);
   string str;
   stringstream ss;
   double rm = p.rmse();
   ss << setprecision(4) << rm;
   ss >> str;

   ASSERT_EQ(str, "27.25");
}TEST(NetflixFixture, rmsetest8) {
   PredictionCalculator p;
   vector<double> preds = {81 , 342, 36};
   vector<double> scores = {93, 114, 125};
      p.rmadd(preds, scores);
   string str;
   stringstream ss;
   double rm = p.rmse();
   ss << setprecision(4) << rm;
   ss >> str;

   ASSERT_EQ(str, "141.5");
}TEST(NetflixFixture, rmsetest9) {
   PredictionCalculator p;
   vector<double> preds = {84332, 342, 60, 75};
   vector<double> scores = {9, 11, 12, 65};
   p.rmadd(preds, scores);
   string str;
   stringstream ss;
   double rm = p.rmse();
   ss << setprecision(4) << rm;
   ss >> str;

   ASSERT_EQ(str, "4.216e+04");
}TEST(NetflixFixture, rmsetest10) {
   PredictionCalculator p;
   vector<double> preds = {84 , 28, 14};
   vector<double> scores = {91, 151, 128};
     p.rmadd(preds, scores);
   string str;
   stringstream ss;
   double rm = p.rmse();
   ss << setprecision(4) << rm;
   ss >> str;

   ASSERT_EQ(str, "96.91");
}

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