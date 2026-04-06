#define SIZE 30001
// brute force
int robotSim(int* commands, int commandsSize, int** obstacles, int obstaclesSize, int* obstaclesColSize) {
 int dir[4][2] = {
  { 0, 1},
  { 1, 0},
  { 0,-1},
  {-1, 0},
 };

 int pt = 0;
 int pos[2] = {0,0};
 int max = 0;
 bool hash[SIZE][SIZE];
 memset(hash, 0, sizeof(bool)*(SIZE)*(SIZE));
 for (int k = 0; k < obstaclesSize; k++) {
   hash[obstacles[k][0]+SIZE][obstacles[k][1]+SIZE] = 1;
 }

 for (int i = 0; i < commandsSize; i++) {
   switch (commands[i]) {
     case -2:
       pt = (pt+4-1) % 4;
       break;
     case -1:
       pt = (pt + 1) % 4;
       break;
       
     default:
       for (int j = 0; j < commands[i]; j++) {
         int x =  pos[0] + dir[pt][0];
         int y =  pos[1] + dir[pt][1];

         if (hash[x+SIZE][y+SIZE]) {
           break;
         } else {
           pos[0] = x;
           pos[1] = y;
           max = fmax(max, pos[0]*pos[0] + pos[1]*pos[1]);
         }
       }

       break;
   }
 }

 return max;
    
}
