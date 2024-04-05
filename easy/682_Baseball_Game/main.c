#include <stdio.h>
#include <ctype.h>

int calPoints(char** operations, int operationsSize) {
 int *tmp = (int *) malloc (sizeof(int));
 int tmpSize = 0;
 int sum = 0;
 for (int i = 0; i < operationsSize; i++) {
  if (isdigit(*operations[i])) {
   int num = 0;
   tmp = (int *) realloc (tmp, (tmpSize + 1) * sizeof(int));
   for (int j = 0; j < strlen(operations[i]); j++) {
    num = num*10 + operations[i][j] - '0';
   }
   tmp[tmpSize++] = num;
  } else if (*operations[i] == '-'){
   int num = 0;
   tmp = (int *) realloc (tmp, (tmpSize + 1) * sizeof(int));
   for (int j = 1; j < strlen(operations[i]); j++) {
    num = num*10 + operations[i][j] - '0';
   }
   num = ~num + 0x1;
   tmp[tmpSize++] = num;

  } else {
   switch (*operations[i]) {
    case '+':
     tmp = (int *) realloc (tmp, (tmpSize + 1) * sizeof(int));
     tmp[tmpSize++] = tmp[tmpSize-1] + tmp[tmpSize-2];
     break;

    case 'D':
     tmp = (int *) realloc (tmp, (tmpSize + 1) * sizeof(int));
     tmp[tmpSize++] = tmp[tmpSize-1] * 2;
     break;

    case 'C':
     tmpSize--;
     break;

    default:
     break;
   }
  }
 }

 for (int i = 0; i < tmpSize; i++) {
  sum += tmp[i];
 }

 return sum;
}

int main (void) {

 return 0;
}
