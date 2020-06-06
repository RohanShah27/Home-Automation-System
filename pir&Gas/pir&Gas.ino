int red_led=12;
//int green_led=11;
int buzz=13;
int gas_value;
int gas_avalue;
int sensorThres=600;

int ledPin = 8;                // choose the pin for the LED
int inputPin = 2;               // choose the input pin (for PIR sensor)
int pirState = LOW;             // we start, assuming no motion detected
int val = 0;  

void setup()
{

pinMode(red_led,OUTPUT);

pinMode(buzz,OUTPUT);

//pinMode(green_led,OUTPUT);

pinMode(A0,INPUT);
//PIR Sensor
 pinMode(ledPin, OUTPUT);      // declare LED as output
  pinMode(inputPin, INPUT);     // declare sensor as input
   

Serial.begin(9600);

}

void loop()

{

gas_avalue=analogRead(A0);

if (gas_avalue > sensorThres)

{

digitalWrite(red_led, HIGH);

//digitalWrite(green_led, LOW);

digitalWrite( buzz, HIGH);

Serial.println("DANGER!!!!");

Serial.println(gas_avalue);

}

else

{

digitalWrite(red_led, LOW);

//digitalWrite(green_led, HIGH);

digitalWrite( buzz, LOW);

Serial.println("NO LEAKAGE");

Serial.println(gas_avalue);

}
// Serial.println("Motion detected!");
 val = digitalRead(inputPin);  // read input value
  if (val == HIGH) {            // check if the input is HIGH
    digitalWrite(ledPin, HIGH);  // turn LED ON
    if (pirState == LOW) {
      // we have just turned on
      Serial.println("Motion detected!");
      // We only want to print on the output change, not state
      pirState = HIGH;
      delay(500);
    }
  } else {
    digitalWrite(ledPin, LOW); // turn LED OFF
    if (pirState == HIGH){
      // we have just turned of
      Serial.println("Motion ended!");
      // We only want to print on the output change, not state
      pirState = LOW;
    }
  }

delay(100);

}


