// brute force
int bestClosingTime(char* customers) {
  int res = 0;
  int len = strlen (customers);
  int cntN = 0;
  int cntY = 0;
  int leftPenalty = 0;
  int rightPenalty = 0;

  for (int i = 0; i < len; i++) {
    if (customers[i] == 'Y') cntY++;
    else cntN++;
  }

  for (int i = 0; i < len; i++)

  return res;
    
}
