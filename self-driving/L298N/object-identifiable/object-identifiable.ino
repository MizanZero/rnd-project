#define ENA 
#define IN1 
#define IN2 
#define ENB 
#define IN3 
#define IN4 



const int MAX_PWM = 150; 
const int DEFAULT_RADIUS=18; 

void stop();
void setPwm(int pwmA, int pwmB);
void forward(int pwm, int duration); 
void backward(int pwm, int duration); 
void left(int radius, int duration); 
void right(int radius, int duration); 



void setup(){
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  stop();
}



void stop(){
  setPwm(0, 0);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}



void setPwm(int pwmA, int pwmB){
  for(int i=0; i<=pwmA; i++){
    analogWrite(ENA, i);
  }
  for(int i=0; i<=pwmB; i++){
    analogWrite(ENB, i);
  }
}



void forward(int pwm=100, int duration=0){
  analogWrite(ENA, pwm);
  analogWrite(ENB, pwm);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  if(duration!=0){
    delay(duration); stop();
  }
}



void right(int radius=DEFAULT_RADIUS, int duration=0){
  setPwm()
}


void loop(){

}