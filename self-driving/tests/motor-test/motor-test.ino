#include <C:/Users/Mizan/Documents/RnD project/self-driving/movement.h>

void setup(){
  /*moveForward();
  delay(1000);
  moveStop();*/
}

void loop(){
  moveForward();
  delay(5000);
  moveStop();
  delay(1000);
  moveBackward();
  delay(5000);
  moveStop();
  delay(1000);
}

