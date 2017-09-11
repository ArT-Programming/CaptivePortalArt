char inputString[255] = "";         // a string to hold incoming data
boolean stringComplete = false;  // whether the string is complete
unsigned int stringIndex = 0;

void handleSerial() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();
    // add it to the inputString:
    inputString[stringIndex] = inChar;
    stringIndex += 1;
    // if the incoming character is a newline, set a flag
    // so the main loop can do something about it:
    if (inChar == '\n') {
      inputString[stringIndex] = '\0';//Maybe this fixes the tx buffer issue, rather implicit. Maybe better to set buffer size.
      stringComplete = true;
      stringIndex = 0;
    }
  }
}
