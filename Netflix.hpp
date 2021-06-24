#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>
using namespace std;
class PredictionCalculator{
    private:
        // vector containing scores
        vector<double> scores;
        // vector containing predictions
        vector<double> preds;
    public:
        //calculate the RMSE
        double rmse() const;
}