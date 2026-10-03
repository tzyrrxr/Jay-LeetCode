int longestValidParentheses(char* s) {
    int len = strlen(s);
    int ret = 0;
    int pt = -1;
    char *stack = (char*) malloc(sizeof(char) * len);

    for (int i = 0; i < len; i++) {
        int cnt = 0;
        pt = -1;
        for (int j = i; j < len; j++)
        {
            if (s[j] == '(')
            {
                stack[++pt] = s[j];
            }
            else if (pt > -1 && s[j] == ')')
            {
                pt--;
                cnt += 2;
                if (cnt > ret && pt == -1)
                    ret = cnt;
            }
            else
            {
                break;
            }
        }
    }
    
    free(stack);

    return ret;
}
