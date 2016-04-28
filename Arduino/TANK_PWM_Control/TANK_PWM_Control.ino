/*
 * This version of Tank arduino code is PWM compatible 
 * The commands are like this 
 * 
 * *T:F-100*D:R-0*  
 * This command is 100% forward without any direction
 * 
 * *T:B-100*D:R-0* 
 * This command is 100% reverse. Without any direction
 * 
 * *T:F-50*D:L-50* 
 * This command is 50% forwared. It will go left but not fully.
 * 
 * This code is compatible with Arduino Mega. The software serial is used. 
 * 
 */



int IN1 = 8; // Motor 1
int IN2 = 9; // Motor 1
int IN3 = 10; //Motor 2
int IN4 = 11; //Motor 2

void setup() {
  Serial.begin(9600);
  Serial.println("Program STarts");
  
  Serial1.begin(9600);



  pinMode(IN1, OUTPUT);  //sağ motor - right motor
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);  //sol motor - left motor
}

void loop() {

  String input = "";


  digitalWrite(IN1, LOW); //öncelikle motorları durduruyoruz! - first we stop the motors!
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);

  while (Serial1.available() > 0) {
    input += (char)Serial1.read();
    delay(5);
  }

  String directt;
  int tvalue = 0 ;

  String directd;
  int dvalue = 0;

  if (input != "") {
    Serial.println(input);
    int tdi = input.indexOf('T');
    int dotdi = input.indexOf(':', tdi);

    if (dotdi - tdi == 1) {
      directt = input.substring(dotdi + 1, input.indexOf('-', dotdi));
      // Serial.println(directt);
    } else {
      //  Serial.println("invalid input");
    }

    int tvi = input.indexOf('-', dotdi + 2); //since this is a character, it should be two length....
    int start1 = input.indexOf('*', tvi);



    tvalue = input.substring(tvi + 1, start1).toInt();
    // Serial.println(tvalue);


    int ddi = input.indexOf('D', input.indexOf('*')); // T:F-48*D:R-50   we are going to search after the first star..
    int ddoti = input.indexOf(':', ddi);

    if (ddoti - ddi == 1) {
      directd = input.substring(ddoti + 1, input.indexOf('-', ddoti));
      //  Serial.println(directd);
    } else {
      // Serial.println("Error");
    }



    int dash2 = input.indexOf('-', ddoti);
    int star2 = input.indexOf('*', dash2);

    dvalue = input.substring(dash2 + 1, star2).toInt();
    //Serial.println(dvalue);

  }

  tvalue = map(tvalue, 0, 100, 0, 255);
  
  dvalue = 100 - dvalue;
  dvalue = map(dvalue, 0 , 100, 0 , tvalue); //this was 255 instead of tvalue

  if (directt.indexOf("F") > -1) {
    if (directd.indexOf("L") > -1) {

      analogWrite(IN2, dvalue);
      digitalWrite(IN1, LOW);

      analogWrite(IN3, tvalue);
      digitalWrite(IN4, LOW);

    } else if (directd.indexOf("R") > -1) {

      analogWrite(IN2,  tvalue);
      digitalWrite(IN1, LOW);

      analogWrite(IN3, dvalue );
      digitalWrite(IN4, LOW);
    }
    //Serial.print(directt + " " + directd + " ");
    //Serial.println(dvalue);
    //Serial.println(tvalue);

  } else if (directt.indexOf("B") > -1) {
    if (directd.indexOf("L") > -1) {

      analogWrite(IN1, dvalue );
      digitalWrite(IN2, LOW);

      analogWrite(IN4,  tvalue);
      digitalWrite(IN3, LOW);

    } else if (directd.indexOf("R") > -1) {

      analogWrite(IN1,  tvalue);
      digitalWrite(IN2, LOW);

      analogWrite(IN4, dvalue );
      digitalWrite(IN3, LOW);
    }
    //Serial.print(directt + " " + directd + " ");
    //Serial.println(dvalue);
    //Serial.println(tvalue);
    delay(500);
  }







}
