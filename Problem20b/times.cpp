//============================================================================
// Name        : Problem20b
// Author      : James Coll
// Version     :
// Copyright   : Munnki
// Description : Simple program that defines a typedef time and allows for addition and subtraction (assumed to mean difference)
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

MyTime mytimeAdd_Time(MyTime t1, MyTime t2);
MyTime mytimeSubtract_Time(MyTime t1, MyTime t2);


int main() {
	MyTime t1, t2;
	MyTime tsum, tsub;
	t1.iSeconds = 34;
	t1.iMinutes = 56;
	t1.iHours = 12;
	t2.iSeconds = 24;
	t2.iMinutes = 37;
	t2.iHours = 7;

	tsum = mytimeAdd_Time(t1, t2);
	tsub = mytimeSubtract_Time(t1, t2);

	cout<<"Time 1 "<<t1.iHours<<" Hrs "<<t1.iMinutes<<" Mns "<<t1.iSeconds<<" snds"<<endl;
	cout<<"Time 2 "<<t2.iHours<<" Hrs "<<t2.iMinutes<<" Mns "<<t2.iSeconds<<" snds"<<endl;
	cout<<"Sum "<<tsum.iHours<<" Hrs "<<tsum.iMinutes<<" Mns "<<tsum.iSeconds<<" snds"<<endl;
	cout<<"Diff "<<tsub.iHours<<" Hrs "<<tsub.iMinutes<<" Mns "<<tsub.iSeconds<<" snds"<<endl;
}

MyTime mytimeAdd_Time(MyTime t1, MyTime t2)
{
	MyTime tsum;
	int iCheck = 0;
	//first we'll add the times together
	tsum.iSeconds = t1.iSeconds + t2.iSeconds;
	tsum.iMinutes = t1.iMinutes + t2.iMinutes;
	tsum.iHours = t1.iHours + t2.iHours;

	//check the times starting with the seconds
	while(tsum.iSeconds>60)
	{
		tsum.iSeconds -= 60;
		iCheck++;
	}

	while(iCheck != 0)
	{
		tsum.iMinutes += 1;
		iCheck--;
	}

	//check the times now the minutes
	while(tsum.iMinutes>60)
	{
		tsum.iMinutes -= 60;
		iCheck++;
	}

	while(iCheck != 0)
	{
		tsum.iHours += 1;
		iCheck--;
	}
	//job done
	return tsum;
}

//this function will always return a positive value
//as a negative time is somewhat meaningless as such
//it will use absolute values
MyTime mytimeSubtract_Time(MyTime t1, MyTime t2)
{

	MyTime tsub;
	int iCheck = 0;
	//first we'll add the times together
	tsub.iSeconds = abs(t1.iSeconds - t2.iSeconds);
	tsub.iMinutes = abs(t1.iMinutes - t2.iMinutes);
	tsub.iHours = abs(t1.iHours - t2.iHours);

	//check the times starting with the seconds
	while(tsub.iSeconds>60)
	{
		tsub.iSeconds -= 60;
		iCheck++;
	}

	while(iCheck != 0)
	{
		tsub.iMinutes += 1;
		iCheck--;
	}

	//check the times now the minutes
	while(tsub.iMinutes>60)
	{
		tsub.iMinutes -= 60;
		iCheck++;
	}

	while(iCheck != 0)
	{
		tsub.iHours += 1;
		iCheck--;
	}
	//job done

	return tsub;
}


