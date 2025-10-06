int maxArea(int* height, int heightSize) {
  int h, l, r, area;

  l = 0;
  r = heightSize - 1;
  area = 0;

  while (l < r) {
    h = height[l] < height[r] ? height[l] : height[r];

    if (h * (r - l) > area) {
      area = h * (r - l);
    }
    if (height[l] < height[r]) {
      l++;
    } else {
      r--;
    }
  }

  return area;

}
