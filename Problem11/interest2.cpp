//============================================================================
// Name        : Problem11.cpp
// Author      : James Coll
// Version     : Version 1
// Copyright   : Munnki 2013
// Description : a program that returns the principal amount on a compounded interest sum
//============================================================================

#include <iostream>
#include <math.h>

using namespace std;

double dFindPrincipal(double dDebtAmount, double dRate, int iNumyears);

int main()
{
	double dPrincipal = 0.0;
	double dRate, iNumyears, dDebtAmount;

	cout<<"Enter current amount owed: ";
	cin>>dDebtAmount;
	
	cout<<"Enter the rate of interest: ";
	cin>>dRate;

	cout<<"Enter the number of years: ";
	cin>>iNumyears;


	dPrincipal = dFindPrincipal(dDebtAmount, dRate, iNumyears);
        

	cout<<"The original amount owed is: "<<dPrincipal<<endl;
	
        return 0;
		
}

double dFindPrincipal(double dDebtAmount, double dRate, int iNumyears)
{

	return dDebtAmount/pow((1 + dRate/100.0),iNumyears);
	
	
}

