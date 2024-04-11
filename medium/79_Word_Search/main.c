#include <stdio.h>

struct position {
 int x;
 int y;
} ;

struct position * CreateNode () {
 struct position *tmp = (struct position*) malloc(sizeof (struct position));
 return tmp;
}

// stack problem is like as mouse maze
bool exist(char** board, int boardSize, int* boardColSize, char* word) {
 int len = strlen(word);
 int top = -1;
 struct position *posStack = (struct position*) malloc(len * sizeof (struct position));

 for (int i = 0; i < boardSize; i++) {
  for (int j = 0; j < boardColSize; j++) {
   if (*word == board[i][j]) {
    // mark first character
    posStack[++top] = CreateNode ();
    posStack[++top]->x = i;
    posStack[++top]->y = j;

    // right
    // down
    // left
    // top
    
   }
  }
 }
    
}

int main (void) {

 return 0;
}
