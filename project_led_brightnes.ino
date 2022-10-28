const byte led_point = 18;

#define POTENTIOMETER_PIN  15



void setup() {
  Serial.begin(9600);

  pinMode(POTENTIOMETER_PIN, INPUT);
  ledcAttachPin(led_point, 0); // assign a led pins to a channel

  
  ledcSetup(0, 4000, 8); // 12 kHz PWM, 8-bit resolution
}


void loop() {
  int analogValue = analogRead(POTENTIOMETER_PIN);
  int brightness = map(analogValue, 0, 4095, 0, 255);
  ledcWrite(0, brightness); // set the brightness of the LED
  // wait for 30 milliseconds to see the dimming effect
  Serial.println(brightness);
  delay(30);
}
