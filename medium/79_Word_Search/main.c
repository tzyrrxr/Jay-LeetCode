#include <stdio.h>


bool DFS(char** board, int bW, int bH, int x, int y, char *w, int wP) {
 int len = strlen(w);
 if (wP >= len) return true;

 // define direction
 int dx[] = {0, 1,  0, -1};
 int dy[] = {1, 0, -1,  0};

 char tmp;
 bool ret = false;

 for (int d = 0; d < 4; d++) {
  // checking the wall
  if (x + dx[d] >= bW || x + dx[d]  < 0 ||
      y + dy[d] >= bH || y + dy[d] < 0 
    ) continue;

  // checking character
  if (w[wP] == board[y + dy[d]][x + dx[d]]) {
   tmp = board[y + dy[d]][x + dx[d]];
   board[y + dy[d]][x + dx[d]] = '-';
   ret = true && DFS (board, bW, bH, x+dx[d], y+dy[d], w, wP+1);
   board[y + dy[d]][x + dx[d]] = tmp;
   if (ret) return ret;
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
 char tmp;

 for (int y = 0; y < boardSize; y++) {
  for (int x = 0; x < *boardColSize; x++) {
   if (board[y][x] == *word) {
    // Depth First Search
    tmp = board[y][x];
    board[y][x] = '-';
    ret = DFS (board, *boardColSize, boardSize, x, y, word, wP+1);
    board[y][x] = tmp;

    if (ret) return ret; // Exist
   }
  }
 }
    
 return ret;
}

int main (void) {

 return 0;
}
