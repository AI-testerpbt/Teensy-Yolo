#include <Mouse.h>

String command = "";

void setup() {
  Mouse.begin();
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial connection
  }
}

void loop() {
  while (Serial.available()) {
    char c = Serial.read();
    if (c == '\n') {
      // --- Handle MOVE:x,y ---
      if (command.startsWith("MOVE:")) {
        int commaIndex = command.indexOf(',');
        if (commaIndex > 5) {
          int x = command.substring(5, commaIndex).toInt();
          int y = command.substring(commaIndex + 1).toInt();
          Mouse.move(x, y);
        }
      }

      // --- Handle TAP:x,y ---
      else if (command.startsWith("TAP:")) {
        int commaIndex = command.indexOf(',');
        if (commaIndex > 4) {
          int x = command.substring(4, commaIndex).toInt();
          int y = command.substring(commaIndex + 1).toInt();
          Mouse.move(x, y);
        }
        delay(5);  // slight delay before click
        Mouse.click();
      }

      command = "";  // clear after processing
    } else {
      command += c;
    }
  }
}