#include "Arduino.h"
#include "MIDI.h"

MIDI_CREATE_DEFAULT_INSTANCE();

#define pinTRIG 2
#define pinECHO 3
#define pinLED 4

void setup() {

  MIDI.begin(MIDI_CHANNEL_OMNI);
  Serial.begin(115200);
  pinMode(pinTRIG, OUTPUT);
  pinMode(pinLED, OUTPUT);
}

void loop() {


  //petit signal audio envoyé
  digitalWrite(pinTRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(pinTRIG, LOW);


  //récupérer le signal
  float duration = pulseIn(pinECHO, HIGH);
  float distance = (duration/58) ;



  if(distance<64){
    MIDI.sendControlChange(1,distance*2, 1);
    digitalWrite(pinLED, HIGH);
  }else{
    digitalWrite(pinLED, LOW);
  }


}