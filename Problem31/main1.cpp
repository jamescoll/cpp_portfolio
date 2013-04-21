#include <iostream>
#include "MyString.h"

using namespace std;

int main()
{
  string cplusstr="hello";
  MyString str1(cplusstr);
  str1.print();
  cout << endl;

  MyString str2(" there");
  str1.concat(str2);
  str1.print();
  cout << endl;

  str1.concat(" how").concat(" are").concat(" you?");
  str1.print();
  cout << endl;

  cout << "Position of first e in the string : " << str1.findfirst('e') << endl;
  cout << "Position of last e in the string : " << str1.findlast('e') << endl;

  cout << "Comparing str1 and str2 : " << str1.compare(str2) << endl;
  cout << "Comparing str2 and str1 : " << str2.compare(str1) << endl;
  cout << "Comparing str1 with hello : " << str1.compare("hello") << endl;
  cout << "Comparing first 5 characters of str1 with hello : " << str1.comparen("hello", 5) << endl;
  cout << "Comparing str1 with substring str2 : " << str1.substring(str2) << endl;
  cout << "Comparing str1 with substring helo : " << str1.substring("helo") << endl;
}
