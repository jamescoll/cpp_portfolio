//============================================================================
// Name        : Problem9.cpp
// Author      : James Coll
// Version     : Version 1
// Copyright   : Munnki 2013
// Description : a program that opens files and displays them 20 lines at a time
//============================================================================


#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main(int argc, char* argv[])
{
string sSentence;

char cChoice='\0';
int iLines;

//declare input  stream
fstream inputfile;

if(argc<2)
{
	cout<< "Run program as "<<argv[0]<<" display20 (inputfile)";
}

//open the input stream
inputfile.open(argv[1], ios::in);


	while(cChoice!='q' && !inputfile.eof())
	{
		for(iLines=0;  iLines<20 ; iLines++)
			{
				getline(inputfile, sSentence, '\n');
				cout<<sSentence<<endl;
			}
			
		cout<<"*******************************************************"<<endl;
		cout<<"Press 'q' to quit or Enter to continue"<<endl;
		cin.get(cChoice);

	}
	//close the file
	inputfile.close();
	return 0;
}
