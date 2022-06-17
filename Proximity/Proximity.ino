//collects data from an analog sensor

int sensorpin = D8;                 // analog pin used to connect the sharp sensor
int val = 0;                 // variable to store the values from sensor(initially zero)

void setup()
{
  Serial.begin(9600);               // starts the serial monitor
}
 
void loop()
{
  float volts = analogRead(sensorpin)*0.0048828125;   
  float distance = 65*pow(volts, -1.10);   
  Serial.print(distance);     
  Serial.println(" cm");
  delay(100);                     
}
