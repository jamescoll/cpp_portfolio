#include "NumberSet.h"
#include <iostream> 
using namespace std;

NumberSet::NumberSet()  
{
  count=0;
}

Number NumberSet::sum() const
{
  int i;
  Number sum=0;
  for (i=0;i<count;i++)
    sum+=items[i];
  return sum;
}

int NumberSet::size() const
{
  return count;
}

Number NumberSet::nthLargest(int n) const
{
  return items[count-n];
}


void NumberSet::add(Number n)
{
  int i,j;
  if (count==MAXCOUNT)
    {
      cout << "The set is already full.\n";
      return;
    }
  // find the position to place n in, so that
  // items remains sorted in increasing order
  for (i=0;i<count;i++)
    if (items[i]>n)
      break;
  // push all values of item that are greater
  // than n forward one position
  for (j=count;j>i;j--)
    items[j]=items[j-1];

  // insert n at position i
  items[i]=n;
  count++;
}

void NumberSet::print() const
{
  for (int i=0;i<count;i++)
    cout << items[i] << " ";
  cout << endl;
}

void NumberSet::remove(Number n)
{
  int i,j;

// Find the position in the items array at which n is stored
  for (i=0;i<count;i++)
    if (items[i]==n)
       break;  
// Move all items in positions greater than i back one, so
// that the gap created by removing n is filled
  for (j=i;j<count-1;j++)
    items[j] = items[j+1];
// Decrement count
  count--;
} 
