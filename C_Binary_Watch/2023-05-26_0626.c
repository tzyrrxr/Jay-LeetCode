/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int H[] = {1, 2, 4, 8};
int M[] = {1, 2, 4, 8, 16, 32};
void hr(char **ret, int turnedOn, int *returnSize);
void min (char **ret, int turnedOn, int *returnSize);
void hr_min (char **ret, int turnedOn, int *returnSize);

char ** readBinaryWatch(int turnedOn, int* returnSize){
 *returnSize = 0;
 char **ret;
 if (turnedOn > 8) return [];
 ret = (char**) malloc(1000 * (char*));
 // hr
 if (turnedOn < 4) {
  hr(ret, turnedOn, returnSize);
 }
 // min
 if (turnedOn < 5) {
  min (ret, turnedOn, returnSize);
 }
 // hr:min
 hr_min (ret, turnedOn, returnSize);

 return ret;
}

void hr(ret, turnedOn, returnSize) {
}
void min (ret, turnedOn, returnSize) {
}
void hr_min (ret, turnedOn, returnSize){
}
