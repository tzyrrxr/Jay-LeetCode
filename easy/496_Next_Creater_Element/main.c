/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
  int *res = (int*) malloc(nums1Size*sizeof(int));
  int *nextGreater = (int*) malloc(10001*sizeof(int)); // hash table for the index of number contain the next greater element
  int stack[nums2Size];
  int top = -1;

  memset(nextGreater, -1, 10001*sizeof(int));

  for (int i = 0; i < nums2Size; i++) {
    int currVal = nums2[i];
    while (top > -1 && stack[top] < currVal) {
      nextGreater[stack[top--]] = currVal; 
    }
    stack[++top] = currVal;
  }

  for (int i = 0; i < nums1Size; i++) res[i] = nextGreater[nums1[i]];

  free(nextGreater);

  *returnSize = nums1Size;
  return res;
    
}
