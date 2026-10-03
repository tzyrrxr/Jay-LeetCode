int longestValidParentheses(char* s) {
    if (!s || !strlen(s))
        return 0;

    int len = strlen(s);
    int ret = 0;
    int pt = -1;
    int *stack = (int*) malloc(sizeof(int) * (len + 1));
    stack[++pt] = -1;

    for (int i = 0; i < len; i++) {
        if(s[i] == '(')
        {
            stack[++pt] = i;
        } else {
            pt--;
            if (pt < 0) {
                stack[++pt] = i;
            } else if (ret < i - stack[pt]) {
                ret = i - stack[pt];
            }
        }
    }
    
    free(stack);

    return ret;
}
