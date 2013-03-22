//============================================================================
// Name        : Problem6.cpp
// Author      : James Coll
// Version     : Version 1
// Copyright   : Munnki 2013
// Description : a program that uses our previously written arctan function in order to compute Pi
//                      using a different more quickly convergent approach than problem5
//============================================================================



#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double dArctan(double dX, int iNumberOfTerms);

int main()
{

	double dPi;
	
	dPi = (4.0)*((4.0*dArctan(0.2, 100000)) - dArctan(0.0041841004, 100000));
	
	cout<<"The value of PI calculated using the arctan function is "<<setprecision(10)<<dPi<<endl;
	
        cout<<"The value of PI in the standard lib is "<<setprecision(20)<<M_PI<<endl;
         
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