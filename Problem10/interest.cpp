//============================================================================
// Name        : Problem10.cpp
// Author      : James Coll
// Version     : Version 1
// Copyright   : Munnki 2013
// Description : a program that calculates compound interest
//============================================================================

#include <iostream>
#include <math.h>

using namespace std;

double dCompoundInterest(double dPrincipal, double dRate, int iNumyears);

int main()
{
	double dCompoundI = 0.0;
	double dRate, dPrincipal;
        int iNumyears;
        
	cout<<"Enter a principal sum: ";
	cin>>dPrincipal;
	
	cout<<"Enter a rate of interest: ";
	cin>>dRate;

	cout<<"Enter a number of years: ";
	cin>>iNumyears;

	dCompoundI = dCompoundInterest(dPrincipal, dRate, iNumyears);

	cout<<"The compound interest on "<< dPrincipal<<" over a  "<<iNumyears<<" period at a rate of "<<dRate<<" percent is "<<dCompoundI<<endl;

	return 0;
		
}

double dCompoundInterest(double dPrincipal, double dRate, int iNumyears)
{
	return dPrincipal*(pow(1+dRate/100.0, iNumyears))-dPrincipal;
}


