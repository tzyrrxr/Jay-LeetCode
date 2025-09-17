
int canBeTypedWords(char* text, char* brokenLetters) {
    int ret = 0;
    int broken = 0;
    char* b;

    while (*text) { // end of text == '\0'

      if (*text == ' ') {
        text++;
      } 
      if (!*text) break;

      broken = 0;
      while(*text && *text != ' ') {
        for (b = brokenLetters; *b; b++) {
          if (*text == *b) {
            broken = 1;
            break;
          }
        }
        text++;

      }

      if (!broken) ret++;
    }


    return ret;
}
