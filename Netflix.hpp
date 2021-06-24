#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>
using namespace std;
class PredictionCalculator{
    private:
        // stores the average score each customer has provided for the movies they've rated
        unordered_map <int, double> avgcustomerrating;
        // stores the average score of the movie ratings
        unordered_map <int, double> avgmovierating;
        // stores the actual score provided by the customer
        unordered_map <int , unordered_map<int, int>> answercache;
        
        vector<double> scores;

        vector<double> preds;

        
    public:
        /*
        //Class constructor
        //@param none
        //@return none
        */
        PredictionCalculator();
        //calculate the RMSE
        double rmse() ;
};