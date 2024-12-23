#include <string>
#include <vector>
#include <cmath>
#include "gnuplot-iostream.h"

#pragma once //Replacement for IFNDEF

class FiniteFunction{

public:
  FiniteFunction(); //Empty constructor
  FiniteFunction(double range_min, double range_max, std::string outfile); //Variable constructor
  ~FiniteFunction(); //Destructor
  double rangeMin(); //Low end of the range the function is defined within
  double rangeMax(); //High end of the range the function is defined within
  double integral(int Ndiv = 1000); 
  std::vector< std::pair<double,double> > scanFunction(int Nscan = 1000); //Scan over function to plot it (slight hack needed to plot function in gnuplot)
  void setRangeMin(double RMin);
  void setRangeMax(double RMax);
  void setOutfile(std::string outfile);
  void plotFunction(); //Plot the function using scanFunction
  
  //Plot the supplied data points (either provided data or points sampled from function) as a histogram using NBins
  void plotData(std::vector<double> &points, int NBins, bool isdata=true); //NB! use isdata flag to pick between data and sampled distributions
  virtual void printInfo(); //Dump parameter info about the current function (Overridable)
  virtual double callFunction(double x); //Call the function with value x (Overridable)

  //Protected members can be accessed by child classes but not users
protected:
  double m_RMin;
  double m_RMax;
  double m_Integral;
  int m_IntDiv = 0; //Number of division for performing integral
  std::string m_FunctionName;
  std::string m_OutData; //Output filename for data
  std::string m_OutPng; //Output filename for plot
  std::vector< std::pair<double,double> > m_data; //input data points to plot
  std::vector< std::pair<double,double> > m_samples; //Holder for randomly sampled data 
  std::vector< std::pair<double,double> > m_function_scan; //holder for data from scanFunction (slight hack needed to plot function in gnuplot)
  bool m_plotfunction = false; //Flag to determine whether to plot function
  bool m_plotdatapoints = false; //Flag to determine whether to plot input data
  bool m_plotsamplepoints = false; //Flag to determine whether to plot sampled data 
  double integrate(int Ndiv);
  std::vector< std::pair<double, double> > makeHist(std::vector<double> &points, int Nbins); //Helper function to turn data points into histogram with Nbins
  void checkPath(std::string outstring); //Helper function to ensure data and png paths are correct
  void generatePlot(Gnuplot &gp); 
  
private:
  double invxsquared(double x); //The default functional form
};

class GaussianFunction : public FiniteFunction{
  public:
    GaussianFunction(); //Copying the constructors and destructors from the base class
    GaussianFunction(double range_min, double range_max, double mu, double sigma,std::string outfile); 
    ~GaussianFunction(); 
    double callFunction(double x) override; //overriding this function
    double mu(); 
    double sigma(); 
    void setmu(double mu);
    void setsigma(double sigma);
    void printInfo() override; //Dump parameter info about the current function (Overridable)


  protected:
    double m_mu;
    double m_sigma;

  private:
    double gaussian(double x);
};

class CauchyLorentzFunction : public FiniteFunction{
  public:
    CauchyLorentzFunction(); //Copying the constructors and destructors from the base class
    CauchyLorentzFunction(double range_min, double range_max, double xo, double gamma,std::string outfile); 
    ~CauchyLorentzFunction(); 
    double callFunction(double x) override; //overriding just this function
    double xo(); 
    double gamma(); 
    void setxo(double xo);
    void setgamma(double gamma);
    void printInfo() override; //Dump parameter info about the current function (Overridable)


  protected:
    double m_xo;
    double m_gamma;

  private:
    double cauchylorentz(double x);
};

class CrystalBallFunction : public FiniteFunction{
  public:
    CrystalBallFunction(); //Copying the constructors and destructors from the base class
    CrystalBallFunction(double range_min, double range_max, double alpha, double xbar, double n, double sigma,std::string outfile); 
    ~CrystalBallFunction(); 
    double callFunction(double x) override; //overriding just this function
    double alpha(); 
    double xbar(); 
    double n();
    double sigma();
    void setalpha(double alpha);
    void setxbar(double xbar);
    void setn(double n);
    void setsigma(double sigma);
    void printInfo() override; //Dump parameter info about the current function (Overridable)


  protected:
    double m_xbar;
    double m_sigma;
    double m_alpha;
    double m_n;

  private:
    double crystalball(double x);
};

