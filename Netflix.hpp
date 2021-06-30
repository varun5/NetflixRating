#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>
using namespace std;
class PredictionCalculator {


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
    // callculates prediction
    double prediction(int userid, short movieid);
    /*
    //main driver function, solves program
    //@param vector p, vector s
    //@return none
    */
    void rmadd(vector<double> p, vector<double> s);
    /*
    //main driver function, solves program
    //@param none
    //@return none
    */
    void solve();
};