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

#include <LiquidCrystal.h>

LiquidCrystal lcd(13,12,11,10,9,8);

int servoPin = 0;
Servo servo1;

int c = 0;

char code[]= {'1','2','3','4'};
short a=0,i=0,s=0,j=0;

int greenPin = A0;
int redPin = A1;



void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);

  servo1.attach(servoPin);
  servo1.write(-10000);
  delay(1000);
  servo1.write(80);
  
  lcd.print("Standby");

  pinMode(greenPin, OUTPUT);
  pinMode(redPin, OUTPUT);
 

}

void GetCode(){                  //Getting code sequence
       i=0;                      //All variables set to 0
       a=0;
       j=0; 
       char key = keypad.getKey();                              
     while(key != '#'){                                     //The user press A to confirm the code otherwise he can keep typing
           key = keypad.getKey();                         
             if(key != NO_KEY && key != '#' ){       //If the char typed isn't A and neither "nothing"
              lcd.setCursor(j,1);                                  //This to write "*" on the LCD whenever a key is pressed it's position is controlled by j
              lcd.print("*");
              j++;
            if(key == code[i]&& i<sizeof(code)){            //if the char typed is correct a and i increments to verify the next caracter
                 a++;                                              //Now I think maybe I should have use only a or i ... too lazy to test it -_-'
                 i++;
                 }
            else
                a--;                                               //if the character typed is wrong a decrements and cannot equal the size of code []
            }
            }
}

void OpenDoor(){             //Lock opening function open for 3s
  lcd.clear();
  lcd.print("Nice");//With a message printed
  digitalWrite(redPin, LOW);
  digitalWrite(greenPin, HIGH);
  servo1.write(-80);
  delay(10000);
  servo1.write(80);
  digitalWrite(greenPin, LOW); 
  digitalWrite(redPin, HIGH);}

void loop() {
  // put your main code here, to run repeatedly:
    char key = keypad.getKey();               //Constantly waiting for a key to be pressed
    digitalWrite(redPin, HIGH);
    if(key == '*'){                      // * to open the lock
            lcd.clear();
            lcd.setCursor(0,0);
            lcd.print("Enter code");            //Message to show
            GetCode();                          //Getting code function
                  if(a==sizeof(code)){           //The GetCode function assign a value to a (it's correct when it has the size of the code array)
                  OpenDoor();                   //Open lock function if code is correct
                  }else{
                  lcd.clear();               
                  lcd.print("Wrong");          //Message to print when the code is wrong
                  }
            delay(2000);
            lcd.clear();
            lcd.print("Standby");             //Return to standby mode it's the message do display when waiting
        }
}        

 
