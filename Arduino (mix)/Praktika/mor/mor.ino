char* morseCode[] = {
  "*-", "-***", "*--", "--*", "-**", "*", "***-", "--**", "**", "*---",
  "-*-", "*-**", "--", "-*", "---", "*--*", "*-*", "***", "-", "**-",
  "**-*", "****", "-*-*", "---*", "----", "--*-", "-*--", "-**-", "**-**", "**--",
  "*-*-",
  "*----", "**---", "***--", "****-", "*****", "-****", "--***", "---**", "----*", "-----",
  "......", "*-*-*-", "---***", "-*-*-", "-*--*-", "*----*", "*-**-*", "-****-", "-**-*", "**--**", "--**--",
  "-***-", "********", "*--*-*", "**-*-",
  ""
};

char* layoutCyrillic[] = {
  "а", "б", "в", "г", "д", "е", "ж", "з", "и", "й",
  "к", "л", "м", "н", "о", "п", "р", "с", "т", "у",
  "ф", "х", "ц", "ч", "ш", "щ", "ы", "ь", "э", "ю",
  "я",
  "1", "2", "3", "4", "5", "6", "7", "8", "9", "0",
  ".", ",", ":", ";", "(", "\'", "\"", "-", "/", "?", "!",
  " *DELIMITER* ", " *ERR* ", "@", " *END* ",
  ""
};

char* layoutLatin[] = {
  "a", "b", "w", "g", "d", "e", "v", "z", "i", "j",
  "k", "l", "m", "n", "o", "p", "r", "s", "t", "u",
  "f", "h", "c", "ö", "ch", "q", "y", "x", "é", "ü",
  "ä",
  "1", "2", "3", "4", "5", "6", "7", "8", "9", "0",
  ".", ",", ":", ";", "(", "\'", "\"", "-", "/", "?", "!",
  " *DELIMITER* ", " *ERR* ", "@", " *END* ",
  ""
};

void morse(char* str, int led) {
  pinMode(led, OUTPUT);
  int n = 0;
  while (str[n] != '\0') {
    n++;
  int* morseMas = new int [n];
  for (int i = 0; str[i] != '\0'; i++) {
    for (int j = 0; layoutCyrillic[j] != ""; j++) {
      for (int k = 0; layoutCyrillic[j][k] != '\0'; k++) {
        if (str[i + k] != layoutCyrillic[j][k]) {
          break;
        }
        if (layoutCyrillic[j][k + 1] == '\0') {
          morseMas[i] = j;
        }
      }
      for (int k = 0; layoutLatin[j][k] != '\0'; k++) {
        if (str[i + k] != layoutLatin[j][k]) {
          break;
        }
        if (layoutLatin[j][k + 1] == '\0') {
          morseMas[i] = j;
        }
      }
    }
  }
  Serial.print("Morse code: ");
  for (int i = 0; i < n; i++) {
    for (int j = 0; morseCode[morseMas[i]][j] != '\0'; j++) {
      if (morseCode[morseMas[i]][j] == '*') {
        Serial.print("*");
        if (led) digitalWrite(led, HIGH);
        delay(100);
        digitalWrite(led, LOW);
      }
      if (morseCode[morseMas[i]][j] ==  '-') {
        Serial.print("-");
        if (led) digitalWrite(led, HIGH);
        delay(300);
        digitalWrite(led, LOW);
      }
      delay(100);
    }
    Serial.print(" ");
    delay(200);
  }
  Serial.print("\n");
  delete [] morseMas;
}
}
  void setup() {
    Serial.begin(9600);
}
  void loop() {
    morse("abc", 13);
    delay(2000);
  }
