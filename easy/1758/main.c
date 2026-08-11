int minOperations(char* s) {
  int first0 = 0;
  int first1 = 0;
  bool pt_first0 = 0;
  bool pt_first1 = 1;

  while (*s != '\0') {
    if (*s - '0' != pt_first1) {
      first1++;
    } 
    if (*s - '0' != pt_first0){
      first0++;
    }
    pt_first0 = !pt_first0;
    pt_first1 = !pt_first1;
    s++;
  }

  return first0 < first1 ? first0 : first1;
    
}
