#include <iostream>
#include <fstream>

using namespace std;
const int MAXNUMPUZZLES=2000;
const int GRIDSIZE=9;
const int BLOCKSIZE=3;

enum  RowColBlock {Row, Col, Block};

bool checkVals(const int a[]);
void printInvalidIds(bool valid[], int size);
void readNextPuzzle(fstream& infile, int grid[][GRIDSIZE]);
bool checkSudoku(int grid[][GRIDSIZE]);
void getVals(const int grid[][GRIDSIZE], int vals[], RowColBlock type, int which);

int main()
{
  int grid[GRIDSIZE][GRIDSIZE];
  bool valid[MAXNUMPUZZLES];

  fstream infile;

  // 1. Open the file "puzzles.txt"

  infile.open("puzzles.txt", ios::in);
  if (infile.fail())
    {
      cout << "Could not open puzzles.txt" << endl;
      return -1;
    }

  
  for (int i=0;i<MAXNUMPUZZLES;i++)
    valid[i] = true;

  int numOfPuzzles = 0;
  while (!infile.eof() && numOfPuzzles<MAXNUMPUZZLES)
    {
      // 2. Read the next puzzle into the 9x9 array grid
      readNextPuzzle(infile, grid);

      // 3. Check if the puzzle is valid - if it is not, set
      //    valid[i] to false
      if (!checkSudoku(grid))
	valid[numOfPuzzles]=false;

      numOfPuzzles++;
    }

  // 4. Finally, write out the ids of the invalid puzzles
  cout << "The incorrect puzzles are ";
  printInvalidIds(valid, numOfPuzzles);
  cout << endl;
}

// checkVals takes in an array of 9 integers and
// checks if they are a permutation of the integers 1,..,9
// it returns true if they are a permutation and false otherwise
bool checkVals(const int a[])
{
  bool seen[BLOCKSIZE*BLOCKSIZE];
  int maxFigure =  BLOCKSIZE*BLOCKSIZE;

  for (int i=0;i<GRIDSIZE;i++)
    seen[i] = false;

  for (int i=0;i<GRIDSIZE;i++)
    {
      if (a[i]>maxFigure || a[i]<1)
	return false;
      if (seen[a[i]-1])
	return false;
      else
	seen[a[i]-1] = true;
    }
  return true;
}

// getVals gets the 9 values corresponding to the part of the grid
// to be checked and puts them in the output array vals
// The part of the array to be checked is determined by the input
// parameters "type" and "which"
// type refers to whether we want a row, column or block
// which refers to which row, column or block is required - there are 9 rows, 
// 9 columns and 9 blocks. 

// For instance, if we require the type=Row and which=1, then the returned vals
// should correspond to grid[1][0], grid[1][1], ..., grid[1][8]

// If we require the type=Block and which=5, then the return vals should correspond
// to grid[3][3], grid[3][4], grid[3][5], 
//    grid[4][3], grid[4][4], grid[4][5],
//    grid[5][3], grid[5][4], grid[5][5]
// So Blocks are number from 0 (top left block) to 8 (bottom right block)

void getVals(const int grid[][GRIDSIZE], int vals[], RowColBlock type, int which)
{
  switch(type)
    {
    case Row:
      for (int i=0;i<GRIDSIZE;i++)
	vals[i] = grid[which][i];
      break;
    case Col:
      for (int i=0;i<GRIDSIZE;i++)
	vals[i] = grid[i][which];
      break;

    case Block:
      int row = 3*(which/3);
      int col = 3*(which%3);
      for (int i=0;i<3;i++)
	for (int j=0;j<3;j++)
	  vals[3*i+j] = grid[row+i][col+j];
    }
}
      
// checkSudoku will check if the grid corresponds to a valid sudoku game
// To be valid, each row, each column and each block of the grid should
// contain the numbers 1,...,9, in any order i.e. be any 
// permutation of the numbers 1,...,9
 
bool checkSudoku(int grid[][GRIDSIZE])
{
  int vals[GRIDSIZE];

  for (int i=0;i<GRIDSIZE;i++)
    {
      getVals(grid, vals, Row, i);
      if (!checkVals(vals))
	return false;
    }
  for (int i=0;i<GRIDSIZE;i++)
    {
      getVals(grid, vals, Col, i);
      if (!checkVals(vals))
	return false;
    }

  for (int i=0;i<GRIDSIZE;i++)
    {
      getVals(grid, vals, Block, i);
      if (!checkVals(vals))
	return false;
    }
  return true;
}

// readNextPuzzle

void readNextPuzzle(fstream& str, int grid[][GRIDSIZE])
{
  char ch;
  for (int i=0;i<GRIDSIZE;i++)
    for (int j=0;j<GRIDSIZE;j++)
      {
	str >> ch;
	grid[i][j]=ch-'0';
      }
  // read to end new line or eof
  str >> ch;
  if (!str.eof())
    str.unget();
}

// printInvalidIds takes the boolean array valid containing size boolean values
// and prints out the positions at which it contains the value 'false'
// e.g. if positions 10, 15, 34, 20 are all false, then it prints out "[10,15,34,20]"

void printInvalidIds(bool valid[], int size)
{
  cout << "[";
  bool first = true;

  for (int i=0;i<size;i++)
    if (!valid[i])
      if (first)
	{
	  cout << i+1;
	  first = false;
	}
      else
	cout << "," << i+1;
  cout << "]";
}
	
  
  
  
