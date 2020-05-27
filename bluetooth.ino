#include <SoftwareSerial.h>  

#define Back_Right A1
#define Back_Left A0
#define FW_Right 12
#define FW_Left 13
#define IN1 7
#define IN2 6
#define IN3 5
#define IN4 4
#define EnA 3
#define EnB 9

SoftwareSerial BTSerial(10, 11);
char received;

void setup() {
 
  BTSerial.begin(9600); 
  pinMode(Back_Right, OUTPUT);
  pinMode(Back_Left, OUTPUT);
  pinMode(FW_Right, OUTPUT);
  pinMode(FW_Left, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(EnA, OUTPUT);
  pinMode(EnB, OUTPUT);
}
void loop() {
   received = '0';
  if (BTSerial.available() > 0) { 
    received = BTSerial.read(); 
    Serial.println(received);
  }
  delay(10);

  if (received == 'F' )
  {
    Forward();
  }
  if (received == 'B' )
  {
    Backward();
  }
  if (received == 'R' )
  {
    Right();
  }
  if (received == 'L' )
  {
    Left();
  }
  if (received == 'G' )
  {
    FoW_Left();
  }
  if (received == 'I' )
  {
    FoW_Right();
  }
  if (received == 'S' )
  {
    Stop();
  }
  if (received == 'W' )
  {
    digitalWrite(FW_Right, HIGH);
    digitalWrite(FW_Left, HIGH);
  }
  if (received == 'w' )
  {
    digitalWrite(FW_Right, LOW);
    digitalWrite(FW_Left, LOW);
  }
  if (received == 'U' )
  {
    digitalWrite(Back_Right, HIGH);
    digitalWrite(Back_Left, HIGH);
  }
  if (received == 'u' )
  {
    digitalWrite(Back_Right, LOW);
    digitalWrite(Back_Left, LOW);
  }
}

void Forward()
{ analogWrite(EnA, 150);
  analogWrite(EnB, 150);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

}
void Backward()
{ analogWrite(EnA, 150);
  analogWrite(EnB, 150);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

}
void Right()
{ analogWrite(EnA, 150);
  analogWrite(EnB, 150);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

}
void Left()
{ analogWrite(EnA, 150);
  analogWrite(EnB, 150);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

}

void FoW_Left()
{ analogWrite(EnA, 110);
  analogWrite(EnB, 110);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

}
void FoW_Right()
{ analogWrite(EnA, 110);
  analogWrite(EnB, 110);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

}

void Stop()
{ analogWrite(EnA, 0);
  analogWrite(EnB, 0);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);

}
