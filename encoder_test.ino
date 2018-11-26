#include<Encoder.h>
Encoder myEnc1(2, 3);
 int in1=6;
int in2=7;
int pwmpin=5;
long sen=0; 
void setup() {
  Serial.begin(9600);
pinMode(in1,OUTPUT);
 pinMode(in2,OUTPUT);
 pinMode(pwmpin,OUTPUT);
    // put your setup code here, to run once:

}

void loop() {
  analogWrite(pwmpin,150);
  digitalWrite(in2,HIGH);
  digitalWrite(in1,LOW);
  sen=myEnc1.read();
  Serial.println(sen);
  delay(1000);
  }
