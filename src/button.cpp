#include "button.h"
#include "main.h"

// set PushButton pin number

Button init_button(int pin) {
    pinMode(pin, INPUT);

    return {pin, HIGH, 0, 0, 0};
}

int update_button(Button *button) {
    // put your main code here, to run repeatedly:
  
  button->buttonState = digitalRead(button->buttonPin);
  
  if (button->buttonState == LOW){
    delay(200);
    //Serial.println("Button Pressed");
    
    if (button->clicks == 0) {
    button->timePress = millis();
    button->timePressLimit = button->timePress + 500;    
    button->clicks = 1;
    }

    else if (button->clicks == 1 && millis() < button->timePressLimit){
      //Serial.println("Button Pressed twice");
        // call handle function

     //set variables back to 0
      button->timePress = 0;
      button->timePressLimit = 0;
      button->clicks = 0;      
      return 2;
    }    
  }

  if (button->clicks == 1 && button->timePressLimit != 0 && millis() > button->timePressLimit){
     //Serial.println("Button Pressed Once");
        // call handle function

     button->timePress = 0;
     button->timePressLimit = 0;
     button->clicks = 0;
    return 1;
  }

  return 0;
}
