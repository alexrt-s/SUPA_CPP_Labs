/*
alexrt-s 13/11/24
preliminary exercises
Hello World etc.
*/

#include <iostream>
#include <cmath>

int main(){
    std::cout << "Hello World" << std::endl; 


    double x;
    double y;

    std::cout << "Enter value of x";
    std::cin >> x;

    std::cout << "Enter value of y";
    std::cin >> y;

    double magnitude = std::sqrt(std::pow(x,2) + std::pow(y,2));
    std::cout <<"Magnitude of the vector is " << magnitude << std::endl;
    return 0;
}