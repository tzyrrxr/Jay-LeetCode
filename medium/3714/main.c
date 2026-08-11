int longestBalanced(char* s) {
  int freq[3];
  int distinct = 0;
  int lowestFreq = INT_MAX;
  int currLongest;
  int longestLen = 1;
    
  for (int i = 0; i< strlen(s); i++) {
    if (freq[s[i]-'a'] == 0) distinct++;
    freq[s[i]-'a']++;
    currLongest = 0;
    lowestFreq = INT_MAX;
    for (int j = 0; j < 3; j++) {
      if (freq[j] != 0) {
        lowestFreq = fmin (lowestFreq, freq[j]);
      }
    }
    currLongest = lowestFreq * distinct;
    longestLen = fmax(currLongest, longestLen);
  }

  return longestLen;
}
