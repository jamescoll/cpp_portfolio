//============================================================================
// Name        : Problem8.cpp
// Author      : James Coll
// Version     : Version 1
// Copyright   : Munnki 2013
// Description : a program that compares two input files and says whether they have the same (text) contents as each other
//============================================================================


#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[])

{

	char cChar1, cChar2;


	fstream inputfileA;
	fstream inputfileB;

	if(argc !=3)
	{
		cout<< "Enter the command as \"compare (inputfile) (outputfile)\"";
		return 0;
	}

	//initialize cChar to some value so they pass the first loop iteration
	cChar1 = 'a';
	cChar2 = 'a';

	inputfileA.open(argv[1], ios::in);


	inputfileB.open(argv[2],ios::in);



	while(!inputfileA.eof()  && !inputfileB.eof() && cChar1==cChar2)
	{
		cChar1=inputfileA.get();
		cChar2=inputfileB.get();
		
	}
	
		//Print out the answer
		if(cChar1 != cChar2)
		{
				cout<<"The files do not match";
		}
		else
		{
			cout<<"The files match.";
		}
	//close the streams
	inputfileA.close();
	inputfileB.close();


	return 0;
}
