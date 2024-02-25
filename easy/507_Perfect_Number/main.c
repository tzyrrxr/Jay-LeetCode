#include <stdio.h>

struct Node {
 int div1;
 int div2;
 struct Node *next;
};

void createNode (struct Node *pt) {
 pt = (struct Node*) malloc (sizeof(struct Node));
}
struct Node *pt;
createNode(pt);

bool checkPerfectNumber(int num) {
 struct Node *root = pt;
 int sum = 1;
 for (int i = 2; i < num; i++) {
  if ((num % i) == 0) {
   pt->div1 = i;
   pt->div2 = div2 / i;
   createNode(pt->next);
   pt = pt->next;
  }
  struct Node *checker = root;
  while (checker) {
   if (checker->div2 == i) {
    // break
    i = num;
    free(checker);
    break;
   }
   checker = checker->next;
  }

 }
 struct Node *sumPt = root;

 while(sumPt) {
  sum += sumPt->div1 + sumPt->div2;
  sumPt = sumPt->next;
 }
    
 return sum == num ? True : False;

}

int main (void) {

 return 0;
}
