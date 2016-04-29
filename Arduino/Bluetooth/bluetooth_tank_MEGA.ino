/** Created by Kaan Göksal 
 * 4/4/2016 
 * This code is used to control a rc vehicle with 
 * L298N + HC06 + Arduino MEGA
 *  
 * Kaan Göksal yazmıştır bu kodu.
 * 4 Nisan 2016
 * Bu kod uzaktan kumandalı bir aracı kontrol eder.
 * L298N + HC06 + Arduino MEGA ile uyumludur! 
 * Serial.print ifadeleri debugging için kullanılmaktadır, silebilirsiniz.
 * 
 * 
 */


int IN1 = 8; // Motor 1
int IN2 = 9; // Motor 1
int IN3 = 10; //Motor 2
int IN4 = 11; //Motor 2


void setup()
{
 
  Serial.begin(9600);
  Serial1.begin(9600); //HC-06 Modulu ile iletisim baslar - opening the comms for hc-06 module
 
 pinMode(IN1, OUTPUT);  //sağ motor - right motor 
 pinMode(IN2, OUTPUT);  
 pinMode(IN3, OUTPUT);
 pinMode(IN4, OUTPUT);  //sol motor - left motor
   Serial1.println("program start");
   Serial.println("program start");
}

void loop()
{
  String input = "";

  
     digitalWrite(IN1, LOW); //öncelikle motorları durduruyoruz! - first we stop the motors! 
     digitalWrite(IN2, LOW); 
     digitalWrite(IN3, LOW);
     digitalWrite(IN4, LOW); 
   
  
  
   while (Serial1.available() > 0)
  {
    input += (char)Serial1.read();
    delay(5);
  }
  
  // eğer input "" dan farklıysa gösterilicek bu sayde Serial spamlenmiyecek! - 
  //If input has a different value than empty string It is going to printout to the client.
  if (input != "" ) {
    Serial.println(input);
  } 
  
  
  
  
  
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
  
if (digitalRead(IN1) != 0 || digitalRead(IN2) != 0 || digitalRead(IN3) != 0 || digitalRead(IN4) != 0 ) {
  Serial.println(digitalRead(IN1));
   Serial.println(digitalRead(IN2));
   Serial.println(digitalRead(IN3));
   Serial.println(digitalRead(IN4));
} 
  delay(125);
}
