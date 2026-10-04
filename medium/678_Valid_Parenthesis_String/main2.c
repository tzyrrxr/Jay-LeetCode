bool checkValidString(char* s) {
    int low = 0;
    int high = 0;
    
    while(*s) {
        if (*s == '(') {
            low++;
            high++;
        } else if (*s == ')') {
            high--;
            low = fmax(--low, 0); // if 'high' is greater than or equal to zero, we can assign '*' as '('.
        } else if (*s == '*') {
            high++;
            low = fmax(--low, 0);
        } else {
            return false;
        }

        if (high < 0) 
            return false;

        s++;
    }
    
    return low == 0;
    
}
