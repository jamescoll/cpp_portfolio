//============================================================================
// Name        : Problem15.cpp
// Author      : James Coll
// Version     : Version 1
// Copyright   : Munnki 2013
// Description : a program for calculating the square root of a number
//============================================================================

#include<iostream>
#include<iomanip>
#include<cstdlib>

using namespace std;

const int ciMaxIterations=100000;

double dMySqrt(double dX);


int main()
{
        double dX;
        
        cout<<"Enter a decimal number:";
        cin>>dX;
        
	cout<<"The square root of "<<dX<<" is "<<setprecision(20)<<dMySqrt(dX)<<endl;
        
	return 0;
} 

double dMySqrt(double dX)
{

  	double dEpsilon = 0.0;
	double dY = dX;
      		
      		int iNumOfIterations=0;
      		while (dY*dY - dX > dEpsilon)
		{
	  		dY = (dX/dY + dY) / 2.0;
	  		iNumOfIterations++;
	  		if (iNumOfIterations>ciMaxIterations)
	    		{
	      			cout << "Exiting because loop condition not true after "  << ciMaxIterations<< " iterations."<< endl;
	      		break;
	    		}
		}
	
	return dY;
}
