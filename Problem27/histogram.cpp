// A. Insert the correct include statements required for the
//    program.
#include <iostream>
#include <fstream>
//UNFINISHED
using namespace std;

// B. Complete the prototype definitions of the three functions
//    That must be implemented to make this program work
void getMaxAndMin(double A, int size, double mx, double mn)
{
	return;
}
int findBin(double A[], double ticks, int numBins)
{
	return 0;
}
void printStars(int bin_count, int numBins)
{
	return;
}

int main()
{

  double *A;
  int size;
  int numBins;
  fstream str;

  cout << "Please enter the number of bins in the histogram:" << endl;
  cin >> numBins;

  // 1. Open the file called input.dat and read all the 
  //    double precision floating point values in the
  //    file into the array A.  (Note: you should allocate
  //    exactly the right amount of space needed for A
  //    using a call to the new operator and use the
  //    fstream variable str declared above). 
  //    COMPLETE THE CODE TO CARRY OUT THESE STEPS
  str.open("input.dat");

  while(!str.eof())
  {
	str.getline(str, A);
	A++;
  }

  // 2. The function getMaxAndMin is called to return
  //    the maximum and minimum values in A in the
  //    variables mx and mn. IMPLEMENT THE FUNCTION
  //    getMaxAndMin

  double mx,mn; 
  getMaxAndMin(A, size, mx, mn);

  // 3. The interval between max and min is
  //    divided into numBins bins.  The 
  //    start of the ith bin is stored in ticks[i]
  //    and the end of the ith bin is stored in ticks[i+1]
  //    (NOTHING TO BE DONE HERE)

  int binmin=static_cast<int>(mn);
  int binmax=static_cast<int>(mx+0.5);

  double *ticks = new double[numBins+1];
  int *bin_count = new int[numBins];
  double diff = static_cast<double>(binmax-binmin)/numBins;

  ticks[0]=binmin;
  for (int i=1;i<=numBins;i++)
    ticks[i]=ticks[i-1]+diff;

  // 4. The number of times  a value of A lies in each bin is
  //    counted and stored in bin_count.
  //    The function findBin takes the next value and determines
  //    which bin it lies in. IMPLEMENT THE findBin FUNCTION

  for (int i=0;i<numBins;i++)
    bin_count[i]=0;

  for (int i=0;i<size;i++)
    {
      int b = findBin(A[i], ticks,numBins);
      bin_count[b]++;
    }

  // 5. The histogram is printed. Each bin is represented
  //    as a line of stars (*'s). The number of stars in 
  //    each line is equal to the number of values in 
  //    the corresponding bin. IMPLEMENT THE printStars FUNCTION
  printStars(bin_count, numBins);

}


	

	  
