#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void substring (char* source, char **dst, int sIndex, int dstLen) {
 *dst = (char*) malloc ((dstLen + 1) * sizeof(char));
 if (!(*dst)) {
  printf("dst is null");
  exit(1);
 }
 strncpy (*dst, source + sIndex, dstLen);
 (*dst)[dstLen] = '\0';
}

bool canParitition (char *s, int target) {
    bool ret = false;
    char *lstr = NULL;
    char *rstr = NULL;
    int left = 0;

    if (target == 0 && strlen(s) == 0) return ret = true;
    
    for (int i = 0; i < strlen(s); i++) {
        substring(s, &lstr, 0, i+1);
        substring(s, &rstr, i+1, strlen(s) - (i+1));
        left = atoi (lstr);
        ret = canParitition(rstr, target - left);
        free (lstr);
        free (rstr);
        if (ret) return ret;
    }
    
    return ret;
}

int punishmentNumber(int n) {
    int ret = 0;
    char s[30] = {'\0'};

    for (int i = 1; i <= n; i++) {
        sprintf(s, "%d", i);
        if (canParitition(s, i*i)) ret += i*i;
    }

    return ret;
}


int main () {
  int n = 10;
  punishmentNumber(n);

  return 0;
}
