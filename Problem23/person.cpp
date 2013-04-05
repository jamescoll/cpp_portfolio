//============================================================================
// Name        : Problem23
// Author      : James Coll
// Version     :
// Copyright   : Munnki
// Description : A  version of the previous program which updates and copies structs containing basic personal
// 			information and using pass by reference and the const keyword (and which allows for nested calls)
//============================================================================

#include <iostream>
#include <cstdlib>
#include <string.h>
using namespace std;

const int MAXLEN=100;

typedef struct
{
	char fname[MAXLEN];
	char sname[MAXLEN];
	int age;
	double height;
	double weight;
} person;


void fillperson(person& per, char caFName[], char caSName[], int iAge, double dHeight, double dWeight);
void printperson(const person& per);
void makecopy(const person& perin, person& perout);
person& setHeight(person& p, double height);
person& setWeight(person& p, double weight);

int main()
{
	person fred, fredcpy;
	fillperson(fred, "fred", "murphy", 22, 180.0, 83.2);
	fred = setWeight(setHeight(fred, 170.0), 170.0);
	makecopy(fred, fredcpy);
	printperson(fredcpy);
}

void fillperson(person& per, char caFName[], char caSName[], int iAge, double dHeight, double dWeight)
{
	strncpy(per.fname, caFName, MAXLEN);
	strncpy(per.sname, caSName, MAXLEN);
	per.age = iAge;
	per.height = dHeight;
	per.weight = dWeight;
}

void makecopy(const person& perin, person& perout)
{
	strncpy(perout.fname, perin.fname, MAXLEN);
	strncpy(perout.sname, perin.sname, MAXLEN);
	perout.age = perin.age;
	perout.height = perin.height;
	perout.weight = perin.weight;
}

void printperson(const person& per)
{
	cout<<"First name:"<<per.fname<<endl;
	cout<<"Second name:"<<per.sname<<endl;
	cout<<"Age:"<<per.age<<endl;
	cout<<"Height:"<<per.height<<endl;
	cout<<"Weight:"<<per.weight<<endl;
}

person& setHeight(person& p, double h)
{
	p.height = h;
	return p;
}

person& setWeight(person& p, double w)
{
	p.weight = w;
	return p;
}

