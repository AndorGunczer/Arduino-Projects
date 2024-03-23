int const redSensorPin = A0;
int const greenSensorPin = A1;
int const blueSensorPin = A2;

int const rgbRedPin = 11;
int const rgbGreenPin = 10;
int const rgbBluePin = 9;

int redSensorValue = 0;
int greenSensorValue = 0;
int blueSensorValue = 0;

int redValue = 0;
int greenValue = 0;
int blueValue = 0;

void takeSensorValues() {
  redSensorValue = analogRead(redSensorPin);
  Serial.print("Value on REDSENSOR: ");
  Serial.print(redSensorValue);
  delay(5);
  greenSensorValue = analogRead(greenSensorPin);
  delay(5);
  blueSensorValue = analogRead(blueSensorPin);
}

void printSensorValues() {
  Serial.print("Raw Sensor Values \t red: ");
  Serial.print(redSensorValue);
  Serial.print("\t green: ");
  Serial.print(greenSensorValue);
  Serial.print("\t blue: ");
  Serial.print(blueSensorValue);
  Serial.print("\n");
}

void setRGBValues() {
  redValue = redSensorValue/4;
  greenValue = greenSensorValue/4;
  blueValue = blueSensorValue/4;
}

void printMappedValues() {
  Serial.print("Mapped Sensor Values \t red: ");
  Serial.print(redValue);
  Serial.print("\t green: ");
  Serial.print(greenValue);
  Serial.print("\t blue: ");
  Serial.print(blueValue);
  Serial.print("\n");
}

void writeValuesToRGBLED() {
  analogWrite(rgbRedPin, redValue);
  analogWrite(rgbGreenPin, greenValue);
  analogWrite(rgbBluePin, blueValue);
}

void setup() {
  // put your setup code here, to run once:
  // Setup serial communication
  Serial.begin(9600);

  // Set Actuator Digital Pin to OUTPUT Mode

  pinMode(rgbRedPin, OUTPUT);
  pinMode(rgbGreenPin, OUTPUT);
  pinMode(rgbBluePin, OUTPUT);

  // Set Sensor Analog Pins to INPUT MODE

  pinMode(redSensorPin, INPUT);
  pinMode(greenSensorPin, INPUT);
  pinMode(blueSensorPin, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  takeSensorValues();
  printSensorValues();
  setRGBValues();
  printMappedValues();
  writeValuesToRGBLED();
}
