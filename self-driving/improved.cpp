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
 srv.write(slightLeft);
 slDist=ult.getDist();
 srv.write(slighRight)
 srDist=ult.getDist();
 if(srDist)

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



void blindNavigate(String dir,int round=1){
 if (round==2){
  emergency();
  break;
 }
 int timeTaken=0;
 turn(dir);
 srv.write(dir);
 forward();

 while(wallInFront){
  previousTime=millis();

  while(dist>=MIN_DIST){
   if(timer(CAR_LEN/speed)){
    wallInFront=false; }
   else if(checkIr()!=[-1,0,0,0,0]){
    avoid();
   else if(timer(WALL_TOO_LONG){
    round++;
    turn("rotateLeft");
    blindNavigate("rotateLeft"); }
 }
}

