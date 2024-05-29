int posizione   // 0 = 0 gradi    255 = 180 gradi


void setup() {
  pinMode(3, OUTPUT);
  posizione = 0;
}

void loop() {
  analogWrite (3, posizione);
}