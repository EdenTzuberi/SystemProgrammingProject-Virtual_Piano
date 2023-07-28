int buttonPin1 = 2;
int buttonPin2 = A5;
int buttonPin3 = A4;
int buttonPin4 = A3;
int buttonPin5 = A2;
int buttonPin6 = A1;
int buttonPin7 = A0;
int buttonPin8 = 13;

int LEDPin1  = 3;
int LEDPin2  = 5;
int LEDPin3  = 6;
int LEDPin4  = 7;
int LEDPin5  = 8;
int LEDPin6  = 9;
int LEDPin7  = 10;
int LEDPin8  = 11;

int arduinoValue = 0; // Set the initial value

void setup() {
  pinMode(buttonPin1, INPUT); // Set push button into input mode
  pinMode(LEDPin1, OUTPUT);

  pinMode(buttonPin2, INPUT); // Set push button into input mode
  pinMode(LEDPin2, OUTPUT);

  pinMode(buttonPin3, INPUT); // Set push button into input mode
  pinMode(LEDPin3, OUTPUT);

  pinMode(buttonPin4, INPUT); // Set push button into input mode
  pinMode(LEDPin4, OUTPUT);

  pinMode(buttonPin5, INPUT); // Set push button into input mode
  pinMode(LEDPin5, OUTPUT);

  pinMode(buttonPin6, INPUT); // Set push button into input mode
  pinMode(LEDPin6, OUTPUT);

  pinMode(buttonPin7, INPUT); // Set push button into input mode
  pinMode(LEDPin7, OUTPUT);

  pinMode(buttonPin8, INPUT); // Set push button into input mode
  pinMode(LEDPin8, OUTPUT);

  Serial.begin(115200); // Set the baud rate to match the C program
}

void loop() {
  
  int buttonState1 = digitalRead(buttonPin1);
  int buttonState2 = analogRead(buttonPin2);
  int buttonState3 = analogRead(buttonPin3); 
  int buttonState4 = analogRead(buttonPin4);
  int buttonState5 = analogRead(buttonPin5);
  int buttonState6 = analogRead(buttonPin6);
  int buttonState7 = analogRead(buttonPin7);
  int buttonState8 = digitalRead(buttonPin8);


  if(buttonState1 == LOW)
  {
    digitalWrite(LEDPin1, LOW);  // turn the LED on (HIGH is the voltage level)      
  }
  else
  {
    digitalWrite(LEDPin1, HIGH);  // turn the LED on (HIGH is the voltage level)      
    arduinoValue = 1;
  }

    if(buttonState2 == 0)
    {
      digitalWrite(LEDPin2, LOW);  // turn the LED on (HIGH is the voltage level)    
    }
  else
    {
      digitalWrite(LEDPin2, HIGH);   // turn the LED off by making the voltage LOW
      arduinoValue = 2;
    }

    if(buttonState3 == 0)
    {
      digitalWrite(LEDPin3, LOW);  // turn the LED on (HIGH is the voltage level)  
    }
  else
    {
      digitalWrite(LEDPin3, HIGH);   // turn the LED off by making the voltage LOW
      arduinoValue = 3;
    }

    if(buttonState4 == 0)
    {
      digitalWrite(LEDPin4, LOW);  // turn the LED on (HIGH is the voltage level)  
    }
  else
    {
      digitalWrite(LEDPin4, HIGH);   // turn the LED off by making the voltage LOW
      arduinoValue = 4;
    }

    if(buttonState5 == 0)
    {
      digitalWrite(LEDPin5, LOW);  // turn the LED on (HIGH is the voltage level)    
    }
  else
    {
      digitalWrite(LEDPin5, HIGH);   // turn the LED off by making the voltage LOW
      arduinoValue = 5;
    }

    if(buttonState6 == 0)
    {
      digitalWrite(LEDPin6, LOW);  // turn the LED on (HIGH is the voltage level)   
    }
  else
    {
      digitalWrite(LEDPin6, HIGH);   // turn the LED off by making the voltage LOW
      arduinoValue = 6;
    }

    if(buttonState7 == 0)
    {
      digitalWrite(LEDPin7, LOW);  // turn the LED on (HIGH is the voltage level)
    }
  else
    {
      digitalWrite(LEDPin7, HIGH);   // turn the LED off by making the voltage LOW
      arduinoValue = 7;
    }

  if(buttonState8 == HIGH)
    {
      digitalWrite(LEDPin8, HIGH);  // turn the LED on (HIGH is the voltage level)
      arduinoValue = 8;   
    }
  else
    {
      digitalWrite(LEDPin8, LOW);  // turn the LED on (HIGH is the voltage level)    
    }
  
    Serial.println(arduinoValue);  // Send the current value to the C program
    
    delay(50); // Adjust the delay as needed  
}