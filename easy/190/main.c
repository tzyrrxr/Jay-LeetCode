int reverseBits(int n) {
  int l = 31;
  int r = 0;

  while (l > r) {
    bool l_bit = (n >> l) & 1;
    bool r_bit = (n >> r) & 1;
    n = n & ~((uint32_t)1 << l);
    n = n | ((uint32_t)r_bit << l);
    n = n & ~((uint32_t)1 << r);
    n = n | ((uint32_t)l_bit << r);
    l--;
    r++;
  }

  return n;
    
}
