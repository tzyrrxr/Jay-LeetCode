bool canMakeArithmeticProgression(int* arr, int arrSize) {
  int n = arrSize;
  int d = 0;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n-i-1; j++) {
      if (arr[j] > arr[j+1]) {
        int tmp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = tmp;
      }
    }
  }

  d = arr[0] - arr[1];
  for (int i = 1; i < n-1; i++) {
    if (arr[i] - arr[i+1] != d) return false;
  }

  return true;
    
}
