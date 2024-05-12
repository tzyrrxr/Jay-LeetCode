#include <stdio.h>

struct Node {
 double wageToQuality;
 int quality;
 struct Node *next;
};

struct Node* CreateNode (double wTQ, int q) {
 struct Node *ret;
 ret = (struct Node*) malloc(sizeof(struct Node));

 ret->wageToQuality = wTQ;
 ret->quality = q;

 return ret;
}

struct Node* DeleteNode (struct Node* n) {
 struct Node* tmp = n;
 free (n);
 return tmp->next;
}

int CMP (const void* a, const void* b) {
 const struct Node* nodeA = *(struct Node**) a;
 const struct Node* nodeB = *(struct Node**) b;

 if (nodeA->wageToQuality > nodeB->wageToQuality) return 1;
 else if (nodeA->wageToQuality < nodeB->wageToQuality) return -1;
 return 0;
}

double mincostToHireWorkers(int* quality, int qualitySize, int* wage, int wageSize, int k) {
 double ret = INT_MAX;
 double tmp = 0;
 double currRatio = 0;
 int count = 0;
 int len = qualitySize;
 int totalQuality = 0;

 struct Node** s = (struct Node**) malloc(len * sizeof(struct Node*));
 struct Node** heap = (struct Node**) malloc(len * sizeof(struct Node*));
 int maxIndex = 0;

 for (int i = 0; i < len; i++) {
  s[i] = CreateNode((double)wage[i]/(double)quality[i], quality[i]);
 }

 qsort(s, len, sizeof(struct Node*), CMP);

 for (int i = 0; i < len; i++) {
  if (count < k) {
   heap[count++] = s[i];
   totalQuality += s[i]->quality;
   if (count == k) {
    currRatio = s[i]->wageToQuality;
    tmp = currRatio * totalQuality;
    if (ret > tmp) ret = tmp;
   }
  } else {
   for (int j = 1; j < k; j++) {
    if (heap[j]->quality > heap[maxIndex]) maxIndex = j;
    totalQuality -= heap[maxIndex]->quality;
    heap[maxIndex] = s[i];
    totalQuality += s[i]->quality;
    currRatio = s[i]->wageToQuality;
    tmp = currRatio * totalQuality;
    if (ret > tmp) ret = tmp;
   }
  }

 }

 return ret;
}

int main (void) {

 return 0;
}
