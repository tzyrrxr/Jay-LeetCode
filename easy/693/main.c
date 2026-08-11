bool hasAlternatingBits(int n) {
  bool pt = n & 1;

  while (n) {
    n >>= 1;
    if (!(pt^(n&1))) return false;
    pt = !pt;
  }
    
  return true;
}
