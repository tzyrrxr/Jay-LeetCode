int reverse(int x){
  int res = 0;

  while (x) {
    // max ...647
    // min -...648
    if (res > INT_MAX/10 || (res == INT_MAX/10 && (x%10) > 7) || res < INT_MIN/10 || (res == INT_MIN/10 && (x%10) < -8)) return 0;
    res = res *10 + x %10;
    x /= 10;
  }

  return res;

}
