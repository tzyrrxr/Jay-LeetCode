int furthestDistanceFromOrigin(char* moves) {
  int L = 0, R = 0;
  for (int i = 0; moves[i] != '\0'; i++) {
    if (moves[i] == 'R') R++;
    else if (moves[i] == 'L') L++;
  }

  return (R > L ? R - L : L - R) + (strlen(moves) - (R+L));
    
}
