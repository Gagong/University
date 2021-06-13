char* Morse_Code[] = {
  "*-", "-***", "*--", "--*", "-**", "*", "***-", "--**", "**", "*---", "-*-", "*-**", "--", "-*", "---", "*--*", "*-*", "***", "-", "**-", "**-*", "****", "-*-*", "---*", "----", "--*-", "-*--", "-**-", "**-**", "**--", "*-*-",
  "*----", "**---", "***--", "****-", "*****", "-****", "--***", "---**", "----*", "-----",
  "......", "*-*-*-", "---***", "-*-*-", "-*--*-", "*----*", "*-**-*", "-****-", "-**-*", "**--**", "--**--",
  "-***-", "********", "*--*-*", "**-*-",
  ""
};

char* ENG[] = {
  "a", "b", "w", "g", "d", "e", "v", "z", "i", "j", "k", "l", "m", "n", "o", "p", "r", "s", "t", "u", "f", "h", "c", "ö", "ch", "q", "y", "x", "é", "ü", "ä",
  "1", "2", "3", "4", "5", "6", "7", "8", "9", "0",
  ".", ",", ":", ";", "(", "\'", "\"", "-", "/", "?", "!",
  " *DELIMITER* ", " *ERR* ", "@", " *END* ",
  ""
};

String Text;

void ConventToMorse(char* str, int led) {
  pinMode(led, OUTPUT);
  int n = 0;
  while (str[n] != '\0') {
    n++;
  }
  int* New_Code = new int [n];
  for (int i = 0; str[i] != '\0'; i++) {
    for (int j = 0; ENG[j] != ""; j++) {
      for (int k = 0; ENG[j][k] != '\0'; k++) {
        if (str[i + k] != ENG[j][k]) {
          break;
        };
        if (ENG[j][k + 1] == '\0') {
          New_Code[i] = j;
        };
      };
    };
  };
  Serial.print("Convent To Morse: ");
  for (int i = 0; i < n; i++) {
    for (int j = 0; Morse_Code[New_Code[i]][j] != '\0'; j++) {
      if (Morse_Code[New_Code[i]][j] == '*') {
        Serial.print("*");
        if (led) {
          digitalWrite(led, HIGH);
        };
        delay(100);
        digitalWrite(led, LOW);
      };
      if (Morse_Code[New_Code[i]][j] == '-') {
        Serial.print("-");
        if (led) {
          digitalWrite(led, HIGH);
        };
        delay(300);
        digitalWrite(led, LOW);
      };
      delay(100);
    };
    Serial.print(" ");
    delay(200);
  };
  Serial.print("\n");
  delete [] New_Code;
};

void setup() {
  Serial.begin(9600);
};

void loop() {
  ConventToMorse("hello", 13);
  delay(2000);
};
