

ir[]={-1,0,0,0,0}

#include <Servo.h>
#include <NewPing.h>
#include <AFMotor.h>
#include <string.h>

#include <C:/Users/Mizan/Documents/RnD Project/self-driving/movement.h>

Servo srv; 


bool timerRunning(int startTime,int duration){
 if(millis()-startTime<duration){
  return true;
 }
 return false;
}

string scout(int distFront,bool ir=false){//returns the type of blockage
 if(ir==false){
  if(distFront>=PREVENTABLE_DISTANCE){
   return "";
  }
  else if(distFront<=PREVENTABLE_DISTANCE && distFront>=LESS_PREVENTABLE_DISTANCE){
   return "preventable";
  }
  else if(distFront<=PREVENTABLE_DISTANCE && distFront>=SAFE_DISTANCE){
   return "less preventable";
  }
  else if(distFront<=SAFE_DISTANCE){
   return "too close";
  else if(){
   return "entered large room";
  }
  else if(){
   return "realised large room/large object";
  }
  else if(){
   return "ir level object";
  }
  }
 }
}
 }


void loop(){
 delay(50);
 if(!irClear()){
  wallNavigate();
 }
 distFront=ult.dist();
 if(distFront<AVOIDABLE_DISTANCE_MAX){
  avoid(scout());
 }
 moveForward();

}


void avoid(string obstructType){
 switch(obstructType){
  case "preventable":
   prevent();
  case "less preventable":
   slowPrevent();
  case "too close":
   halt();
  case "entered large room":
   reverse(); //already contains stop()
  case "realised large room/large object":
   navigate();
  case "ir level object":
   blindNavigate();
}//end of avoid function


bool irClear(){
 frontIr=digitalRead(frontIrPin);
 backIr=digitalRead(backIrPin);
 leftIr=digitalRead(leftIrPin);
 rightIr=digitalRead(rightIrPin);
 ir[]={-1,frontIr,backIr,leftIr,rightIr}

 if(ir!={-1,0,0,0,0}){
  return false;
 }

 return true;

}//Ir function


void prevent(string dir){
 speed(MIN_SPEED);
 srv.write(slAngle);
 slDist=ult.getDist();
 srv.write(srAngle)
 srDist=ult.getDist();

 if(srDist>=slDist){
  turn("lsRight");
  position=1 }
 else if(srDist<=slDist){
  turn("lsLeft");
 }
 else{
  turn("lsRight")
  position=-1; }

  if(passiveLookout()!="clear"){
   switch(position){
    case 1: turn("left"); srv.write("right"); forward();

    case -1: turn("right"); srv.wite("left"); backward(); }//switch end
   
   }//if end
}//end of prevent function


void halt(){
 stop();
 reverse();
 prevent(); }



void navigate(string dir="rotateRight",
              int round=1){
 if (round>2){
  emergency(); round=1;
  break;
 }

 else{
 turn(dir);
 srv.write(oppDir); //opposite direction here
 forward(); //medium speed


  if(passiveLookout()!="clear"){
   switch(position){
    case 1: turn("left"); srv.write("right"); forward();

    case -1: turn("right"); srv.wite("left"); backward(); }//switch end

  while(wallInFront){
    while(ult.getDist()>=AVOIDABLE_DISTANCE_MIN){ 
      startTime=millis();
      delayWithIr(startTime,SEPARATION_TIME_MIN);
    }
  }

   }
  }
  position=0;            }

bool delayWithIR(int duration){
 int startTime=millis();
 while(timerRunning(startTime,duration)){
  if (!irClear()){
   halt();
}
}
}


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
 digitalWrite(servo,flAngle); delay(300)
 flDist=dist();
 digitalWrite(servo,rlAngle);
 rlDist()=dist();
 if(flDist>=SEP_MIN && rlDist>=SEP_MIN){
  if(flDist>=rlDist){
   turn("lsLeft");
   forward();
}
}
}


