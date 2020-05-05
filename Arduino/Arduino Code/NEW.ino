#include <SoftwareSerial.h>
#include <Wire.h> // I2C library, required for MLX90614
#include <SparkFunMLX90614.h> // SparkFunMLX90614 Arduino library

IRTherm therm; // Create an IRTherm object to interact with throughout


SoftwareSerial BTserial(10, 11); // Setup of Bluetooth module on pins 10 (TXD) and 11 (RXD);

void setup() {
  
  BTserial.begin(9600); // Bluetooth at baud 9600 for talking to the node server
  Serial.begin(4800); // Default Serial on Baud 4800 for printing out some messages in the Serial Monitor

  therm.begin(); // Initialize thermal IR sensor
  therm.setUnit(TEMP_C); // Set the library's units to Farenheit
  // Alternatively, TEMP_F can be replaced with TEMP_C for Celsius or
  // TEMP_K for Kelvin.
}

void loop() {

  
    
  // Calls on BTSerial and sends the string to any connected devices.
//  BTserial.print("30\n"); 

   if (therm.read()) // On success, read() will return 1, on fail 0.
  {
    // Use the object() and ambient() functions to grab the object and ambient
  // temperatures.
  // They'll be floats, calculated out to the unit you set with setUnit().
//  Serial.println("test2");
    BTserial.print(String(therm.object(), 2)+"\n");
//    BTserial.write('°'); // Degree Symbol
//    BTserial.print("F");
//    BTserial.print("Ambient: " + String(therm.ambient(), 2));
//    BTserial.write('°'); // Degree Symbol
//    BTserial.println("F");
//    BTserial.println();
    
  }
  delay(1000);

  // readStringUntil()
  // Reads all bytes off of the the Serial buffer until it finds the escape character '/n'
  // And then removes these bytes from the buffer
  // Returns the value as a string, which we print to the Serial monitor

  Serial.println(BTserial.readStringUntil('\n'));

  //Just so the Serial Monitor on Arduino and console on the Node server don't get too spammed

}
