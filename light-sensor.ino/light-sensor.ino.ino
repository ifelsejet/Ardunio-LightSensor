//Constants
const int pResistor = A0; // Photoresistor at Arduino analog pin A0
const int ledPin= 9;       // Led pin at Arduino pin 9
const int analogMax = 256;
const long delayTime  = 1000;

//Variables
int photoValue;          // Store value from photoresistor (0-1023)

void setup(){
 Serial.begin(9600);   
 pinMode(ledPin, OUTPUT);  // Set ledPin - 9 pin as an output
 pinMode(pResistor, INPUT);// Set pResistor - A0 pin as an input (optional)
}

void loop(){  
  for(int i = 0; i < analogMax; i+=2){
      analogWrite(ledPin, i);
      delay(delayTime); 
      photoValue = analogRead(pResistor);
      Serial.print(i);
      Serial.print(" : ");
      Serial.println(photoValue);

  }

}
