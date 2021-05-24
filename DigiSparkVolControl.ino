
#include <TrinketHidCombo.h>

const int volUpPin = 0;  // digispark pins to Volume Up
const int volDownPin = 1;  // digispark pin to Volume Down

// varibales will change:
  int buttonState1 = 0; //VolUp Variable
  int buttonState2 = 0; //VolDown Variable

void setup() {

// Initialize pin 0 (VolUp) & 1 (VolDown) as inputs
  pinMode(volUpPin, INPUT);
  pinMode(volDownPin, INPUT);
  digitalWrite(volUpPin, HIGH);
  digitalWrite(volDownPin, HIGH);
  
  TrinketHidCombo.begin(); // start the USB device engine and enumerate
}

void loop() {


// Read the state of each button
  buttonState1=digitalRead(volUpPin);
  buttonState2=digitalRead(volDownPin);
  
// Small delay for debounce

  delayMicroseconds(20);

// Check state of each button and lower or raise volume. Otherwise, poll USB. 
  
  if (buttonState2 == LOW) {  
    TrinketHidCombo.pressMultimediaKey(MMKEY_VOL_DOWN);
  } 
  
  else if (buttonState1 == LOW) {
    TrinketHidCombo.pressMultimediaKey(MMKEY_VOL_UP);
  }
  
  else {
    TrinketHidCombo.poll(); // do nothing, check if USB needs anything done
  }
  
delay(250);

}
