typedef struct {
  int key;
  int *val;
  int capacity; // for dynamic alloc size
  int count;
  UT_hash_handle hh;
} HashItem;
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
long long* distance(int* nums, int numsSize, int* returnSize) {
  long long *arr = (long long *) calloc(numsSize, sizeof(long long));
  int n = numsSize;
  long long total;
  HashItem *hash = NULL;
  HashItem *p = NULL;
  HashItem *tmp = NULL;
  for (int i = 0; i < n; i++) {
    p = NULL;
    HASH_FIND_INT(hash, &nums[i], p);
    if (p == NULL) {
      p = (HashItem*) malloc(sizeof(HashItem));
      p->key = nums[i];
      p->capacity = 16;
      p->val = (int*)malloc(p->capacity * sizeof(int));
      p->count = 0;
      HASH_ADD_INT(hash, key, p);
    }
    if (p->count == p->capacity) {
      p->capacity *= 2;
      p->val = (int*) realloc(p->val, p->capacity*sizeof(int));
    }
    p->val[p->count++] = i;
  }

  /*
   * ex. nums = [1,3,7,10]
   * process i = 2; nums[2] = 7 
   * Split 2 side, left and right sides
   * Left side:
   * (7 - 1) + (7 - 3) = (7 * 2) - (1 + 3)
   * conclustion: left side = nums[i] * number of left - (sum of left val)
   *
   * Right side(include itself):
   * (10 - 7) + (7 - 7) = (10+7) - (7*2) = (total of array values - sum of left val) - (7*2)
   *
   * Left side + Right side =
   * nums[i] * number of left - (sum of left val) + (total of array values - sum of left val) - (nums[i]*(count - i))
   * = Total of array values - 2*(sum of left val) - nums[i] * (count - i*2)
   */
  p = NULL;
  HASH_ITER(hh, hash, p, tmp) {
    total = 0;
    for (int i = 0; i < p->count; i++) {
      total += p->val[i];
    }
    long long leftVal = 0;
    for (int i = 0; i < p->count; i++) {
      arr[p->val[i]] = total - 2*(leftVal) - (long long)p->val[i] * (p->count - i*2);
      leftVal += p->val[i];
    }

  }
    
  *returnSize = numsSize;
  return arr;
}
