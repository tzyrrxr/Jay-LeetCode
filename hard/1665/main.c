int CMP (const void *a, const void *b) {
    int T1 = *(int **) a;
    int T2 = *(int **) b;
    return (T1[1] - T1[0]) - (T2[1] - T2[0]);
}

int minimumEffort(int** tasks, int tasksSize, int* tasksColSize) {
    // sort minimum differences
    qsort(tasks, tasksSize, sizeof(int*), CMP);
    int ret = 0;

    for (int i = 0; i < tasksSize; i++) {
        if(ret + tasks[i][0] > tasks[i][1]) {
            ret += tasks[i][0];
        } else {
            ret = tasks[i][1];
        }
    }
    
    return ret;
}
