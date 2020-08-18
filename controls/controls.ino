
#define enA 1
#define in1 2
#define in2 3

#define enB 4
#define in3 5
#define in4 6

#define enC 7
#define in5 8
#define in6 9

#define enD 10
#define in7 11
#define in8 12

#define enE 13
#define in9 14
#define in10 15

#define enF 16
#define in11 17
#define in12 18

#define enG 19
#define in13 20
#define in14 21

long int data;
long int Forward = 10;
long int Backward = 30;
long int Left = 20;
long int Right = 40;
long int Pull_in=50;
long int Pull_out=60;
long int Lift_up=70;
long int Lift_down=80;
long int Push_in=90;
long int Push_out=100;
/*
 * Pull_in and Pull_out are for picking up the load on the bot
 * Lift_up and Lift_down are for the lifting mechanism
 * Push_in and Push_out is for dropping the load on a platfprm on said height
 */

char state = 0;
void setup()
{
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);

  pinMode(enB, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  
  pinMode(enC, OUTPUT);
  pinMode(in5, OUTPUT);
  pinMode(in6, OUTPUT);
  digitalWrite(in5, LOW);
  digitalWrite(in6, LOW);
  
  pinMode(enD, OUTPUT);
  pinMode(in7, OUTPUT);
  pinMode(in8, OUTPUT);
  digitalWrite(in7, LOW);
  digitalWrite(in8, LOW);
  
  pinMode(enE, OUTPUT);
  pinMode(in9, OUTPUT);
  pinMode(in10, OUTPUT);
  digitalWrite(in9, LOW);
  digitalWrite(in10, LOW);
  
  pinMode(enF, OUTPUT);
  pinMode(in11, OUTPUT);
  pinMode(in12, OUTPUT);
  digitalWrite(in11, LOW);
  digitalWrite(in12, LOW);
   
  pinMode(enG, OUTPUT);
  pinMode(in13, OUTPUT);
  pinMode(in14, OUTPUT);
  digitalWrite(in13, LOW);
  digitalWrite(in14, LOW);

  
  Serial.begin(9600); 
}

void loop()
{
  analogWrite(enA, 255);
  analogWrite(enB, 255);
  analogWrite(enC, 255);
  analogWrite(enD, 255);
  analogWrite(enE, 255);
  analogWrite(enF, 255);
  analogWrite(enG, 255);
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
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
  digitalWrite(in5,HIGH);
  digitalWrite(in6,LOW);
  digitalWrite(in7,HIGH);
  digitalWrite(in8,LOW);
  Serial.println("Forward");
}
if (data == Backward)
{
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
  digitalWrite(in5,LOW);
  digitalWrite(in6,HIGH);
  digitalWrite(in7,LOW);
  digitalWrite(in8,HIGH);
  Serial.println("Backward");
}
if (data == Left)
{
  analogWrite(enA, 50);
  analogWrite(enB, 255);
  analogWrite(enC, 50);
  analogWrite(enD, 255);
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
  digitalWrite(in5,HIGH);
  digitalWrite(in6,LOW);
  digitalWrite(in7,HIGH);
  digitalWrite(in8,LOW);
  Serial.println("Left");
}
if (data == Right)
{
  analogWrite(enA, 255);
  analogWrite(enB, 50);
  analogWrite(enC, 255);
  analogWrite(enD, 50);
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
  digitalWrite(in5,HIGH);
  digitalWrite(in6,LOW);
  digitalWrite(in7,HIGH);
  digitalWrite(in8,LOW);
  Serial.println("Right");
}
if (data == Pull_in)
{
  digitalWrite(in9,LOW);
  digitalWrite(in10,HIGH);
  Serial.println("Pull In");
}
if (data == Pull_out)
{
  digitalWrite(in9,HIGH);
  digitalWrite(in10,LOW);
  Serial.println("Pull Out");
}
if (data == Lift_up)
{
  digitalWrite(in11,HIGH);
  digitalWrite(in12,LOW);
  Serial.println("Lift Up");
}
if (data == Lift_down)
{
  digitalWrite(in11,LOW);
  digitalWrite(in12,HIGH);
  Serial.println("Lift Down");
}
if (data == Push_in)
{
  digitalWrite(in9,LOW);
  digitalWrite(in10,HIGH);
  Serial.println("Push In");
}
if (data == Push_out)
{
  digitalWrite(in9,HIGH);
  digitalWrite(in10,LOW);
  Serial.println("Push Out");
}
}
