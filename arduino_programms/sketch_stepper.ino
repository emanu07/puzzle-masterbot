#include <Stepper.h>

Stepper motore(200, 7, 9, 8, 10);
void setup() {
  motore.setSpeed(150);
  int movimento= 1;
}

void rotate45() {
    motore.step(257);
    delay(500);
}
void rotate90() {
    motore.step(515);
    delay(500);
}
void rotate180() {
    motore.step(1030);
    delay(500);
}
void rotate270() {
    motore.step(1545);
    delay(500);
}
