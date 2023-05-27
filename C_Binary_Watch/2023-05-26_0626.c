#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

char ** readBinaryWatch(int turnedOn, int* returnSize){
	char **retArr = (char **) malloc (200*sizeof(char*));
	int size = 0; // directly use *returnSize, the compiler will consider implicit.

	// half a day == 720 minutes
	// suppose that the time is defined by minute.
	// through all conditions.
	for (int t = 0; t < 720; t++) {
		int hr = t / 60;
		int min = t % 60;
		int LightLed = 0;
		while (hr) {
			if (hr % 2 == 1) {
				LightLed++;
			}
			hr = hr >> 1;
		}
		while (min) {
			if (min % 2 == 1) {
				LightLed++;
			}
			min = min >> 1;
		}
		// checking
		//printf("%d\n", LightLed);

		// checking whether LightLed number is equal to turnedOn number.
		if (LightLed == turnedOn) {
			// xx:xx + '\0' -> 6 char
			//
			retArr[size] = (char*) malloc(6*sizeof(char));
			snprintf(retArr[size], 6, "%d:%02d", t/60, t%60);
			//printf("%d:%02d", t/60, t%60);
			size++;
		}
	}
	*returnSize = size;

	return retArr;	
}

int main(void) {
	int size;
	char **result = readBinaryWatch (1, &size);
	// checking
	printf ("Size : %d\n", size);
	for (int i = 0; i<size; i++)
		printf("result: %s\n", result[i]);
	return 0;
}
