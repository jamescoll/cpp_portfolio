#include <iostream>
#include <cstring>
using namespace std;

const int MAXLEN=100;
struct person
{
  char fname[MAXLEN];
  char sname[MAXLEN];
  int age;
  double height;
  double weight;
};

void fillperson(person& p, const char fname[], const char sname[], int age,
		double height, double weight);

void makecopy(const person& p, person& pcpy);

void printperson(const person& p);

person& setHeight(person& p, double h);
person& setWeight(person& p, double w);

int main()
{
  person fred, fredcpy;
  fillperson(fred, "fred", "murphy", 22, 180.0, 83.2);
  setWeight( setHeight(fred, 184.0), 90); // fred got taller and heavier!
  printperson(fred);
}

void fillperson(person& p, const char fname[], const char sname[], int age,
		double height, double weight)
{
  strcpy(p.fname, fname);
  strcpy(p.sname, sname);
  p.age = age;
  p.height = height;
  p.weight = weight;
}

void makecopy(const person& p, person& pcpy)
{
  strcpy(pcpy.fname, p.fname);
  strcpy(pcpy.sname, p.sname);
  pcpy.age = p.age;
  pcpy.height = p.height;
  pcpy.weight = p.weight;
}


void printperson(const person& p)
{
  cout << "First Name: " << p.fname << endl;
  cout << "Surname: " << p.sname << endl;
  cout << "Age: " << p.age << endl;
  cout << "Height: " << p.height << endl;
  cout << "Weight: " << p.weight << endl;;
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
