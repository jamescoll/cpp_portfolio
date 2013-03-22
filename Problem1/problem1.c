//============================================================================
// Name        : Problem1.c
// Author      : James Coll
// Version     : Version 1
// Copyright   : Munnki 2013
// Description : A series of mathematical problems involving modulo, a bubble sort and other operators
//============================================================================

#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "string.h"

//a define for the large number multiplication
#define MAX_NUM 10000
#define RAND_MAXIMUM 100

int iSum(int iN);
int iSumEvenSquares(int iN);
unsigned long long ullProductFiveOrEleven(int iArray[], int iN);
void vBubbleSort (int iArray[], int iArraySize);
char * cpProductFiveOrEleven(int iArray[], int iN);
int iFindNthLargest(int iArray[], int iN, int in);

int main()
{
	int in, iN;//our two integer values
	int iResult; //for our integer results
	

	in = 0;//initialise our variables
	iN = 0;
	iResult = 0;


	printf("Enter the first integer N: ");
	scanf("%9d", &iN);
	
	while(in == 0)
	{
		//because we have an nth largest value then zero makes no sense for an in value
		printf("Enter the second integer n (non-zero): ");
		scanf("%9d", &in);
	}

	while(in>iN)
	{
		printf("The first integer needs to be larger\n.");
		printf("Enter the first integer N: ");
		scanf("%9d", &iN);
		printf("Enter the second integer n: ");
		scanf("%9d", &in);
	}

	iResult = iSum(iN);

	if(iResult == 0)
	{
		printf("Error 1 - Problem in Function 1\n");
	}
	else
	{
		printf("The sum of the first %d integers is %d\n", iN, iResult);
		iResult = 0;//reset iResult so that error checking can proceed for the next function
	}

	iResult=iSumEvenSquares(iN);

	if(iResult == 0)
	{
		printf("Error 2 - Problem in Function 1\n");
	}
	else
	{
		printf("The sum of the squares of the even integers less than %d is %d\n", iN, iResult);
		iResult = 0; //reset iResult so that error checking can proceed for the next function
	}

	int iArray[iN];
	int iIndex;

	srand(time(NULL));

	for(iIndex = 0; iIndex<iN; iIndex++)
	{
		
		//populate our array with random integers
		iArray[iIndex] = rand()%RAND_MAXIMUM;
	}

	unsigned long long ullResult;
	
	ullResult = 0ULL;
	
	ullResult = ullProductFiveOrEleven(iArray, iN);

	printf("The product of mod five and mod eleven array elements is %llu\n", ullResult);
	

	iResult = iFindNthLargest(iArray, iN, in);

	if(iResult == 0)
	{
		printf("Error 4 - Problem in Function 4\n");
	}
	else
	{
		printf("The largest element in the array is %d\n", iResult);
		iResult = 0;
	}




}

int iSum(int iN)
{
	//Multiply N by (N+1) and divide by 2
	return ((iN*(iN+1))/2);
}

int iSumEvenSquares(int iN)
{
	//4*(n+1)*(2n+1)/6
	return (4*((iN+1)*((2*iN)+1)/6));
}

unsigned long long ullProductFiveOrEleven(int iArray[], int iN)
{
	int iIndex;
	unsigned long long ullProduct;
	int iCounter;

	//do not initialise to 0 or else all values will equal to zero
	ullProduct = 1ULL;
	iCounter = 0;
	
	for(iIndex = 0; iIndex<iN; iIndex++)
	{
		if(iArray[iIndex]!=0)
		{
			if((iArray[iIndex]%5==0)||(iArray[iIndex]%11==0))
			{
				
				ullProduct=ullProduct*iArray[iIndex];
				

			}
		}
	}
	
	return ullProduct;

}



//do a bubblesort then go to the fourth element in the array
int iFindNthLargest(int iArray[], int iN, int in)
{
	int iLargest;
	int iTmp;

	iLargest = 0;

	vBubbleSort(iArray, iN);
	
	//fourth from top rather than from the bottom
	iTmp = iN - in;
	
	iLargest = iArray[iTmp];	

	return iLargest;
}

void vBubbleSort (int iArray[], int iArraySize)
{
	int iElement1, iElement2, iTemp;
	
	for (iElement1 = (iArraySize - 1); iElement1 > 0; iElement1--)
	{
		for (iElement2 = 1; iElement2 <= iElement1; iElement2++)
		{
			if (iArray[iElement2-1]>iArray[iElement2])
			{
				iTemp = iArray[iElement2- 1];
				iArray[iElement2- 1] = iArray[iElement2];
				iArray[iElement2] = iTemp;
			}	
		}
	}
	
	return;
}




