#include <string.h>

/*
 * suppose that numRows = 4, strlen(s) = 10
 *
 * 0    6 
 * 1  5 7   11
 * 2 4  8 10
 * 3    9     
 *
 * 0-6 = 6, numRows + (numRows-2)
 * (1-5 = 4; 5-7 = 2;) 4+2=6
 * (2-4 = 2; 4-8 = 4;) 2+4=6
 * 3-9 = 6
 *
 */

char* convert(char* s, int numRows) {
  int len = strlen(s);
  int r = numRows;

  char* ret = (char*) malloc((len+1)*sizeof(char));
  int retPt = 0;
  int i = 0;

  int pt = 0;
  while (pt < len) {
    ret[retPt] = s[pt];
    retPt++;
    if (r < 2) {
      pt++;
    } else {
      if (pt + (2*r-2) == pt) {
        break;
      }
      pt = pt + (2*r-2);
    }
  }


  if (r > 1) {
    for (i = 1; i < r-1; i++) {
     pt = i;
     while (pt < len) {
       ret[retPt] = s[pt];
       retPt++;
       if (pt + (2*r-2-i*2) == pt || pt + (2*r-2-i*2) >= len) {
         break;
       }
       pt = pt + (2*r-2-i*2);
       ret[retPt] = s[pt];
       retPt++;
       if (pt + (i*2) == pt || pt + (i*2) >= len) {
         break;
       }
       pt = pt + (i*2);
     }

    }

    pt = i;
    while (pt < len) {
      ret[retPt] = s[pt];
      retPt++;
      if (pt + (2*r-2) == pt) {
        break;
      }
      pt = pt + (2*r-2);
    }
  }

  ret[len] = '\0';
  return ret;
}
