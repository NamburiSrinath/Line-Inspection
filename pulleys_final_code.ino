int a;
void setup() {
  // put your setup code here, to run once:
pinMode(40,OUTPUT);
pinMode(41,OUTPUT);
pinMode(42,OUTPUT);
pinMode(43,OUTPUT);
pinMode(44,OUTPUT);
pinMode(45,OUTPUT);
pinMode(46,OUTPUT);
pinMode(47,OUTPUT);
Serial.begin(9600);
}

/////////////////////////////////////////////////////////////////
//motor 1 ------ 46,47
//motor 2 ------ 42,43
//motor 3 ------ 44,45
//motor 4 ------ 40,41




///////////////////////////////////////////////////////////
void dc(int a,int b)
 { digitalWrite(a,HIGH);
   digitalWrite(b,LOW);
    Serial.print("Run dc with high  ");
   Serial.print(a);
   Serial.print("  LOW  ");
   Serial.println(b);
      }

void stp()
{
  digitalWrite(40,LOW);
  digitalWrite(41,LOW);
  digitalWrite(42,LOW);
  digitalWrite(43,LOW);
  digitalWrite(44,LOW);
digitalWrite(45,LOW);
  digitalWrite(46,LOW);
  digitalWrite(47,LOW);
}


      

void loop() {
  // put your main code here, to run repeatedly:
if(Serial.available())
{
a = Serial.parseInt();
switch (a)
{
case 1://///////////////////////////4 tight
{
  dc(40,41);
  break;
}

case 2:////////////////////////////4 loose
{
  dc(41,40);
  break;
}

case 3://////////////////////////////2 tight
{
  dc(42,43);
  break;
}

case 4://///////////////////////////2 loose
{
  dc(43,42);
  break;
}

case 5://///////////////////////////motor 3 tightrning
{
  dc(44,45);
  break;
}

case 6://////////////////////////////motor 3 loosening
{
  dc(45,44);
  break;
}

case 7://///////////////////////////motor 1 tight
{
  dc(46,47);
  break;
}

case 8:////////////////////////////motor 1 loose
{
  dc(47,46);
  break;
}

case 9:////////////////////////////// 3,4 tight
{
  dc(40,41);
  dc(44,45);
  break;
}

case 10:////////////////////3,4 loose
{
  dc(41,40);
  dc(45,44);
  break;
}

case 11:////////////////////1,2 tight
{
  dc(42,43);
  dc(46,47);
  break;
}

case 12:////////////////////1,2 loose
{
  dc(43,42);
  dc(47,46);
  break;
}

case 13:///////////////////////stop all
{
 stp();
 break;
}
}
}
}
