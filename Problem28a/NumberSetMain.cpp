#include <iostream> 
using namespace std;
#include "NumberSet.h"

int main () 
 { 
  
    NumberSet set1, set2; 
 
    Number x, sum1, sum2; 
    cout<<"Enter 10 variables - the first ten for set1 and the second for set2"<<endl;
    int count = 5; 
    int i; 
    for (i=0;i<count;i++) { 
      cin >> x;
      set1.add(x);  
    } 
    for (i=0;i<count;i++) { 
      cin >> x; 
      set2.add(x);
    } 
    cout << "Elements of Set 1 are: ";
    for (i=0;i<count;i++)
    {
 	cout<<set1.get(i)<<" ";
    }
    cout << endl;

    cout << "Elements of Set 2 are: ";
    for (i=0;i<count;i++)
    {
 	cout<<set2.get(i)<<" ";
    }
    cout << endl;
    cout << "Maximum of set1 is " << set1.getMax() << endl;
    cout << "Maximum of set2 is " << set2.getMax() << endl;
    cout << "Minimum of set1 is " << set1.getMin() << endl;
    cout << "Minimum of set2 is " << set2.getMin() << endl;
    set1.remove(set1.getMax());
    set2.remove(set2.getMax());
    set1.remove(set1.getMin());
    set2.remove(set2.getMin());
    count = 3;
    cout << "Elements of Set 1 are: ";
    for (i=0;i<count;i++)
    {
 	cout<<set1.get(i)<<" ";
    }
    cout << endl;

    cout << "Elements of Set 2 are: ";
    for (i=0;i<count;i++)
    {
 	cout<<set2.get(i)<<" ";
    }
    cout << endl;
    cout << "Now - Maximum of set1 is " << set1.getMax() << endl;
    cout << "Now - Maximum of set2 is " << set2.getMax() << endl;
    cout << "Now - Minimum of set1 is " << set1.getMin() << endl;
    cout << "Now - Minimum of set2 is " << set2.getMin() << endl;
    

}
