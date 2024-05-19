#include <stdio.h>

int dir[4][2] = {
 {1, 0}, 
 {0, 1}, 
 {-1, 0}, 
 {0, -1} 
};

bool CheckValid (int x, int y, int rows, int cols) {
 if (x >= 0 && y >= 0 && x < cols && y < rows) return true;
 return false;
}
int numberOfCleanRooms(int** room, int roomSize, int* roomColSize) {
 int move = 1;
 int x, y;
 int dx, dy;
 int rows = roomSize;
 int cols = *roomColSize;
 int d = 0;
 int limits = 0;

 x = y = 0;
 room[y][x] = -1;

 while (limits < 4) {
  d %= 4;
  dx = dir[d][0];
  dy = dir[d][1];

  while (1) {
   if (CheckValid(x+dx, y+dy, rows, cols) && room[y+dy][x+dx] != 1) {

    if (room[y+dy][x+dx] != -1) {
     move++;
     limits = 0;
     room[y+dy][x+dx] = -1;
    }
    x += dx;
    y += dy;

   } else if (CheckValid(x+dx, y+dy, rows, cols) == false || room[y+dy][x+dx] == 1){
    d++;
    limits++;
    break;
   }
  }

 }

 return move;

}

int main (void) {
 
 return 0;
}
