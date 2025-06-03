#include <Servo.h>

// ------------------- DEFINIZIONE SERVI -------------------
Servo servo1, servo2, servo3, servo4;

// ------------------- STEP PER SERVO1 E SERVO2 -------------------
int steps1[] = {76, 79, 120, 111, 64, 64, 76, 60, 128};     // Servo1
int steps2[] = {125, 123, 122, 95, 96, 88, 125, 100, 108};  // Servo2
const int numSteps12 = 9;

// ------------------- IMPOSTAZIONI GENERALI -------------------
const int interpSteps = 30;
const int interpDelay = 20;
const int delayStep = 800;

// ------------------- MOVIMENTO FLUIDO SINGOLO -------------------
void moveSmooth(Servo &servo, int from, int to, int steps = interpSteps, int delayT = interpDelay) {
  for (int i = 0; i <= steps; i++) {
    float progress = (float)i / steps;
    int pos = from + progress * (to - from);
    servo.write(pos);
    delay(delayT);
  }
}

// ------------------- MOVIMENTO FLUIDO SINCRONO PER DUE SERVO -------------------
void moveSmoothSync(Servo &servoA, int fromA, int toA, Servo &servoB, int fromB, int toB, int steps = interpSteps, int delayT = interpDelay) {
  for (int i = 0; i <= steps; i++) {
    float progress = (float)i / steps;
    int posA = fromA + progress * (toA - fromA);
    int posB = fromB + progress * (toB - fromB);
    servoA.write(posA);
    servoB.write(posB);
    delay(delayT);
  }
}

// ------------------- SERVO1 E SERVO2: 7 STEP SINCRONI -------------------
void Movimentobracciocubo(Servo &servoA, const int* stepsA, Servo &servoB, const int* stepsB, int numSteps, int posizioneRiposoA, int posizioneRiposoB) //cambiare con variabili nuove, stepsA. stepsB, numSteps
{
  for (int i = 1; i < numSteps; i++) {
    moveSmoothSync(servoA, stepsA[i - 1], stepsA[i], servoB, stepsB[i - 1], stepsB[i]);
    delay(delayStep);
  }
  moveSmoothSync(servoA, stepsA[numSteps - 1], posizioneRiposoA, servoB, stepsB[numSteps - 1], posizioneRiposoB);
}

// ------------------- SERVO3 E SERVO4: MOVIMENTI CON TARGET DIFFERENTI PER SCAN ARM-------------------
void MovimentoBraccioCentri(Servo &servoA, Servo &servoB) {
  const int targetA = 90;
  const int targetB = 130;
  moveSmoothSync(servoA, 117, targetA, servoB, 64, targetB);
  delay(delayStep);
  moveSmoothSync(servoA, targetA, 117, servoB, targetB, 64);
}

void MovimentoBraccioSpigoli(Servo &servoA, Servo &servoB) {
  const int targetA = 87;
  const int targetB = 111;
  moveSmoothSync(servoA, 117, targetA, servoB, 64, targetB);
  delay(delayStep);
  moveSmoothSync(servoA, targetA, 117, servoB, targetB, 64);
}

void MovimentoBraccioVertici(Servo &servoA, Servo &servoB) {
  const int targetA = 91;
  const int targetB = 110;
  moveSmoothSync(servoA, 117, targetA, servoB, 64, targetB);
  delay(delayStep);
  moveSmoothSync(servoA, targetA, 117, servoB, targetB, 64);
}

// ------------------- SETUP -------------------
void setup() {
  servo1.attach(3);
  servo2.attach(5);
  servo3.attach(6);
  servo4.attach(11);
}

// ------------------- LOOP DI TEST -------------------
void loop() {
  // Movimento sincronizzato su 7 step per servo1 e servo2
  Movimentobracciocubo(servo1, steps1, servo2, steps2, numSteps12, 76, 125);

  // Movimento sincronizzato con target diversi per servo3 e servo4
  MovimentoBraccioCentri(servo3, servo4);
  MovimentoBraccioSpigoli(servo3, servo4);
  MovimentoBraccioVertici(servo3, servo4);

  delay(3000); // Pausa prima di ricominciare
}
