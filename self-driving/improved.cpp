void loop(){

 ir[]=checkIr();
 passiveLookout();
 start(d);
 ir=checkIr();
 avoid(ir);


}


void avoid(){
 switch(scout()){
  case "preventable":
   prevent();
  case "too close":
   halt();
  case "entered large room":
   reverse(); //already contains halt()
  case "realised large room":
   navigate();
}//avoid function


int* checkIr(){
 frontIr=digitalRead(frontIrPin);
 backIr=digitalRead(backIrPin);
 leftIr=digitalRead(leftIrPin);
 rightIr=digitalRead(rightIrPin);
 ir[]={-1,frontIr,backIr,leftIr,rightIr}

 return ir;

}//Ir function


void prevent();
 srv.write(slightLeft);
 slDist=ult.getDist();
 srv.write(slighRight)
 srDist=ult.getDist();

 if(srDist>=slDist){
  turn("sr");
  delay(frontDist/speed);
  turn("sl"); }
 else{
  turn("sl");
  delay(frontDist/speed);
  turn("sr");


