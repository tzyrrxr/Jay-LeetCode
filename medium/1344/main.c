double angleClock(int hour, int minutes) {
  double min_angle = 360 * (minutes/60.0);
  double hr_angle = (hour%12) * 30 + 30 * (minutes/60.0);
  double ret_angle = min_angle > hr_angle ? min_angle - hr_angle : hr_angle - min_angle;

  return ret_angle > 360 - ret_angle ? 360 - ret_angle : ret_angle;
    
}
