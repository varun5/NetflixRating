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

using namespace std;
// /u/downing/public_html/git/cs371g-netflix-caches/kevin-wu24-AnswerCache.bin        

// /u/downing/public_html/git/cs371g-netflix-caches/kevin-wu24-AvgMovieRating.bin               
// /u/downing/public_html/git/cs371g-netflix-caches/kevin-wu24-AvgCustomerRating.bin 

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
    while (curr-- > 0) {
        sum += (scores[curr] - preds[curr]) * (scores[curr] - preds[curr]);
    }
    cout<< sum << endl;
    sum /= N;
    double result = std::pow(sum, 0.5);

    assert(result >= 0);
    return result;
}
