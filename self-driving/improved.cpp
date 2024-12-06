bool timer(int startTime,int duration){}



String scout(){//returns the type of blockage
 }


void loop(){

 ir[]=checkIr();
 passiveLookout();
 start(d);
 ir=checkIr();
 avoid(ir);


}


void avoid(String obstructType){
 switch(obstructType){
  case "preventable":
   prevent();
  case "too close":
   halt();
  case "entered large room":
   reverse(); //already contains stop()
  case "realised large room":
   navigate();
  case "small object":
   blindNavigate();
}//avoid function


int* checkIr(){
 frontIr=digitalRead(frontIrPin);
 backIr=digitalRead(backIrPin);
 leftIr=digitalRead(leftIrPin);
 rightIr=digitalRead(rightIrPin);
 ir[]={-1,frontIr,backIr,leftIr,rightIr}

 for(int i=1; i<=4; i++){
  if(ir[a]==1){
   stop(); }//if end
}//for end

 return ir;

}//Ir function


void prevent(String dir){
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



void navigate(String dir,
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

















