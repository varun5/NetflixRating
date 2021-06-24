#include "Netflix.hpp"
#include <cmath>
#include <string>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
#include <vector>
#include <unordered_map>

using namespace std;


//calculates the RMSE
double PredictionCalculator::rmse() const
{
    //ensure that predictions and scores are not empty
    assert(!scores.empty());
    assert(!preds.empty());
    //track sum
    double sum = 0;
    int N = scores.size();
    //loop through, finding squares and adding to sum
    while (N > 0) {
        sum += (scores[N] - preds[N]) * (scores[N] - preds[N]);
        --N;
    }
    sum /= N;
    double result = std::pow(sum, 0.5);

    assert(result >= 0);
    return result;
}
