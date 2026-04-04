char* decodeCiphertext(char* encodedText, int rows) {
  int len = strlen(encodedText);
  int cols = len / rows;
  char * ret = (char*) malloc((len+1)*sizeof(char)); // Reserve '\0'

  int pt = -1; // for return

  for (int c = 0; c < cols; c++) {
    int cpt = -1; // increase row by row.
    for (int r = 0; r < rows; r++) {
      if (c +(++cpt) >= cols) {
        break;
      } else {
        char decode = encodedText[r*cols + c + cpt];
        ret[++pt] = decode;
      }
    }
  }

  // clear ' '
  while (pt >= 0 && ret[pt] == ' ') {
    pt--;
  }

  ret[++pt] = '\0';
  char* tmp = realloc(ret, (pt+1) * sizeof(char));
  if (tmp != NULL) {
    ret = tmp;
  }


  return ret;

}
