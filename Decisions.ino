/*
 * First draft. Not tested
 * 
 * 
 * 
 */


void decision() {
   if (pan_angle < 90 && distance < 20) {
      right();
   }

   else if (pan_angle > 90 && distance < 20) {
     left();
   }

   else {
     forward();
   }

}




/*
 * //Old decision function
void decision() { //Move foward if distance is higher than preset minimum distance on both sides
  while (distance_l < sensor_distance && distance_r < sensor_distance && distance_combined != 0) {    //Revere
    reverse();
    prints();
    ultra_scan();
 }

  if (distance_r < sensor_distance && distance_r != 0) {
    left();
  }
  else if (distance_l < sensor_distance && distance_l != 0) {
    right();
  }
 
  else if (distance_l > sensor_distance && distance_r > sensor_distance) {
    forward();
  }
   else{     //Move forward if both sensors return 0 (out of range)
    forward();
  
  }
}

*/
