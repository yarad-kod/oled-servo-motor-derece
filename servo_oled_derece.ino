#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Servo.h>

#define SCREEN_WIDTH 128 // OLED width, in pixels
#define SCREEN_HEIGHT 64 // OLED height, in pixels
#define OLED_RESET     -1 // Reset pin (or -1 if sharing Arduino reset)

// Create the display object (I2C)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

Servo myservo;
int angle = 0;

void setup() {
  // Initialize serial monitor (optional, for debugging)
  Serial.begin(9600);

  // Initialize OLED
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // 0x3C is a common I2C address
    Serial.println(F("SSD1306 allocation failed"));
    for (;;); // Loop forever if OLED init fails
  }
  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);

  // Attach servo to pin 9
  myservo.attach(9);
}

void loop() {
  for (angle = 0; angle <= 180; angle++) {
    myservo.write(angle);
    display.clearDisplay();
    display.setTextSize(2);
    display.setCursor(5, 25); // Adjust for centering
    display.print(angle);
    display.print(F(" Derece"));
    display.display();
    delay(15); // Give servo time to move
  }
  delay(500); // Pause at 180°

  for (angle = 180; angle >= 0; angle--) {
    myservo.write(angle);
    display.clearDisplay();
    display.setTextSize(2);
    display.setCursor(5, 25);
    display.print(angle);
    display.print(F(" Derece"));
    display.display();
    delay(15);
  }
  delay(500); // Pause at 0°, then repeat
}
