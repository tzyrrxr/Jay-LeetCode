int DFS (int cnt, int s, int e, int *nums, int k) {
  if (!(s<=e)) return 0;
  if (nums[s]*k >= nums[e]) return cnt;
  int l, r;
  if (nums[s]*k < nums[e]) {
    l = DFS(cnt+1, s+1, e, nums, k);
    r = DFS(cnt+1, s, e-1, nums, k);
  }
  if (l != 0 && r != 0)
    return l < r ? l : r;
  else if (l == 0) return r;
  else if (r == 0) return l;
  
  return 0;
}

int CMP (const void *a, const void *b) {
  return *(int*) a - *(int*)b;
}
int minRemoval(int* nums, int numsSize, int k) {
  qsort(nums, numsSize, sizeof(int), CMP);
    
  return DFS(0, 0, numsSize-1, nums, k);
}
