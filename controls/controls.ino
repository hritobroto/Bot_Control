/*
 * Assumptions made: One motor is used for all movements
 * But in the actual bot different motors will be used
 * This code is for demonstration purposes only
 */
#define enA 9
#define in1 6
#define in2 7

long int data;
long int Forward = 10;
long int Backward = 30;
long int Left = 20;
long int Right = 40;
long int Pull=50;
long int Lift=60;

char state = 0;
void setup()
{
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  Serial.begin(9600); 
}

void loop()
{
  analogWrite(enA, 255); // Send PWM signal to L298N Enable pin
  delay(20);
  
  while(Serial.available()==0) ;

 if(Serial.available()>0) 
{
data = Serial.parseInt();

} 
delay(400);
//Serial.print(data);

if (data == Forward)
{
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  Serial.println("Forward");
}
if (data == Backward)
{
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  Serial.println("Backward");
}
/*if (data == Left)
{
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  Serial.println("Left");
}
if (data == Right)
{
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  Serial.println("Right");
}*/
if (data == Pull)
{
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  Serial.println("Pull");
}
if (data == Lift)
{
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  Serial.println("Lift");
}
   
}
