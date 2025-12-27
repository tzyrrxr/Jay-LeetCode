int bestClosingTime(char* customers) {
  int res;
  int min = INT_MAX;
  int len = strlen (customers);
  int Penalty = 0;

  for (int i = 0; i < len; i++) {
    if (customers[i] == 'Y') Penalty++; // Closed day penalty
  }

  min = Penalty;
  res = 0;
  for (int i = 0; i < len; i++) {
    if (customers[i] == 'Y') {
      Penalty--;
    } else {
      Penalty++;
    }

    if (Penalty < min) {
      min = Penalty;
      res = i+1;
    }

  }

  return res;
    
}
