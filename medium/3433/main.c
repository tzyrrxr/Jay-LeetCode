#include <stdio.h> 
#include <stdlib.h> 
#include <stdbool.h> 
#include <string.h> 
#include <ctype.h> // isdigit

// RULES
// ["MESSAGE", "timestampi", "mentions_stringi"]
// mentions_stringi -> count mention number
// ex. if there are 3 people and mention id0, id2 -> return mention [1,0,1]
// mentions_stringi == HERE -> mean that mention all of online people.
// mentions_stringi == ALL -> mean that mention all of people include offline.
//
// ["OFFLINE", "timestampi", "idi"]
// It means that id number of people is offline now. It's going to be online on timestamp + 60.
//
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countMentions(int numberOfUsers, char*** events, int eventsSize, int* eventsColSize, int* returnSize) {
  int *mentions = (int*) calloc(numberOfUsers, sizeof(int));
  //bool *isOnline = (bool*)calloc(numberOfUsers, sizeof(bool));
  int *wakeupTime = (int*)calloc(numberOfUsers, sizeof(int));
  *returnSize = numberOfUsers;

  for (int i = 0; i < eventsSize; i++) {
    char* status = events[i][0];
    int timestamp = atoi(events[i][1]);
    char* mentionsStr = events[i][2];
    int id = -1;

    // MESSAGE
    if (strcmp(status,"MESSAGE") == 0) {
     if (strcmp(mentionsStr,"ALL") == 0) {
       for (int i = 0; i < numberOfUsers; i++) mentions[i]++;
     } else if (strcmp(mentionsStr,"HERE") == 0){
       for (int i = 0; i < numberOfUsers; i++) {
         // verify whether wakeup occured
         if (wakeupTime[i] <= timestamp) {
           mentions[i]++;
         }
       }
     } else {
       // check mentions string
       // strtok to split " "
       // strtok(str, " ") -> start splitting str.
       // strtok(NULL, " ") -> keep splitting the same string until no tokens remain.
       char *token = strtok(mentionsStr, " ");
       while (token != NULL) {
         // add 2 to skip "id"
         if (wakeupTime[atoi(token+2)] <= timestamp) {
           mentions[atoi(token+2)]++;
         }
         token = strtok(NULL, " "); // NOTE!!
       }
     }
    } else { // offline
        // check mentions string
        if (wakeupTime[atoi(mentionsStr)] <= timestamp) {
          wakeupTime[atoi(mentionsStr)] = timestamp + 60;
        }
    }
  }
    
  //free(isOnline);
  free(wakeupTime);

  return mentions;
}
