#inlcude <stdio.h>

int possibleStringCount(char* word) {
  int ret = 1;
  for (int i = 1; word[i] != '\0'; i++) {
   if (word[i-1] == word[i]) ret++;
  }
    
  return ret;

}

int main ()
{

  int ret = 0;

  ret = possibleStringCount ("abbccc");
  printf("%d\n", ret);

  return 0;
}
