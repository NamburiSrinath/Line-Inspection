
#include<Encoder.h>

const long ppr=88560;

Encoder myEnc1(2, 3);
//Encoder myEnc2(8, 9);
//Input variables
long stp,err,lse,sumer,diff,e=0,p,i,d,dse,senso;
int pwm,minpwm,mxpwm,j,egg,dir,y;
double kp,ki,kd,sen,seno;
//Motor pins
//int dirpin=2;.

int in1=6;
int in2=7;
int pwmpin=5;


void setup() 
{
//Setting Serial communication   
    Serial.begin(9600);
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
   int a=Serial.parseInt();

   if(a==1) e+=30;
   if(a==0) e-=30;
   stp=e*(ppr/360);}
// encoder measure data
  sen=abs(myEnc1.read());
//  senso=myEnc2.read();
//PID calculation
  err=stp-sen;

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
 Serial.println("values");
 Serial.print("p");Serial.print(" ");Serial.println(p);
 Serial.print("i");Serial.print(" ");Serial.println(i);
 Serial.print("d");Serial.print(" ");Serial.println(d);
 Serial.print("pwm");Serial.print(" ");Serial.println(pwm);
 Serial.print("sen, read value");Serial.print(" ");Serial.println(sen);
 Serial.print("seno");Serial.print(" ");Serial.println(seno);
 Serial.print("err");Serial.print(" ");Serial.println(err);
 //Serial.println("p");Serial.print(" ");Serial.print(p);
 //Serial.println("p");Serial.print(" ");Serial.print(p);
 //Serial.println("p");Serial.print(" ");Serial.print(p);
//motor actuation criteria
if(abs(err)<5)
{//if this criteria is met motor stop
  pwm=0;
 sumer=0;
// digitalWrite(dirpin,HIGH);

digitalWrite(in2,HIGH);
digitalWrite(in1,LOW);


 analogWrite(pwmpin,pwm);
 Serial.println('7');
  egg=0;
  dir=0;
}
/*else if(abs(seno-sen)<20&&(pwm==mxpwm))
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
 Serial.println('8');
 }
 }*/
//way motor actuates
 else
 { 
  if(err<0)
 {
   dir=-1;
   digitalWrite(in1,LOW);
   digitalWrite(in2,HIGH);
Serial.println("erro");
  // digitalWrite(dirpin,HIGH);
   analogWrite(pwmpin,pwm);
    egg=0;
    Serial.println('9');
 }
 if(err>0)
 {
      dir=1;
      digitalWrite(in2,LOW);
      digitalWrite(in1,HIGH);
  // digitalWrite(dirpin,HIGH);
      //digitalWrite(dirpin,LOW);
       analogWrite(pwmpin,pwm);
       egg=0;
       Serial.println("10");
   }
   }
   seno=sen;
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


