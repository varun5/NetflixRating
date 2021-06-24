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


//calculates the RMSE
double PredictionCalculator::rmse() 
{
    preds = {34, 37, 44, 47, 48, 48, 46, 43, 32, 27, 26, 24};
    scores = {37, 40, 46, 44, 46, 50, 45, 44, 34, 30, 22, 23};
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
