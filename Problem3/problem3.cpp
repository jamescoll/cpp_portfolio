//============================================================================
// Name        : Problem3.cpp
// Author      : James Coll
// Version     : Version 1
// Copyright   : Munnki 2013
// Description : A program which uses the string library to count alphabetical occurences of letters
//============================================================================


#include <iostream>

using namespace std;

int main()
{
	int iStrlen;
	int iIndex;
	int iaLetterCount[26];
	string sString;
	string sAlphabet = "abcdefghijklmnopqrstuvwxyz";
	
	//read in text from stdin until user presses 1
	cout<<"Enter text (Press 1 to finish)";
	getline(cin, sString, '1');
	
	//get length of string
	iStrlen = sString.size();
	
	for(iIndex=0;iIndex<26;iIndex++)//initialize the array to zeros
	{
		iaLetterCount[iIndex] = 0;
	}
	
	//iterate through string looking for number of letter occurences
	for(iIndex = 0; iIndex<iStrlen; iIndex++)
	{
		
			if (sString[iIndex] == 'a' || sString[iIndex] == 'A')
				iaLetterCount[0]+=1;
			if (sString[iIndex] == 'b' || sString[iIndex] == 'B')
				iaLetterCount[1]+=1;
			if (sString[iIndex] == 'c' || sString[iIndex] == 'C')
				iaLetterCount[2]+=1;
			if (sString[iIndex] == 'd' || sString[iIndex] == 'D')
				iaLetterCount[3]+=1;
			if (sString[iIndex] == 'e' || sString[iIndex] == 'E')
				iaLetterCount[4]+=1;
			if (sString[iIndex] == 'f' || sString[iIndex] == 'F')
				iaLetterCount[5]+=1;
			if (sString[iIndex] == 'g' || sString[iIndex] == 'G')
				iaLetterCount[6]+=1;
			if (sString[iIndex] == 'h' || sString[iIndex] == 'H')
				iaLetterCount[7]+=1;
			if (sString[iIndex] == 'i' || sString[iIndex] == 'I')
				iaLetterCount[8]+=1;
			if (sString[iIndex] == 'j' || sString[iIndex] == 'J')
				iaLetterCount[9]+=1;
			if (sString[iIndex] == 'k' || sString[iIndex] == 'K')
				iaLetterCount[10]+=1;
			if (sString[iIndex] == 'l' || sString[iIndex] == 'L')
				iaLetterCount[11]+=1;
			if (sString[iIndex] == 'm' || sString[iIndex] == 'M')
				iaLetterCount[12]+=1;
			if (sString[iIndex] == 'n' || sString[iIndex] == 'N')
				iaLetterCount[13]+=1;
			if (sString[iIndex] == 'o' || sString[iIndex] == 'O')
				iaLetterCount[14]+=1;
			if (sString[iIndex] == 'p' || sString[iIndex] == 'P')
				iaLetterCount[15]+=1;
			if (sString[iIndex] == 'q' || sString[iIndex] == 'Q')
				iaLetterCount[16]+=1;
			if (sString[iIndex] == 'r' || sString[iIndex] == 'R')
				iaLetterCount[17]+=1;
			if (sString[iIndex] == 's' || sString[iIndex] == 'S')
				iaLetterCount[18]+=1;
			if (sString[iIndex] == 't' || sString[iIndex] == 'T')
				iaLetterCount[19]+=1;
			if (sString[iIndex] == 'u' || sString[iIndex] == 'U')
				iaLetterCount[20]+=1;
			if (sString[iIndex] == 'v' || sString[iIndex] == 'V')
				iaLetterCount[21]+=1;
			if (sString[iIndex] == 'w' || sString[iIndex] == 'W')
				iaLetterCount[22]+=1;
			if (sString[iIndex] == 'x' || sString[iIndex] == 'X')
				iaLetterCount[23]+=1;
			if (sString[iIndex] == 'y' || sString[iIndex] == 'Y')
				iaLetterCount[24]+=1;
			if (sString[iIndex] == 'z' || sString[iIndex] == 'Z')
				iaLetterCount[25]+=1;
	}
	
	cout<<"Sentence contained the following letters:\n";
	
	for (iIndex=0; iIndex<26; iIndex++)
	{
		if(iIndex%5 == 0 && iIndex !=0)//split up the page a little, making things easier to read
			cout<<"\n";
		cout<<sAlphabet[iIndex]<<": "<<iaLetterCount[iIndex]<<" ";//this prints out the letter count using an array (saves a lot of typing)

	}
	
	
	return 0;
}