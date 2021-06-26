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

TEST(NetflixFixture, solve) {
   PredictionCalculator p;
   p.scores = {7 , 11 ,24 ,23};
   p.preds = {7,13, 26, 29};
   ASSERT_EQ(p.rmse(), 1.0);
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

