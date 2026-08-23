bool sumGame(char* num) {
    int l = 0;
    int r = strlen(num)-1;
    int lSum = 0;
    int rSum = 0;
    int lQ_count = 0;
    int rQ_count = 0;

    while (l < r) {
        if (num[l] != '?') lSum += num[l] - '0';
        else lQ_count++;
        if (num[r] != '?') rSum += num[r] - '0';
        else rQ_count++;
        l++;
        r--;
    }

    // avaible number of ? is even. Bob move ? at the last one.
    if (!((lQ_count + rQ_count) & 1)) {
        // complementary to 9
        if (lSum - rSum == (rQ_count - lQ_count)*9/2)
            return false;
    }

    return true;
}