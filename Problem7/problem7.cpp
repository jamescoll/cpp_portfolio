//============================================================================
// Name        : Problem7.cpp
// Author      : James Coll
// Version     : Version 1
// Copyright   : Munnki 2013
// Description : a program that copies an input file to an output file using c++ iostream techniques
//============================================================================



#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[])
{
	char cCurrentChar;
	fstream inputfile;
	fstream outputfile;
	
	inputfile.open(argv[1], ios::in);       
	outputfile.open(argv[2], ios::out);
        
        
	for ((cCurrentChar=inputfile.get());!inputfile.eof();(cCurrentChar=inputfile.get()))outputfile.put(cCurrentChar);

	inputfile.close();
	outputfile.close();
	
	return 0;
}
	