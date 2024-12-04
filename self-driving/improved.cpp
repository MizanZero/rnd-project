void loop(){

 d=ult.getDist();
 delay(10);

 avoid(detectAt(d));
}


void avoid(int lvl){
 switch(lvl){
  case 1:
   prevent();
  case 2:
   halt();
  case 3:
   reverse(); //already contains halt()
  case 4:
   navigate();
}}

void detectAt(float d){
 if(d>=200){
  return 1; }
 else if(d >= 10){
  return 2; }
 else if(scout()=="Small room"){
  return 3; }
 else 
