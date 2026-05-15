bool check(int* nums, int numsSize) {
    int *tmp = (int*) malloc(numsSize*sizeof(int));
    bool match = true;

    memcpy(tmp, nums, numsSize*sizeof(int));
    qsort(tmp, numsSize, sizeof(int), CMP);

    for (int offset = 0; offset < numsSize; offset++) {
        match = true;
        for (int i = 0; i < numsSize; i++) {
            if (nums[(offset + i)%numsSize] != tmp[i]) {
                match = false;
                break;
            }
        }
        if (match) {
            return true;
        }
    }

    free(tmp);
    
    return false;
}
