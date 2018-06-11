/*Daniel Satur - 11 June 2018*/

#include <LiquidCrystal.h>
#include <Servo.h>

const int RS = 12, E = 11, D4 = 5, D5 = 4, D6 = 3, D7 = 2;
const int left_bot_digPin = 6, right_bot_digPin = 7, reset_servo_digPin = 13;
LiquidCrystal lcd(RS, E, D4, D5, D6, D7);
Servo left_bot, right_bot, reset;
const int left_button_digPin = 8, right_button_digPin = 9;
int left_servo_angle, right_servo_angle, reset_servo_angle;
int knock_sensor_digPin = 10;
int score;
int left_status, right_status, reset_status, knock_status;

void setup(){
  lcd.begin(16, 2);
  lcd.print("Current Score:");
  
  left_bot.attach(left_bot_digPin);
  left_servo_angle = 90;
  left_bot.write(left_servo_angle);
  
  right_bot.attach(right_bot_digPin);
  right_servo_angle = 90;
  right_bot.write(right_servo_angle);

  reset.attach(reset_servo_digPin);
  reset_servo_angle = 90;
  reset.write(reset_servo_angle);
  
  pinMode(left_button_digPin, INPUT);
  pinMode(right_button_digPin, INPUT);
  pinMode(knock_sensor_digPin, INPUT);
  score=0;
  Serial.begin(9600);
}

void loop(){
  left_status = digitalRead(left_button_digPin);
  right_status = digitalRead(right_button_digPin);
  knock_status = digitalRead(knock_sensor_digPin);
  reset_status = digitalRead(reset_servo_digPin);
  lcd.setCursor(0, 1);
  lcd.print(score);

  if(left_status==HIGH){
    while(left_servo_angle<=170){
      left_servo_angle++;
      left_bot.write(left_servo_angle);
    }
  }
  
  if(left_status==LOW){
    while(left_servo_angle>=10){
      left_servo_angle--;
      left_bot.write(left_servo_angle);
    }
  }
  
  if(right_status==LOW){
    while(right_servo_angle<=170){
      right_servo_angle++;
      right_bot.write(right_servo_angle);
    }
  }
  
  if(right_status==HIGH){
    while(right_servo_angle>=10){
      right_servo_angle--;
      right_bot.write(right_servo_angle);
    }
  }

  if(reset_status==LOW){
    while(reset_servo_angle<=170){
      reset_servo_angle++;
      reset.write(reset_servo_angle);
    }
  }
  
  if(reset_status==HIGH){
    while(reset_servo_angle>=10){
      reset_servo_angle--;
      reset.write(reset_servo_angle);
    }
  }
  
  if(knock_status==LOW){
    score++;
    Serial.print("Score: ");
    Serial.print(score);
    Serial.println();
  }
}

    
 
