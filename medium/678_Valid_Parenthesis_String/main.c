#include <stdio.h>

bool checkValidString(char* s) {
 if (strlen(s) <= 1) return false;
 int tmp = 0;
 int i = 0;
 bool ret = false;

 // asterisk as ""
 while (s[i] != '\0') {
  tmp += ( (s[i] == '(') - (s[i] == ')') );

  if (tmp < 0) {
   ret = false;
   break;
  } 

  i++;
  ret = true;
 }
 if (ret == 1 && tmp == 0) return true;
    
 i = 0;
 tmp = 0;
 // asterisk as "("
 while (s[i] != '\0') {
  tmp += ( (s[i] == '(' || s[i] == '*') - (s[i] == ')') );
  if (tmp < 0) {
   ret = false;
   break;
  }
  i++;
  ret = true;
 }

 if (ret == 1 && tmp == 0) return true;

 i = 0;
 tmp = 0;
 // asterisk as ")"
 while (s[i] != '\0') {
  tmp += ( (s[i] == '(') - (s[i] == ')' || s[i] == '*') );
  if (tmp > 0) {
   ret = false;
   break;
  }
  i++;
  ret = true;
 }

 return (ret == 1 && tmp == 0) ? true : false;
}

int main (void) {

 return 0;
}
