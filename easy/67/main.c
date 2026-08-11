char* addBinary(char* a, char* b) {
  int a_len = strlen(a);
  int b_len = strlen(b);
  int ch_len = fmax(a_len, b_len)+1;
  bool carry = 0;
  char *ch = (char*) malloc((ch_len+1) * sizeof(char));
  if (!ch) return NULL;

  ch[ch_len] = '\0';
  int curr_index = ch_len-1;

  while (curr_index >= 0) {
    int a_bit = --a_len < 0 ? 0 : a[a_len] - '0';
    int b_bit = --b_len < 0 ? 0 : b[b_len] - '0';
    int sum = a_bit + b_bit + (int)carry;
    ch[curr_index--] = (sum & 1) + '0';
    carry = (bool)(sum >> 1);

  }
  if (*ch == '0') {
    memmove(ch, ch+1, ch_len*sizeof(char));
    ch = realloc(ch, ch_len*sizeof(char));
  }
    
  return ch;
}
