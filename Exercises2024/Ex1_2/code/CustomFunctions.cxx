/*
alexrt-s
13/11/24
SUPACOO Assignment 1
*/


#include "CustomFunctions.h"

std::vector<float> magnitude(int print, std::vector<float> X,std::vector<float> Y){   //function to calculate the magnitude of each vector
    std::vector<float> magnitudes;
    std::string output;
    for (int i = 0; i <= X.size() - 2;i++){
        float magnitude = std::sqrt(std::pow(X[i],2) + std::pow(Y[i],2));
        magnitudes.push_back(magnitude);
        if (print == 1){
            std::cout << "Magnitude: " << magnitude << std::endl;
        }
        output += "Magnitude: " + std::to_string(magnitude) + "\n";
    }
    std::ofstream Magnitude_Results;        //ofstream used to output results to file


    Magnitude_Results.open("magnitude_results.txt",std::ios_base::app);   //std::ios_base::app appends to file, so adds results if file already exists
    Magnitude_Results << output;
    Magnitude_Results.close();      //close the file when done
    

    return magnitudes;
}

int print_data(int lineNos,std::vector<float> x_Data,std::vector<float> y_Data){
    if (lineNos > x_Data.size()){ 
                                        
        std::cout << "Warning: Can't print " << lineNos << " lines of data from file containing " \
        << x_Data.size() << " lines of data" << std::endl;

        std::cout << "Printing the first 5 lines instead ..." << std::endl;

        lineNos = 5;


    }
    
    //std::vector<float> magnitudes = magnitude(0,x_Data,y_Data);
    for (int i = 0; i <= lineNos - 1; i ++ ) {
        std::cout <<"line " << i << ": x: " << x_Data[i] << "; Y: " << y_Data[i] << std::endl;
        
    }
    //from previous step where print function also prints the magnitude, rather than having a separate function
    
    
    std::cout << "Successfully read " << lineNos << " lines from file" << std::endl;
    return 0;
}
std::pair <std::vector<float>, std::vector<float>> read_data(std::string filename){

    std::ifstream  TwoDFloat;                   //ifstream to read in data
    TwoDFloat.open(filename);
    if (TwoDFloat.fail()) {
        std::cout << "Could not open the file" << std::endl;
    }
    else {
        std::cout << "Successfully opened file" << std::endl;
        std::cout << "Reading file ..." << std::endl;
    }

    int lineNum = 0;                                                    //the first line is the column titles
    std::vector<float> X;                                               
    std::vector<float> Y;

    std::string line;
    while (!TwoDFloat.eof()) {                                          //while not at the end of the file 
        lineNum += 1;                                       //first line is not data so i can skip it
        std:getline(TwoDFloat,line);
        //std::cout << line << std::endl;

        float x, y;

        // parsing the data using stringstream
        std::stringstream ss(line);

        // read the x value
        ss >> x;

        // ignore the comma
        ss.ignore(1);

        // read the y value
        ss >> y;
        if (lineNum > 1){      //adding the values to the vectors 
            X.push_back(x);
            Y.push_back(y);
        }
    }
    TwoDFloat.close();
    return {X,Y};
}

std::pair<float,float> Fit_Straight_Line(std::vector<float> X, std::vector<float> Y, std::vector<float> XErr, std::vector<float> YErr){
    //performing least squares minimisation
    float m;
    float c;
    float sumxy = 0;
    float sumx = 0;
    float sumy = 0;
    float sumxsq = 0;
    int N = X.size() - 2; 
    for (int i = 0; i < N ; i++){
        sumx += X[i];
        sumy += Y[i];
        sumxy += X[i] * Y[i];
        sumxsq += X[i] * X[i];
        //std::cout << "X " << X[i] << " Y "<< Y[i] << " XY "<< X[i] * Y[i] << "X^2 " << X[i] * X[i] << std::endl;
    }
    

    m = ((N * sumxy) - (sumx * sumy))/((N * sumxsq) - sumx * sumx);
    c = ((sumxsq * sumy) - (sumxy * sumx))/((N * sumxsq)-(sumx * sumx));
    //std::cout << "Line of Best Fit y = mx + c m: " << m << "; c: " << c << std::endl;

    
    //trying to calculate the chi-square - i got a wee bit confused with the equation here but 
    //i think the code is ok
    
    float Chisq = 0;

    for (int i = 0; i < N ; i++){
        Chisq += ((Y[i] - (m * X[i] + c )) * (Y[i] - (m * X[i] + c ))) /(YErr[i] * YErr[i]);
    }
    int nDof = X.size() - 2;                     //no of observations - no of free parameters (2)
    
    float chisqndof = Chisq/nDof;
    
    std::ofstream Fit_Results;

    std::string output = "y = mx + c ; m = " + std::to_string(m) + "; c = " + std::to_string(c) + " ; Chi2/nDoF = " + std::to_string(chisqndof) +  "\n";

    std::cout << output << std::endl;

    Fit_Results.open("fit_results.txt",std::ios_base::app);
    Fit_Results << output;
    Fit_Results.close();

    return {m,c};
}



float x_to_the_y(float X, float Y){
    //recursive function that applies a number to the power of an integer
    int y = (int)Y;   //converting to int rounds to nearest integer
    if (y == 0){
        return 1;
    }
    else if (y == 1){
        return X;
    }
    else if (y > 0){
        return x_to_the_y(X * X, y -1);
    }
    else if (y == -1){
        return 1/X;
    }
    else {
        return x_to_the_y(1/X * 1/X,(y + 1)* (-1));
    }
}

std::vector<float> X_to_the_Y_vector(std::vector<float> X, std::vector<float> Y){
    //calling the above function and applying it in a loop 
    std::vector<float> xpowy;
    float xpy;
    std::string output;
    for (int i = 0; i < X.size();i++){
        xpy = x_to_the_y(X[i],Y[i]);
        xpowy.push_back(xpy);
        std::cout << "X to the power of y is: " << xpy << std::endl;
        output += "X to the power of y is: " + std::to_string(xpy) + "\n";

    }

    std::ofstream Power_Results;    //appending to output file again


    Power_Results.open("power_results.txt",std::ios_base::app);
    Power_Results << output;
    Power_Results.close();

    return xpowy;
}