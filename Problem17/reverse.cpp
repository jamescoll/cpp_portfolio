//============================================================================
// Name        : Problem17.cpp
// Author      : James Coll
// Version     : Version 1
// Copyright   : Munnki 2013
// Description : a program which flips a string in place method i uses pointers and ii uses recursion
//============================================================================


#include "iostream" 
#include "string.h" 

using namespace std; 

void vStringFlip(char caString[]);

void vStringFlipRecursive(char caString[], int iArraySize, int iPos=0);



int main()
{ 
	char caString[] = "The quick brown fox jumped over the lazy hedgehog"; 
        int iStrLen = strlen(caString);
        
	cout << caString << endl; 

        vStringFlip(caString);
        
	cout << caString << endl; 
        
        vStringFlipRecursive(caString, iStrLen);

        cout << caString << endl; 
}

void vStringFlip(char caString[])
{
        char *p = caString; 
	char *q = caString + strlen(caString)-1; 
	char cTmp;
        
        while(p < q)
	{ 
		cTmp = *p; 
		*p = *q; 
		*q = cTmp; 
		p++; 
		q--; 
		
	};
}

void vStringFlipRecursive(char caArray[], int iArraySize, int iPos)
{
  if (iPos<iArraySize-1)
    {
      vStringFlipRecursive(caArray, iArraySize-1, iPos+1);
      char cTmp = caArray[iPos];
      caArray[iPos] = caArray[iArraySize-1];
      caArray[iArraySize-1] = cTmp;
    }
}
