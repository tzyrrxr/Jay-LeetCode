char findKthBit(int n, int k) {
  if (n == 1) {
    return '0';
  }

  // Calculate the length of the sequence S_n
  // S1 = "0" -> 1
  // S2 = "011" -> 3
  // S3 = "0111001" -> 7
  // S4 = "011100110110001" -> 15

  int len = 1 << n; // Length of the sequence, ignoring index 0.

  // Rule
  // S_(n-1) + '1' + Reverse(Inverse(S_(n-1)))
  if (len/2 == k) { // the middle of sequence is always '1'.
    return '1';
  } else if (len/2 > k){ // if the k is less than the first half, it corresponds to S_(n-1).
    return findKthBit(n -1 , k);
  } 

  // For bits in the second half part, use the reverse of the corresponding bit in the first half.
  char preBit = findKthBit (n-1, len-k);
  return (preBit == '1') ? '0' : '1'; // Invert the bit as per the sequence rules.
    
}
