/******************************************************************************
Flex_Sensor_Example.ino
Example sketch for SparkFun's flex sensors
  (https://www.sparkfun.com/products/10264)
Jim Lindblom @ SparkFun Electronics
April 28, 2016

Create a voltage divider circuit combining a flex sensor with a 47k resistor.
- The resistor should connect from A0 to GND.
- The flex sensor should connect from A0 to 3.3V
As the resistance of the flex sensor increases (meaning it's being bent), the
voltage at A0 should decrease.

Development environment specifics:
Arduino 1.6.7
******************************************************************************/
const int FLEX_PIN_1 = A0; // Pin connected to voltage divider output
const int FLEX_PIN_2 = A1; // Pin connected to voltage divider output
const int FLEX_PIN_3 = A2; // Pin connected to voltage divider output
const int FLEX_PIN_4 = A3; // Pin connected to voltage divider output
const int FLEX_PIN_5 = A4; // Pin connected to voltage divider output
// Measure the voltage at 5V and the actual resistance of your
// 47k resistor, and enter them below:
const float VCC = 4.98; // Measured voltage of Ardunio 5V line
const float R_DIV = 47500.0; // Measured resistance of 3.3k resistor

// Upload the code, then try to adjust these values to more
// accurately calculate bend degree.
const float STRAIGHT_RESISTANCE = 37300.0; // resistance when straight
const float BEND_RESISTANCE = 90000.0; // resistance at 90 deg

void setup() 
{
  Serial.begin(9600);
  pinMode(FLEX_PIN_1, INPUT);
  pinMode(FLEX_PIN_2, INPUT);
  pinMode(FLEX_PIN_3, INPUT);
  pinMode(FLEX_PIN_4, INPUT);
  pinMode(FLEX_PIN_5, INPUT);
}

void loop() 
{
  //First Finger
  // Read the ADC, and calculate voltage and resistance from it
  int flexADC_1 = analogRead(FLEX_PIN_1);
  float flexV_1 = flexADC_1 * VCC / 1023.0;
  float flexR_1 = R_DIV * (VCC / flexV_1 - 1.0);
  Serial.println("Resistance 1: " + String(flexR_1) + " ohms");

    // Use the calculated resistance to estimate the sensor's
  // bend angle:
  float angle_1 = map(flexR_1, STRAIGHT_RESISTANCE, BEND_RESISTANCE,
                   0, 90.0);
  Serial.println("Bend1 1: " + String(angle_1) + " degrees");

  //Second Finger
  // Read the ADC, and calculate voltage and resistance from it
  int flexADC_2 = analogRead(FLEX_PIN_2);
  float flexV_2 = flexADC_2 * VCC / 1023.0;
  float flexR_2 = R_DIV * (VCC / flexV_2 - 1.0);
  Serial.println("Resistance 2: " + String(flexR_2) + " ohms");
  // Use the calculated resistance to estimate the sensor's
  // bend angle:
  float angle_2 = map(flexR_2, STRAIGHT_RESISTANCE, BEND_RESISTANCE,
                   0, 90.0);
  Serial.println("Bend1 2: " + String(angle_2) + " degrees");

  

  //Third Finger
  // Read the ADC, and calculate voltage and resistance from it
  int flexADC_3 = analogRead(FLEX_PIN_3);
  float flexV_3 = flexADC_3 * VCC / 1023.0;
  float flexR_3 = R_DIV * (VCC / flexV_3 - 1.0);
  Serial.println("Resistance 3: " + String(flexR_3) + " ohms");
   // Use the calculated resistance to estimate the sensor's
  // bend angle:
  float angle_3 = map(flexR_3, STRAIGHT_RESISTANCE, BEND_RESISTANCE,
                   0, 90.0);
  Serial.println("Bend1 3: " + String(angle_3) + " degrees");



//Fourth Finger
  // Read the ADC, and calculate voltage and resistance from it
  int flexADC_4 = analogRead(FLEX_PIN_4);
  float flexV_4 = flexADC_4 * VCC / 1023.0;
  float flexR_4 = R_DIV * (VCC / flexV_4 - 1.0);
  Serial.println("Resistance 4: " + String(flexR_4) + " ohms");
   // Use the calculated resistance to estimate the sensor's
  // bend angle:
  float angle_4 = map(flexR_4, STRAIGHT_RESISTANCE, BEND_RESISTANCE,
                   0, 90.0);
  Serial.println("Bend1 4: " + String(angle_4) + " degrees");


//Fifth Finger
  // Read the ADC, and calculate voltage and resistance from it
  int flexADC_5 = analogRead(FLEX_PIN_5);
  float flexV_5 = flexADC_5 * VCC / 1023.0;
  float flexR_5 = R_DIV * (VCC / flexV_5 - 1.0);
  Serial.println("Resistance 5: " + String(flexR_5) + " ohms");
   // Use the calculated resistance to estimate the sensor's
  // bend angle:
  float angle_5 = map(flexR_5, STRAIGHT_RESISTANCE, BEND_RESISTANCE,
                   0, 90.0);
  Serial.println("Bend1 5: " + String(angle_5) + " degrees");
  

  if(angle_1>5 && angle_2 >5 && angle_3>5 && angle_4>5 && angle_5> 5)
  {
    Serial.println("Label: ح");
  }
  else if(angle_1<-1 && angle_2<-5  &&angle_3<-5  &&angle_4<-5  && angle_5 <-5 ){
    Serial.println("Label: خ");
  }
  else if(angle_1>5 && angle_2>5  && angle_3>5  && angle_4<-3 && angle_5<-3){
    Serial.println("Label: د");
  }
   else if(angle_1>5 && angle_2>5 && angle_3<-3  && angle_4<-3 && angle_5<-3){
    Serial.println("Label: ذ");
  }
   else if(angle_1>5 && angle_2 >5 && angle_3>5 && angle_4<-3 && angle_5> 5){
    Serial.println("Label: ر");
  }
  else
  {
    Serial.println("Label: O");
  }
  Serial.println();

  delay(1000);
}
