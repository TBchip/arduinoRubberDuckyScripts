#include <Keyboard.h>

char windows = KEY_LEFT_GUI;

void setup() {
  delay(1000);
  Keyboard.begin();
  
  Keyboard.press(windows);
  Keyboard.press('r');
  Keyboard.releaseAll();
  delay(100);
  
  Keyboard.println("www.google.com");
  
  Keyboard.end();
}

void loop() {
  // put your main code here, to run repeatedly:

}
