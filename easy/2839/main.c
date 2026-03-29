bool canBeEqual(char* s1, char* s2) {
  int len = strlen(s1);
  int evenHash[26] = {0};
  int oddHash[26] = {0};

  for (int i = 0; i < len; i++) {

    if ((i%2) == 0) {
      evenHash[s1[i] - 'a']++;
      evenHash[s2[i] - 'a']--;
    } else {
      oddHash[s1[i] - 'a']++;
      oddHash[s2[i] - 'a']--;
    }

  }

  for (int i = 0; i < 26; i++) {
    if (evenHash[i] != 0 || oddHash[i] != 0) return false;
  }

  return true;
    
}
