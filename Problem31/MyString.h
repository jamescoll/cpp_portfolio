#include <iostream>
#include <cstring>
#include <string>
using namespace std;

const int STRLENGTH=100;
class MyString
{
public:
  MyString();
  MyString(const string& s);
  MyString(const char s[]);
  MyString& concat(const MyString& s);
  int compare(const MyString& s);
  int comparen(const MyString& s, int n);
  int substring(const MyString& s);
  int findfirst(char k);
  int findlast(char k);
  void setString(const MyString& s);
  void print() const;

private:
  char str[STRLENGTH];
};

