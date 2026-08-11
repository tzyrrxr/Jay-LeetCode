bool canMakeArithmeticProgression(int* arr, int arrSize) {
  int n = arrSize;
  int d = 0;
  int max = INT_MIN;
  int min = INT_MAX;
  bool res = true;

  for (int i = 0; i < n; i++) {
    if (max < arr[i]) max = arr[i];
    if (min > arr[i]) min = arr[i];
  }

  if (max == min) return true;

  d = (max-min) / (n-1);
  if (d == 0) return false;

  int base = min;

  // cyclic sort
  for (int i = 0; i < n; ) {
    if (arr[i] == d*i + base) {
      i++;
    } else {
      int num = arr[i] - base;
      int index = num / d;

      if (num %d != 0 || index >= n || arr[i] == arr[index]) {
        res = false;
        break;
      }

      int tmp = arr[i];
      arr[i] = arr[index];
      arr[index] = tmp;
    }
  }

  return res;
    
}
