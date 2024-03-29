int baselineTemp = 0;
int celsius = 0;
int fahrenheit = 0;
int pinSensor =2;

int pinBuzzer =7;
int pirSensor =0;

void setup()
{
  pinMode(A0, INPUT);
  Serial.begin(9600);
  pinMode(pinSensor, INPUT);
  pinMode(pinBuzzer, OUTPUT);
  pinMode(7, OUTPUT);
}

void loop()
{
  baselineTemp = 60;
  pirSensor = digitalRead(pinSensor);
  celsius = map(((analogRead(A0) - 20) * 3.04), 0, 1023, -40, 125);
  
   fahrenheit = ((celsius * 9) / 5 + 32);
  Serial.print(celsius);
  Serial.print(" C, ");
  Serial.print(fahrenheit);
  Serial.println(" F");
  
 
  if (celsius >= baselineTemp + 1) {
   
    tone(7, 220, 100);
    delay(100);
  }
  

 
  if (pirSensor == HIGH)
  {
  
   
    tone(pinBuzzer, 1000, 500);
  
  }
  
 
  
  delay(100);
}