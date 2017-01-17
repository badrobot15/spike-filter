#include <SpikeFilter.h>

//This example shows how to use the library with acquiring noise
//and spike free sensor readings from the Sharp GP2Y0A41SK0F

//Attach pin that will read the sensor data
SpikeFilter myFilter(A0);

int senseVal,finalVal;

void setup(){
  
  Serial.begin(9600);
  
}

void loop(){
  
  //Call filter() function to recieve spike free sensor values
  senseVal = myFilter.filter();
  
  //Convert sensor data to cm
  finalVal = ((6350/(senseVal-9))-4);
  
  Serial.println(finalVal);
  delay(100); 
}
