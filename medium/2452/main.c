/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** twoEditWords(char** queries, int queriesSize, char** dictionary, int dictionarySize, int* returnSize) {
  int len = strlen(queries[0]);
  char** ret = (char**) malloc(queriesSize * sizeof(char*));

  *returnSize = 0;
  for (int i = 0; i < queriesSize; i++) {
    for (int j = 0; j < dictionarySize; j++) {
      int diff = 0;
      for (int k = 0; k < len; k++) {
        if (queries[i][k] != dictionary[j][k]) diff++;
        if (diff > 2) break;
      }
      if (diff <= 2) {
        ret[(*returnSize)] = (char*) malloc((len+1)*sizeof(char));
        memcpy(ret[(*returnSize)], queries[i], (len+1)*sizeof(char));
        (*returnSize)++;
        break; // avoid duplicating the query word.
      }
    }
  }

  if ((*returnSize) > 0 && (*returnSize) <= queriesSize) {
    char** tmp = realloc(ret, (*returnSize)*sizeof(char**));
    if (tmp != NULL) {
      ret = tmp;
    }
  } else if ((*returnSize) == 0){
    free(ret);
  }

  return (*returnSize) != 0 ? ret : NULL;
    
}
