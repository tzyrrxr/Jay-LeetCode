/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define TIME_LEN 6
char** readBinaryWatch(int turnedOn, int* returnSize) {
  char **res = (char**) malloc(200*sizeof(char*));
  *returnSize = 0;
  for (int t = 0; t < 720; t++) {
    int hr = t / 60;
    int min = t % 60;
    int ledOn = 0;
    while (hr) {
      ledOn += hr & 1;
      hr >>= 1;
    }
    while (min) {
      ledOn += min & 1;
      min >>= 1;
    }
    if (ledOn == turnedOn) {
      res[(*returnSize)] = (char*) malloc(TIME_LEN*sizeof(char));
      res[(*returnSize)][TIME_LEN-1] = '\0';

      snprintf(res[(*returnSize)], TIME_LEN, "%d:%02d", t/60, t%60);
      (*returnSize)++;
    }
  }
  char** tmp = realloc(res, (*returnSize)*sizeof(char**));
  if (tmp) res = tmp;

  return res;

}
