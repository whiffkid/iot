#include<Keypad.h>

const byte ROWS=4;
const byte COLS=4;

char keys[ROWS][COLS]={
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS]={9,8,7,6};
byte colPins[COLS]={A0,A1,A2,A3};

Keypad keypad=Keypad(makeKeymap(keys),rowPins,colPins,ROWS,COLS);

String input ="";

void setup(){
  Serial.begin(9600);
  Serial.println("MATRIX KEYPAD");
  delay(1000);
}

void loop(){
  char key=keypad.getKey();
  if (key){
    if(key=='#'){
      input="";
      Serial.println("Input cleared");
      Serial.println("Enter:");
    }
    else if(key=='*'){
      if(input.length()>0){
        input.remove(input.length()-1);
      }
    }
    else{
      input+=key;
      Serial.println("key pressed:");
      Serial.println(key);

      Serial.println("Input");
      Serial.println(input);
    }
  }
}