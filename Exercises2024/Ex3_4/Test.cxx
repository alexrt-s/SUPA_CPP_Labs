/*
alexrt-s
12/12/24
SUPACOO Assignment 2
*/

#include "FiniteFunctions.h"
#include <iostream>
#include <vector>
#include <string>
#include <sstream>




int main(){
    std::ifstream  RandData;                   //ifstream to read in data
    RandData.open("Outputs/data/MysteryData24111.txt");
    if (RandData.fail()) {
        std::cout << "Could not open the file" << std::endl;
    }
    else {
        std::cout << "Successfully opened file" << std::endl;
        std::cout << "Reading file ..." << std::endl;
    }

    std::vector<double> X;                                               

    std::string line;
    while (!RandData.eof()) {                                          //while not at the end of the file 
        std::getline(RandData,line);
        std::stringstream ss(line);
        double x;

        if (ss >> x){

            X.push_back(x);
        }

    }
    std::cout << X.size() << std::endl;
/*
    for (int i = 0; i < X.size();i++){
        std::cout << X[i] << std::endl;
    }
*/

    FiniteFunction func( -10, 10, "Outputs/invxsquared");
    func.plotData(X, 50, true);
    func.plotFunction();
    func.printInfo();


    GaussianFunction Func( -10,  10,2,1.8, "Outputs/normal");
    Func.plotData(X, 50, true);
    Func.plotFunction();
    Func.printInfo();

    CauchyLorentzFunction FUNC( -10,  10,2,1.8, "Outputs/Cauchy-Lorentz");
    FUNC.plotData(X, 50, true);
    FUNC.plotFunction();
    FUNC.printInfo();

    //double alpha, double xbar, double n, double sigma,
    CrystalBallFunction funC( -10, 10,1.2,2,1.2,1.5, "Outputs/Crystal Ball");
    funC.plotData(X, 50, true);
    funC.plotFunction();
    funC.printInfo();

    return 0;
}
