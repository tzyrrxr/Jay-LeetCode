// brute force
int bestClosingTime(char* customers) {
  int res;
  int min = INT_MAX;
  int len = strlen (customers);
  int cntN = 0;
  int cntY = 0;
  int allDay = 0;
  int closedDay = 0;

  for (int i = 0; i < len; i++) {
    if (customers[i] == 'Y') cntY++;
    else cntN++;
  }
  allDay = cntN;
  closedDay = cntY;

  if (min > allDay) { 
   min = allDay;
   res = len;
  }

  for (int i = len-1, curN = cntN, curY = cntY, preBest = 0, curPenalty = 0; i >= 0; i--) {
    if (customers[i] == 'Y') {
      curY--;
    } else {
      curN--;
    }
    curPenalty = curN + (cntY - curY);
    preBest = curN;
    if (curPenalty <= min) {
      min = curPenalty;
      res = i;
    }
  }

  if (min > closedDay) res = 0;

  return res;
    
}
