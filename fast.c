bool repeatedSubstringPattern(char * s)
{
    int n = strlen(s);
    int i = 1, j = 0;
    int * dp = calloc(n + 1, sizeof(int));
    
    while (i < n)
    {
        if (s[i] == s[j]) dp[++i] = ++j;
        else if (j == 0) i++;
        else j = dp[j];
    }

    return dp[n] && dp[n] % (n - dp[n]) == 0 ;
}
