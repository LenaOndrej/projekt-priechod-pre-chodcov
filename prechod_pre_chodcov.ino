int LED = 21;                          // pin s diódou
int PIR = 4;                          // pin so senzorom
int pir = LOW;                        // na začiatku vypnutý
int val = LOW;                          // premenná na čítanie stavu

void setup() {
  pinMode(LED, OUTPUT);               // dióda je výstup
  pinMode(PIR, INPUT);                // senzor je vstup

  Serial.begin(9600);
}

void loop() {
val = digitalRead(PIR);               // načítanie vstupnej hodnoty
if (val == HIGH) {                    // nastavenie, ak senzor zachytil pohyb
  digitalWrite(LED, HIGH);            // zapne diódu na daný čas
   delay(500);
  digitalWrite(LED, LOW);             // vypne diódu na daný čas
  delay(500);
  if (pir == LOW) {                   // nastavenie, ak senzor nezachytil pohyb
    Serial.println("Pozor chodec!");
    pir = HIGH;
    }
    } else {
      digitalWrite(LED, LOW);
      if (pir == HIGH)  {
        Serial.println("Chodec prešiel!");
        pir = LOW;
        }
      }
}
