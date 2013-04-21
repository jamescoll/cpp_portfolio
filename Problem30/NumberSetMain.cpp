#include <iostream> 
using namespace std;
#include "NumberSet.h"

int main () 
 { 
   NumberSet set1;
   Number x;
   int count = 10; 
   int i; 
   for (i=0;i<count;i++) { 
     cin >> x;
     set1.add(x);  
   } 
   set1.print();
   cout << "Fifth largest value in set1 is " << set1.nthLargest(5) << endl;
   set1.remove(set1.nthLargest(5));
   set1.print();
   cout << "Now, fifth largest value in set1 is " << set1.nthLargest(5) << endl;

}
