/*
alexrt-s
13/11/24
SUPACOO Assignment 1
*/

#include "CustomFunctions.h"

int main(){
    std::pair<std::vector<float>,std::vector<float>> data = read_data("../input2D_float.txt");
    std::vector<float> X;
    std::vector<float> Y;
    X = data.first;           //the first column of data is x values
    Y = data.second;          //the second is y values

    std::string cont = "0";   //continue running the while loop if cont == 0 

    while (cont == "0"){      //started implementing this before lecture 2, so didnt see the material
                              //about switch unitl after id alredy written this - sorry!
        std::string function;
        std::cout << "Which function do you want to use? type 0 for print(), 1 for magnitude, 2 for fit, 3 for X^y" <<  std::endl;
        std::cin >> function;

        if (function == "0"){         //calls the print function if input == 0 etc.
            int print_lines;
            std::cout << "How many lines do you want to print?" << std::endl;
            std::cin  >> print_lines;
            print_data(print_lines, X,Y);
        }
        else if (function == "1") {
            magnitude(1,X,Y);
        }

        else if (function == "2"){
            std::pair<std::vector<float>,std::vector<float>> data = read_data("../error2D_float.txt");
            std::vector<float> XErr;
            std::vector<float> YErr;

            XErr = data.first;
            YErr = data.second;


            std::pair<float,float> fit;
            float m;
            float c;
            

            fit = Fit_Straight_Line(X,Y,XErr,YErr);

            //m = fit.first;
            //c = fit.second;
        }
        else if (function == "3"){
            X_to_the_Y_vector(X,Y);
        }
        else {
            std::cout << "Error. Only valid inputs are 0, 1, 2 or 3" << std::endl;  //handles any input other than expected
        }    
        std::cout << "would you like to continue applying functions to the data (Enter 0), or (Enter anything but 0)?" << std::endl;
        std::cin >> cont;
    }
    return 0;
}


