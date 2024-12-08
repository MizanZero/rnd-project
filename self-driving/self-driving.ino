
#include <Servo.h>
#include <NewPing.h>
#include <AFMotor.h>
#include <string.h>

#include <C:/Users/Mizan/Documents/RnD Project/self-driving/movement.h>

Servo srv;


bool timerRunning(int startTime,int duration){
 delay(10);
 if(millis()-startTime<duration){
  return true;
 }
 return false;
}

string scout(int distFront,bool ir=false){//returns the type of blockage
 if(ir==false){
  if(distFront>=PREVENTABLE_DISTANCE){
   return "preventable"; 
  }
  else if(distFront<=PREVENTABLE_DISTANCE && distFront>=LESS_PREVENTABLE_DISTANCE){
   return "less preventable";
  }
  else if(distFront<=SAFE_DISTANCE){
   return "too close";
  }
  }
 }
 }


void loop(){
 delay(1000);
 if(irClear()==false){
  halt();  
 }
 distFront=ult.dist();
 if(distFront<safeDist){
  avoid(scout());
 }
 moveForward();
 
}


void avoid(string obstructType){
 switch(obstructType){
  case "preventable":
   prevent();
  case"less preventable":
   slowPrevent();
  case "too close":
   halt();
  case "entered large room":
   reverse(); //already contains stop()
  case "realised large room":
   navigate();
  case "small object":
   blindNavigate();
}//avoid function


int* irClear(){
 frontIr=digitalRead(frontIrPin);
 backIr=digitalRead(backIrPin);
 leftIr=digitalRead(leftIrPin);
 rightIr=digitalRead(rightIrPin);
 ir[]={-1,frontIr,backIr,leftIr,rightIr}

 if(ir!={-1,0,0,0,0}){
  return false;
 }

 return ir;

}//Ir function


void prevent(string dir){
 speed(MIN_SPEED);
 srv.write(slightLeft);
 slDist=ult.getDist();
 srv.write(slighRight)
 srDist=ult.getDist();

 if(srDist>=slDist){
  turn("sr");
  delay(avdSep/speed);
  turn("sl");
  position=1 }
 else{
  turn("sl");
  delay(avdSep/speed);
  turn("sr");
  position=-1; }

  if(passiveLookout()!=clear){
   switch(position){
    case 1: turn("left"); delay(avdSep/speed);
            turn("right");

    case -1: turn("right"); delay(avdSep/speed);
	     turn("left"); }/*switch end*/
   }//if end
  else{}
}//end of prevent function


void halt(){
 stop();
 reverse();
 prevent(); }



void navigate(string dir,
              int round=1){

 if (round>2){
  emergency(); round=1;
  break;
 }
 turn(dir);
 srv.write(oppDir); //opposite direction here
 forward(); //medium speed

 while(wallInFront,
       timer(startTime,WALL_SCAN_DURATION)){
  startTime=millis();
  endTime=millis();
 }


 if(!timer(startTime,endTime)){
  break;

 else{
  round=2; turn(oppDir); srv(dir);
  forward(MAX_SPEED,
          MIN_SPEED*(endTime-startTime))
  navigate(oppDir);
 }
}

















