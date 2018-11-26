#include<Servo.h>
//////////////////////////


//Arm EXTENDS TO MAXIMUM and gets attached to sagging line.......

///////////////////////
Servo sa,sb,sc,sd,h2;
int w,x,y,z,cnt =10;
char a,b;
void setup() {
  // put your setup code here, to run once:
sa.attach(A6);
sb.attach(A7);
sc.attach(7);
sd.attach(8);
h2.attach(11);
Serial.begin(9600);
Serial2.begin(9600);
//Serial3.begin(9600);...........16,17 tx and rx pins
//Servo left arm are A0,A1,A2,A3,.......GRIPPER1 TO J17(ie to arduino A4)
//Servo right arm GRIPPER 2 TO J28(ie arduino 11).....A6,A7,7,8
}

void loop() {
  // put your main code here, to run repeatedly:
if(Serial.available())
{
  a=Serial.read();
  switch(a)
  {
    case '1':
    if(w<180)
    {
      w+=cnt;
      sa.write(w);
    }
    break;
    case '2':
    if(w>0)
    {
      w-=cnt;
      sa.write(w);
    }
    break;
    case '3':
    if(x<180)
    {
      x+=cnt;
      sb.write(x);
    }
    break;
    case '4':
    if(x>0)
    {
      x-=cnt;
      sb.write(x);
    }
    break;
    case '5':
    if(y<180)
    {
      y+=cnt;
      sc.write(y);
    }
    break;
    case '6':
    if(y>0)
    {
      y-=cnt;
      sc.write(y);
    }
    break;
    case '7':
    if(z<180)
    {
      z+=cnt;
      sd.write(z);
    }
    break;
    case '8':
    if(z>0)
    {
      z-=cnt;
      sd.write(z);
    }
    break;
    case '9':
    // b=Serial.read();
     Serial2.println('9');
     //Serial.println('a');
     break;
     case 'a':
     Serial2.println('a');
     break;  
     case 'b':
     //b=Serial.parseInt();
     Serial2.println('b');
     
     break;   
  }
}
}
