//============================================================================
// Name        : Problem20.cpp
// Author      : James Coll
// Version     : Version 1
// Copyright   : Munnki 2013
// Description : two implementations of quick select 
//============================================================================


#include <iostream>
#include <cstdlib> // get the rand() function
#include <algorithm>

using namespace std;

const int ciArraySize = 1000;

int iQuickSelect(int iaArray[], int iArraySize, int iK); // prototype definition of quick select
int iQuickSelectEfficient(int iaArray[], int iArraySize, int iK);
int iQuickSelectHelperEfficient(int a[], int size, int k, int left[], int right[], int temp[]);

int main()
{
  int iArray[ciArraySize];
  int iK;
  int iKLargestValue;
  srand(time(NULL));

  for (int i=0;i<ciArraySize;i++)
    iArray[i] = rand()%1000;

  cout<<"Enter the kLargest value we want to find (1 for largest)";
  cin>>iK;
  

  

  iKLargestValue = iQuickSelect(iArray, ciArraySize, iK);
  cout << "Kth largest value is " << iKLargestValue<< endl;

  std::sort(&iArray[0], &iArray[ciArraySize]);
  cout << "Using the sort function, we can check kth largest value is " << iArray[ciArraySize-iK] << endl;
}
  

int iQuickSelect(int iaArray[], int iArraySize, int iK)
{
  // Select a random "pivot"

  // Compare each value in the array to the value at the
  // pivot, and decide whether that value is less than or
  // greater than the pivot value

  // Values that are less than the pivot value are placed in
  // the 'left' array
  // Value that are greater than the piot value are placed in
  // the 'right' array
  // Then recursively apply iQuickSelect on either the right-
  // or left-hand array, depending on the size of these arrays

  int iPivot;
  int iValueAtPivot;

  int iaLeft[ciArraySize], iaRight[ciArraySize]; 
  // declare the arrays left[] and right[] that are used to 
  // hold values that are compared to the pivot.

  // Note: you might be tempted to declare these arrays
  // int left[size], right[size];
  // This might work depending on the compiler, but is INCORRECT.
  // Static arrays cannot be given a variable size.

  // However, there IS a memory issue associated with declaring 
  // the arrays in this manner -- namely that EACH call of the 
  // recursive function will allocate these arrays, using a LOT 
  // more memory than actually needed (there could be 
  // about log(N) calls to the function active at some point in the
  // program, meaning that log(N)xNx2 integer values are being stored 
  // in memory.
  // There are several ways to avoid this memory overhead. One is to
  // use pointers - students shouldn't need to do this, as we have not
  // covered pointers yet on the course.
  // Another is to use dynamic array allocation - again this should be
  // avoided, as we haven't covered it yet.
  // I give a different solution in QuickSelect2.cpp


  iPivot = rand()%iArraySize;
  iValueAtPivot = iaArray[iPivot];
  int iKLargestValue;
 
  // now compare all values of a with valueatpivot
  int iNumLeft=0, iNumRight=0;
  for (int i=0;i<iArraySize;i++)
    {
      if (iaArray[i]<=iValueAtPivot)
	iaLeft[iNumLeft++] = iaArray[i];
      else
	if (iaArray[i]>iValueAtPivot)
	  iaRight[iNumRight++]=iaArray[i];
    }

  if (iNumRight>=iK)
    {
      // the kth largest value must be in the right[]
      iKLargestValue = iQuickSelect(iaRight, iNumRight, iK);
    }
  else
    if ((iK-iNumRight)>1)
      {
	// the kth largest value must be in the left[]
	iKLargestValue = iQuickSelect(iaLeft, iNumLeft, iK-iNumRight);
      } 
  else
    iKLargestValue = iValueAtPivot;

  return iKLargestValue;
}

    
int iQuickSelectEfficient(int iaArray[], int iArraySize, int iK)
{
  int iaLeft[ciArraySize], iaRight[ciArraySize], iaTemp[ciArraySize];

  return iQuickSelectHelperEfficient(iaArray, iArraySize, iK, iaLeft, iaRight, iaTemp);
}
  
int iQuickSelectHelperEfficient(int iaArray[], int iArraySize, int iK, int iaLeft[], int iaRight[], int iaTemp[])
{
  int iPivot;
  int iValueAtPivot;

  iPivot = rand()%iArraySize;
  iValueAtPivot = iaArray[iPivot];
  int iKLargestValue;
 
  // now compare all values of a with valueatpivot
  int iNumLeft=0, iNumRight=0;
  for (int i=0;i<iArraySize;i++)
    {
      if (iaArray[i]<=iValueAtPivot)
	iaLeft[iNumLeft++] = iaArray[i];
      else
	if (iaArray[i]>iValueAtPivot)
	  iaRight[iNumRight++]=iaArray[i];
    }

  if (iNumRight>=iK)
    {
      // the kth largest value must be in the right[]
      iKLargestValue = iQuickSelectHelperEfficient(iaRight, iNumRight, iK, iaLeft, iaTemp, iaRight);
    }
  else
    if ((iK-iNumRight)>1)
      {
	// the kth largest value must be in the left[]
	iKLargestValue = iQuickSelectHelperEfficient(iaLeft, iNumLeft, iK-iNumRight, iaRight, iaTemp, iaLeft);
      } 
  else
    iKLargestValue = iValueAtPivot;

  return iKLargestValue;
}

    
