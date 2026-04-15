int closestTarget(char** words, int wordsSize, char* target, int startIndex) {
  int min = INT_MAX;

  for (int i = 0; i < wordsSize; i++) {
    if (strcmp(words[(startIndex + i) % wordsSize], target) == 0) {
      min = fmin(min, i);
    }
    if (strcmp(words[(startIndex - i + wordsSize) % wordsSize], target) == 0) {
      min = fmin(min, i);
    }
  }

  return min == INT_MAX ? -1 : min;
    
}
