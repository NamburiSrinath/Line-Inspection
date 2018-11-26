#include<Servo.h>
 
 //SoftwareSerial BTSerial(11,10); //RX|tx         
int h,l,dly=50; // hold and leave angles for servo of both hands. delay for waiting for serial input

int in1=22,in2=23,in3=24,in4=25,in5=26,in6=27,in7=28,in8=29;
int cnt=10,w=40,x=40,y=40,z=40,hold1=0,leave1=38,sA=40,sB=40,sC=40,sD=40,hold2=45,leave2=0,DC1=0,DC2=0;

void pol1(int e)
{ Serial1.println(e);
Serial.println(e);
}

void pol2(int e)
{Serial2.println(e);
Serial.println(e);} 
 
 void dc(int a,int b)
 { digitalWrite(a,HIGH);
   digitalWrite(b,LOW);
    Serial.print("Run dc with high  ");
   Serial.print(a);
   Serial.print("  LOW  ");
   Serial.println(b);
      
  }

 void stp()                   // stop all dc motors
 {digitalWrite(in1,LOW);
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

   digitalWrite(36,LOW);
   digitalWrite(37,LOW);
   digitalWrite(34,LOW);
   digitalWrite(35,LOW);

    digitalWrite(28, LOW);    // stopping the horizontal dc when the line is held
           digitalWrite(29, LOW);
           digitalWrite(32, LOW);
           digitalWrite(33, LOW);
   Serial.println("stop dcs");
  }
    
  Servo s1, s2;   // for A side
  Servo s3, s4;  // for B side
  Servo sa,sb,sc,sd,h2;  //arm 2 
  Servo W,X,Y,Z,h1;  //arm 1
   
  int u,i,o;
  int pos1=0 , pos2=5, pos3=0, pos4=0 ;  // A:H   A:V   B:H   B:V  respectively
  int a=0, b=0,c=0,zzz=0;
  void intrrpta(),intrrptb();
 
  void setup()
  {
    Serial1.begin(9600);
    Serial.begin(115200);
     Serial2.begin(9600);
//   Serial3.begin(57600);
  //  Serial.begin(9600);
   // Serial2.begin(9600);
    
    attachInterrupt(digitalPinToInterrupt(20),intrrpta, RISING);
    attachInterrupt(digitalPinToInterrupt(21),intrrptb, RISING);
    
    s1.attach(4);           // horizontal servo A side
    s2.attach(9);
    s3.attach(7);           // horizontal servo B side                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         ); 
    s4.attach(10); 
     W.attach(A0);
    X.attach(A1);
    Y.attach(A2);
    Z.attach(A3);
   // DC1,
   h1.attach(22);// gripper

   sa.attach(A4);
   sb.attach(A5);
   sc.attach(A6);
   sd.attach(A7); //dc2
   h2.attach(23); // gripper
    
    s1.write(pos1);         // for the initial angles of the servos 
    s2.write(pos2);
 
    s3.write(pos3);
    s4.write(pos4);

    pinMode(43,OUTPUT);
  
    pinMode(22, OUTPUT);   //dc1  
    pinMode(23, OUTPUT);           // going to one motor driver   //horizontal servos
    pinMode(24, OUTPUT);   //dc2
    pinMode(25, OUTPUT);  
    
    pinMode(26, OUTPUT);   //dc3
    pinMode(27, OUTPUT);           // going to another motor driver  // vertical servos for moving f/w or b/w 
    pinMode(28, OUTPUT);   //dc4
    pinMode(29, OUTPUT);
    pinMode(31, OUTPUT);

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
         dc(22,23);
          b=0; a=0; 
          dc(28,29);
          while(a==0 || b==0)
       {if(Serial.available()) break;

       if(b!=0)
      { digitalWrite(22, LOW);
           digitalWrite(23, LOW);}

           if(a!=0)
      { digitalWrite(29, LOW);
           digitalWrite(28, LOW);}
       
          }
            // giving high signals to horizontal dc for holding the line 
           
          
//            a=1;  b=1;

         Serial.println("Both motors stopped");
           digitalWrite(28, LOW);    // stopping the horizontal dc when the line is held
           digitalWrite(29, LOW);
           digitalWrite(32, LOW);
           digitalWrite(33, LOW);
         Serial.println("ok");

       
        s3.write(55);
        delay(1500);
        s2.write(70);
        delay(1500);
        s4.write(40); 
        delay(1500);
         s1.write(90);
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
     
     
     case 8:    // START
     {
       
        
          dc(25,24);
          dc(27,26);
          //Serial.println("start");
          if(Serial.available())
          { stp();
          }
        
       
        break;
      }
     
         
     case 2:    
     {
        dc(24,25);
        dc(26,27);
         
        if(Serial.available())
        { stp();}
        
        
    /*    digitalWrite(41, HIGH);   // GREEN LED to show that it is running  
        digitalWrite(42, LOW); 
        digitalWrite(40, LOW);
       
        digitalWrite(43, LOW);*/    
        break; 
     }
      case 5:    //stop
      { stp();
      //digitalWrite(13,HIGH);
        Serial.println("stop");
        
     /*   digitalWrite(42, HIGH);   // yellow LED to show that it is running  
        digitalWrite(41, LOW); 
        digitalWrite(40, LOW);
        digitalWrite(43, LOW); */ 
         break;
     
      }
      case 6:  // release the robot by burning an alarm
      {
        Serial.println("Disconnecting");
       
        /*  for(pos1= 86  ; pos1>= 5  ; pos1--)     // horizontal servo side A
          {
            s1.write(pos1);
            delay(50);
         }  Serial.println("S1 finished");
    
          for(pos3= 55  ; pos3>= 10  ; pos3--)     // horizontal servo side B
           {
            s3.write(pos3);
            delay(50);
          }
     
          for(pos2= 70  ; pos2>=5   ; pos2--)     // vertical servo side A
           {
             s2.write(pos2);
             delay(50);
           }
     
          for(pos4= 85 ; pos4>= 10 ; pos4--)     // vertical servo side B
           {
            s4.write(pos4);
            delay(50);
          }*/

        s1.write(0);
        delay(1500);
        s3.write(10);
        delay(1500);
        s2.write(5);
        delay(1500);
       s4.write(0); 
        delay(1500);        
        
          Serial.println("Going for dc");
          //digitalWrite(43, HIGH);    // for alarm 
          
             digitalWrite(29, LOW);   // giving high signals to horizontal dc for releasing the line
             digitalWrite(28, HIGH);
           digitalWrite(33, LOW);
           digitalWrite(32, HIGH); 

             for(int p=0; p<=500; p++)
            { if(Serial.available())
              break;
              delay(5);
            } 
         stp();
         break;
      }

      case 1:
      
        Serial.flush();
        //Serial.println("enterd a1 menu");
        while(!Serial.available()){ delay(dly); }
        o= Serial.parseInt();

        while(o!=99)
        {switch(o)
        {
//         case 0:
//          stp();
//          break;
           
        case 40:
          if(w<180)
          {w+=cnt;
           W.write(w);}
          break;

          case 41:
          if(w>0)
          {w-=cnt;
       W.write(w);}
          break;

           case 42:
          if(x<180)
          {x+=cnt;
         X.write(x);}
          break;

          case 43:
          if(x>0)
          {x-=cnt;
        X.write(x);}
          break;
          
          case 44:
          if(y<180)
          {y+=cnt;
          Y.write(y);}
          break;

          case 45:
          if(y>0)
          {y-=cnt;
          Y.write(y);}
          break;
          
          case 46:
          if(z<180)
          {z+=cnt;
        Z.write(z);}
          break;

          case 47:
          if(z>0)
          {z-=cnt;
         Z.write(z);}
          break;

          case 48:
          
         pol1(1);
//           dc(in10,in9);
//          delay(100);
//          stp();

          break;

          case 49:
         
//          dc(in10,in9);
//          delay(100);
//          stp();
//            
         
          pol1(0);
          break;


          case 17:
         h1.write(h);
        Serial.println("hold the line");
          break;

          case 18:
         h1.write(l);
           Serial.println("Leave the line");
          break;
          }

           Serial.flush();
        while(!Serial.available()){ delay(dly); }
        o= Serial.parseInt();
        }
        Serial.println("leaving arm 1 menu"); 
      break;


       case 3:
      
        Serial.flush();
        while(!Serial.available()){ delay(dly); }
        o= Serial.parseInt();
         while(o!=99)
        {switch(o)
        { case 30:
          if(sA<180)
          {sA+=cnt;
          sa.write(sA);}
          break;

          case 31:
          if(sA>0)
          {sA-=cnt;
           sa.write(sA);}
          break;

          case 32:
          if(sB<180)
          {sB+=cnt;
           sb.write(sB);}
          break;

          case 33:
          if(sB>0)
          {sB-=cnt;
           sb.write(sB);}
          break;
          
          case 34:
          if(sC<180)
          {sC+=cnt;
           sc.write(sC);}
          break;

          case 35:
          if(sC>0)
          {sC-=cnt;
         sc.write(sC);}
          break;
          
          case 36:
          if(sD<180)
          {sD+=cnt;
           sd.write(sD);}
          break;

          case 37:
          if(sD>0)
          {sD-=cnt;
          sd.write(sD);}
          break;

          case 38:
         
           pol2(1);
//
//           dc(in11,in12);
//          delay(100);
//          stp();
          break;

          case 39:
         
         
          pol2(2);
//
//           dc(in12,in11);
//          delay(100);
//          stp();
          break;
          

           case 27:
          h2.write(h);
           Serial.println("Hold_the_line");
          break;

          case 28:
           h2.write(l);
         Serial.println("leave_the_line");
          break;

          /*default:
          Serial.flush();
          break;*/ 
          }
           Serial.flush();
        while(!Serial.available()){ delay(dly); }
        o= Serial.parseInt();
        }
     Serial.println("leaving arm 2 menu");  
      break;

      case 9:
  Serial.println("entered dc menu");  
      Serial.flush();
        while(!Serial.available()){ delay(dly); }
        o= Serial.parseInt();
         while(o!=99)
        {switch(o)
        {
          case 0:
          stp();
          break;
          
          case 1:
          Serial.println("in dc1 menu");  
          dc(in1,in2);
          break;
           
          case 2:
          dc(in2,in1);
          break;

           
          case 3:
          dc(in3,in4);
          break;

           
          case 4:
          dc(in4,in3);
          break;

           
          case 5:
          dc(in5,in6);
          break;
           
          case 6:
          dc(in6,in5);
          break;

           
          case 7:
          dc(in7,in8);
          break;
           
          case 8:
          dc(in8,in7);
          break;

          case 20:    // forward 1+2
         dc(in1,in2);
         dc(in3,in4);
          break;

          case 10: //  forward  3+4
          dc(in5,in6);
          dc(in7,in8);
          break;

          case 11: //  bckwd  1+2
          dc(in2,in1);
          dc(in4,in3);
          break;

          case 12:  // bckwd  3+4
          dc(in6,in5);
          dc(in8,in7);
          break;

            case 80:  // fwd  1+2+3+4
         dc(in1,in2);
         dc(in3,in4);
         dc(in5,in6);
         dc(in7,in8);
          break;

           case 81:  // bkwd  1+2+3+4
          dc(in2,in1);
          dc(in4,in3);
          dc(in6,in5);
          dc(in8,in7);
          break;
        }

           Serial.flush();
        while(!Serial.available()){ delay(dly); }
        o= Serial.parseInt();
          
        }
      break;
      }
    
    }
    u=0;
    delay(50);
    } 
      void intrrpta()
      { a=1;
      Serial.println("motor a stopped");}

       void intrrptb()
      { b=1;
       Serial.println("motor b stopped");}
   
      
    
