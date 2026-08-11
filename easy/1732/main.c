int largestAltitude(int* gain, int gainSize) {
  int highest = 0;

  for (int i = 0, altitude = 0; i < gainSize; i++) {
    altitude += gain[i];
    if (altitude > highest) {
      highest = altitude;
    }
  }

  return highest;
    
}
