#define led7     13
#define led6     11
#define led5     10
#define led4     9
#define led3     8
#define led2     7
#define led1     6
#define led0     5
#define Power    12
#define Switch   4
#define Button8  3
#define Button7  2
#define Button6  23
#define Button5  22
#define Button4  21
#define Button3  20
#define Button2  19
#define Button1  18

const unsigned long pulseDuration = 500000; // 2000: 2ms as default

int valSwitch = 0;      
int valButton1 = 0;
int valButton2 = 0;
int Flag  = 0;   

// the setup routine runs once when you press reset:
void setup() {               
  // initialize the digital pin as an output.
  pinMode(led7, OUTPUT);
  pinMode(led6, OUTPUT); 
  pinMode(led5, OUTPUT); 
  pinMode(led4, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led2, OUTPUT); 
  pinMode(led1, OUTPUT); 
  pinMode(led0, OUTPUT);
  pinMode(Switch,   INPUT); 
  pinMode(Button8,  INPUT);
  pinMode(Button7,  INPUT); 
  pinMode(Button6,  INPUT); 
  pinMode(Button5,  INPUT);
  pinMode(Button4,  INPUT); 
  pinMode(Button3,  INPUT); 
  pinMode(Button2,  INPUT);
  pinMode(Button1,  INPUT); 
  pinMode(Power, OUTPUT); 
  Serial.begin(115200);

}

// the loop routine runs over and over again forever:
void loop() {
  // power of button
  digitalWrite(Power, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(led7, LOW);digitalWrite(led6, LOW);digitalWrite(led5, LOW);digitalWrite(led4, LOW);digitalWrite(led3, LOW);digitalWrite(led2, LOW);digitalWrite(led1, LOW);digitalWrite(led0, LOW);
  valButton1 = 0;
  valButton2 = 0;

  valButton1 += static_cast<int>(digitalRead(Button1)) * 1; 
  valButton1 += static_cast<int>(digitalRead(Button2)) * 2;
  valButton2 += valButton1;
  valButton2 += static_cast<int>(digitalRead(Button3)) * 3;
  valButton2 += static_cast<int>(digitalRead(Button4)) * 4;
  valButton2 += static_cast<int>(digitalRead(Button5)) * 5;
  valButton2 += static_cast<int>(digitalRead(Button6)) * 6;
  valButton2 += static_cast<int>(digitalRead(Button7)) * 7;
  valButton2 += static_cast<int>(digitalRead(Button8)) * 8;
  valSwitch = digitalRead(Switch);
  Serial.println(valButton2);
    
}



void trigger(byte inByte, unsigned long pulseDuration) {
  int b0 = bitRead(inByte, 0);
  int b1 = bitRead(inByte, 1);
  int b2 = bitRead(inByte, 2);
  int b3 = bitRead(inByte, 3);
  int b4 = bitRead(inByte, 4);
  int b5 = bitRead(inByte, 5);
  int b6 = bitRead(inByte, 6);
  int b7 = bitRead(inByte, 7); 

  unsigned long Timer = micros();
  while (micros() - Timer < pulseDuration){
    // set data bit pins
    digitalWrite(led0, b0);        
    digitalWrite(led1, b1);
    digitalWrite(led2, b2);
    digitalWrite(led3, b3);
    digitalWrite(led4, b4);
    digitalWrite(led5, b5);
    digitalWrite(led6, b6);
    digitalWrite(led7, b7);
  }
}
