int maxProduct(int n) {
  int d[2] = {0};

  while (n) {
    if (n % 10 > d[0]) {
      d[1] = d[0];
      d[0] = n % 10;
    } else if (n % 10 > d[1] && n % 10 <= d[0]) {
      d[1] = n % 10;
    }
    n /= 10;
  }
    
  return d[0] * d[1];
}
