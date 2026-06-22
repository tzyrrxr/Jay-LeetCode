maxNumberOfBalloons(char* text) {
  int min = INT_MAX;
  int hash[26] = {0};
  char target[] = {'b', 'a', 'l', 'o', 'n'};

  for (int i = 0; text[i] != NULL; i++) {
    switch(text[i]) {
      case 'b':
      case 'a':
      case 'n':
      case 'l':
      case 'o':
        hash[text[i] - 'a']++;
        break;

      default:
        break;
    }
  }

  hash['l'-'a'] >>= 1;
  hash['o'-'a'] >>= 1;

  for (int i = 0; i < sizeof(target); i++) {
    if (min > hash[target[i] - 'a']) {
      min = hash[target[i] - 'a'];
    }
  }
    
  return min;
}
