#include<Servo.h>
/////////////////////////////////////////////////////

//COMING TO ROBOT AND ATTACHED TO LINE


////////////////////////////////////////////
Servo W,X,Y,Z;
int w,x,y,z,cnt =10;
char a;
void setup() {
  // put your setup code here, to run once:
W.attach(A0);
X.attach(A1);
Y.attach(A2);
Z.attach(A3);
Serial.begin(9600);
Serial3.begin(9600);//connected to 14,15 tx and rx
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
      W.write(w);
    }
    break;
    case '2':
    if(w>0)
    {
      w-=cnt;
      W.write(w);
    }
    break;
    case '3':
    if(x<180)
    {
      x+=cnt;
      X.write(x);
    }
    break;
    case '4':
    if(x>0)
    {
      x-=cnt;
      X.write(x);
    }
    break;
    case '5':
    if(y<180)
    {
      y+=cnt;
      Y.write(y);
    }
    break;
    case '6':
    if(y>0)
    {
      y-=cnt;
      Y.write(y);
    }
    break;
    case '7':
    if(z<180)
    {
      z+=cnt;
      Z.write(z);
    }
    break;
    case '8':
    if(z>0)
    {
      z-=cnt;
      Z.write(z);
    }
    break;
    case '9': //sending data to arduino uno....to be checked in encoder code........
    Serial3.println('9');//sending data to arduino uno....to be checked in encoder code........
    break;
    case 'a':
    Serial3.println('a');//sending data to arduino uno....to be checked in encoder code........
    break;
    case 'b':
    Serial3.println('b');//sending data to arduino uno....to be checked in encoder code........
    break;
  }
}
}
