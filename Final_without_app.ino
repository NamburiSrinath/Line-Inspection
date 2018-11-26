#include<Servo.h>
//#include<SoftwareSerial.h>
 
 //SoftwareSerial BTSerial(19,18); //RX|tx         
int h,l,dly=50; // hold and leave angles for servo of both hands. delay for waiting for serial input

int in1=40,in2=41,in3=42,in4=43,in5=44,in6=45,in7=46,in8=47;//pulley motors
int cnt=10,cnt2=40,w=40,x=40,y=40,z=40,g1=40,g2=40,hold1=0,leave1=38,sA=40,sB=40,sC=40,sD=40,hold2=45,leave2=0,DC1=0,DC2=0;

void pol1(char e)//data to encoder1 motor
{ Serial2.println(e);
Serial.println(e);
Serial.println("Given to encoder 1");
}

void pol2(char e)//data to encoder2 motor
{Serial3.println(e);
Serial.println(e);
Serial.println("Given to encoder 2");
} 
 
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
  Servo s3,s4;  // for B side
  Servo sa,sb,sc,sd,h2;  //arm 2 
  Servo W,X,Y,Z,h1;  //arm 1
 
   
  int u,i,o;
  int pos1=0 , pos2=10, pos3=0, pos4=0 ;  // A:H   A:V   B:H   B:V  respectively
  int a=0, b=0,c=0,zzz=0;
  //void intrrpta(),intrrptb();
 
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
    s4.attach(10);//B side locking
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
    s4.write(pos4);

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
case 38:
dc(28,29);
dc(22,23);
Serial.println("Forward motion");
break;
case 39:
dc(29,28);
dc(23,22);
Serial.println("reverse motion");
break;
case 80:
dc(24,25);
break;
case 81:
dc(26,27);
break;
case 82:
dc(25,24);
break;
case 83:
dc(27,26);
break;



         
         case 40:    // HOLD
          dc(24,25);//running to close and held the line
          b=0; a=0; 
          dc(26,27);//running to close and held the line
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

       
           /* s3.write(70);//locking using servos
            delay(1500);
            s1.write(0);
            delay(1500);
            s4.write(90); 
            delay(1500);
            s2.write(90);
            delay(1500);*/
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
     case 60://encoder 1 saying to stop
     Serial.println("In encoder 1 mode");
     Serial.println("motor 1 stopped");
     pol1('x');
      break;
     case 61://encoder 1 rotate forward
     pol1('y');
          Serial.println("In encoder 1 mode");
          Serial.println("motor forward");
     break;
     case 62://encoder1 rotate backward
     pol1('z');
          Serial.println("In encoder 1 mode");
     Serial.println("motor 1 back");
     break;
     case 63://encoder 2 saying to stop
     pol2('x');
          Serial.println("In encoder 2 mode");
     Serial.println("motor 2 stop");
     break;
     case 64: //encoder2 rotate forward
     pol2('y');
          Serial.println("In encoder 2 mode");
     Serial.println("motor 2 forward");
     break;
     case 65://encoder2 rotate backward
     pol2('z');
          Serial.println("In encoder 2 mode");
     Serial.println("motor 2 back");
     break;
     case 1:
    if(w<180)
    {
      w+=cnt;
      W.write(w);
      Serial.println("servo 1");
    }
    break;
    case 2:
    if(w>0)
    {
      w-=cnt;
      W.write(w);
        Serial.println("servo 1");
    }
    break;
    case 3:
    if(x<180)
    {
      x+=cnt;
      X.write(x);
    
          Serial.println("servo 2");
          }
    break;
    case 4:
    if(x>0)
    {
      x-=cnt;
      X.write(x);
            Serial.println("servo 2");
    }
    break;
    case 5:
    if(y<180)
    {
      y+=cnt;
      Y.write(y);
            Serial.println("servo 3");
    }
    break;
    case 6:
    if(y>0)
    {
      y-=cnt;
      Y.write(y);
            Serial.println("servo 3");
    }
    break;
    case 7:
    if(z<180)
    {
      z+=cnt;
      Z.write(z);
            Serial.println("servo 4");
    }
    break;
    case 8:
    if(z>0)
    {
      z-=cnt;
      Z.write(z);
            Serial.println("servo 4");
    }
    break;
    case 9:
    if(w<180)
    {
      w+=cnt;
      sa.write(w);
            Serial.println(" Rservo 1");
    }
    break;
    case 10:
    if(w>0)
    {
      w-=cnt;
      sa.write(w);
            Serial.println("Rservo 1");
    }
    break;
    case 11:
    if(x<180)
    {
      x+=cnt;
      sb.write(x);
    Serial.println("Rservo 2");
    }
    break;
    case 12:
    if(x>0)
    {
      x-=cnt;
      sb.write(x);
    Serial.println("Rservo 2");
    }
    break;
    case 13:
    if(y<180)
    {
      y+=cnt;
      sc.write(y);
    Serial.println("Rservo 3");
    }
    break;
    case 14:
    if(y>0)
    {
      y-=cnt;
      sc.write(y);
    Serial.println("Rservo 3");
    }
    break;
    case 15:
    if(z<180)
    {
      z+=cnt;
      sd.write(z);
    Serial.println("Rservo 4");
    }
    break;
    case 16:
    if(z>0)
    {
      z-=cnt;
      sd.write(z);
      Serial.println("Rservo 4");
    }
    break;
    case 17:
    {
      if(g1>0)
      {
        g1+=cnt2;
        h1.write(g1);
      Serial.println("gripper 1");
      }
    }
    break;
    case 18:
    {
      if(g1<180)
      {
        g1-=cnt2;
        h1.write(g1);
        Serial.println("gripper 1");
      }
    }
    break;
    case 19:
    {
      if(g2>0)
      {
        g2+=cnt;
        h2.write(g2);
      Serial.println("gripper 2");
      }
    }
    break;
    case 20:
    {
      if(g2<180)
      {
        g2-=cnt;
        h2.write(g2);
      Serial.println("gripper 2");
      }
    }
    break;
     case 84:
    if(y<180)
    {
      y+=cnt;
      s1.write(y);
    Serial.println("A5 close");
    }
    
    break;
    
     case 85:
    if(y>0)
    {
      y-=cnt;
      s1.write(y);
    Serial.println("A5 open");
    }
    break;
     case 86:
    if(y<180)
    {
      y+=cnt;
      s2.write(y);
    Serial.println("9");
    }
    break;
     case 87:
    if(y>0)
    {
      y-=cnt;
      s2.write(y);
    Serial.println("9");
    }
    break;
     case 88:
    if(y<180)
    {
      y+=cnt;
      s3.write(y);
    Serial.println("12 open");
    }
    break;
     case 89:
    if(y>0)
    {
      y-=cnt;
      s3.write(y);
    Serial.println("12 close");
    }
    break;
     case 90:
    if(y<180)
    {
      y+=cnt;
      s4.write(y);
   Serial.println("10");
    }
    break;
     case 91:
    if(y>0)
    {
      y-=cnt;
      s4.write(y);
    Serial.println("10");
    }
    
    break;
    
 
    case 0:
          stp();
          break;
          
          case 21:
          Serial.println("in dc1 menu");  
          dc(in1,in2);
          Serial.println("pulley 4 tight");
          break;
           
          case 22:
          dc(in2,in1);
          Serial.println("pulley 4 loose");
          break;

           
          case 23:
          dc(in3,in4);
          Serial.println("pulley 2 tight");
          break;

           
          case 24:
          dc(in4,in3);
          Serial.println("pulley 2 loose");
          break;

           
          case 25:
          dc(in5,in6);
          Serial.println("pulley 3 tight");
          break;
           
          case 26:
          dc(in6,in5);
          Serial.println("pulley 3 loose");
          break;

           
          case 27:
          dc(in7,in8);
          Serial.println("pulley 1 tight");
          break;
           
          case 28:
          dc(in8,in7);
          Serial.println("pulley 1 loose");
          break;

          case 29:    // forward 1+2
         dc(in7,in8);
         dc(in3,in4);
         Serial.println("1+2 tighten");
          break;

          case 30: //  forward  3+4
          dc(in5,in6);
          dc(in1,in2);
          Serial.println("3+4 tighten");
          break;

          case 31: //  bckwd  1+2
          dc(in8,in7);
          dc(in4,in3);
          Serial.println("1+2 loosen");
          break;

          case 32:  // bckwd  3+4
          dc(in6,in5);
          dc(in2,in1);
          Serial.println("3+4 loosen");
          break;

            case 33:  // fwd  1+2+3+4
         dc(in1,in2);
         dc(in3,in4);
         dc(in5,in6);
         dc(in7,in8);
          break;

           case 34:  // bkwd  1+2+3+4
          dc(in2,in1);
          dc(in4,in3);
          dc(in6,in5);
          dc(in8,in7);
          break;
          
       }
    }
  }
