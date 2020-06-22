#include <Servo.h>

#include <Key.h>
#include <Keypad.h>

const byte ROWS = 4;
const byte COLS = 3;
char keys[ROWS][COLS] =  {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};

byte rowPins[ROWS] = {6,1,2,4};
byte colPins[COLS] = {5,7,3};

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

int servoPin = 0;
Servo servo1;

int c = 0;

char code[]= {'0','0','0','0'};
short a=0,i=0,s=0,j=0,n=120;

const int buzzer = A5;



void setup() {
  // put your setup code here, to run once:
  pinMode(buzzer, OUTPUT); // Set buzzer - pin 9 as an output
  servo1.attach(servoPin);
  //servo1.write(-10000);
  delay(1000);
  servo1.write(40);
  
 

}

void GetCode(){                  //Getting code sequence
       n=120;
       i=0;                      //All variables set to 0
       a=0;
       j=0; 
       char key = keypad.getKey();                              
     while(key != '#'){                                     //The user press # to confirm the code otherwise he can keep typing
           key = keypad.getKey();                         
             if(key != NO_KEY && key != '#' ){       //If the char typed isn't # and neither "nothing"                              
              //tone(buzzer, n, 500);
              //delay(500);
            if(key == '1'){
                  tone(buzzer, 0.26163 * 1000, 200);
                 }else if(key == '2'){
                  tone(buzzer, 0.29366 * 1000, 200);
                 }else if(key == '3'){
                  tone(buzzer, 0.32963 * 1000, 200);
                 }else if(key == '4'){
                  tone(buzzer, 0.34923 * 1000, 200);
                 }else if(key == '5'){
                  tone(buzzer, 0.392 * 1000, 200);
                 }else if(key == '6'){
                  tone(buzzer, 0.44 * 1000, 200);
                 }else if(key == '7'){
                  tone(buzzer, 0.49388 * 1000, 200);
                 }else if(key == '8'){
                  tone(buzzer, 0.52325 * 1000, 200);
                 }else if(key == '9'){
                  tone(buzzer, 0.58733 * 1000, 200);
                 }else if(key == '0'){
                  tone(buzzer, 0.65925 * 1000, 200);
                 }
            if(key == code[i]&& i<sizeof(code)){            //if the char typed is correct a and i increments to verify the next caracter
                 a++;                                              //Now I think maybe I should have use only a or i ... too lazy to test it -_-'
                 i++;
                 
            }
            else{
                a--;}                                            //if the character typed is wrong a decrements and cannot equal the size of code []
            }
            }
}

void OpenDoor(){             //Lock opening function open for 10s
  servo1.write(-40);
  tone(buzzer, 100, 1000);
  delay(700);
  tone(buzzer, 90, 1000); 
  delay(700);
  tone(buzzer, 80, 1000);
  delay(700);
  tone(buzzer, 70, 1000);
  delay(700);
  tone(buzzer, 60, 1000);
  delay(700);
  tone(buzzer, 50, 1000);
  delay(700);
  tone(buzzer, 40, 1000);
  delay(700);
  tone(buzzer, 30, 1000);
  delay(700);
  tone(buzzer, 20, 1000);
  delay(700);
  tone(buzzer, 10, 1000);
  delay(700);
  
  
  //noTone(buzzer); //Stop buzzer
  servo1.write(40);}

void loop() {
  // put your main code here, to run repeatedly:
    char key = keypad.getKey();               //Constantly waiting for a key to be pressed
    if(key == '*'){                      // * to open the lock            //Message to show
            GetCode();                          //Getting code function
                  if(a==sizeof(code)){           //The GetCode function assign a value to a (it's correct when it has the size of the code array)
                  OpenDoor();                   //Open lock function if code is correct
                  }else{          //Message to print when the code is wrong
                  }
            delay(2000);             //Return to standby mode it's the message do display when waiting
        }
}        

 
