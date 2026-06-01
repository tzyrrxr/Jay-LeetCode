int CMP (const void *a, const void *b) {
  return *(int *)b - *(int*)a;
}
int minimumCost(int* cost, int costSize) {
 int ret = 0;
 if (costSize <= 2) {
   while (costSize) {
     ret += cost[costSize-1];
     costSize--;
   }
   return ret;
 }
 qsort (cost, costSize, sizeof(int), CMP);
 for (int i = 0, pt = 0; i < costSize; i++) {
   if (pt == 2) {
     pt = 0;
     continue;
   } else {
     ret += cost[i];
     pt++;
   }
 }

 return ret;
}
