#include <SoftwareSerial.h>

SoftwareSerial BT(2, 3); //TX, RX respetively
String readdata;

int left1 = 8;                                         //Left Motor pin initialization//
int left2 = 9;                                        
int right1 = 10;                                       //right Motor pin initialization//
int right2 = 11;

void setup()
{
 BT.begin(9600);
 Serial.begin(9600);
  pinMode(left1,OUTPUT);                          //Left Motor pin declaration//
  pinMode(right1,OUTPUT);                        //Right Motor pin declaration//
  pinMode(right2,OUTPUT);


  pinMode(left2,OUTPUT);}
void forward()
{
                
  digitalWrite(left1,HIGH);   
  digitalWrite(left2,LOW);          // forward move function //
  digitalWrite(right1,HIGH);               
  digitalWrite(right2,LOW);
}
void backward()
{
                
  digitalWrite(left1,LOW);   
  digitalWrite(left2,HIGH);          // backward move function //
  digitalWrite(right1,LOW);               
  digitalWrite(right2,HIGH);
}
void right()
{
              
  digitalWrite(left1,HIGH);   
  digitalWrite(left2,LOW);          //  right turn function //
  digitalWrite(right1,LOW);               
  digitalWrite(right2,HIGH);
}
void left()
{
                
  digitalWrite(left1,LOW);   
  digitalWrite(left2,HIGH);          // left turn function //
  digitalWrite(right1,HIGH);               
  digitalWrite(right2,LOW);
}
void stopall()
{
               
  digitalWrite(left1,LOW);   
  digitalWrite(left2,LOW);          //stop//
  digitalWrite(right1,LOW);               
  digitalWrite(right2,LOW);
}

//-----------------------------------------------------------------------// 
void loop() {
  while (BT.available()){          //Check if there is an available byte to read
  delay(10);                       //Delay added to make thing stable
  char c  = BT.read();              //Conduct a serial read
  readdata  += c;                   //build the string- "forward", "reverse", "left" and "right"
  } 
  if (readdata.length() > 0) {
    Serial.println(readdata);

  if(readdata == "forward")
  {
    Serial.println("Forward");
    forward();
    delay(100);
  }

  else if(readdata == "backward")
  {
    Serial.println("Backward");
    backward();
    delay(100);
  }

  else if (readdata == "right")
  {
    Serial.println("Right");
   right();
    delay (100);
   
  }

 else if ( readdata == "left")
 {
  Serial.println("Left");
   left();
   delay (100);
 }

 else if (readdata == "stop")
 {
  Serial.println("Stop");
   stopall();
   delay (100);
 }

readdata="";   //Reset the variable
}
} 
