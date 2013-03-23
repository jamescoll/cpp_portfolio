//============================================================================
// Name        : Problem14.cpp
// Author      : James Coll/Dr Neil Hurley (comments and implementation of algorithm for atan)
// Version     : Version 1
// Copyright   : Munnki 2013
// Description : a command line version of the arctangent program
//============================================================================



#include <iostream>
#include <iomanip>  
#include <cmath>    
#include <cstdlib>  


using namespace std;


double dAtangent(double dX, double dPrecision=10e-10);

// run by 'command line' 'inputvalue'
int main(int argc, char *argv[])
{
  double dX, dY;
  double dEpsilon = 10e-10;
  if (argc < 2)
    {
      cerr << "Usage : " << argv[0] << " <value>," << endl;
      return -1;
    }

  // strtod takes the input character array and converts it to a floating point value
  dX = strtod(argv[1], 0);

  cout << "dAtangent(" << dX << ") is " << setprecision(20) << dAtangent(dX, dEpsilon) << endl;
  cout<<"Standard library atan returns:"<<atan(dX)<<endl;
  
  // Now use the atangent() function to calculate the mathematical constant
  // I'll assign y to the difference between the expression for PI using the atan()
  // formula and the constant M_PI provided in the cmath library.  If the formula
  // works, then y should be a small number

   dY = 16.0*dAtangent(1.0/5.0) - 4.0*dAtangent(1.0/239.0)-M_PI;
    
  cout << "Difference between formula and PI  = " << setprecision(10) << fabs(dY) << endl;

}

double dAtangent(double dX, double dPrecision)
{
  double dTerm;
  double dSum=0.0;
  int i;

  dTerm = dX;
  i = 2;
  do 
    {
      dSum += dTerm;
      // you can check that it is possible to update term to the
      // next term using the formula below e.g.
      // when i=2, (2*i-3)/(2*i-1) = 1/3 and the ratio of the second
      // term to the first is -x*x/3.  When i=3
      // (2*i-3)/(2*i-1) = 3/5 and the ratio of the third term to the 
      // second is -x*x*3/5 etc.
      dTerm = -dTerm*dX*dX*(2*i-3)/(2*i-1);
      i ++;
    } while (fabs(dTerm)>dPrecision);
  return dSum;
}


  
  
  
