#include "Netflix.hpp"
#include "boost/archive/binary_iarchive.hpp"
#include "boost/archive/binary_oarchive.hpp"
#include <boost/serialization/unordered_map.hpp>
#include <boost/serialization/unordered_set.hpp>
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

using namespace std;
// /u/downing/public_html/git/cs371g-netflix-caches/kevin-wu24-AnswerCache.bin

// /u/downing/public_html/git/cs371g-netflix-caches/kevin-wu24-AvgMovieRating.bin
// /u/downing/public_html/git/cs371g-netflix-caches/kevin-wu24-AvgCustomerRating.bin

// stores the average score each customer has provided for the movies they've
// rated
unordered_map<int, double> avgcustomerrating;
// stores the average score of the movie ratings
unordered_map<short, double> avgmovierating;
// stores the actual score provided by the customer
unordered_map<short, unordered_map<int, char>> answercache;

vector<double> scores;

vector<double> preds;

// load Kevin's cache to use

PredictionCalculator::PredictionCalculator() {

  // Average customer rating
  {
    std::ifstream ifs("/u/downing/public_html/git/cs371g-netflix-caches/"
                      "kevin-wu24-AvgCustomerRating.bin");
    boost::archive::binary_iarchive ia(ifs);
    ia >> avgcustomerrating;
  }
  // Average movie rating
  {
    std::ifstream ifs("/u/downing/public_html/git/cs371g-netflix-caches/"
                      "kevin-wu24-AvgMovieRating.bin");
    boost::archive::binary_iarchive ia(ifs);
    ia >> avgmovierating;
  }
  // Answer Cache
  {
    std::ifstream ifs("/u/downing/public_html/git/cs371g-netflix-caches/"
                      "kevin-wu24-AnswerCache.bin");
    boost::archive::binary_iarchive ia(ifs);
    ia >> answercache;
  }
}

// solves program, main driver function
void PredictionCalculator::solve() {
  string input;
  int movieid = -1;
  int userid = -1;
  cout<<"A";
  while (std::getline(std::cin, input)) {
    cout<< "B";
    if (input[input.length() - 1] == ':') {
      stringstream ss;
      ss << input;
      ss >> movieid;
      cout << movieid << endl;
    } else {
      stringstream ss;
      ss << input;
      ss >> userid;
      cout << fixed << setprecision(1) << prediction(userid, movieid) << endl;
    }
    cout << "C" << endl;
    double root = rmse();
    cout << fixed << setprecision(2) << "RMSE: " << root << "\n";
  }
}

double PredictionCalculator::calc_average() {
    double total = 0;
    double counter = 0;
    for (auto const& [key, val] : avgmovierating)
    {
        total +=  val;       
        counter++;
    }
    //cout << "Total: " << total << "Size: " << avgmovierating.size() << "Counter: " << counter <<endl;
    return total/counter;
}


double PredictionCalculator::prediction(int userid, short movieid){
    const double allavg = calc_average();
    double usercurr = avgcustomerrating.at(userid);
    double movcurr = avgmovierating.at(movieid);
    usercurr -= allavg;
    movcurr -= allavg;
    double result = 0;
    result += allavg;
    result += usercurr;
    result += movcurr;
    double pred = floor((result) * 10)/10;
    preds.push_back(min(max(pred, 1.0), 5.0));
    scores.push_back(answercache[userid][movieid]);
}


// calculates the RMSE
double PredictionCalculator::rmse() {
  // ensure that predictions and scores are not empty
  assert(!scores.empty());
  assert(!preds.empty());
  // track sum
  double sum = 0;
  int N = scores.size();
  int curr = N;
  // loop through, finding squares and adding to sum
  while (curr-- > 0) {
    sum += (scores[curr] - preds[curr]) * (scores[curr] - preds[curr]);
  }
  sum /= N;
  double result = std::pow(sum, 0.5);

  assert(result >= 0);

  return result;
}
