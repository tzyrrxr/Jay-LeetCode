char* addBinary(char* a, char* b) {
  int a_len = strlen(a);
  int b_len = strlen(b);
  int ch_len = fmax(a_len, b_len)+1;
  bool carry = 0;
  char *ch = (char*) malloc((ch_len+1) * sizeof(char));
  ch[ch_len] = '\0';

  while (ch_len-- > 0) {
    int a_bit = --a_len < 0 ? 0 : a[a_len] - '0';
    int b_bit = --b_len < 0 ? 0 : b[b_len] - '0';
    int sum = a_bit + b_bit + (int)carry;
    ch[ch_len] = (sum & 1) + '0';
    carry = (bool)(sum >> 1);

  }
    
  return *ch == '0' ? ch+1 : ch;
}
