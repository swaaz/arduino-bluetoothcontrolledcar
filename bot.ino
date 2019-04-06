//speed of motors betwen 0 and 255, if you like you can change it
int pwm_speedA = 255;
int pwm_speedB = 255;
char command;
 
void setup() {
Serial.begin(9600);
//pins for motor controller 
pinMode(12, OUTPUT); //motordrive-2-leftside-behind-reverse
pinMode(11, OUTPUT); //motordrive-2-leftside-behind-forward
pinMode(10, OUTPUT); //motordrive-2-leftside-front-reverse
pinMode(9, OUTPUT); //motordrive-2-leftside-front-forward
pinMode(8, OUTPUT); //motordrive-1-rightside-front-reverse
pinMode(7, OUTPUT); //motordrive-1-rightside-front-forward
pinMode(6, OUTPUT); //motordrive-1-rightside-behind-reverse
pinMode(5, OUTPUT); //motordrive-1-rightside-behind-forward
pinMode(A0, OUTPUT); //analogpin-motordrive-1-right
pinMode(A1, OUTPUT); //analogpin-motordrive-1-left
pinMode(A2, OUTPUT); //analogpin-motordrive-1-right
pinMode(A3, OUTPUT); //analogpin-motordrive-1-left


}
 
void loop() {
 
if(Serial.available() > 0){
command = Serial.read();
Serial.println(command);
motors_stop();
switch(command){
case 'F':
forward();
break;
case 'B':
backward();
break;
case 'G':
fleft();
break;
case 'I':
fright();
break;
case 'R' :
spot_right(); 
break;
case 'L' :
spot_left(); 
break;
case 'H':
bleft();
break;
case 'J':
bright();
break;
default :
motors_stop();
break; 
}
}
 
}






// function for driving straight
void forward(){



digitalWrite(12, LOW);
digitalWrite(11, HIGH);
digitalWrite(10, LOW);
digitalWrite(9, HIGH);
digitalWrite(8, LOW);
digitalWrite(7, HIGH);
digitalWrite(6, LOW);
digitalWrite(5, HIGH);

analogWrite(A0, pwm_speedA);
analogWrite(A1, pwm_speedB); 
analogWrite(A2, pwm_speedA);
analogWrite(A3, pwm_speedB);

}
  
//function for reversing
void backward(){
 



digitalWrite(12, HIGH);
digitalWrite(11, LOW);
digitalWrite(10, HIGH);
digitalWrite(9, LOW);
digitalWrite(8, HIGH);
digitalWrite(7, LOW);
digitalWrite(6, HIGH);
digitalWrite(5, LOW);

analogWrite(A0, pwm_speedA);
analogWrite(A1, pwm_speedB); 
analogWrite(A2, pwm_speedA);
analogWrite(A3, pwm_speedB);


}
 
//function for turning left
void fleft(){
digitalWrite(12, LOW);
digitalWrite(11, LOW);
digitalWrite(10, LOW);
digitalWrite(9,  LOW);
digitalWrite(8, LOW);
digitalWrite(7, HIGH);
digitalWrite(6, LOW);
digitalWrite(5, HIGH);

analogWrite(A0, pwm_speedA);
analogWrite(A1, pwm_speedB);
analogWrite(A2, pwm_speedA);
analogWrite(A3, pwm_speedB);
}

void spot_left()
{
digitalWrite(12, HIGH);
digitalWrite(11, LOW);
digitalWrite(10, HIGH);
digitalWrite(9, LOW);
digitalWrite(8, LOW);
digitalWrite(7, HIGH);
digitalWrite(6, LOW);
digitalWrite(5, HIGH);

analogWrite(A0, pwm_speedA);
analogWrite(A1, pwm_speedB);
analogWrite(A2, pwm_speedA);
analogWrite(A3, pwm_speedB);
}
 
//function for turning right
void fright(){
digitalWrite(12, LOW);
digitalWrite(11, HIGH);
digitalWrite(10, LOW);
digitalWrite(9, HIGH);
digitalWrite(8, LOW);
digitalWrite(7, LOW);
digitalWrite(6, LOW);
digitalWrite(5, LOW);

analogWrite(A0, pwm_speedA);
analogWrite(A1, pwm_speedB);
analogWrite(A2, pwm_speedA);
analogWrite(A3, pwm_speedB);
}

void spot_right()
{
digitalWrite(12, LOW);
digitalWrite(11, HIGH);
digitalWrite(10, LOW);
digitalWrite(9, HIGH);


digitalWrite(8, HIGH);
digitalWrite(7, LOW);
digitalWrite(6, HIGH);
digitalWrite(5, LOW);

analogWrite(A0, pwm_speedA);
analogWrite(A1, pwm_speedB);
analogWrite(A2, pwm_speedA);
analogWrite(A3, pwm_speedB);
}
void bright()
{
digitalWrite(12, HIGH);
digitalWrite(11, LOW);
digitalWrite(10, HIGH);
digitalWrite(9, LOW);


digitalWrite(8, LOW);
digitalWrite(7, LOW);
digitalWrite(6, LOW);
digitalWrite(5, LOW);

analogWrite(A0, pwm_speedA);
analogWrite(A1, pwm_speedB);
analogWrite(A2, pwm_speedA);
analogWrite(A3, pwm_speedB);
}
void bleft()
{
digitalWrite(12, LOW);
digitalWrite(11, LOW);
digitalWrite(10, LOW);
digitalWrite(9, LOW);


digitalWrite(8, HIGH);
digitalWrite(7, LOW);
digitalWrite(6, HIGH);
digitalWrite(5, LOW);

analogWrite(A0, pwm_speedA);
analogWrite(A1, pwm_speedB);
analogWrite(A2, pwm_speedA);
analogWrite(A3, pwm_speedB);
}
//function for stopping motors


void motors_stop(){
digitalWrite(12, LOW);
digitalWrite(11, LOW);
digitalWrite(10,LOW);
digitalWrite(9, LOW);
 


digitalWrite(8, LOW);
digitalWrite(7, LOW);
digitalWrite(6,LOW);
digitalWrite(5, LOW);


analogWrite(A0, 0);
analogWrite(A1, 0); 
analogWrite(A2, 0);
analogWrite(A3, 0);

}
