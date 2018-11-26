#include<Servo.h>
#include<SoftwareSerial.h>
 
 //SoftwareSerial BTSerial(19,18); //RX|tx         
int h,l,dly=50; // hold and leave angles for servo of both hands. delay for waiting for serial input

int in1=40,in2=41,in3=42,in4=43,in5=44,in6=45,in7=46,in8=47;//pulley motors
int cnt=10,w=40,x=40,y=40,z=40,hold1=0,leave1=38,sA=40,sB=40,sC=40,sD=40,hold2=45,leave2=0,DC1=0,DC2=0;

void pol1(int e)//data to encoder1 motor
{ Serial1.println(e);
Serial.println(e);
}

void pol2(int e)//data to encoder2 motor
{Serial2.println(e);
Serial.println(e);} 
 
 void dc(int a,int b)//to run any motor
 { digitalWrite(a,HIGH);
   digitalWrite(b,LOW);
    Serial.print("Run dc with high  ");
   Serial.print(a);
   Serial.print("  LOW  ");
   Serial.println(b);
      
  }

 void stp()                   // stop all dc motors
 {digitalWrite(in1,LOW);//pulleys till in8
   digitalWrite(in2,LOW);
   digitalWrite(in3,LOW);
   digitalWrite(in4,LOW);
   digitalWrite(in5,LOW);
   digitalWrite(in6,LOW);
   digitalWrite(in7,LOW);
   digitalWrite(in8,LOW);
//
//   digitalWrite(in9,LOW);
//   digitalWrite(in10,LOW);
//   digitalWrite(in12,LOW);
//   digitalWrite(in11,LOW);

   digitalWrite(22,LOW);//22-23(forward)
   digitalWrite(23,LOW);
   digitalWrite(24,LOW);//24-25(closing mechanism)
   digitalWrite(25,LOW);

    digitalWrite(26, LOW);// 26-27(closing)stopping the horizontal dc when the line is held
    digitalWrite(27, LOW);
    digitalWrite(28, LOW);//28-29(forward)
    digitalWrite(29, LOW);
   Serial.println("stop dcs");
  }
    
  Servo s1, s2;   // for A side
  Servo s3;  // for B side
  Servo sa,sb,sc,sd,h2;  //arm 2 
  Servo W,X,Y,Z,h1;  //arm 1
   
  int u,i,o;
  int pos1=0 , pos2=10, pos3=0, pos4=0 ;  // A:H   A:V   B:H   B:V  respectively
  int a=0, b=0,c=0,zzz=0;
  void intrrpta(),intrrptb();
 
  void setup()
  {
    Serial2.begin(9600);
    Serial1.begin(115200);
     Serial3.begin(9600);
//   Serial3.begin(57600);
    Serial.begin(9600);
   // Serial2.begin(9600);
    
    //attachInterrupt(digitalPinToInterrupt(20),intrrpta, RISING);
    //attachInterrupt(digitalPinToInterrupt(21),intrrptb, RISING);
    
    s1.attach(A5);// horizontal servo A side closing
    s2.attach(9);//A side locking
    s3.attach(12);// horizontal servo B side closing                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        ); 
    //s4.attach(10);//B side locking
    W.attach(A0);
    X.attach(A1);
    Y.attach(A2);
    Z.attach(A3);
   // DC1,
   h1.attach(A4);// gripper

   sa.attach(A6);
   sb.attach(A7);
   sc.attach(7);
   sd.attach(8); //dc2
   h2.attach(11); // gripper
    
    s1.write(pos1);         // for the initial angles of the servos 
    s2.write(pos2);
 
    s3.write(pos3);
    //s4.write(pos4);

    pinMode(43,OUTPUT);
  
    pinMode(30, OUTPUT);   //dc1  
    pinMode(31, OUTPUT);           // going to one motor driver   //horizontal servos
    pinMode(32, OUTPUT);   //dc2
    pinMode(33, OUTPUT);  
    
    pinMode(34, OUTPUT);   //dc3
    pinMode(35, OUTPUT);           // going to another motor driver  // vertical servos for moving f/w or b/w 
    pinMode(36, OUTPUT);   //dc4
    pinMode(37, OUTPUT);
    pinMode(13, OUTPUT);

    pinMode(40, OUTPUT);
    pinMode(41, OUTPUT);
    pinMode(42, OUTPUT);
    pinMode(43, OUTPUT);
    pinMode(44, OUTPUT);
    pinMode(45, OUTPUT);
    pinMode(46, OUTPUT);
    pinMode(47, OUTPUT);
    pinMode(26, OUTPUT);
    pinMode(27, OUTPUT);
    pinMode(30, OUTPUT);
    pinMode(31, OUTPUT);
   // pinMode(32, OUTPUT);
    //pinMode(33, OUTPUT);
    pinMode(5, OUTPUT);
    pinMode(8, OUTPUT);
    pinMode(11, OUTPUT);
    pinMode(10, OUTPUT);
    pinMode(12, OUTPUT);
analogWrite(11, 255);
   
    
   
//    pinMode(46,OUTPUT); //enable pins
//    pinMode(47,OUTPUT);
//    pinMode(48,OUTPUT);
//    pinMode(49,OUTPUT);
   while (! Serial); 
   Serial.println("wht to do");
   Serial.println();
  }

  void loop()
  { 
    if(Serial.available()>0)
    {
      u=Serial.parseInt();
      Serial.println(u);

    
       switch(u)
       { 
         
         case 4:    // HOLD
          //dc(25,24);//running to close and held the line
          b=0; a=0; 
          //dc(27,26);//running to close and held the line
          while(a==0 || b==0)
         {
          if(Serial.available()) 
         break;

          if(b!=0)
           { 
            digitalWrite(26, LOW);//stopping held
            digitalWrite(27, LOW);
            }

           if(a!=0)
            { 
              digitalWrite(25, LOW);//stop held
             digitalWrite(24, LOW);}
       
             }
            // giving high signals to horizontal dc for holding the line 
           
          
            //            a=1;  b=1;

            Serial.println("Both motors stopped");
            digitalWrite(24, LOW);    // stopping the horizontal dc when the line is held
            digitalWrite(25, LOW);
            digitalWrite(26, LOW);
            digitalWrite(27, LOW);
            Serial.println("ok");

       
            s3.write(70);//locking using servos
            delay(1500);
            s1.write(90);
            delay(1500);
            //s4.write(0); 
            //delay(1500);
            s2.write(70);
            delay(1500);
       /*for(pos1=5 ; pos1<= 35  ; pos1++)     // horizontal servo side A
        {
          s1.write(pos1);
          delay(50);
        } Serial.println("S1 completed");
    
       for(pos3= 10; pos3<= 55  ; pos3++)     // horizontal servo side B
        {
          s3.write(pos3);
          delay(50);
        }
     
       for(pos2= 5; pos2<= 70 ; pos2++)     // vertical servo side A
        {
          s2.write(pos2);
          delay(50);
        }
    
    
       for(pos4= 10; pos4<=85   ; pos4++)     // vertical servo side B
        {
          s4.write(pos4);
          delay(50);
        }*/
    /*   digitalWrite(42, LOW); 
       digitalWrite(41, LOW);
       digitalWrite(43, LOW); 
       digitalWrite(40, HIGH);     //showing that the robot is ready 
      }*/
     break ;
       }
    }
  }
