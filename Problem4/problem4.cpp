//============================================================================
// Name        : Problem4.cpp
// Author      : James Coll
// Version     : Version 1
// Copyright   : Munnki 2013
// Description : an algorithm for the arctan function (this also includes 
//               Dr Hurley's method which is used for the second call.
//============================================================================



#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double dArctan(double dX, int iNumberOfTerms);
double dAtangent(double dX, double dPrecision);

int main()
{
	double dX, dResult;
        double dEpsilon = 10e-10;
	int iNumberOfTerms;
	
	dResult = 0;



	cout<<"Enter a z value between -1 and 1 :";
	cin>>dX;
	
	//add check that the absolute value of z is between -1 and 1
	while(abs(dX)>1)
	{
		cout<<"Enter a z value between -1 and 1 :";
		cin>>dX;
	}
	
	cout<<"Enter the number of terms you wish to evaluate: ";
	cin>>iNumberOfTerms;
	
	dResult = dArctan(dX, iNumberOfTerms);
	
	if(dResult == 0.0)
	{	
		cout<<"Error in calculation function"<<endl;
	}
	else
	{
		cout<<"By the expansion series the arctan of "<<setprecision(20)<<dX<<" is "<<dResult<<"."<<endl;
	}
        
        cout<<"The arctan of "<<dX<<" by the standard library function is "<<setprecision(20)<<atan(dX)<<endl;
        
        cout<<"The arctan of "<<dX<<" by the Dr Hurley's function is "<<setprecision(20)<<dAtangent(dX, dEpsilon)<<endl;
	
        cout<<"Comparing each by calculating Pi dArctan gives "<<16.0*dArctan(1.0/5.0, 100000) - 4.0*dArctan(1.0/239.0, 100000)-M_PI<<endl;
        
        cout<<"Comparing each by calculating Pi atan gives "<<16.0*atan(1.0/5.0) - 4.0*atan(1.0/239.0)-M_PI<<endl;
        
        cout<<"Comparing each by calculating Pi dAtangent gives "<<16.0*dAtangent(1.0/5.0, dEpsilon) - 4.0*dAtangent(1.0/239.0, dEpsilon)-M_PI<<endl;

	return 0;


}

double dArctan (double dX, int iNumberOfTerms)
{
	double dTmpA, dTmpB, dTmpC;
	int i2Nplus1;
	int iIndex;
	
	dTmpC = 0.0;
	
	for(iIndex=0; iIndex<iNumberOfTerms; iIndex++)
	{
		
		i2Nplus1 = ((iIndex*2)+1);
		dTmpA = pow(-1.0, iIndex);
		dTmpB = pow(dX, i2Nplus1);
		dTmpC = dTmpC + ((dTmpA*dTmpB)/i2Nplus1);
	}
	
	return dTmpC;
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