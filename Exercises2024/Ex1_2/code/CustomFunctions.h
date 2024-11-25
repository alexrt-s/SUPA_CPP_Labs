/*
alexrt-s
13/11/24
SUPACOO Assignment 1
*/


#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <cmath>

std::vector<float> magnitude(int print, std::vector<float> X,std::vector<float> Y);

int print_data(int lineNos,std::vector<float> x_Data,std::vector<float> y_Data);

std::pair <std::vector<float>, std::vector<float>> read_data(std::string filename);

std::pair<float,float> Fit_Straight_Line(std::vector<float> X, std::vector<float> Y, std::vector<float> XErr, std::vector<float> YErr);

float x_to_the_y(float X, float Y);

std::vector<float> X_to_the_Y_vector(std::vector<float> X, std::vector<float> Y);


