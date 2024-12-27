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
    FiniteFunction func( -10, 10, "Outputs/invxsquared");
    std::vector<double> Sampled_data = func.Metropolis(10000);
    func.plotData(Sampled_data,50, false);
    func.plotData(X, 50, true);
    func.plotFunction();
    func.printInfo();


    GaussianFunction Func( -10,  10,2,1.8, "Outputs/normal");
    std::vector<double> sampled_data = Func.Metropolis(1000);
    Func.plotData(sampled_data,50, false);
    Func.plotData(X, 50, true);
    Func.plotFunction();
    Func.printInfo();

    CauchyLorentzFunction FUNC( -10,  10,2,1.8, "Outputs/Cauchy-Lorentz");
    FUNC.plotData(X, 50, true);
    std::vector<double> sampled_Data = FUNC.Metropolis(1000);
    FUNC.plotData(sampled_Data,50, false);
    FUNC.plotFunction();
    FUNC.printInfo();

    

    //double alpha, double xbar, double n, double sigma,
    CrystalBallFunction funC( -10, 10,1.2,2,1.2,1.5, "Outputs/Crystal Ball");
    funC.plotData(X, 50, true);
    std::vector<double> Sampled_Data = funC.Metropolis(1000);
    funC.plotData(Sampled_Data,50, false);
    funC.plotFunction();
    funC.printInfo();
    */

    FiniteFunction IN( -10, 10, "Outputs/invxsquared");
    IN.plotData(X, 50, true);
    std::vector<double> Sampled_Data_IN = IN.Metropolis(1000);
    IN.plotData(Sampled_Data_IN,50, false);
    IN.plotFunction();
    IN.printInfo();


    GaussianFunction GS( -10,  10,2,1.8, "Outputs/normal");
    GS.plotData(X, 50, true);
    std::vector<double> Sampled_Data_GS = GS.Metropolis(1000);
    GS.plotData(Sampled_Data_GS,50, false);
    GS.plotFunction();
    GS.printInfo();


    CauchyLorentzFunction CL( -10, 10,2,1.8, "Outputs/Cauchy-Lorentz");
    CL.plotData(X, 50, true);
    std::vector<double> Sampled_Data_CL = CL.Metropolis(1000);
    CL.plotData(Sampled_Data_CL,50, false);
    CL.plotFunction();
    CL.printInfo();

    CrystalBallFunction CB( -10, 10,1.2,2,1.2,1.5, "Outputs/Crystal Ball");
    CB.plotData(X, 50, true);
    std::vector<double> Sampled_Data_CB = CB.Metropolis(1000);
    CB.plotData(Sampled_Data_CB,50, false);
    CB.plotFunction();
    CB.printInfo();


    

   
    return 0;
}
