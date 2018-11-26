
#include<Encoder.h>

const long ppr=88560;

Encoder myEnc1(2, 3);
//Encoder myEnc2(8, 9);
//Input variables
long stp=0,err,lse,sumer,diff,e=0,p,i,d,dse,senso;
int pwm,minpwm,mxpwm,j,egg,dir,y;
double kp,ki,kd,sen,seno;
//Motor pins
//int dirpin=2;.

int in1=7;
int in2=6;
int pwmpin=5;

void setup() 
{
//Setting Serial communication   
    Serial.begin(38400);
       // Serial.println("st:");
    //Motor pins enabled as output
    pinMode(in1,OUTPUT);
    pinMode(in2,OUTPUT);
    pinMode(pwmpin,OUTPUT);
   //inital contdtion for each start of motor
     sumer=0;
     lse=0;
     err=0;
    stp=0;
   //Declaring PID constants for loop
    kp=0.1;
    ki=0.000;  //.001*0.43398;
    kd=0.0000000;
  //Define maximum and minimum & maximum pwm values
    minpwm=1;
    mxpwm=255;
    j=0;
    dir=0;
}
////////////////////////////////////////…………Loop……………////////…/////////////////////////////



 
void loop()
 {
    //Data collection
    if(Serial.available()>0)
{
   char a=Serial.read();

   if(a=='a') e+=30;
   if(a=='b') e-=30;
   stp=e*(ppr/360);}
// encoder measure data
  sen=myEnc1.read();
//  senso=myEnc2.read();
//PID calculation
  err=stp-sen;
  Serial.println(err);
dse=err-lse;
  p=kp*(err);
  i=ki*sumer;
 d=kd*(dse);
 pwm=p+i+d;
 sumer+=err;
 lse=err;
 pwm=abs(pwm);
//limiting the PWM
if (pwm<minpwm)
{
  pwm=minpwm;
}
if(pwm>mxpwm)
{
    pwm=mxpwm;
 }
//motor actuation criteria
if(abs(err)<5)
{//if this criteria is met motor stop
  pwm=0;
 sumer=0;
// digitalWrite(dirpin,HIGH);
 analogWrite(pwmpin,pwm);
digitalWrite(in2,HIGH);
digitalWrite(in1,LOW);



  egg=0;
  dir=0;
}
else if(abs(seno-sen)<20&&(pwm==mxpwm))
  {
    //fault detection if met motor stop
     j++;
     if(j>60)
  {
  pwm=0;
 sumer=0;
  j=0;
 dir=2;
 egg=1;
 }
 }
//way motor actuates
 else
 { 
  if(err<0)
 {
   dir=-1;
   analogWrite(pwmpin,pwm);
   digitalWrite(in1,HIGH);
   digitalWrite(in2,LOW);

  // digitalWrite(dirpin,HIGH);
   
    egg=0;
 }
 if(err>0)
 {
      dir=1;
      analogWrite(pwmpin,pwm);
      digitalWrite(in2,HIGH);
      digitalWrite(in1,LOW);

      //digitalWrite(dirpin,LOW);
       
       egg=0;
   }
   }
  // seno=sen;
 //sample time for frequency .01Hz
 delay(10);
 /*Serial.print(stp);
 Serial.print("\t");
 Serial.print(sen);
 Serial.print("\t");
 Serial.print((err*360)/ppr);
 Serial.print("\t");
 Serial.print(pwm);
 Serial.print("\t");
 Serial.print(egg);
 Serial.print("\t");
 Serial.print(senso);
 Serial.print("\t");
 Serial.println(dir);*/
}


