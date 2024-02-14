#include <stdio.h>

int findPoisonedDuration(int* timeSeries, int timeSeriesSize, int duration) {
 int sum = 0;

 if (timeSeriesSize > 0) {
  sum = duration;
 }

 for (int i = 1; i < timeSeriesSize; i++) {
  sum += duration;
  if (timeSeries[i-1] -1 + duration >= timeSeries[i]) {
   sum = sum - ((timeSeries[i-1] -1 + duration) - (timeSeries[i] - 1));
  }
 }

 return sum;
}

int main (int argc, char *argv[]) {

 int timeSeries[] = {1,2};

 printf("duration time: %ds\n", findPoisonedDuration(timeSeries, 2, 2));

 return 0;
}
