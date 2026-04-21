typedef struct {
  int key;
  int val;
  UT_hash_handle hh;
} hash;

hash *h = NULL;

void add_key (int key, int val) {
  hash *item;
  HASH_FIND_INT(h, &key, item);

  if (item == NULL) {
    item = (hash*) malloc(sizeof(hash));
    item->key = key;
    HASH_ADD_INT(h, key, item);
  }
  item->val = val;
}

int minimumHammingDistance(int* source, int sourceSize, int* target, int targetSize, int** allowedSwaps, int allowedSwapsSize, int* allowedSwapsColSize) {
  int ret = sourceSize;
  hash *item;
  int key;
  h = NULL;
  for (int j = 0; j < allowedSwapsSize; j++) {
    add_key(allowedSwaps[j][0], 0);
    add_key(allowedSwaps[j][1], 0);
  }

  for (int i = 0; i < sourceSize; i++) {
   // error here
    if (source[i] == target[i]) {
      key = i;
      HASH_FIND_INT(h, &key, item);
      if (item != NULL && item->val == 1) continue;
      add_key(i, 1);
      ret--;
      continue;
    }
    for (int j = 0; j < allowedSwapsSize; j++) {
      if (target[allowedSwaps[j][0]] == source[i]) {
        key = allowedSwaps[j][0];
        HASH_FIND_INT(h, &key, item);
        if (item->val == 1) continue;
        add_key(allowedSwaps[j][0], 1);
        ret--;
        break;
      } else if (target[allowedSwaps[j][1]] == source[i]) {
        key = allowedSwaps[j][1];
        HASH_FIND_INT(h, &key, item);
        if (item->val == 1) continue;
        add_key(allowedSwaps[j][1], 1);
        ret--;
        break;
      }
    }
  }

  // TODO
  // free hash
    
  return ret;
}
