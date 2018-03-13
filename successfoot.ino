9#define  midichannel	0;                

int buttonPin  = 2 ;

boolean currentState = LOW ;
boolean lastState = LOW ;

unsigned char status;

void setup()
{

Serial.begin(115200); 
pinMode( buttonPin, INPUT);

} 

void loop()
{
currentState = digitalRead(buttonPin);
if (currentState == HIGH && lastState == LOW)
{
MIDI_TX(144,70,100);
delay(2); 

}

else if(currentState == LOW && lastState == HIGH)
{
MIDI_TX(144,70,0);
delay(2); 
}

lastState = currentState;
}

void MIDI_TX(unsigned char MESSAGE, unsigned char PITCH, unsigned char VELOCITY) 
{
  status = MESSAGE + midichannel;
  Serial.write(status);
  Serial.write(PITCH);
  Serial.write(VELOCITY);
}

