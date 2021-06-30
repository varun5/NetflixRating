#include <iostream>

#include "Netflix.hpp"

int main() {
    using namespace std;
    PredictionCalculator p;
    //cout<<p.rmse()<<endl;
    //cout << p.calc_average() <<endl;
    p.solve();
}