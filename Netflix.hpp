#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>
using namespace std;
class PredictionCalculator{
    
        
    public:
        /*
        //Class constructor
        //@param none
        //@return none
        */
        PredictionCalculator();
        //calculate the RMSE
        double rmse() ;
        // calculate average
        double calc_average();

        /*
        //main driver function, solves program
        //@param none
        //@return none
        */
        void solve();
};