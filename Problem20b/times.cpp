//============================================================================
// Name : Problem20b
// Author : James Coll
// Version :
// Copyright : Munnki
// Description : Simple program that defines a typedef time and allows for addition and subtraction (assumed to mean difference)
//============================================================================

#include <iostream>
using namespace std;

typedef struct
{
    int iSeconds;
    int iMinutes;
    int iHours;
} MyTime;



void convertSeconds(int iTotalSecs, MyTime& t1);

void addTimes(const MyTime& t1, const MyTime& t2, MyTime& sum);

int iTotalSeconds(const MyTime& t1);


void convertSecs(int iTotalSecs, MyTime& t1)
{
    iTotalSecs = abs(iTotalSecs);
    int iRemainingSeconds;
    t1.iHours = iTotalSecs/(60*60);
    iRemainingSeconds = iTotalSecs%(60*60);
    
    t1.iMinutes = iRemainingSeconds/60;
    iRemainingSeconds = iRemainingSeconds%60;
    
    t1.iSeconds = iRemainingSeconds;
}

int iTotalSeconds(const MyTime& t1)
{
    return t1.iHours*60*60+t1.iMinutes*60+t1.iSeconds;
}

void subtractTimes(const MyTime& t1, const MyTime& t2, MyTime& sum)
{
    int iTotal1=iTotalSeconds(t1);
    int iTotal2=iTotalSeconds(t2);
    convertSecs(iTotal1-iTotal2, sum);
}


void addTimes(const MyTime& t1, const MyTime& t2, MyTime& sum)
{
    int iTotal1=iTotalSeconds(t1);
    int iTotal2=iTotalSeconds(t2);
    convertSecs(iTotal1+iTotal2, sum);
}

int main()
{
    MyTime t1,t2,t3, t4;
    
    t1.iHours=12; t1.iMinutes=0;t1.iSeconds=0;
    t2.iHours=0; t2.iMinutes=5;t2.iSeconds=0;
    
    addTimes(t1,t2, t3);
    cout<<"Addition\n";
    cout << t3.iHours << "h:" << t3.iMinutes << "m:"
    << t3.iSeconds << "s" << endl;
    
    subtractTimes(t1,t2,t4);
    cout<<"Subtraction\n";
    cout << t4.iHours << "h:" << t4.iMinutes << "m:"
    << t4.iSeconds << "s" << endl;
}




