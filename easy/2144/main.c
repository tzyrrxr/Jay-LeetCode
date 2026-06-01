int CMP (const void *a, const void *b) {
  return *(int *)b - *(int*)a;
}
int minimumCost(int* cost, int costSize) {
 int ret = 0;
 qsort (cost, costSize, sizeof(int), CMP);
 for (int i = 0; i < costSize; i++) {
   if ((i +1)% 3 != 0) {
     ret += cost[i];
   }
 }

 return ret;
}
