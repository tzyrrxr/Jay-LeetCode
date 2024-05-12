#include <stdio.h>
#include <stdlib.h>

struct Node {
    double wageToQuality;
    int quality;
    struct Node *next;
};

struct Node* CreateNode(double wTQ, int q) {
    struct Node *node = malloc(sizeof(struct Node));
    node->wageToQuality = wTQ;
    node->quality = q;
    return node;
}

int CMP(const void* a, const void* b) {
    const struct Node* nodeA = *(struct Node**) a;
    const struct Node* nodeB = *(struct Node**) b;
    if (nodeA->wageToQuality > nodeB->wageToQuality) return 1;
    else if (nodeA->wageToQuality < nodeB->wageToQuality) return -1;
    return 0;
}

double mincostToHireWorkers(int* quality, int qualitySize, int* wage, int wageSize, int k) {
    double ret = INT_MAX;
    struct Node** s = malloc(qualitySize * sizeof(struct Node*));
    struct Node** heap = malloc(k * sizeof(struct Node*));
    int heapSize = 0, totalQuality = 0;

    for (int i = 0; i < qualitySize; i++) {
        s[i] = CreateNode((double)wage[i] / (double)quality[i], quality[i]);
    }

    qsort(s, qualitySize, sizeof(struct Node*), CMP);

    for (int i = 0; i < qualitySize; i++) {
        if (heapSize < k) {
            heap[heapSize++] = s[i];
            totalQuality += s[i]->quality;
        } else {
            // Find the worker with the highest quality to replace
            int maxIndex = 0;
            for (int j = 0; j < k; j++) {
                if (heap[j]->quality > heap[maxIndex]->quality) {
                    maxIndex = j;
                }
            }
            totalQuality -= heap[maxIndex]->quality;
            heap[maxIndex] = s[i];
            totalQuality += s[i]->quality;
        }

        if (heapSize == k) {
            double cost = s[i]->wageToQuality * totalQuality;
            if (cost < ret) ret = cost;
        }
    }

    // Clean up
    for (int i = 0; i < qualitySize; i++) {
        free(s[i]);
    }
    free(s);
    free(heap);

    return ret;
}

int main() {
    int quality[] = {25, 68, 35, 62, 52, 57, 35, 83, 40, 51};
    int wage[] = {147, 97, 251, 129, 438, 443, 120, 366, 362, 343};
    int k = 6;
    double result = mincostToHireWorkers(quality, 10, wage, 10, k);
    printf("Minimum cost to hire %d workers is %.2f\n", k, result);
    return 0;
}

