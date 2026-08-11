int numSteps(char* s) {
  int carry = 0;
  int steps = 0;

  for (int i = strlen(s)-1; i > 0; i--) { 
    if ((s[i] - '0' + carry) & 1) { // if the current sum bit is odd.
      carry = 1; // the operation generates create a new carry.
      steps += 2; // an odd requires 2 steps: Add 1, then divide by 2
    } else {
      steps++; // an even requires 1 steps: Divide by 2
    }
  }

  // Handle the overleft carry for the most significant bit.
  if (carry) steps++;

  return steps;
    
}
