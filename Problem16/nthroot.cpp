//============================================================================
// Name        : Problem16.cpp
// Author      : James Coll
// Version     : Version 1
// Copyright   : Munnki 2013
// Description : a program for calculating the rth root of a number
//============================================================================

#include<iostream>
#include<iomanip>
#include<cstdlib>
#include <math.h>

using namespace std;

double dRthroot(double dX, double dR);

const int iMaxIterations=100000;

int main()
{
	double dInputNumber, dInputRoot;
        
	cout<<"Enter a number:";
	cin>>dInputNumber;
	cout<<"Enter a root:";
	cin>>dInputRoot;
	cout<<"The "<<dInputRoot<<" root of "<<dInputNumber<<" is "<<setprecision(20)<<dRthroot(dInputNumber, dInputRoot)<<endl;
	cout<<"The (standard library)"<<dInputRoot<<" root of "<<dInputNumber<<" is "<<setprecision(20)<<pow(dInputNumber, (1.0/dInputRoot))<<endl;
        return 0;
} 

double dRthroot(double dX, double dR)
{

  	
  	double dEpsilon = 0.0;
	double dY = dX;
      	int iNumIterations=0;


      		while ((pow(dY,dR) - dX) > dEpsilon)
		{
			
	  		dY = (1-1/dR)*dY + dX/(dR*pow(dY,dR-1));
	  		iNumIterations++;
	  		if (iNumIterations>iMaxIterations)
	    		{
	      			cout << "Exiting because loop condition not true after "  << iMaxIterations<< " iterations."<< endl;
	      		break;
	    		}
		}
	
	return dY;
}
