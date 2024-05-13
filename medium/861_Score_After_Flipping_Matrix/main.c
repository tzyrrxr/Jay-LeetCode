#include <stdio.h>

// greedy algorithm
int matrixScore(int** grid, int gridSize, int* gridColSize) {
 int row = gridSize;
 int col = *gridColSize;
 int zeroCnt = 0;
 int tmp = 0;
 int sum = 0;

 // flip row
 for (int m = 0; m < row; m++) {
  if (!grid[m][0]) {
   for (int n = 0; n < col; n++) grid[m][n] = !grid[m][n];
  }
 }

 // flip column
 for (int n = 1; n < col; n++, zeroCnt=0) {

  for (int m = 0; m < row; m++) {
   if (!grid[m][n]) zeroCnt++;
  }

  if (zeroCnt > row - zeroCnt) {
   for (int m = 0; m < row; m++) {
    grid[m][n] = !grid[m][n];
   }
  }
 }


 // sum
 for (int m = 0; m < row; m++, tmp = 0) {
  for (int n = 0; n < col; n++) {
   tmp = tmp * 2 + grid[m][n];
  }
  sum += tmp;
 }

 return sum;
    
}

int main (void) {

 return 0;
}
