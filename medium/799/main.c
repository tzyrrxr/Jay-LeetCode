double champagneTower(int poured, int query_row, int query_glass){
  double glass[5050] = {0};
  int thisGlass = (query_row+1) * query_row / 2 + query_glass;

  glass[0] = poured;
  for (int i = 1; i < 100; i++) {
    int base = (i+1)*(i)/2;

    for (int j = 0; j < i+1; j++) {
      if (j == 0) {
        glass[base+j] = fmax(0, (double)(glass[base-i+j]-1)/2);
      } else if (j == i) {
        glass[base+j] = fmax(0, (double)(glass[base-i+j-1]-1)/2);
      } else {
        glass[base+j] = fmax(0, (double)(glass[base-i+j]-1) / 2) + fmax(0, (glass[base-i+j-1]-1)/2);
      }
      if (thisGlass == base+j) {
        break;
      }
    }

  }

  return fmin (glass[thisGlass], 1);

}
