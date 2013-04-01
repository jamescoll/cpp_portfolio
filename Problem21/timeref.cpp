//============================================================================
// Name        : Problem21
// Author      : James Coll
// Version     :
// Copyright   : Munnki
// Description : A program which computes the sum and difference of two times passing values by
//	reference using const in order to prevent changes to immutable values
//============================================================================

#include <iostream>
#include <cstdlib>
using namespace std;

typedef struct
{
	int iSeconds;
	int iMinutes;
	int iHours;
} MyTime;

void mytimeAdd_Time(const MyTime& t1, const MyTime& t2, MyTime& tout);
void mytimeSubtract_Time(const MyTime& t1, const MyTime& t2, MyTime& tout);


int main() {
	MyTime t1, t2;
	MyTime tsum, tsub;
	t1.iSeconds = 34;
	t1.iMinutes = 56;
	t1.iHours = 12;
	t2.iSeconds = 24;
	t2.iMinutes = 37;
	t2.iHours = 7;

	mytimeAdd_Time(t1, t2, tsum);
	mytimeSubtract_Time(t1, t2, tsub);

	cout<<"Time 1 "<<t1.iHours<<" Hrs "<<t1.iMinutes<<" Mns "<<t1.iSeconds<<" snds"<<endl;
	cout<<"Time 2 "<<t2.iHours<<" Hrs "<<t2.iMinutes<<" Mns "<<t2.iSeconds<<" snds"<<endl;
	cout<<"Sum "<<tsum.iHours<<" Hrs "<<tsum.iMinutes<<" Mns "<<tsum.iSeconds<<" snds"<<endl;
	cout<<"Diff "<<tsub.iHours<<" Hrs "<<tsub.iMinutes<<" Mns "<<tsub.iSeconds<<" snds"<<endl;
}

void mytimeAdd_Time(const MyTime& t1, const MyTime& t2, MyTime& tout)
{

	int iCheck = 0;
	//first we'll add the times together
	tout.iSeconds = t1.iSeconds + t2.iSeconds;
	tout.iMinutes = t1.iMinutes + t2.iMinutes;
	tout.iHours = t1.iHours + t2.iHours;

	//check the times starting with the seconds
	while(tout.iSeconds>60)
	{
		tout.iSeconds -= 60;
		iCheck++;
	}

	while(iCheck != 0)
	{
		tout.iMinutes += 1;
		iCheck--;
	}

	//check the times now the minutes
	while(tout.iMinutes>60)
	{
		tout.iMinutes -= 60;
		iCheck++;
	}

	while(iCheck != 0)
	{
		tout.iHours += 1;
		iCheck--;
	}

}

//this function will always return a positive value
//as a negative time is somewhat meaningless as such
//it will use absolute values
void mytimeSubtract_Time(const MyTime& t1, const MyTime& t2, MyTime& tout)
{


	int iCheck = 0;
	//first we'll add the times together
	tout.iSeconds = abs(t1.iSeconds - t2.iSeconds);
	tout.iMinutes = abs(t1.iMinutes - t2.iMinutes);
	tout.iHours = abs(t1.iHours - t2.iHours);

	//check the times starting with the seconds
	while(tout.iSeconds>60)
	{
		tout.iSeconds -= 60;
		iCheck++;
	}

	while(iCheck != 0)
	{
		tout.iMinutes += 1;
		iCheck--;
	}

	//check the times now the minutes
	while(tout.iMinutes>60)
	{
		tout.iMinutes -= 60;
		iCheck++;
	}

	while(iCheck != 0)
	{
		tout.iHours += 1;
		iCheck--;
	}

}


