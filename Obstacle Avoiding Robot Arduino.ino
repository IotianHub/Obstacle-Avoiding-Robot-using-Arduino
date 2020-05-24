/* Obstacle Avoiding Robot Using Ultrasonic Sensor and Arduino

* Iotian Hub(www.iotianhub.com)

*/

int trigPin = 9; // trig pin of HC-SR04

int echoPin = 10; // Echo pin of HC-SR04

int revleft = 4; //Reverse motion of Left motor

int revright = 6; //Reverse motion of Right motor

int fwdleft = 5; //Forward motion of Left motor

int fwdright = 7; //Forward motion of Right motor

long duration, distance;

void setup() {

delay(random(500,2000)); // delay for random time

Serial.begin(9600);

pinMode(revleft, OUTPUT); // set Motor pins as output

pinMode(fwdleft, OUTPUT);

pinMode(revright, OUTPUT);

pinMode(fwdright, OUTPUT);

pinMode(trigPin, OUTPUT); // set trig pin as output

pinMode(echoPin, INPUT);  //set echo pin as input to capture reflected waves

}

void loop() {

digitalWrite(trigPin, LOW);

delayMicroseconds(2);

digitalWrite(trigPin, HIGH); // send waves for 10 us

delayMicroseconds(10);

duration = pulseIn(echoPin, HIGH); // receive reflected waves

distance = duration / 58.2; // convert to distance

delay(10); // If you dont get proper movements of your robot then alter the pin numbers

if (distance > 19)

{

digitalWrite(fwdright, HIGH);  // move forward

digitalWrite(revright, LOW);

digitalWrite(fwdleft, HIGH);

digitalWrite(revleft, LOW);

}

if (distance < 18)

{

digitalWrite(fwdright, LOW); //Stop

digitalWrite(revright, LOW);

digitalWrite(fwdleft, LOW);

digitalWrite(revleft, LOW);

delay(500);

digitalWrite(fwdright, LOW); //move backword

digitalWrite(revright, HIGH);

digitalWrite(fwdleft, LOW);

digitalWrite(revleft, HIGH);

delay(500);

digitalWrite(fwdright, LOW); //Stop

digitalWrite(revright, LOW);

digitalWrite(fwdleft, LOW);

digitalWrite(revleft, LOW);

delay(100);

digitalWrite(fwdright, HIGH);

digitalWrite(revright, LOW);

digitalWrite(revleft, LOW);

digitalWrite(fwdleft, LOW);

delay(500);

}

}
