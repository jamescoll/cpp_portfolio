//============================================================================
// Name        : Problem2.cpp
// Author      : James Coll
// Version     : Version 1
// Copyright   : Munnki 2013
// Description : A straightforward io program that requests simple input from the user
//============================================================================

#include <iostream>
using namespace std;

int main()
{
	int iInputA, iInputB;
	int iSum, iSub;
	cout<<"Enter an integer: ";
	cin>>iInputA;
	cout<<"Enter another integer: ";
	cin>>iInputB;
	
	iSum = iInputA + iInputB;
	iSub = iInputA - iInputB;
	
	cout<<"The sum of the two integers is "<<iSum<<"\n";
	cout<<"The subtraction of the two integers is "<<iSub<<"\n";
	
	return 0;
}