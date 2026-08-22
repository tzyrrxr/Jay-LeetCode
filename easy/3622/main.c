bool checkDivisibility(int n) {
    unsigned int prod = 1; 
    unsigned int sum = 0; 
    int tmp = n;
    while (tmp)
    {
        int dig = tmp % 10;
        prod *= dig;
        sum += dig;
        tmp /= 10;
    }

    return (n % (prod + sum)) == 0;
}