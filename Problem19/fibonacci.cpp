//============================================================================
// Name        : Problem19.cpp
// Author      : James Coll
// Version     : Version 1
// Copyright   : Munnki 2013
// Description : the fibonacci sequence implemented properly with a helper to avoid memory issues 
//============================================================================



#include <iostream>
using namespace std;

// The is an efficient way to implement fibonacci recursively. Each call
// to the fib_helper function incurs just one further recursive call.

// Note that fibonacci numbers get large very quickly - if you want to try
// this program for large values of n, you need to change the int variables
// to floating-point variables, as the integers will overflow.

int iFiboHelper(int iPrev, int iCurr, int iCount, int iN);
int iFibonacci(int iN);

int main()
{
  int iInput;
  cout<<"Enter the fibonacci term you wish to find:";
  cin >> iInput;

  cout << "The nth fibonacci number is " << iFibonacci(iInput) << endl;
}

int iFibonacci(int iN)
{
  if (iN<=2)
    return 1;
  else
    return iFiboHelper(1,1,2,iN);
}


int iFiboHelper(int iPrev, int iCurr, int iCount, int iN)
{
  if (iCount == iN)
    return iCurr;
  else
    return iFiboHelper(iCurr, iCurr+iPrev, iCount + 1, iN);
}
