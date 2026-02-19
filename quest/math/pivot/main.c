int pivotInteger(int n) {
  for (int x = 1; x <= n; x++) {
    int num1 = (1+x) * x / 2;
    int num2 = (x+n) * (n-x+1) / 2;
    if (num1 == num2) return x;
  }
    
  return -1;
}
