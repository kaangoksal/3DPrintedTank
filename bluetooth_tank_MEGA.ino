

int IN1 = 8;
int IN2 = 9;
int IN3 = 10;
int IN4 = 11;


void setup()
{
 
  Serial.begin(9600);
  Serial1.begin(9600);
 
 pinMode(IN1, OUTPUT);  //right motor
 pinMode(IN2, OUTPUT);  
 pinMode(IN3, OUTPUT);
 pinMode(IN4, OUTPUT);  //left motor
 
  
}

void loop()
{
  String input = "";
  Serial.println("program start");
  
     digitalWrite(IN1, LOW);
     digitalWrite(IN2, LOW); 
     digitalWrite(IN3, LOW);
     digitalWrite(IN4, LOW); 
	 
	
  
   while (Serial1.available() > 0)
  {
    input += (char)Serial1.read();
    delay(5);
  }
  
  Serial.println(input);
  
  
  
  
  
  
  if(input.indexOf("forward") > -1 || input.indexOf("w") > -1)
  {
       Serial.println("forward");
	
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);    //left motor back
	  
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);     //right motor back
	 
    
  }
  else if(input.indexOf("backward") > -1 || input.indexOf("s") > -1)
  {
        Serial.println("backward");
	
 
        digitalWrite(IN1, HIGH);   //Right Motor Go Forward
        digitalWrite(IN2, LOW);
  
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, HIGH);
  }
  
   else if(input.indexOf("right") > -1 || input.indexOf("d") > -1)
  {
  Serial.println("right");
  
 
   digitalWrite(IN3, HIGH);
   digitalWrite(IN4, LOW); 
 
  }
   else if(input.indexOf("left") > -1 || input.indexOf("a") > -1)
  {
    Serial.println("left");
	
   
   digitalWrite(IN1, LOW);   //Right Motor Go Forward
  digitalWrite(IN2, HIGH);
  }
  
   
 Serial.println(digitalRead(IN1));
 Serial.println(digitalRead(IN2));
 Serial.println(digitalRead(IN3));
 Serial.println(digitalRead(IN4));
  delay(125);
}
