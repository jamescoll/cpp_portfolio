//============================================================================
// Name        : Problem12.cpp
// Author      : James Coll
// Version     : Version 1
// Copyright   : Munnki 2013
// Description : a program that capitalizes a character array
//============================================================================

#include <iostream>
#include <string.h>

using namespace std;


void vCapitalize(char caArray[], int iArraySize);


int main()
{

	char caArray[] = "This is some text for our string which will be output as uppercase though - not the symbols - after the capitalize function";

	//we need to properly work out the array size here
	int iArraySize = sizeof(caArray);
	
	cout<<"Before capitalize: "<<caArray<<endl;

	vCapitalize(caArray, iArraySize);

	cout<<"After capitalize: "<<caArray<<endl;


	return 0;
}

void vCapitalize(char caArray[], int iArraySize)
{

	for(int index=0; index<iArraySize; index++)
	{
		if(caArray[index]>=97 && caArray[index]<=122)
			caArray[index]-=32;
	}

}
