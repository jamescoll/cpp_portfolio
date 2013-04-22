#include <iostream>
#include <fstream>
using namespace std;

const int MAXNUMFACTORS=100;

void findFactors(int number, int factors[], int& numFactors);
int productOfFactors(int factors[], int numFactors);
void printFactors(int factors[], int numFactors);

int main()
{
  int n;
  int factors[MAXNUMFACTORS];
  int numFactors;
  fstream str;
  int prod;


  str.open("numbers.dat", ios::in);

  str >> n;
  while (!str.eof())
    {
      numFactors=0;
      findFactors(n, factors, numFactors);
      cout << "The factors of " << n << " are: ";
      printFactors(factors, numFactors);
      cout << endl;
      prod = productOfFactors(factors, numFactors);
      
      if (prod == n)
	cout << "The product of the prime factors is " << prod << endl;
      else
	cout << "Error:: the product of the prime factors, " << prod << 
	  " is not equal to " << n << endl;
      str>>n;
    }
}

void findFactors(int number, int factors[], int& numFactors)
{
  for (int i=2;i<=number;i++)
    {
      if (number % i ==0)
	{
	  factors[numFactors]=i;
	  numFactors++;
	  findFactors(number/i, factors, numFactors);
	  break;
	}
    }
}

int productOfFactors(int factors[], int numFactors)
{
  int prod = 1;
  for (int i=0;i<numFactors;i++)
    prod*=factors[i];

  return prod;
}

void printFactors(int factors[], int numFactors)
{
  
  cout << "[";
  for (int i=0;i<numFactors;i++)
    {
      cout << factors[i];
      if (i<numFactors-1)
	cout << ",";
    }
  cout << "]";
}







  
  
