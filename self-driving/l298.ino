const int LANE_SWITCH_TIME;
const int servo;
const int flAngle;
const int rlAngle;
const int rlDist;
const int flDist;


void turn(string dir){
  switch(dir){
    case "left":
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 150);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENB, 80);

    case "right":
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENB, 150);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 80);

    case "lsRight":
  turn("right"); delay(LANE_SWITCH_TIME/2);
  turn("left"); delay(LANE_SWITCH_TIME/2);

    case "lsLeft":
  turn("left"); delay(LANE_SWITCH_TIME/2);
  turn("right"); delay(LANE_SWITCH_TIME/2);

  }
}



void loop(){
 frontDist=dist();
 if(frontDist<=SAFE_DISTANCE){
  prevent();
}
}



void prevent(){
 digitalWrite(servo,flAngle); delay(300) //fornt left
 flDist=dist();
 digitalWrite(servo,rlAngle); //front left
 rlDist()=dist();
 if(flDist>=SEP_MIN && rlDist>=SEP_MIN){
  if(flDist>=rlDist){
   turn("lsLeft");
   forward();
}
}
}



