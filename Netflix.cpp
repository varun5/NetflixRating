#include "Netflix.hpp"
#include <cmath>
#include <string>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <cassert>
#include "boost/archive/binary_iarchive.hpp"
#include "boost/archive/binary_oarchive.hpp"
#include <boost/serialization/serialization.hpp>
#include <boost/serialization/unordered_map.hpp>
#include <boost/serialization/unordered_set.hpp>

using namespace std;
// /u/downing/public_html/git/cs371g-netflix-caches/kevin-wu24-AnswerCache.bin

// /u/downing/public_html/git/cs371g-netflix-caches/kevin-wu24-AvgMovieRating.bin
// /u/downing/public_html/git/cs371g-netflix-caches/kevin-wu24-AvgCustomerRating.bin

//load Kevin's cache to use

PredictionCalculator::PredictionCalculator()
{
    //Average customer rating
    {
        std::ifstream ifs("/u/downing/public_html/git/cs371g-netflix-caches/kevin-wu24-AvgCustomerRating.bin");
        boost::archive::binary_iarchive ia(ifs);
        ia >> avgcustomerrating;
    }
    //Average movie rating
    {
        std::ifstream ifs("/u/downing/public_html/git/cs371g-netflix-caches/kevin-wu24-AvgMovieRating.bin");
        boost::archive::binary_iarchive ia(ifs);
        ia >> avgmovierating;
    }
    //Answer Cache
    {
        std::ifstream ifs("/u/downing/public_html/git/cs371g-netflix-caches/kevin-wu24-AnswerCache.bin");
        boost::archive::binary_iarchive ia(ifs);
        ia >> answercache;
    }
}

//calculates the RMSE
double PredictionCalculator::rmse()
{
    //ensure that predictions and scores are not empty
    assert(!scores.empty());
    assert(!preds.empty());
    //track sum
    double sum = 0;
    int N = scores.size();
    int curr = N;
    //loop through, finding squares and adding to sum
    while (curr-- > 0)
    {
        sum += (scores[curr] - preds[curr]) * (scores[curr] - preds[curr]);
    }
    cout << sum << endl;
    sum /= N;
    double result = std::pow(sum, 0.5);

    assert(result >= 0);
    return result;
}
