//speed of motors betwen 0 and 255, if you like you can change it
int pwm_speedA = 255;
int pwm_speedB = 255;
char command;
 
void setup() {
Serial.begin(9600);
//pins for motor controller 
pinMode(12, OUTPUT);
pinMode(11, OUTPUT);
pinMode(10, OUTPUT);
pinMode(9, OUTPUT);
pinMode(8, OUTPUT); 
pinMode(7, OUTPUT);
pinMode(6, OUTPUT);
pinMode(5, OUTPUT);
pinMode(A0, OUTPUT); 
pinMode(A1, OUTPUT);
pinMode(A2, OUTPUT);
pinMode(A3, OUTPUT);


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
