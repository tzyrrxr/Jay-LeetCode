bool judgeCircle(char* moves) {
  int x = 0, y = 0;
  for (int i = 0; moves[i]; i++) {
    switch (moves[i]){
      case 'U':
        y++;
        break;
      case 'D':
        y--;
        break;
      case 'R':
        x++;
        break;
      case 'L':
        x--;
        break;

      default:
        break;
    }
  }

  return !(x||y);
    
}
