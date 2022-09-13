
/*String InBytes;

void setup() {
 Serial.begin(9600);
 pinMode(LED_BUILTIN, HIGH);
}
void loop() {
 if (Serial.available()>0){
 InBytes = Serial.readStringUntil('\n');
 if (InBytes=="0"){
    digitalWrite(LED_BUILTIN, HIGH);
    Serial.write("led on");
 }
  if (InBytes=="1"){
    digitalWrite(LED_BUILTIN, LOW);
    Serial.write("led off");
 }
 }
}
*/
String InBytes;
const int RELAY_PIN=A5;
void setup() {
 Serial.begin(9600);
 pinMode(RELAY_PIN, OUTPUT);
}
void loop() {
 if (Serial.available()>0){
 InBytes = Serial.readStringUntil('\n');
 if (InBytes=="0"){
    digitalWrite(RELAY_PIN, HIGH);
    Serial.write("led on");
    delay(1000);
    digitalWrite(RELAY_PIN, LOW);
 }
  if (InBytes=="1"){
    digitalWrite(RELAY_PIN, LOW);
    Serial.write("led off");
 }
 }
}
