#include <stdio.h>


bool DFS(char** board, int x, int y, char *w, int wP) {
 int len = strlen(w);
 if (wP >= len) return true;

 // define direction
 int dx[] = {0, 1,  0, -1}
 int dy[] = {1, 0, -1,  0};

 char tmp;
 bool ret = flase;

 for (int d = 0; d < 4; d++) {
  // checking the wall
  if () {
  }

  // checking character
  if (w[wP] == board[x][y]) {
   tmp = board[x][y];
   board[x][y] = '-';
   ret = true && DFS (board, x+dx[d], y+dy[d], w, wP+1);
   board[x][y] = tmp;
  }
 }

 return ret;

}
// stack problem 
// similar mouse maze 
bool exist(char** board, int boardSize, int* boardColSize, char* word) {
 int len = strlen(word);
 int wP = 0; // word pointer
 int top = -1;
 bool ret = false;

 for (int i = 0; i < boardSize; i++) {
  for (int j = 0; j < boardColSize; j++) {
   if (board[i][j] == *word) {
    // Depth First Search
    ret = DFS (board, i, j, word, wP+1);

    if (ret) return ret; // Exist
   }
  }
 }
    
 return ret;
}

int main (void) {

 return 0;
}
