//============================================================================
// Name        : Problem13.cpp
// Author      : James Coll
// Version     : Version 1
// Copyright   : Munnki 2013
// Description : a program that converts from a DD-MMM-YYYY format to a DD-MM-YY format date
//============================================================================


#include <iostream>
#include <string.h>
#include <ctype.h>

using namespace std;

//these two macros define the size of the input and output formats respectively
const int ciInputSize = 12;
const int ciOutputSize = 9;

bool bConvertFormat(char caInputFormat[], char caOutputFormat[]);
bool bIsLeapYear(int iYear);

static char *scMonths[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"}; 



int main()
{
	char caInputDate[ciInputSize];
	char caOutputDate[ciOutputSize];

	do
	{
			cout<<endl<<"Enter a date in the format DD-MMM-YYYY:";
			cin>>caInputDate;
		
	} while (!bConvertFormat(caInputDate, caOutputDate));


	cout<<endl<<"Converted to "<<caOutputDate<<endl;
	
	return 0;
}
//input date format must be DD-MMM-YYYY
bool bConvertFormat(char caInputFormat[], char caOutputFormat[])
{

	//let's check for the '-' symbol first - it should be at position
	//two and position six in the array
	if(caInputFormat[2] != '-' || caInputFormat[6] != '-')
	{
		cout<<"Enter a date in the correct format ('-' in wrong position)"<<endl;
		return false;
	}

	//let's then check for an array of the correct length
	if(caInputFormat[11] != '\0')
	{
		cout<<"Enter a date in the correct format (DD-MMM-YYYY - incorrect length)";
		return false;
	}
	
	//first look at the first two characters in the string and convert
	//them to an int value
	int iDay;
	
	//this is using the ASCII codes as a look-up table
	iDay = (caInputFormat[0]-48)*10;
	iDay += (caInputFormat[1]-48);
	 

	//now check that those days are valid (first pass trivial check)
	if(iDay<=0 || iDay>31)
	{
		cout<<"Enter a date in the correct format (not a valid day)"<<endl;
		return false;
	}

	//now look at the month and compare it to the entries in the month table
	//we only need to care about whether it is exactly like one of the twelve entries
	//in our array	
	char caMonth[4];

	//copy what was entered into a temporary month array
	for(int i=0; i<3; i++)
		caMonth[i]=caInputFormat[i+3];
	
	//add a null terminator - we may get rid of this later
	caMonth[3]='\0';
	//cycle through our array containing months and compare the value stored in
	//month with each of them - if none check out then return false
	int iNumberMonth = 0;

	for(int i=0; i<12; i++)
	{
		
		

		if (strcmp(caMonth, scMonths[i]) == 0)
		{
			iNumberMonth = i+1;
		}
		
	}			

	//if iNumberMonth has remained zero then a valid month wasn't entered
	if(iNumberMonth == 0)
	{
		cout<<"Enter a date in the correct format (not a valid month)"<<endl;
		cout<<"Jan-Feb-Mar-Apr-May-Jun-Jul-Aug-Sep-Oct-Nov-Dec"<<endl;
		return false;
	}	
	//now we'll convert the year to an integer using the same method as with our
	//month

	//actually we need to check this to determine if our array is made up of four values

	for(int i=7; i<11; i++)
	{
		if(!isdigit(caInputFormat[i]))
		{
			cout<<"Enter a date in the correct format (not a valid year YYYY)";
			return false;
		}
		
	}

	//do the conversion - we have already checked that our year is in YYYY format
	int iYear;
	iYear = (caInputFormat[7]-48)*1000;
	iYear += (caInputFormat[8]-48)*100;
	iYear += (caInputFormat[9]-48)*10;
	iYear += caInputFormat[10]-48;
	

	//finally we have a day, date and year in integer form that are valid
	//now we need to check the days and years values for validity (months were already done)


	//so we will iterate through the months and check each for a valid number of days...allowing also for leap years (feb)
	//as we have already checked for 1-31 values then we only need to worry about months with days less than 31
			
	if(iNumberMonth == 2)
	{
		if(iDay>29)
		{
			cout<<"Enter a date in the correct format (incorrect number of days in month)";
			return false;
		}	
		if(iDay==29)
		{
			if(!bIsLeapYear(iYear))
			{
				cout<<"Enter a date in the correct format (incorrect number of days in month)";
				return false;		
			}
		}
	}

	if(iNumberMonth == 4 || iNumberMonth == 6 || iNumberMonth == 9 || iNumberMonth == 11)
	{
		if(iDay==31)
		{
			cout<<"Enter a date in the correct format (incorrect number of days in month)";
			return false;
		}
		
	}
	

	//we have a valid number of days in each month, a valid year and a valid month
	//now we just need to set the output format for the date
	//output format is DD/MM/YY

	if(iDay<10)
	{
		caOutputFormat[0] = '0';
		caOutputFormat[1] = '0' + iDay;
	}
	else if (iDay<20)
	{
		caOutputFormat[0] = '1';
		caOutputFormat[1] = '0' + (iDay - 10);
	}
	else if (iDay<30)
	{
		caOutputFormat[0] = '2';
		caOutputFormat[1] = '0' + (iDay - 20);
	}
	else
	{
		caOutputFormat[0] = '3';
		caOutputFormat[1] = '0' + (iDay - 30);
	}
	
	caOutputFormat[2] = '/';

	//now the months
	if(iNumberMonth<10)
	{
		caOutputFormat[3] = '0';
		caOutputFormat[4] = '0' + iNumberMonth;
	}
	else
	{
		caOutputFormat[3] = '1';
		caOutputFormat[4] = '0' + (iNumberMonth - 10);
	}
	
	caOutputFormat[5] = '/';

	//years are weird because for years less than one thousand the DD-MM-YY format doesn't really make sense
	//this code assumes that the user is happy with getting those values even for years less than 1000
        //the year 0000 will be read the same as the year 0100 and the year 1000 with two digit year representations
        //centuries effectively don't matter

	caOutputFormat[6] = caInputFormat[9];
	caOutputFormat[7] = caInputFormat[10];

	//don't forget the chomp

	caOutputFormat[8] = '\0';

	return true;
}

bool bIsLeapYear(int iYear)
{
	if((iYear%4==0) && !(iYear%100==0))
		return true;
	else
		return false;
}
