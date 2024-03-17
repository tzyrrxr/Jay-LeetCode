#include <stdio.h>
#include <stdlib.h>

struct node {
 int val;
 int count;
};

struct node* createNode (int value) {
 struct node* ret;
 ret = (struct node*) malloc (sizeof(struct node));

 ret->val = value;
 ret->count = 1;

 return ret;
}

void QuickSort(int *arr, int left, int right) {
  if (left >= right) return;

  int pivotIndex = left;
  int sortOfLeftIndex = left + 1;
  int sortOfRightIndex = right;
  int tmp;

  for (;sortOfLeftIndex <= sortOfRightIndex;) {
    // finding the exchange index
    for (; sortOfLeftIndex <= right && arr[sortOfLeftIndex] <= arr[pivotIndex];sortOfLeftIndex++);
    for (;sortOfRightIndex > left && arr[sortOfRightIndex] >= arr[pivotIndex];sortOfRightIndex--);
    if (sortOfLeftIndex <= sortOfRightIndex) {
      tmp = arr[sortOfLeftIndex];
      arr[sortOfLeftIndex] = arr[sortOfRightIndex];
      arr[sortOfRightIndex] = tmp;
    }
  }
  // exchange pivot value and meet index
  tmp = arr[left];
  arr[left] = arr[sortOfRightIndex];
  arr[sortOfRightIndex] = tmp;

  QuickSort (arr, left, sortOfRightIndex-1);
  QuickSort (arr, sortOfRightIndex+1, right);

}

int findLHS(int* nums, int numsSize){

 int probeVal;
 struct node* indexArr[numsSize];
 int index;

 int max = 0;

 QuickSort (nums, 0, numsSize-1);

 // put the value into the array
 index = 0;
 indexArr[index] = createNode(nums[0]);
 probeVal = nums[0];

 for (int i = 1; i < numsSize; i++) {
  if (probeVal != nums[i]) {
   indexArr[++index] = createNode(nums[i]);
   probeVal = nums[i];
  } else {
   (indexArr[index]->count)++;
  }
 }

 // calculate numbers
 for (int i = 0; i < index; i++) {
  int distance = indexArr[i+1]->val - indexArr[i]->val;
  if ( (distance == 1  || distance == -1) && max < indexArr[i]->count + indexArr[i+1]->count) {
   max = indexArr[i]->count + indexArr[i+1]->count;
  }
 }

 return max;
}

int main (void) {

 int arr[] = {1,2,3,4};
 findLHS (arr, 4);

 return 0;
}
