
#include <IRLibAll.h>


 
//Create a receiver object to listen on pin 2
IRrecvPCI myReceiver(2);
 
//Create a decoder object 
IRdecode myDecoder;   

IRsendRC6 mySender;
 
void setup() {
  Serial.begin(9600);
  delay(2000); while (!Serial); //delay for Leonardo
  myReceiver.enableIRIn(); // Start the receiver
  Serial.println(F("Ready to receive IR signals"));
}
 
void loop() {
  //Continue looping until you get a complete signal received
  if (myReceiver.getResults()) {
    myDecoder.decode();           //Decode it
    myDecoder.dumpResults(false);  //Now print results. Use false for less detail
    myReceiver.enableIRIn();      //Restart receiver
  }
  if (Serial.read() != -1) {
    //send a code every time a character is received from the serial port
    //Sony DVD power A8BCA
    Serial.println("sending");
    mySender.send(0x1000C, 20);
  }
}
