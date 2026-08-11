void div10(unsigned int n, int *q, int *r) {
  *q = 0;
  *r = 0;
  // Approximation method
  // final target 0.1
  // 0.1 = 0.8 / 8
  // find 0.8
  // 4/5 = 12/15
  // geometric series
  // S = a/(1-r)
  // (12/16) / (15/16) = (12/16) / (1 - (1/16))
  // a = 12/16; r = 1/16
  *q = (n >> 1) + (n >> 2); // 1/2 + 1/4 = 3/4 = 12/16 
  *q = *q + (*q >> 4) + (*q >> 8) + (*q >> 12) + (*q >> 16) + (*q >> 20) + (*q >> 24) + (*q >> 28); 

  // 0.8 / 8 = 1
  *q = *q >> 3;

  *r = n - ((*q << 3) + (*q << 1));

  // fix approximation method
  if (*r > 9) {
    (*q)++;
    *r -= 10;
  }
  
}

void mul10(unsigned int *n) {
  unsigned int num = *n;
  *n = (num << 3) + (num << 1);
}

int mirrorDistance(int n) {
  unsigned int revN = 0;
  unsigned int tmp = n;

  for (int i = 0; tmp; i++) {
    int q, r;
    div10(tmp, &q, &r);
    mul10(&revN);
    revN += r;
    tmp = q;
  }

  return revN > n ? revN-n : n-revN;
    
}
