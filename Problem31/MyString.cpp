#include "MyString.h"
MyString::MyString()
{ 
  strcpy(str, "");
}

MyString::MyString(const char s[])
{
  strcpy(str, s);
}

MyString::MyString(const string& s)
{
  int i;
  for (i=0;i<s.length();i++)
    str[i] = s[i];
  str[i]='\0';
}

int MyString::compare(const MyString& s)
{
  int c = strcmp(str, s.str);
  
  if (c>0)
    return 1;
  else if (c<0)
    return -1;
  return 0;
}

int MyString::comparen(const MyString& s, int n)
{
  int c = strncmp(str, s.str, n);
  if (c>0)
    return 1;
  else if (c<0)
    return -1;
  return 0;
}

MyString& MyString::concat(const MyString& s)
{
  strcat(str, s.str);
  return *this;
}

int MyString::findfirst(char k)
{
  int i;
  for (i=0;str[i]!=k && str[i]!='\0'; i++);

  if (str[i]==k)
    return i;
  return -1;
}

int MyString::findlast(char k)
{
  int i;
  for (i=strlen(str);str[i]!=k && i>=0; i--);

  if (str[i]==k)
    return i;
  return -1;
}

int MyString::substring(const MyString& s)
{
  char *p = strstr(str, s.str);
  if (p)
    return (p - str);
  return -1;
}

void MyString::setString(const MyString &s)
{
  strcpy(str, s.str);
}

void MyString::print() const
{
  cout << str;
}

