#include <LiquidCrystal.h>

static int space=100;
static int retain=200;
int i,k,a,n;
String str,str1;
LiquidCrystal lcd(8,9,10,11,12,13);

int alpha[26][6]={{1,0,0,0,0,0},
                {1,1,0,0,0,0},
                {1,0,0,1,0,0},
                {1,0,0,1,1,0},
                {1,0,0,0,1,0},
                {1,1,0,1,0,0},
                {1,1,0,1,1,0},
                {1,1,0,0,1,0},
                {0,1,0,1,0,0},
                {0,1,0,1,1,0},
                {1,0,1,0,0,0},
                {1,1,1,0,0,0},
                {1,0,1,1,0,0},
                {1,0,1,1,1,0},
                {1,0,1,0,1,0},
                {1,1,1,1,0,0},
                {1,1,1,1,1,0},
                {1,1,1,0,1,0},
                {0,1,1,1,0,0},
                {0,1,1,1,1,0},
                {1,0,1,0,0,1},
                {1,1,1,0,0,1},
                {0,1,0,1,1,1},
                {1,0,1,1,0,1},
                {1,0,1,1,1,1},
                {1,0,1,0,1,1}};


void setup()
{
    pinMode(2, OUTPUT);
    pinMode(3, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(5, OUTPUT);
    pinMode(6, OUTPUT);
    pinMode(7, OUTPUT);
  	Serial.begin(9600);
  	lcd.begin(16, 2);
}

void loop()
{
    if (Serial.available() > 0) { 
        str=Serial.readString();
        str.toLowerCase();
        i=0;
        n=str.length();
    }
    
    if(i<=n) {
        if(i%16==0){
            lcd.clear();
            str1=str.substring(i,i+16);
            lcd.setCursor(0, 0);
            lcd.print(str1);
        }
        a=str[i];
        lcd.setCursor(0, 1);
        lcd.print("Current char: ");
      	lcd.print(str[i]);
        if(a>=97&&a<=122) {
            a-=97;
            digitalWrite(2,alpha[a][0]);
            digitalWrite(3,alpha[a][1]);
            digitalWrite(4,alpha[a][2]);
            digitalWrite(5,alpha[a][3]);
            digitalWrite(6,alpha[a][4]);
            digitalWrite(7,alpha[a][5]);
          	Serial.println((char)(a+97));
            delay(retain);
        }
        else if(a==' ') {
          	Serial.println(' ');
            delay(retain);
        }
        digitalWrite(2,0);
        digitalWrite(3,0);
        digitalWrite(4,0);
        digitalWrite(5,0);
        digitalWrite(6,0);
        digitalWrite(7,0);
        delay(space);
        i++;
    }
}