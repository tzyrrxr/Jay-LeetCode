#define MOD 1000000007

// return array number from max to min
int CMP_INT (const void *a, const void *b) { return *(int*)b - *(int*)a; } 
int CMP_LONG (const void *a, const void *b) { return *(long long*)b - *(long long*)a; } 

// 1. the margin fences contain 1 and m (or n)
// 2. Find the common lengths in horizontal and vertical 
int maximizeSquareArea(int m, int n, int* hFences, int hFencesSize, int* vFences, int vFencesSize) {
  int side = -1;
  int hcurr = 0, vcurr = 0;
  int *hf = (int *) malloc((hFencesSize + 2)* sizeof(int));
  int *vf = (int *) malloc((vFencesSize + 2)* sizeof(int));
  // possiable count is C(n, 2) = n*(n-1) / 2
  long long  *hlen = (long long *) malloc(((hFencesSize + 2)*(hFencesSize+1)/2)*sizeof(long long));
  long long  *vlen = (long long *) malloc(((vFencesSize + 2)*(vFencesSize+1)/2)*sizeof(long long));

  memcpy(hf+1, hFences, hFencesSize*sizeof(int));
  memcpy(vf+1, vFences, vFencesSize*sizeof(int));
  hf[0] = 1; hf[hFencesSize + 1] = m;
  vf[0] = 1; vf[vFencesSize + 1] = n;

  qsort(hf, hFencesSize + 2, sizeof(int), CMP_INT);
  qsort(vf, vFencesSize + 2, sizeof(int), CMP_INT);

  // Get all h len as possiable
  for (int i = 0; i < hFencesSize + 2; i++) {
    for (int j = i + 1; j < hFencesSize + 2; j++) {
      long long len = hf[i] - hf[j];
      hlen[hcurr++] = len;
    }
  }

  // Get all v len as possiable
  for (int i = 0; i < vFencesSize + 2; i++) {
    for (int j = i + 1; j < vFencesSize + 2; j++) {
      long long len = vf[i] - vf[j];
      vlen[vcurr++] = len;
    }
  }

  qsort(hlen, hcurr, sizeof(long long), CMP_LONG);
  qsort(vlen, vcurr, sizeof(long long), CMP_LONG);

  int i = 0;
  int j = 0;
  while (i < hcurr && j < vcurr) {
    if (hlen[i] == vlen[j]) {
      side = hlen[i];
      break;
    } else if (hlen[i] > vlen[j]) {
      i++;
    } else {
      j++;
    }
  }

  return side != -1 ? ((long long)side*side) % MOD : side;

}
