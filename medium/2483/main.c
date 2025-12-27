int bestClosingTime(char* customers) {
  int res;
  int min = INT_MAX;
  int len = strlen (customers);
  int Penalty = 0;
  int closedDayPenalty = 0;

  for (int i = 0, closedDayPenalty = 0; i < len; i++) {
    if (customers[i] == 'Y') {
      Penalty--;
      closedDayPenalty++;
    } else {
      Penalty++;
    }

    if (Penalty < min) {
      min = Penalty;
      res = i+1;
    }

  }

  if (min >= closedDayPenalty) {
    return 0;
  }

  return res;
    
}
