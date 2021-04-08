const int BUTTON_PIN = 7;
const int BUZZER = 5;
const int VIBRATOR = 3;
int c = 0;
void setup() {
Serial.begin(9600);
pinMode(BUTTON_PIN, INPUT_PULLUP);
pinMode(BUZZER, OUTPUT);
pinMode(VIBRATOR, OUTPUT);
}

void loop() {
int i = digitalRead(BUTTON_PIN);
if(i==HIGH){
//Mask removed
digitalWrite(VIBRATOR, HIGH); //turn on vibration
c++;
if(c>2000)
{
  //each time c becomes a value when 200 is added, it is 1 second.
  //ten seconds passed
  tone(BUZZER, 50); //turn on buzzer
}
Serial.println(c);
}
else
{
  //Mask on face
  c=0;
  noTone(BUZZER); //Turn off Buzzer
  digitalWrite(VIBRATOR, LOW); //Turn of Vibration
  Serial.println(c);
}

}
