bool isPalindrome(int x) {
  if (x < 0) return false;
  long long reverse = 0;
  int tmp = x;

  while (tmp) {
    reverse = reverse * 10 + tmp % 10;
    tmp /= 10;
  }

  return (int)reverse == x;
    
}
