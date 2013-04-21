#include "NumberSet.h"
#include <iostream> 
using namespace std;

NumberSet::NumberSet()  
{
  count=0;
}

Number NumberSet::getMax() const
{
  return max;
}

Number NumberSet::getMin() const
{
  return min;
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

void NumberSet::add(Number n)
{
  if (count==MAXCOUNT)
    {
      cout << "The set is already full.\n";
      return;
    }
  if (n>max || count ==0)
    max = n;
  if (n<min || count ==0)
    min = n;
  items[count++]=n;
}

Number NumberSet::get(int index) const
{
	return items[index];	
}


void NumberSet::remove(Number n)
{
  int i;  

// Find the position in the items array at which n is stored
  for (i=0;i<count;i++)
    if (items[i]==n)
       break;  
// Now replace n with the last number in the set  
   items[i]=items[count-1];
  
// Decrement count
  count--;

// Update max and min if necessary
  if ((max==n || min==n) && (count>0))
    {
      min = max = items[0];
      for (i=1;i<count;i++)
	{
	  if (min>items[i])
	    min=items[i];
	  if (max<items[i])
	    max=items[i];
	}
    }
} 
