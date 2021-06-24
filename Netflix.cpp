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

double PredictionCalculator::rmse() const
{
    assert(!scores.empty());
    assert(!preds.empty());
    double sum = 0;
    int N = scores.size();
    while (N > 0) {
        sum += (scores[N] - preds[N]) * (scores[N] - preds[N]);
        --N;
    }
    sum /= N;
    double result = std::pow(sum, 0.5);

    assert(result >= 0);
    return result;
}
