#include <stdio.h>

int countStudents(int* students, int studentsSize, int* sandwiches, int sandwichesSize) {
 int top = 0;
 int remain = studentsSize;
 int i = 0;
 int edge = 0;

 while (remain) {

  if (students[i] == sandwiches[top]) {
   top++;
   remain--;
   lST[i]++;
   edge = 0;
  } else {
   for ()
   edge++;
  }
  if (edge == remain) return remain;

  i++;
  if (i >= studentsSize) i = 0;
 }

 return remain;
}

int main (void) {

 return 0;
}
