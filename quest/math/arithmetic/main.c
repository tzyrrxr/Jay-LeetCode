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

  bool *visited = (bool*) calloc(n, sizeof(bool));
  int index;
  for (int i = 0; i < n; i++) {
    if ((arr[i]-min) % d) {
      res = false;
      break;
    }
    index = (arr[i]-min)/d;
    if (index >= n || visited[index]) {
      res = false;
      break;
    }
    visited[index] = true;
  }

  free(visited);

  return res;
    
}
