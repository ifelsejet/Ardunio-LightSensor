int lightPin = 0;
int TranslateAnalog = 0;
int photoValue;          // Store value from photoresistor (0-1023)
const int pResistor = A0; // Photoresistor at Arduino analog pin A0
const int ledPin= 9;       // Led pin at Arduino pin 9
const int analogMax = 256;
const long delayTime  = 1000;



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); //Start serial communication
  pinMode(7, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  //Write the value of the photoresistor to the serial monitor
  Serial.println(analogRead(lightPin));
  //Read the Photoresistor value
  TranslateAnalog = analogRead(lightPin);
  //if PhotoResistor Value is above 335 --> turn LED OFF
  if(TranslateAnalog > 355) {
    digitalWrite(7, LOW);
  }
    //if PhotoResistor Value is above 335 --> turn LED ON
  if(TranslateAnalog < 355){
    digitalWrite(7, HIGH);
  }
  for(int i = 0; i < analogMax; i+=2){
      analogWrite(ledPin, i);
      delay(delayTime); 
      photoValue = analogRead(pResistor);
      Serial.print(i);
      Serial.print(" : ");
      Serial.println(photoValue);

}
}
