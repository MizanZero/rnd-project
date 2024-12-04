void loop(){

 d=ult.getDist();
 delay(10);

 avoid(detectAt(d));
}


void avoid(int lvl){
 switch(scout()){
  case "small room":
   prevent();
  case "too close":
   halt();
  case "entered large room":
   reverse(); //already contains halt()
  case "large room":
   navigate();
}}


