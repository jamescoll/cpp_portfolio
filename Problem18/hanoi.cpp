//============================================================================
// Name        : Problem18.cpp
// Author      : James Coll
// Version     : Version 1
// Copyright   : Munnki 2013
// Description : The famous Towers of Hanoi in code
//============================================================================

#include <iostream>

using namespace std;

void vTowersOfHanoi(int iNumberOfDisks, int cLocation, int tmpLocation, int fLocation);

int main()
{
    int iNumberOfDisks;
    cout << "Enter number of disks: ";
    cin >> iNumberOfDisks;
    vTowersOfHanoi(iNumberOfDisks, 1, 2, 3);
    return 0;
}

void vTowersOfHanoi(int iNumberOfDisks, int cLocation, int tmpLocation, int fLocation)
{
    if( iNumberOfDisks != 0 ) 
    {
        vTowersOfHanoi(iNumberOfDisks-1, cLocation, fLocation, tmpLocation );
        cout << cLocation << "->" << fLocation << endl;
        vTowersOfHanoi( iNumberOfDisks-1, tmpLocation, cLocation, fLocation );
    }
}


