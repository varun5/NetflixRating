#include <iostream>

#include "Netflix.hpp"

int main() {
    using namespace std;
    PredictionCalculator p;
    cout<<p.rmse()<<endl;
}