typedef struct {
  unsigned long long key;
  UT_hash_handle hh;
} Node;

// brute force
int robotSim(int* commands, int commandsSize, int** obstacles, int obstaclesSize, int* obstaclesColSize) {
 int dir[4][2] = {
  { 0, 1},
  { 1, 0},
  { 0,-1},
  {-1, 0},
 };
 Node *users = NULL;
 int pt = 0;
 int pos[2] = {0,0};
 int max = 0;
 for (int k = 0; k < obstaclesSize; k++) {
   int x = obstacles[k][0];
   int y = obstacles[k][1];
   Node *new = (Node *) malloc(sizeof(Node));
   new->key = ((unsigned long long)x << 32) | (y & 0xffffffff);
   HASH_ADD(hh, users, key, sizeof(long long),new);
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
         unsigned long long target = ((unsigned long long)x << 32) | (y & 0xffffffff);
         Node *hit = NULL;
         HASH_FIND(hh, users, &target, sizeof(long long), hit);

         if (hit) {
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
