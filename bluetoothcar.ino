#define LF A0
#define LR A2
#define RF A4
#define RR A5
char t;
 
void setup() {
pinMode(A0,OUTPUT);   //left motors forward
pinMode(A2,OUTPUT);   //left motors reverse
pinMode(A4,OUTPUT);   //right motors forward
pinMode(A5,OUTPUT);   //right motors reverse
//Led
Serial.begin(9600);
 
}
 
void loop() {
if(Serial.available()){
  t = Serial.read();
  Serial.println(t);
}
 
if(t == 'F'){            //move forward(all motors rotate in forward direction)
  digitalWrite(LF,HIGH);
  digitalWrite(RF,HIGH);
}
 
else if(t == 'B'){      //move reverse (all motors rotate in reverse direction)
  digitalWrite(LR,HIGH);
  digitalWrite(RR,HIGH);
}
 
else if(t == 'L'){      //turn right (left side motors rotate in forward direction, right side motors doesn't rotate)
  digitalWrite(LF,HIGH);
}
 
else if(t == 'R'){      //turn left (right side motors rotate in forward direction, left side motors doesn't rotate)
  digitalWrite(RF,HIGH);
}

else if(t == 'W'){    //turn led on or off)
  digitalWrite(9,HIGH);
}
else if(t == 'w'){
  digitalWrite(9,LOW);
}
 
else if(t == 'S'){      //STOP (all motors stop)
  digitalWrite(LF,LOW);
  digitalWrite(LR,LOW);
  digitalWrite(RF,LOW);
  digitalWrite(RR,LOW);
}
//delay(100);
}
