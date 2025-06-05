#include <Servo.h>																		 //libreria per i servomotori
#include <Stepper.h>																	 //libreria per stepper
int stato=0;                                           //variabile che mi fa cambiare fase sul loop
bool first=true;                                       //serve per trasformare le fesi della macchina a stati finiti in dei cicli finiti e non dei loop
//variabili utili per la parte di programma "orientare_cubo"
int c1, c2, c3=3, c4=4, c5=5, c6=6;	                	//creo le variabili che contengono l'informazione del colore dei centri
int n=0;							                              	//creo una variabile che utilizzerò come contatore
//variabili utili per la parte di programma "scansione_pezzi"
int nf;							                            	  	//variabile utile per il contatore delle facce del cubo
int ns;								                              	//variabile utile per il contatore delle volte di pezzi da scansionare
int t=0;							                              	//variabile utile per capire in che posizione degli Array mettere i singoli pezzi
int lati[1][24];				                          		//array che conterrà tutte le informazioni sui lati scombinati e adimensionali
int vertici[1][24];				                        		//array che conterrà  tutte le informazioni sui vertici scombinati e adimensonali
//variabili utili per la parte di programma "ordinare_vertici"
int vertici_ins[8][3];                                //array che contiene gli insiemi delle informazioni degli array dei singoli vertici scombinati
int vertici_vero[8][3]={{1,4,5}, {1,4,3}, {1,3,2}, {1,2,5}, {4,5,6}, {3,4,6}, {2,3,6}, {2,5,6}};//array che contiene le informazioni dei vertici giusti
//variabili utili per la parte di programma "ordinare_pezzi"
int lati_ins[12][2];                                  //array che contiene gli insiemi degli array dei singoli 12 lati
int lati_vero[12][2]={{1,4}, {1,3}, {1,2}, {1,5}, {2,3}, {2,6}, {2,5}, {3,4}, {3,6}, {4,5}, {4,6}, {5,6}};//array che contiene le informazioni dei lati giusti
//variabili utili per la parte di programma "sequenza_combinazione_vertici_definitiva"
int end=0;																						//variabile che mi farà uscire dal ciclo più grande
int end_int=0;																				//variabile che mi farà uscire dal ciclo più interno
int d=0;																					  	//contatore
int i=0;																					  	//contatore
int m=0;																					  	//variabile che conterrà l'informazione del numero del buffer
int parita=0;																					//contatore per vedere quante volte permuta i vertici, in modo da capire se eseguire una parità o meno
//variabili utili per la parte di programma "sequenza_combinazione_pezzi" sono gia stati precedentemente nominati, basterà solamente reinizializzare le variabili a 0 a inizio programma

// Pin collegamenti per sensore di colore
int red=0;
int green=0;
int blue=0;
const int S0 = 1;
const int S1 = 2;
const int S2 = 4;
const int S3 = 12;
const int OUT = 13;

//piedinature Stepper
Stepper motore(200, 7, 9, 8, 10);

// Funzione per misurare la frequenza per un dato filtro
int leggiColore(int s2, int s3) {
  digitalWrite(S2, s2);
  digitalWrite(S3, s3);
  delay(100);  // Attendi che il sensore si stabilizzi
  return pulseIn(OUT, LOW);
}

// Funzione per riconoscere il colore in base agli intervalli forniti
int riconosciColore(int R, int G, int B) {
  if (R >=4 && R <= 8 && G >= 16 && G <= 27 && B >= 13 && B <= 21) {
    return 3;
  } else if (R >= 17 && R <= 31 && G >= 15 && G <= 22 && B >= 9 && B <= 16) {
    return 4;
  } else if (R >= 13 && R <= 18 && G >= 8 && G <= 15 && B >= 14 && B <= 20) {
    return 2;
  } else if (R >= 2 && R <= 5 && G >= 9 && G <= 15 && B >= 9 && B <= 15) {
    return 5;
  } else if (R >= 3 && R <= 7 && G >= 4 && G <= 7 && B >= 8 && B <= 12) {
    return 1;
  } else if (R >= 2 && R <= 6 && G >= 4 && G <= 7 && B >= 3 && B <= 7) {
    return 6;
  } 
}


// ------------------- DEFINIZIONE SERVI -------------------
Servo servo1, servo2, servo3, servo4;

// ------------------- STEP PER SERVO1 E SERVO2 -------------------
int steps1[] = {76, 79, 120, 111, 64, 64, 76, 60, 128};     // Servo1
int steps2[] = {125, 123, 122, 95, 96, 88, 125, 100, 108};  // Servo2
const int numSteps12 = 9;

// ---------- STEP PER BRACCIO PER ROTAZIONE CUBO --------
int stepsorienta1[] = {76, 79, 120, 111};     // Servo1
int stepsorienta2[] = {125, 123, 122, 95};  // Servo2
const int numStepsorienta = 4;
//const int numStepsorienta12 = 4; l'ho passivato perchè solo qua l'ha chiamato numStepsorienta12 quando ovunque il richiamo è numStepsorienta, come impostato ora sopra 

// ------------------- IMPOSTAZIONI GENERALI -------------------
const int interpSteps = 30;
const int interpDelay = 20;
const int delayStep = 800;
//-----------------NON SO COSA FACCIANO STE VARIABILI MA VANNO MESSE FUORI DAL SETUP----------------
int posizioneRiposo1=169;
int posizioneRiposo2=8;

int posizioneRiposoA=169;
int posizioneRiposoB=8;

// ------------------- FUNZIONE MOVIMENTO FLUIDO SINCRONO PER DUE SERVO -------------------
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

// ------------------- FUNZIONE SERVO1 E SERVO2: 7 STEP SINCRONI -------------------
void Movesx(Servo &servoA, const int* stepsA, Servo &servoB, const int* stepsB, int numSteps, int posizioneRiposoA, int posizioneRiposoB) {
  for (int i = 1; i < numSteps; i++) {
    moveSmoothSync(servoA, stepsA[i - 1], stepsA[i], servoB, stepsB[i - 1], stepsB[i]);
    delay(delayStep);
  }
  moveSmoothSync(servoA, stepsA[numSteps - 1], posizioneRiposoA, servoB, stepsB[numSteps - 1], posizioneRiposoB);
}



// ------------------- FUNZIONI SERVO3 E SERVO4: MOVIMENTI CON TARGET DIFFERENTI -------------------
void scanCentri(Servo &servoA, Servo &servoB) {
  const int targetA = 90;
  const int targetB = 130;
  moveSmoothSync(servoA, 117, targetA, servoB, 64, targetB);
  delay(delayStep);
  moveSmoothSync(servoA, targetA, 117, servoB, targetB, 64);
}

void scanCentriritorno(Servo &servoA, Servo &servoB) {
  const int targetA = 90;
  const int targetB = 130;
  moveSmoothSync(servoA, targetA, 117, servoB, targetB, 64);
	delay(delayStep);
}

void scanSpigoli(Servo &servoA, Servo &servoB) {
  const int targetA = 87;
  const int targetB = 111;
  moveSmoothSync(servoA, 117, targetA, servoB, 64, targetB);
  delay(delayStep);
}

void scanSpigoliritorno(Servo &servoA, Servo &servoB) {
  const int targetA = 87;
  const int targetB = 111;
  moveSmoothSync(servoA, targetA, 117, servoB, targetB, 64);
	delay(delayStep);
}

void scanVertici(Servo &servoA, Servo &servoB) {
  const int targetA = 91;
  const int targetB = 110;
  moveSmoothSync(servoA, 117, targetA, servoB, 64, targetB);
  delay(delayStep);
}

void scanVerticiritorno(Servo &servoA, Servo &servoB) {
  const int targetA = 91;
  const int targetB = 110;
  moveSmoothSync(servoA, targetA, 117, servoB, targetB, 64);
	delay(delayStep);
}

//---------- MOVIMENTO STEPPER --------
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
void rotate315() {
    motore.step(1802);
    delay(500);
}

//--------ACTION-----
void action90(Servo &servo1, const int* stepsorienta1, Servo &servo2, const int* stepsorienta2, int numStepsorienta, int posizioneRiposo1, int posizioneRiposo2) {
  // Movimento avanti
  for (int i = 1; i < numStepsorienta; i++) {
    moveSmoothSync(servo1, stepsorienta1[i - 1], stepsorienta1[i], servo2, stepsorienta2[i - 1], stepsorienta2[i]);
    delay(delayStep);
  }

  // Rotazione 90 gradi
  motore.step(515);
  delay(500);

  // Movimento indietro (ritorno)
  for (int i = numStepsorienta - 1; i > 0; i--) {
    moveSmoothSync(servo1, stepsorienta1[i], stepsorienta1[i - 1], servo2, stepsorienta2[i], stepsorienta2[i - 1]);
    delay(delayStep);
  }
}

void action180(Servo &servo1, const int* stepsorienta1, Servo &servo2, const int* stepsorienta2, int numStepsorienta, int posizioneRiposo1, int posizioneRiposo2) {
  for (int i = 1; i < numStepsorienta; i++) {
    moveSmoothSync(servo1, stepsorienta1[i - 1], stepsorienta1[i], servo2, stepsorienta2[i - 1], stepsorienta2[i]);
    delay(delayStep);
  }

  motore.step(1030);  // Rotazione 180 gradi
  delay(500);

  for (int i = numStepsorienta - 1; i > 0; i--) {
    moveSmoothSync(servo1, stepsorienta1[i], stepsorienta1[i - 1], servo2, stepsorienta2[i], stepsorienta2[i - 1]);
    delay(delayStep);
  }
}

void action270(Servo &servo1, const int* stepsorienta1, Servo &servo2, const int* stepsorienta2, int numStepsorienta, int posizioneRiposo1, int posizioneRiposo2) {
  for (int i = 1; i < numStepsorienta; i++) {
    moveSmoothSync(servo1, stepsorienta1[i - 1], stepsorienta1[i], servo2, stepsorienta2[i - 1], stepsorienta2[i]);
    delay(delayStep);
  }

  motore.step(1545);  // Rotazione 270 gradi
  delay(500);

  for (int i = numStepsorienta - 1; i > 0; i--) {
    moveSmoothSync(servo1, stepsorienta1[i], stepsorienta1[i - 1], servo2, stepsorienta2[i], stepsorienta2[i - 1]);
    delay(delayStep);
  }
}

void sequence1() {
  Movesx(servo1, steps1, servo2, steps2, 9, 169, 8); Movesx(servo1, steps1, servo2, steps2, 9, 169, 8); Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
  action90(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
	action90(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
	action90(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
  Movesx(servo1, steps1, servo2, steps2, 9, 169, 8); Movesx(servo1, steps1, servo2, steps2, 9, 169, 8); Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
  action270(servo1,stepsorienta1, servo2, stepsorienta2,numStepsorienta, posizioneRiposo1, posizioneRiposo2);
  Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
  action90(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
  rotate90();
  Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
  action90(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
}

void sequence2() {
  Movesx(servo1, steps1, servo2, steps2, 9, 169, 8); Movesx(servo1, steps1, servo2, steps2, 9, 169, 8); Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
  action270(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
  rotate90();
  Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
  action180(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
  Movesx(servo1, steps1, servo2, steps2, 9, 169, 8); Movesx(servo1, steps1, servo2, steps2, 9, 169, 8); Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
  action90(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
  Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
  action180(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
}

void sequence3() {
  Movesx(servo1, steps1, servo2, steps2, 9, 169, 8); Movesx(servo1, steps1, servo2, steps2, 9, 169, 8); Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
  action90(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
  rotate90();
  Movesx(servo1, steps1, servo2, steps2, 9, 169, 8); Movesx(servo1, steps1, servo2, steps2, 9, 169, 8); Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
  action270(servo1,stepsorienta1, servo2, stepsorienta2,numStepsorienta, posizioneRiposo1, posizioneRiposo2);
  Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
  action270(servo1,stepsorienta1, servo2, stepsorienta2,numStepsorienta, posizioneRiposo1, posizioneRiposo2);
  rotate90();
  Movesx(servo1, steps1, servo2, steps2, 9, 169, 8); Movesx(servo1, steps1, servo2, steps2, 9, 169, 8); Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
}

void sequence4() {
  action270(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
  Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
  action270(servo1,stepsorienta1, servo2, stepsorienta2,numStepsorienta, posizioneRiposo1, posizioneRiposo2);
  Movesx(servo1, steps1, servo2, steps2, 9, 169, 8); Movesx(servo1, steps1, servo2, steps2, 9, 169, 8); Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
  action180(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
  Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
  action90(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
  Movesx(servo1, steps1, servo2, steps2, 9, 169, 8); Movesx(servo1, steps1, servo2, steps2, 9, 169, 8); Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
  action90(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
  Movesx(servo1, steps1, servo2, steps2, 9, 169, 8); Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
}

void sequence5() {
  Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
  action270(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
  Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
  action90(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
  Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
  action90(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
  Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
  action90(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
  Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
}

void sequence6() {
  action270(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
  Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
  action270(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
  Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
  action90(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
  rotate90();
  Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
  action90(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
  Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
}

void sequence7() {
  action270(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
  rotate90();
  Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
  action270(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
  Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
  action90(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
  Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
  action90(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
  Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
}

void sequence8() {
  action90(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
  rotate90();
  Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
  action270(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
  Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
  action270(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
  rotate90();
  Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
}

void sequence9() {
  Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
  action270(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
  Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
  action270(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
  Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
  action90(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
  Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
}

void sequence10() {
  action90(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
  Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
  action90(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
  rotate90();
  Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
  action270(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
  rotate90();
}


void sequence11() {
  Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
  rotate90();
  Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
  action180(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
  Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
  action90(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
  Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
}

void sequence12() {
  action90(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
  Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
  action90(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
  Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
  action270(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
  Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
  Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
}

void sequence13() {
  Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
  action90(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
  rotate90();
  Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
  action90(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
  rotate90();
  Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
  rotate270();
}


	

void setup() {
//sensore di colore
	pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(OUT, INPUT);

// Imposta frequenza massima di uscita
  digitalWrite(S0, HIGH);
  digitalWrite(S1, HIGH);


//servomotori
	servo1.attach(3);
  servo2.attach(5);
  servo3.attach(6);
  servo4.attach(11);

//stepper
	motore.setSpeed(150);

}

void loop() {//funzione contenente le 4 fasi principali della risoluzione del cubo di Rubik
  switch (stato){
    case 0:
      orienta();//equivale al programma "orientare_cubo"
      break;
    case 1:
      scansiona();//equivale al programma "scansione_pezzi"
      break;
    case 2:
      ordina();//equivale ai programmi "ordinare_vertici", "ordinare_lati", "sequenza_combinazione_vertici" e "sequenza_combinazione_pezzi"
      break;
		case 3:
			attesa();//fase di attesa dove non fa nulla perchè il cubo è stato risolto
			break;
  }

}

void orienta(){
  if (first==true){
		scanCentri(servo3, servo4);
		red = leggiColore(LOW, LOW);     // Filtro Rosso
 	  green = leggiColore(HIGH, HIGH); // Filtro Verde
    blue = leggiColore(LOW, HIGH);   // Filtro Blu

  //da cambiare i serialprintln con delle variabili da cambiare con i valori arbitrari
    c1 = riconosciColore(red, green, blue);
    delay(1000);
		scanCentriritorno(servo3, servo4);
  	while(c1 != 1){							//se il colore non è bianco
			Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
		  scanCentri(servo3, servo4);
			red = leggiColore(LOW, LOW);     // Filtro Rosso
 	    green = leggiColore(HIGH, HIGH); // Filtro Verde
      blue = leggiColore(LOW, HIGH);   // Filtro Blu

  //da cambiare i serialprintln con delle variabili da cambiare con i valori arbitrari
      c1 = riconosciColore(red, green, blue);
      delay(1000);
			scanCentriritorno(servo3, servo4);					
		  n++;								//aggiorno di uno il contatore
  		if(n==3){							//se il contatore è a 3
	  		rotate90();			//ruota il cubo di 90 orari
		  	n=0;							//aggiorna il contatore a 0
  		}
  	}
	  Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);					//sposta cubo verso sinistra
  	scanCentri(servo3, servo4);
		red = leggiColore(LOW, LOW);     // Filtro Rosso
 	  green = leggiColore(HIGH, HIGH); // Filtro Verde
    blue = leggiColore(LOW, HIGH);   // Filtro Blu

  //da cambiare i serialprintln con delle variabili da cambiare con i valori arbitrari
    c2 = riconosciColore(red, green, blue);
    delay(1000);
		scanCentriritorno(servo3, servo4);
  	rotate90();					//ruota il cubo di 90 orari
	  while(c2!=2){
	   	Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
		  scanCentri(servo3, servo4);
			red = leggiColore(LOW, LOW);     // Filtro Rosso
 	    green = leggiColore(HIGH, HIGH); // Filtro Verde
      blue = leggiColore(LOW, HIGH);   // Filtro Blu

  //da cambiare i serialprintln con delle variabili da cambiare con i valori arbitrari
      c2 = riconosciColore(red, green, blue);
      delay(1000);
			scanCentriritorno(servo3, servo4);
	  }
	  rotate90();					//ruota il cubo di 90 orari
  	Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);					//sposta cubo verso sinistra
	  rotate270();				//ruota il cubo di 270 orari
    first=false;
  }
  go(1);//va alla fase 1
}

void scansiona(){
  if (first=true){
		for(nf=0; nf<6; nf++){					//crea funzione per ogni faccia del cubo
			for(ns=0; ns<4; ns++, t++){			//crea funzione per ogni scansione della faccia
				scanSpigoli(servo3, servo4);
				red = leggiColore(LOW, LOW);     // Filtro Rosso
 	      green = leggiColore(HIGH, HIGH); // Filtro Verde
   		  blue = leggiColore(LOW, HIGH);   // Filtro Blu

  //da cambiare i serialprintln con delle variabili da cambiare con i valori arbitrari
   		  lati[0][t]= riconosciColore(red, green, blue);
    		delay(1000);
				scanSpigoliritorno(servo3, servo4);
				rotate90();			//ruota il cubo di 90 orari
			}
			if(nf==3){							//se il programma sta facendo la quarta faccia
				rotate90();			//ruota il cubo di 90 orari
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);			//sposta cubo verso sinistra
			}
			else if(nf==4){						//se il programma sta facendo la quinta faccia
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);			//sposta cubo verso sinistra
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);			//sposta cubo verso sinistra			
			}
			else{								//se non è ne la quarta che la quinta faccia
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);			//sposta cubo verso sinistra
			}	
		}
		rotate270();					//ruota il cubo di 270 orari
		Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);					//sposta cubo verso sinistra
		t=0;									//faccio si che la variabile t ritorni a 0 perche dovrò riusarla per l'altro array

		rotate45();//muove il braccio che scansiona i vertici e ruota di 45 gradi il cassetto in modo da legere bene i vertici -->non so se debba andare così. Richiamare la funzione corretta che porti lo scan_arm fino ai vertici
		for(nf=0; nf<6; nf++){					//crea funzione per ogni faccia del cubo
			for(ns=0; ns<4; ns++, t++){			//crea funzione per ogni scansione della faccia
				scanVertici(servo3, servo4);
				red = leggiColore(LOW, LOW);     // Filtro Rosso
 	      green = leggiColore(HIGH, HIGH); // Filtro Verde
   		  blue = leggiColore(LOW, HIGH);   // Filtro Blu
   		  vertici[0][t]= riconosciColore(red, green, blue);
    		delay(1000);
				scanVerticiritorno(servo3, servo4);
				rotate90();			//ruota il cubo di 90 orari
			}
			if(nf==3){							//se il programma sta facendo la quarta faccia
				rotate90();			//ruota il cubo di 90 orari
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);			//sposta cubo verso sinistra
			}
			else if(nf==4){						//se il programma sta facendo la quinta faccia
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);			//sposta cubo verso sinistra
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);			//sposta cubo verso sinistra			
			}
			else{								//se non è ne la quarta che la quinta faccia
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);			//sposta cubo verso sinistra
			}	
		}
		rotate270();					//ruota il cubo di 270 orari
		Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);					//sposta cubo verso sinistra
		rotate45();
		first=false;
	}
	go(2);//va alla fase 2
}

void ordina(){
	if(first==true){
		vertici_ins[0][0]= vertici[0][0];//vertice di coordinate a,n,q che deve prendere le informazioni del 1esimo, del 16esimo e del 18esimo dell'array vertici
		vertici_ins[0][1]= vertici[0][15];
		vertici_ins[0][2]= vertici[0][17];
		vertici_ins[1][0]= vertici[0][3];//vertice di coordinate b,m,j che deve prendere le informazioni del 4esimo, del 19esimo e del 5esimo dell'array vertici
		vertici_ins[1][1]= vertici[0][18];
		vertici_ins[1][2]= vertici[0][4];
		vertici_ins[2][0]= vertici[0][2];//vertice di coordinate c,i,f che deve prendere le informazioni del 3esimo, del 6esimo e del 22esimo dell'array vertici
		vertici_ins[2][1]= vertici[0][5];
		vertici_ins[2][2]= vertici[0][21];
		vertici_ins[3][0]= vertici[0][1];//vertice di coordinate d,e,r che deve prendere le informazioni del 2esimo, del 23esimo e del 15esimo dell'array vertici
		vertici_ins[3][1]= vertici[0][22];
		vertici_ins[3][2]= vertici[0][14];
		vertici_ins[4][0]= vertici[0][16];//vertice di coordinate o,t,z che deve prendere le informazioni del 17esimo, del 13esimo e del 12esimo dell'array vertici
		vertici_ins[4][1]= vertici[0][12];
		vertici_ins[4][2]= vertici[0][11];
		vertici_ins[5][0]= vertici[0][7];//vertice di coordinate k,p,x che deve prendere le informazioni del 8esimo, del 20esimo e del 9esimo dell'array vertici
		vertici_ins[5][1]= vertici[0][19];
		vertici_ins[5][2]= vertici[0][8];
		vertici_ins[6][0]= vertici[0][20];//vertice di coordinate g,l,v che deve prendere le informazioni del 21esimo, del 7esimo e del 10esimo dell'array vertici
		vertici_ins[6][1]= vertici[0][6];
		vertici_ins[6][2]= vertici[0][9];
		vertici_ins[7][0]= vertici[0][23];//vertice di coordinate h,s,u che deve prendere le informazioni del 24esimo, del 14esimo e del 11esimo dell'array vertici
		vertici_ins[7][1]= vertici[0][13];
		vertici_ins[7][2]= vertici[0][10];
	
	
		/*Questa parte di programma serve per trasferire l'informazione dell'array adimensionale dei lati in un array organizzato che mi dia tutte 
		le informazioni di ogni singolo lato. In questo modo posso nominare arbitrariamente ogni posizione del cubo*/
	
		
		lati_ins[0][0]= lati[0][3];//lato di coordinate a,m che deve prendere le informazioni del 4esimo e del 18esimo dell'array lati
		lati_ins[0][1]= lati[0][17];
		lati_ins[1][0]= lati[0][2];//lato di coordinate b,i (buffer) che deve prendere le informazioni del 3esimo e del 5esimo dell'array lati
		lati_ins[1][1]= lati[0][4];
		lati_ins[2][0]= lati[0][1];//lato di coordinate c,e che deve prendere le informazioni del 2esimo e del 22esimo dell'array lati
		lati_ins[2][1]= lati[0][21];
		lati_ins[3][0]= lati[0][0];//lato di coordinate d,q che deve prendere le informazioni del 1esimo e del 15esimo dell'array lati
		lati_ins[3][1]= lati[0][14];
		lati_ins[4][0]= lati[0][20];//lato di coordinate f,l che deve prendere le informazioni del 21esimo e del 6esimo dell'array lati
		lati_ins[4][1]= lati[0][5];
		lati_ins[5][0]= lati[0][23];//lato di coordinate g,u che deve prendere le informazioni del 24esimo e del 10esimo dell'array lati
		lati_ins[5][1]= lati[0][9];
		lati_ins[6][0]= lati[0][22];//lato di coordinate h,r che deve prendere le informazioni del 23esimo e del 14esimo dell'array lati
		lati_ins[6][1]= lati[0][13];
		lati_ins[7][0]= lati[0][7];//lato di coordinate j,p che deve prendere le informazioni del 8esimo e del 19esimo dell'array lati
		lati_ins[7][1]= lati[0][18];
		lati_ins[8][0]= lati[0][6];//lato di coordinate k,v che deve prendere le informazioni del 7esimo e del 9esimo dell'array lati
		lati_ins[8][1]= lati[0][8];
		lati_ins[9][0]= lati[0][16];//lato di coordinate n,t che deve prendere le informazioni del 17esimo e del 16esimo dell'array lati
		lati_ins[9][1]= lati[0][15];
		lati_ins[10][0]= lati[0][19];//lato di coordinate o,x che deve prendere le informazioni del 20esimo e del 12esimo dell'array lati
		lati_ins[10][1]= lati[0][11];
		lati_ins[11][0]= lati[0][12];//lato di coordinate s,z che deve prendere le informazioni del 13esimo e del 11esimo dell'array lati
		lati_ins[11][1]= lati[0][10];
	
	
		/*Questa parte di programma serve a risolvere i vertici e ad effettuare le parità */
	
	
		//identifico vertici[0][0], [0][1] e [0][2] come zona di buffer, quando in realtà sarà la zona a;n;q
		n=0;//rimetto n=0 perchè è stata usata da numerosi programmi	
		do{

			if (vertici_vero[0][0]==vertici_ins[0][0] && vertici_vero[0][1]==vertici_ins[0][1] && vertici_vero[0][2]==vertici_ins[0][2]){	//se nel buffer ci sono i colori giusti e messi bene
				for (i=0;i<8;i++){
					for (d=0;d<3;d++){
						if (vertici_vero[i][d]!= vertici_ins[i][d]){	//se nella posizione analizzata ci sono colori diversi -> cubo non risolto (molto probabilmente bisogna mettere anche qui il pezzo di codice di commutazione come nel cubo risolto ma messo male
							commutazioni_ver(d, i, vertici_ins);//avvia la funzione commutazioni_ver
							parita=parita+1;//aggiorno il contatore delle parità  
							end_int=1;		//imposto la variabile a 1 per far si che quando uscirà  dal primo for sarà  costretto ad andare nell'altro e chiudere anch'esso
							break;			//esco dal for
						}
						else if(i!=7 && vertici_ins[i][d]==vertici_vero[i][d]){
							//non fa nulla se non è l'ultimo confronto e se i valori confrontati sono uguali
						}
						else if (i==7 && d==2) {//se tutti sono giusti 
							end=1;				//modifico la variabile end
							end_int=1;			//imposto la variabile a 1 per far si che quando uscirà dal primo for sarà costretto ad andare nell'altro e chiudere anch'esso
							break;				//faccio smettere il for
						}
					}
					if (end_int==1){			//se la variabile per far chiudere tutti i for è stata attivata
						end_int=0;				//ristabilizzo la variabile per poterla riutilizzare
						break;					//faccio smettere anche questo for
					}
				}
			}
		
			else if (vertici_vero[0][0]==vertici_ins[0][1] && vertici_vero[0][1]==vertici_ins[0][2] && vertici_vero[0][2]==vertici_ins[0][0]){//se nel buffer ci sono i colori giusti ma ruotati male (rotazione vertice buffer di 120 gradi antiorari)
		
				for (i=0;i<8;i++){
					for(d=0;d<3;d++){
						if (i==0){//se i è in zona buffer 
							//non fa nulla, perchè sennò scambierebbe in loop la posizione di buffer messa male
						}
						else if(vertici_ins[i][d]!=vertici_vero[i][d]){//se nella posizione ci sono colori diversi-> cubo non risolto 
							commutazioni_ver(d, i, vertici_ins);//avvia la funzione commutazioni_ver
							parita=parita+1;//aggiorno il contatore delle parità
							end_int=1;		//imposto la variabile a 1 per far si che quando uscirà dal primo for sarà costretto ad andare nell'altro e chiudere anch'esso
							break;			//esco dal for							
						}
						else if(vertici_ins[i][d]==vertici_vero[i][d]){//se nella posizione analizzata il pezzo è giusto
						//non faccio nulla e continuo con l'analisi
						} 
					}
					if (end_int==1){			//se la variabile per far chiudere tutti i for è stata attivata
						end_int=0;				//ristabilizzo la variabile per poterla riutilizzare
						break;					//faccio smettere anche questo for
					}
				}
			
			}
		
			else if (vertici_vero[0][0]==vertici_ins[0][2] && vertici_vero[0][1]==vertici_ins[0][0] && vertici_vero[0][2]==vertici_ins[0][1]){//se nel buffer ci sono i colori giusti ma ruotati male (rotazione vertice buffer di 120 gradi orari)
				for (i=0;i<8;i++){
					for(d=0;d<3;d++){
						if (i==0){//se i è in zona buffer 
							//non fa nulla, perchè sennò scambierebbe in loop la posizione di buffer messa male
						}
						else if(vertici_ins[i][d]!=vertici_vero[i][d]){//se nella posizione ci sono colori diversi-> cubo non risolto 
							commutazioni_ver(d, i, vertici_ins);//avvia la funzione commutazioni_ver
							parita=parita+1;//aggiorno il contatore delle parità
							end_int=1;		//imposto la variabile a 1 per far si che quando uscirà dal primo for sarà costretto ad andare nell'altro e chiudere anch'esso
							break;			//esco dal for							
						}
						else if(vertici_ins[i][d]==vertici_vero[i][d]){//se nella posizione analizzata il pezzo è giusto
						//non faccio nulla e continuo con l'analisi
						} 
					}
					if (end_int==1){			//se la variabile per far chiudere tutti i for è stata attivata
						end_int=0;				//ristabilizzo la variabile per poterla riutilizzare
						break;					//faccio smettere anche questo for
					}
				}
			
			}
		
			else if (end!=1){//se il cubo non è risolto --> nel buffer ci sono colori completamente sbagliati
				for(i=0;i<8;i++){//confronta ogni vertice
					if(vertici_ins[0][0]==vertici_vero[i][0] || vertici_ins[0][0]==vertici_vero[i][1] || vertici_ins[0][0]==vertici_vero[i][2] ){//se nel vertice analizzato c'è anche solo un colore che combacia con quello della prima posizione del buffer
						if(vertici_ins[0][1]==vertici_vero[i][0] || vertici_ins[0][1]==vertici_vero[i][1] || vertici_ins[0][1]==vertici_vero[i][2]){//se nel vertice analizzato c'è anche solo un colore che combacia con quello dell seconda posizione del buffer
							if(vertici_ins[0][2]==vertici_vero[i][0] || vertici_ins[0][2]==vertici_vero[i][1] || vertici_ins[0][2]==vertici_vero[i][2]){//se nel vertice analizzato c'è anche solo un colore che combacia con quello dell'ultima posizione del buffer --> trovato vertice dove permutare il pezzo
								if (vertici_ins[0][0]==vertici_vero[i][0]){//se la prima informazione di buffer va messa nella prima informazione del vertice analizzato
									d=0;//salvo la posizione dove deve andare la prima informazione di buffer
									commutazioni_ver(d, i, vertici_ins);//avvia la funzione commutazioni_ver
									parita=parita+1;//aggiorno il contatore delle parità
									break;//esce dal for (spero lo faccia)
								}
								else if(vertici_ins[0][0]==vertici_vero[i][1]){//se la prima informazione di buffer va messa nella seconda informazione del vertice analizzato
									d=1;//salvo la posizione dove deve andare la prima informazione di buffer
									commutazioni_ver(d, i, vertici_ins);//avvia la funzione commutazioni_ver
									parita=parita+1;//aggiorno il contatore delle parità
									break;//esce dal for (spero lo faccia)								
								}
								else if(vertici_ins[0][0]==vertici_vero[i][2]){//se la prima informazione di buffer va messa nell'ultima informazione del vertice analizzato
									d=2;//salvo la posizione dove deve andare la prima informazione di buffer
									commutazioni_ver(d, i, vertici_ins);//avvia la funzione commutazioni_ver
									parita=parita+1;//aggiorno il contatore delle parità
									break;//esce dal for (spero lo faccia)
								}
							
							}
						}
					}
				}
			}
		
		}while(end!=1);
		if(parita%2==0){//se sono state eseguite un numero pari di commutazioni
			//non fa nulla
		}
		else if(parita%2==1){//se sono state eseguite un numero dispari di commutazioni --> svolge l'algoritmo di parità
			sequence1();
			sequence2();
			sequence3();
			sequence4();
		}
	
	
		/*Questa parte di programma serve a sistemare i lati*/
		//identifico lati [1][0] e [1][1] come zona di buffer, quando in realtà sarà la zona b;i
		d=0;//rimetto d=0 perchè è stata usata da numerosi programmi
		i=0;//rimetto i=0 perchè è stata usata da numerosi programmi
		n=0;//rimetto n=0 perchè è stata usata da numerosi programmi
		m=0;//rimetto m=0 perchè è stata usata da numerosi programmi
		end=0;//rimetto end=0 perchè è stata usata da numerosi programmi
		end_int=0;//rimetto end_int=0 perchè è stata usata da numerosi programmi
		do{
			if(lati_ins[1][0]==lati_vero[1][0] && lati_ins[1][1]==lati_vero[1][1]){//se nel buffer c'è il suo colore giusto e messo bene
				for(i=0;i<12;i++){
					for (d=0; d<2; d++){
						if(lati_ins[i][d]!=lati_vero[i][d]){//se nella posizione ci sono colori diversi-> cubo non risolto
							n=lati_ins[i][0];//associo ad n l'informazione del primo pezzo non messo correttamente 
							m=lati_ins[1][0];//associo ad m l'informazione del primo pezzo nel buffer
							lati_ins[i][0]=m;//nel luogo dove c'era il pezzo che non andava bene metto la prima informazione del buffer
							lati_ins[1][0]=n;//metto in informazione al buffer il primo colore del luogo dove il colore è sbagliato
							n=lati_ins[i][1];//associo ad n l'informazione dell'ultimo pezzo non messo correttamente 
							m=lati_ins[1][1];//associo ad m l'informazione dell'ultimo pezzo nel buffer
							lati_ins[i][1]=m;//nel luogo dove c'era il pezzo che non andava bene metto l'ultima informazione del buffer
							lati_ins[1][1]=n;//metto in informazione al buffer l'ultimo colore del luogo dove il colore è sbagliato
							commutazioni(d,i);//avvia la funzione "commutazioni"		
							end_int=1;//imposto la variabile a 1 per far si che quando uscirà dal primo for sarà costretto ad andare nell'altro e chiudere anch'esso
							break;//esco dal for							
						}
						else if(i!=11 && lati_ins[i][d]==lati_vero[i][d]){
							//non fa nulla se non è l'ultimo confronto e se i valori confrontati sono uguali
						}
						else if (i==11 && d==1) {//se tutti sono giusti 
							end=1;//modifico la variabile end
							end_int=1;//imposto la variabile a 1 per far si che quando uscirà  dal primo for sarà costretto ad andare nell'altro e chiudere anch'esso
							break;//faccio smettere il for
						}
			
					}
					if (end_int==1){//se la variabile per far chiudere tutti i for è stata attivata
						end_int=0;//ristabilizzo la variabile per poterla riutilizzare
						break;//faccio smettere anche questo for
					}
					
				}
			}
			else if(lati_ins[1][0]==lati_vero[1][1] && lati_ins[1][1]==lati_vero[1][0]){//se nel buffer ci sono i colori giusti ma sono messi male
				for(i=0;i<12;i++){
					for (d=0; d<2; d++){
						if (i==1){//se i è in zona buffer 
							//non fa nulla, perchè sennò scambierebbe in loop la posizione di buffer messa male
						}
						else if(lati_ins[i][d]!=lati_vero[i][d]){//se nella posizione ci sono colori diversi
							m=lati_ins[1][0];//associo ad m l'informazione del primo luogo del buffer
							n=lati_ins[1][1];//associo ad m l'informazione dell'ultimo luogo del buffer
							lati_ins[1][0]=n;//scambio l'informazione
							lati_ins[1][1]=m;//scambio l'informazione
							m=lati_ins[i][0];//associo ad m l'informazione del primo luogo della zona da permutare
							n=lati_ins[i][1];//associo ad m l'informazione dell'ultimo luogo della zona da permutare
							lati_ins[i][0]=n;//scambio l'informazione
							lati_ins[i][1]=m;//scambio l'informazione
							n=lati_ins[i][0];//associo ad n l'informazione del luogo dove andrà messa l'informazione del buffer
							m=lati_ins[1][0];//associo ad m l'informazione del buffer
							lati_ins[i][0]=m;//metto l'informazione nel buffer nel giusto luogo
							lati_ins[1][0]=n;//aggiorno il buffer
							n=lati_ins[i][1];//associo ad n l'informazione del luogo dove andrà messa l'informazione del buffer
							m=lati_ins[1][1];//associo ad m l'informazione del buffer
							lati_ins[i][1]=m;//metto l'informazione nel buffer nel giusto luogo
							lati_ins[1][1]=n;//aggiorno il buffer
							d=1;
							commutazioni(d,i);//avvia la funzione "commutazioni"
							end_int=1;//imposto la variabile a 1 per far si che quando uscirà dal primo for sarà costretto ad andare nell'altro e chiudere anch'esso
							break;//esco dal for							
						}
						else if(i!=11 && lati_ins[i][d]==lati_vero[i][d]){
							//non fa nulla se non è l'ultimo confronto e se i valori confrontati sono uguali
						}
						else if (i==11 && d==1 && lati_ins[i][d]==lati_vero[i][d]) {//se tutti sono giusti 
							end=1;//modifico la variabile end
							end_int=1;//imposto la variabile a 1 per far si che quando uscirò dal primo for sarà costretto ad andare nell'altro e chiudere anch'esso
							break;//faccio smettere il for
						}
			
					}
					if (end_int==1){//se la variabile per far chiudere tutti i for è stata attivata
						end_int=0;//ristabilizzo la variabile per poterla riutilizzare
						break;//faccio smettere anche questo for
					}		
				}
			}
		
			else if(end!=1){//se l'array non ha finito di essere combinato
				for(i=0;i<12;i++){
					//bisognerà fare di nuovo degli if sia per il caso che siano nel modo corretto per la posizione o che siano messi al rovescio
					if(lati_ins[1][0]== lati_vero[i][0] && lati_ins[1][1]==lati_vero[i][1]){//se la zona di buffer ha la stessa informazione della zona confrontata
						n=lati_ins[i][0];//associo ad n l'informazione del luogo dove andrà messa l'informazione del buffer
						m=lati_ins[1][0];//associo ad m l'informazione del buffer
						lati_ins[i][0]=m;//metto l'informazione nel buffer nel giusto luogo
						lati_ins[1][0]=n;//aggiorno il buffer
						n=lati_ins[i][1];//associo ad n l'informazione del luogo dove andrà messa l'informazione del buffer
						m=lati_ins[1][1];//associo ad m l'informazione del buffer
						lati_ins[i][1]=m;//metto l'informazione nel buffer nel giusto luogo
						lati_ins[1][1]=n;//aggiorno il buffer
						d=0;
						commutazioni(d,i);//avvia la funzione "commutazioni"
						break;//esce dal for
					}//funzione che serve per riordinare in base ai voleri dell'array lati_vero quello del lati
				
					//funzione che dovrebbe essere giusta e da copiare per tutte le parti con sfasamenti
					else if(lati_ins[1][0]== lati_vero[i][1] && lati_ins[1][1]==lati_vero[i][0]){//se la zona di buffer ha la stessa informazione della zona confrontata ma sfasata
						m=lati_ins[1][0];//associo ad m l'informazione del primo luogo del buffer
						n=lati_ins[1][1];//associo ad m l'informazione dell'ultimo luogo del buffer
						lati_ins[1][0]=n;//scambio l'informazione
						lati_ins[1][1]=m;//scambio l'informazione
						m=lati_ins[i][0];//associo ad m l'informazione del primo luogo della zona da permutare
						n=lati_ins[i][1];//associo ad m l'informazione dell'ultimo luogo della zona da permutare
						lati_ins[i][0]=n;//scambio l'informazione
						lati_ins[i][1]=m;//scambio l'informazione
						n=lati_ins[i][0];//associo ad n l'informazione del luogo dove andrà messa l'informazione del buffer
						m=lati_ins[1][0];//associo ad m l'informazione del buffer
						lati_ins[i][0]=m;//metto l'informazione nel buffer nel giusto luogo
						lati_ins[1][0]=n;//aggiorno il buffer
						n=lati_ins[i][1];//associo ad n l'informazione del luogo dove andrà  messa l'informazione del buffer
						m=lati_ins[1][1];//associo ad m l'informazione del buffer
						lati_ins[i][1]=m;//metto l'informazione nel buffer nel giusto luogo
						lati_ins[1][1]=n;//aggiorno il buffer
						d=1;
						commutazioni(d,i);//avvia la funzione "commutazioni"
						break;//esce dal for
					}//funzione che serve per riordinare in base ai voleri dell'array lati_vero quello del lati	
				}
			}
		} while(end!=1);
		first=false;
	}
	go(3);//vado alla terza fase

}

void attesa(){
	//non deve fare nulla
}

void go(int st){//funzione che serve per la macchina a stati finiti, cambierà dunque fase dopo averne finita una. Equivale alla transizione dei programmi dei PLC
  stato=st;//va alla fase che ho detto io
  first=false;//per riutilizzare la variabile first anche nelle altre fasi
}


//Questa funzione serve a permutare i vertici di buffer con quello da sistemare
void perm(){//perm che scambia ilvertice di buffer con quello preso in considerazione 
	sequence5();
	sequence6();
	sequence7();
	sequence8();
}

//Questa funzione serve a permutare il lato di buffer con quello da sistemare
void t_perm(){//funzione che stampa le mosse che svolgono la T perm
	sequence9();
	sequence10();
	sequence11();
	sequence12();
	sequence13();
}

//Questa funzione serve a permutare veramente le informazioni dei vertici e stampa le informazioni che servono a spostare i singoli vertici
int commutazioni_ver(int d, int i, int vertici_ins[8][3]){//parte di programma che identifica come permutare ogni singolo vertice in base alla posizione e che mi restituirà l'informazione per risolvere i vertici uno ad uno
	int a=0;//variabile che conterrà l'informazione da mettere
	int b=0;//variabile che conterrà l'informazione del buffer
	if(d==0){//se la prima posizione scombinata che troviamo è quella relativa alla prima postazione codificata del vertice
		switch(i){
			case 0:{//se i è uguale a 0 (impossibile ma la mettiamo lo stesso, non può commutare la stessa zona di buffer), avvia la risoluzione per la posizione "a"
				printf("error\n");//stampa errore
				break;//esce dallo switch
			}
			case 1:{//se i è uguale a 1, avvia la risoluzione per la posizione "b"
				a=vertici_ins[0][0];//associo ad a la prima informazione di buffer
				b=vertici_ins[i][d];//associo a b l'informazione della zona "b"
				vertici_ins[0][0]=b;//metto in prima zona buffer l'informazione della zona "b"
				vertici_ins[i][d]=a;//metto in zona "b" la prima informazione di buffer
				a=vertici_ins[0][1];//associo ad a la seconda informazione di buffer
				b=vertici_ins[i][2];//associo a b l'informazione della zona "j"
				vertici_ins[0][1]=b;//metto in prima zona buffer l'informazione della zona "j"
				vertici_ins[i][2]=a;//metto in zona "j" la seconda informazione di buffer
				a=vertici_ins[0][2];//associo ad a l'ultima informazione di buffer
				b=vertici_ins[i][1];//associo a b l'informazione della zona "m"
				vertici_ins[0][2]=b;//metto in ultima zona buffer l'informazione della zona "m"
				vertici_ins[i][1]=a;//metto in zona "m" l'ultima informazione di buffer
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				action270(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				action90(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				perm();//stampa la permutazione dei vertici
				action270(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				action90(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				break;//esce dallo switch
			}
			case 2:{//se i è uguale a 2, avvia la risoluzione per la posizione "c"
				a=vertici_ins[0][0];//associo ad a la prima informazione di buffer
				b=vertici_ins[i][d];//associo a b l'informazione della zona "c"
				vertici_ins[0][0]=b;//metto in prima zona buffer l'informazione della zona "c"
				vertici_ins[i][d]=a;//metto in zona "c" la prima informazione di buffer
				a=vertici_ins[0][1];//associo ad a la seconda informazione di buffer
				b=vertici_ins[i][2];//associo a b l'informazione della zona "f"
				vertici_ins[0][1]=b;//metto in seconda zona buffer l'informazione della zona "f"
				vertici_ins[i][2]=a;//metto in zona "f" la seconda informazione di buffer
				a=vertici_ins[0][2];//associo ad a l'ultima informazione di buffer
				b=vertici_ins[i][1];//associo a b l'informazione della zona "i"
				vertici_ins[0][2]=b;//metto in ultima zona buffer l'informazione della zona "i"
				vertici_ins[i][1]=a;//metto in zona "i" l'ultima informazione di buffer
				rotate90();
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				action270(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				rotate270();
				perm();//stampa la permutazione dei vertici
				rotate90();
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				action90(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				rotate270();
				break;//esce dallo switch
			}
			case 3:{//se i è uguale a 3, avvia la risoluzione per la posizione "d"
				a=vertici_ins[0][0];//associo ad a la prima informazione di buffer
				b=vertici_ins[i][d];//associo a b l'informazione della zona "d"
				vertici_ins[0][0]=b;//metto in prima zona buffer l'informazione della zona "d"
				vertici_ins[i][d]=a;//metto in zona "d" la prima informazione di buffer
				a=vertici_ins[0][1];//associo ad a la seconda informazione di buffer
				b=vertici_ins[i][2];//associo a b l'informazione della zona "r"
				vertici_ins[0][1]=b;//metto in seconda zona buffer l'informazione della zona "r"
				vertici_ins[i][2]=a;//metto in zona "r" la seconda informazione di buffer
				a=vertici_ins[0][2];//associo ad a l'ultima informazione di buffer
				b=vertici_ins[i][1];//associo a b l'informazione della zona "e"
				vertici_ins[0][2]=b;//metto in ultima zona buffer l'informazione della zona "e"
				vertici_ins[i][1]=a;//metto in zona "e" l'ultima informazione di buffer
				rotate90();
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				action270(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				rotate90();
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				action90(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				rotate90();
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				perm();//stampa la permutazione dei vertici
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				rotate270();
				action270(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				rotate270();
				action90(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				rotate270();
				break;//esce dallo switch
			}
			case 4:{//se i è uguale a 4, avvia la risoluzione per la posizione "o"
				a=vertici_ins[0][0];//associo ad a la prima informazione di buffer
				b=vertici_ins[i][d];//associo a b l'informazione della zona "o"
				vertici_ins[0][0]=b;//metto in prima zona buffer l'informazione della zona "o"
				vertici_ins[i][d]=a;//metto in zona "o" la prima informazione di buffer
				a=vertici_ins[0][1];//associo ad a la seconda informazione di buffer
				b=vertici_ins[i][2];//associo a b l'informazione della zona "z"
				vertici_ins[0][1]=b;//metto in seconda zona buffer l'informazione della zona "z"
				vertici_ins[i][2]=a;//metto in zona "z" la seconda informazione di buffer
				a=vertici_ins[0][2];//associo ad a l'ultima informazione di buffer
				b=vertici_ins[i][1];//associo a b l'informazione della zona "t"
				vertici_ins[0][2]=b;//metto in ultima zona buffer l'informazione della zona "t"
				vertici_ins[i][1]=a;//metto in zona "t" l'ultima informazione di buffer
				action90(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				action270(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				perm();//stampa la permutazione dei vertici
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				action90(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				action270(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				break;//esce dallo switch
			}
			case 5:{//se i è uguale a 5, avvia la risoluzione per la posizione "k"
				a=vertici_ins[0][0];//associo ad a la prima informazione di buffer
				b=vertici_ins[i][d];//associo a b l'informazione della zona "k"
				vertici_ins[0][0]=b;//metto in prima zona buffer l'informazione della zona "k"
				vertici_ins[i][d]=a;//metto in zona "k" la prima informazione di buffer			
				a=vertici_ins[0][1];//associo ad a la seconda informazione di buffer
				b=vertici_ins[i][2];//associo a b l'informazione della zona "x"
				vertici_ins[0][1]=b;//metto in seconda zona buffer l'informazione della zona "x"
				vertici_ins[i][2]=a;//metto in zona "x" la seconda informazione di buffer
				a=vertici_ins[0][2];//associo ad a l'ultima informazione di buffer
				b=vertici_ins[i][1];//associo a b l'informazione della zona "p"
				vertici_ins[0][2]=b;//metto in ultima zona buffer l'informazione della zona "p"
				vertici_ins[i][1]=a;//metto in zona "p" l'ultima informazione di buffer
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				action270(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				perm();//stampa la permutazione dei vertici
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				action90(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				break;//esce dallo switch
			}
			case 6:{//se i è uguale a 6, avvia la risoluzione per la posizione "g"
				a=vertici_ins[0][0];//associo ad a la prima informazione di buffer
				b=vertici_ins[i][d];//associo a b l'informazione della zona "g"
				vertici_ins[0][0]=b;//metto in prima zona buffer l'informazione della zona "g"
				vertici_ins[i][d]=a;//metto in zona "g" la prima informazione di buffer
				a=vertici_ins[0][1];//associo ad a la seconda informazione di buffer
				b=vertici_ins[i][2];//associo a b l'informazione della zona "v"
				vertici_ins[0][1]=b;//metto in seconda zona buffer l'informazione della zona "v"
				vertici_ins[i][2]=a;//metto in zona "v" la seconda informazione di buffer				
				a=vertici_ins[0][2];//associo ad a l'ultima informazione di buffer
				b=vertici_ins[i][1];//associo a b l'informazione della zona "l"
				vertici_ins[0][2]=b;//metto in ultima zona buffer l'informazione della zona "l"
				vertici_ins[i][1]=a;//metto in zona "l" l'ultima informazione di buffer
				rotate90();
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				action270(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				action270(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				rotate270();
				perm();//stampa la permutazione dei vertici
				rotate90();
				action90(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				action90(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				rotate270();
				break;//esce dallo switch
			}
			case 7:{//se i è uguale a 7, avvia la risoluzione per la posizione "h"
				a=vertici_ins[0][0];//associo ad a la prima informazione di buffer
				b=vertici_ins[i][d];//associo a b l'informazione della zona "h"
				vertici_ins[0][0]=b;//metto in prima zona buffer l'informazione della zona "h"
				vertici_ins[i][d]=a;//metto in zona "h" la prima informazione di buffer				
				a=vertici_ins[0][1];//associo ad a la seconda informazione di buffer
				b=vertici_ins[i][1];//associo a b l'informazione della zona "s"
				vertici_ins[0][1]=b;//metto in seconda zona buffer l'informazione della zona "s"
				vertici_ins[i][1]=a;//metto in zona "s" la seconda informazione di buffer			
				a=vertici_ins[0][2];//associo ad a l'ultima informazione di buffer
				b=vertici_ins[i][2];//associo a b l'informazione della zona "u"
				vertici_ins[0][2]=b;//metto in ultima zona buffer l'informazione della zona "u"
				vertici_ins[i][2]=a;//metto in zona "u" l'ultima informazione di buffer
				action270(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				perm();//stampa la permutazione dei vertici
				action90(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				break;//esce dallo switch
			}
			default: //se in i c'è qualcosa di diverso da questi caratteri
				printf("errore\n");
				break;//esce dallo switch
			
		}
	}
	
	else if  (d==1){//se la prima posizione scombinata che troviamo è quella relativa alla seconda postazione codificata del vertice
		switch(i){
			case 0:{//se i è uguale a 0 (impossibile ma la mettiamo lo stesso, non può commutare la stessa zona di buffer), avvia la risoluzione per la posizione "n"
				printf("error\n");//stampa errore
				break;//esce dallo switch
			}
			case 1:{//se i è uguale a 1, avvia la risoluzione per la posizione "m"
				a=vertici_ins[0][0];//associo ad a la prima informazione di buffer
				b=vertici_ins[i][d];//associo a b l'informazione della zona "m"
				vertici_ins[0][0]=b;//metto in prima zona buffer l'informazione della zona "m"
				vertici_ins[i][d]=a;//metto in zona "m" la prima informazione di buffer				
				a=vertici_ins[0][1];//associo ad a la seconda informazione di buffer
				b=vertici_ins[i][0];//associo a b l'informazione della zona "b"
				vertici_ins[0][1]=b;//metto in prima zona buffer l'informazione della zona "b"
				vertici_ins[i][0]=a;//metto in zona "b" la seconda informazione di buffer		
				a=vertici_ins[0][2];//associo ad a l'ultima informazione di buffer
				b=vertici_ins[i][2];//associo a b l'informazione della zona "j"
				vertici_ins[0][2]=b;//metto in ultima zona buffer l'informazione della zona "j"
				vertici_ins[i][2]=a;//metto in zona "j" l'ultima informazione di buffer
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				action90(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				rotate90();
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				action270(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				rotate90();
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				rotate270();
				perm();//stampa la permutazione dei vertici
				rotate90();
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				rotate270();
				action90(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				rotate270();
				action270(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				break;//esce dallo switch
			}
			case 2:{//se i è uguale a 2, avvia la risoluzione per la posizione "i"
				a=vertici_ins[0][0];//associo ad a la prima informazione di buffer
				b=vertici_ins[i][d];//associo a b l'informazione della zona "i"
				vertici_ins[0][0]=b;//metto in prima zona buffer l'informazione della zona "i"
				vertici_ins[i][d]=a;//metto in zona "i" la prima informazione di buffer					
				a=vertici_ins[0][1];//associo ad a la seconda informazione di buffer
				b=vertici_ins[i][0];//associo a b l'informazione della zona "c"
				vertici_ins[0][1]=b;//metto in prima zona buffer l'informazione della zona "c"
				vertici_ins[i][0]=a;//metto in zona "c" la seconda informazione di buffer			
				a=vertici_ins[0][2];//associo ad a l'ultima informazione di buffer
				b=vertici_ins[i][2];//associo a b l'informazione della zona "f"
				vertici_ins[0][2]=b;//metto in ultima zona buffer l'informazione della zona "f"
				vertici_ins[i][2]=a;//metto in zona "f" l'ultima informazione di buffer
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				action90(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				perm();//stampa la permutazione dei vertici
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				action270(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				break;//esce dallo switch
			}
			case 3:{//se i è uguale a 3, avvia la risoluzione per la posizione "e"
				a=vertici_ins[0][0];//associo ad a la prima informazione di buffer
				b=vertici_ins[i][d];//associo a b l'informazione della zona "e"
				vertici_ins[0][0]=b;//metto in prima zona buffer l'informazione della zona "e"
				vertici_ins[i][d]=a;//metto in zona "e" la prima informazione di buffer						
				a=vertici_ins[0][1];//associo ad a la seconda informazione di buffer
				b=vertici_ins[i][0];//associo a b l'informazione della zona "d"
				vertici_ins[0][1]=b;//metto in prima zona buffer l'informazione della zona "d"
				vertici_ins[i][0]=a;//metto in zona "d" la seconda informazione di buffer				
				a=vertici_ins[0][2];//associo ad a l'ultima informazione di buffer
				b=vertici_ins[i][2];//associo a b l'informazione della zona "r"
				vertici_ins[0][2]=b;//metto in ultima zona buffer l'informazione della zona "r"
				vertici_ins[i][2]=a;//metto in zona "r" l'ultima informazione di buffer
				rotate90();
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				action90(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				action270(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				rotate270();
				perm();//stampa la permutazione dei vertici
				rotate90();
				action90(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				action270(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				rotate270();
				break;//esce dallo switch
			}
			case 4:{//se i è uguale a 4, avvia la risoluzione per la posizione "t"
				a=vertici_ins[0][0];//associo ad a la prima informazione di buffer
				b=vertici_ins[i][d];//associo a b l'informazione della zona "t"
				vertici_ins[0][0]=b;//metto in prima zona buffer l'informazione della zona "t"
				vertici_ins[i][d]=a;//metto in zona "t" la prima informazione di buffer							
				a=vertici_ins[0][1];//associo ad a la seconda informazione di buffer
				b=vertici_ins[i][0];//associo a b l'informazione della zona "o"
				vertici_ins[0][1]=b;//metto in prima zona buffer l'informazione della zona "o"
				vertici_ins[i][0]=a;//metto in zona "o" la seconda informazione di buffer				
				a=vertici_ins[0][2];//associo ad a l'ultima informazione di buffer
				b=vertici_ins[i][2];//associo a b l'informazione della zona "z"
				vertici_ins[0][2]=b;//metto in ultima zona buffer l'informazione della zona "z"
				vertici_ins[i][2]=a;//metto in zona "z" l'ultima informazione di buffer
				action180(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				perm();//stampa la permutazione dei vertici
				action180(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				break;//esce dallo switch
			}
			case 5:{//se i è uguale a 5, avvia la risoluzione per la posizione "p"
				a=vertici_ins[0][0];//associo ad a la prima informazione di buffer
				b=vertici_ins[i][d];//associo a b l'informazione della zona "p"
				vertici_ins[0][0]=b;//metto in prima zona buffer l'informazione della zona "p"
				vertici_ins[i][d]=a;//metto in zona "p" la prima informazione di buffer								
				a=vertici_ins[0][1];//associo ad a la seconda informazione di buffer
				b=vertici_ins[i][0];//associo a b l'informazione della zona "k"
				vertici_ins[0][1]=b;//metto in prima zona buffer l'informazione della zona "k"
				vertici_ins[i][0]=a;//metto in zona "k" la seconda informazione di buffer					
				a=vertici_ins[0][2];//associo ad a l'ultima informazione di buffer
				b=vertici_ins[i][2];//associo a b l'informazione della zona "x"
				vertici_ins[0][2]=b;//metto in ultima zona buffer l'informazione della zona "x"
				vertici_ins[i][2]=a;//metto in zona "x" l'ultima informazione di buffer
				action90(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				perm();//stampa la permutazione dei vertici
				action270(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				break;//esce dallo switch
			}
			case 6:{//se i è uguale a 6, avvia la risoluzione per la posizione "l"
				a=vertici_ins[0][0];//associo ad a la prima informazione di buffer
				b=vertici_ins[i][d];//associo a b l'informazione della zona "l"
				vertici_ins[0][0]=b;//metto in prima zona buffer l'informazione della zona "l"
				vertici_ins[i][d]=a;//metto in zona "l" la prima informazione di buffer			
				a=vertici_ins[0][1];//associo ad a la seconda informazione di buffer
				b=vertici_ins[i][0];//associo a b l'informazione della zona "g"
				vertici_ins[0][1]=b;//metto in prima zona buffer l'informazione della zona "g"
				vertici_ins[i][0]=a;//metto in zona "g" la seconda informazione di buffer		
				a=vertici_ins[0][2];//associo ad a l'ultima informazione di buffer
				b=vertici_ins[i][2];//associo a b l'informazione della zona "v"
				vertici_ins[0][2]=b;//metto in ultima zona buffer l'informazione della zona "v"
				vertici_ins[i][2]=a;//metto in zona "v" l'ultima informazione di buffer
				//cubo già  in posizione
				perm();//stampa la permutazione dei vertici
				//cubo già  rimesso a posto
				break;//esce dallo switch
			}
			case 7:{//se i è uguale a 7, avvia la risoluzione per la posizione "s"
				a=vertici_ins[0][0];//associo ad a la prima informazione di buffer
				b=vertici_ins[i][d];//associo a b l'informazione della zona "s"
				vertici_ins[0][0]=b;//metto in prima zona buffer l'informazione della zona "s"
				vertici_ins[i][d]=a;//metto in zona "s" la prima informazione di buffer				
				a=vertici_ins[0][1];//associo ad a la seconda informazione di buffer
				b=vertici_ins[i][2];//associo a b l'informazione della zona "u"
				vertici_ins[0][1]=b;//metto in prima zona buffer l'informazione della zona "u"
				vertici_ins[i][2]=a;//metto in zona "u" la seconda informazione di buffer		
				a=vertici_ins[0][2];//associo ad a l'ultima informazione di buffer
				b=vertici_ins[i][0];//associo a b l'informazione della zona "h"
				vertici_ins[0][2]=b;//metto in ultima zona buffer l'informazione della zona "h"
				vertici_ins[i][0]=a;//metto in zona "h" l'ultima informazione di buffer
				rotate90();
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				action180(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				rotate90();
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				action90(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				rotate90();
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				perm();//stampa la permutazione dei vertici
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				rotate270();
				action270(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				rotate270();
				action180(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				rotate270();
				break;//esce dallo switch
			}
			default: //se in i c'è qualcosa di diverso da questi caratteri
				printf("errore\n");
				break;//esce dallo switch
		}
	}
	
	else if(d==2){//se la prima posizione scombinata che troviamo è quella relativa all'ultima postazione codificata del vertice
		switch(i){
			case 0:{//se i è uguale a 0 (impossibile ma la mettiamo lo stesso, non può commutare la stessa zona di buffer), avvia la risoluzione per la posizione "q"
				printf("error\n");//stampa errore
				break;//esce dallo switch
			}
			case 1:{//se i è uguale a 1, avvia la risoluzione per la posizione "j"
				a=vertici_ins[0][0];//associo ad a la prima informazione di buffer
				b=vertici_ins[i][d];//associo a b l'informazione della zona "j"
				vertici_ins[0][0]=b;//metto in prima zona buffer l'informazione della zona "j"
				vertici_ins[i][d]=a;//metto in zona "j" la prima informazione di buffer								
				a=vertici_ins[0][1];//associo ad a la seconda informazione di buffer
				b=vertici_ins[i][1];//associo a b l'informazione della zona "m"
				vertici_ins[0][1]=b;//metto in prima zona buffer l'informazione della zona "m"
				vertici_ins[i][1]=a;//metto in zona "m" la seconda informazione di buffer		
				a=vertici_ins[0][2];//associo ad a l'ultima informazione di buffer
				b=vertici_ins[i][0];//associo a b l'informazione della zona "b"
				vertici_ins[0][2]=b;//metto in ultima zona buffer l'informazione della zona "b"
				vertici_ins[i][0]=a;//metto in zona "b" l'ultima informazione di buffer
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				action180(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				perm();//stampa la permutazione dei vertici
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				action180(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				break;//esce dallo switch
			}
			case 2:{//se i è uguale a 2, avvia la risoluzione per la posizione "f"
				a=vertici_ins[0][0];//associo ad a la prima informazione di buffer
				b=vertici_ins[i][d];//associo a b l'informazione della zona "f"
				vertici_ins[0][0]=b;//metto in prima zona buffer l'informazione della zona "f"
				vertici_ins[i][d]=a;//metto in zona "f" la prima informazione di buffer								
				a=vertici_ins[0][1];//associo ad a la seconda informazione di buffer
				b=vertici_ins[i][1];//associo a b l'informazione della zona "i"
				vertici_ins[0][1]=b;//metto in prima zona buffer l'informazione della zona "i"
				vertici_ins[i][1]=a;//metto in zona "i" la seconda informazione di buffer		
				a=vertici_ins[0][2];//associo ad a l'ultima informazione di buffer
				b=vertici_ins[i][0];//associo a b l'informazione della zona "c"
				vertici_ins[0][2]=b;//metto in ultima zona buffer l'informazione della zona "c"
				vertici_ins[i][0]=a;//metto in zona "c" l'ultima informazione di buffer
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				action180(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				action90(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				perm();//stampa la permutazione dei vertici
				action270(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				action180(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				break;//esce dallo switch
			}
			case 3:{//se i è uguale a 3, avvia la risoluzione per la posizione "r"
				a=vertici_ins[0][0];//associo ad a la prima informazione di buffer
				b=vertici_ins[i][d];//associo a b l'informazione della zona "r"
				vertici_ins[0][0]=b;//metto in prima zona buffer l'informazione della zona "r"
				vertici_ins[i][d]=a;//metto in zona "r" la prima informazione di buffer						
				a=vertici_ins[0][1];//associo ad a la seconda informazione di buffer
				b=vertici_ins[i][1];//associo a b l'informazione della zona "e"
				vertici_ins[0][1]=b;//metto in prima zona buffer l'informazione della zona "e"
				vertici_ins[i][1]=a;//metto in zona "e" la seconda informazione di buffer		
				a=vertici_ins[0][2];//associo ad a l'ultima informazione di buffer
				b=vertici_ins[i][0];//associo a b l'informazione della zona "d"
				vertici_ins[0][2]=b;//metto in ultima zona buffer l'informazione della zona "d"
				vertici_ins[i][0]=a;//metto in zona "d" l'ultima informazione di buffer
				rotate90();
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				action180(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				rotate270();
				perm();//stampa la permutazione dei vertici
				rotate90();
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				action180(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				rotate270();
				break;//esce dallo switch
			}
			case 4:{//se i è uguale a 4, avvia la risoluzione per la posizione "z"
				a=vertici_ins[0][0];//associo ad a la prima informazione di buffer
				b=vertici_ins[i][d];//associo a b l'informazione della zona "z"
				vertici_ins[0][0]=b;//metto in prima zona buffer l'informazione della zona "z"
				vertici_ins[i][d]=a;//metto in zona "z" la prima informazione di buffer											
				a=vertici_ins[0][1];//associo ad a la seconda informazione di buffer
				b=vertici_ins[i][1];//associo a b l'informazione della zona "t"
				vertici_ins[0][1]=b;//metto in prima zona buffer l'informazione della zona "t"
				vertici_ins[i][1]=a;//metto in zona "t" la seconda informazione di buffer					
				a=vertici_ins[0][2];//associo ad a l'ultima informazione di buffer
				b=vertici_ins[i][0];//associo a b l'informazione della zona "o"
				vertici_ins[0][2]=b;//metto in ultima zona buffer l'informazione della zona "o"
				vertici_ins[i][0]=a;//metto in zona "o" l'ultima informazione di buffer
				action270(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				rotate90();
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				action90(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				rotate270();
				perm();//stampa la permutazione dei vertici
				rotate90();
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				action270(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				rotate270();
				action90(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				break;//esce dallo switch
			}
			case 5:{//se i è uguale a 5, avvia la risoluzione per la posizione "x"
				a=vertici_ins[0][0];//associo ad a la prima informazione di buffer
				b=vertici_ins[i][d];//associo a b l'informazione della zona "x"
				vertici_ins[0][0]=b;//metto in prima zona buffer l'informazione della zona "x"
				vertici_ins[i][d]=a;//metto in zona "x" la prima informazione di buffer											
				a=vertici_ins[0][1];//associo ad a la seconda informazione di buffer
				b=vertici_ins[i][1];//associo a b l'informazione della zona "p"
				vertici_ins[0][1]=b;//metto in prima zona buffer l'informazione della zona "p"
				vertici_ins[i][1]=a;//metto in zona "p" la seconda informazione di buffer					
				a=vertici_ins[0][2];//associo ad a l'ultima informazione di buffer
				b=vertici_ins[i][0];//associo a b l'informazione della zona "k"
				vertici_ins[0][2]=b;//metto in ultima zona buffer l'informazione della zona "k"
				vertici_ins[i][0]=a;//metto in zona "k" l'ultima informazione di buffer
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				action180(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				rotate90();
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				action270(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				rotate90();
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				perm();//stampa la permutazione dei vertici
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				rotate270();
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				action90(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				rotate270();
				action180(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				break;//esce dallo switch
			}
			case 6:{//se i è uguale a 6, avvia la risoluzione per la posizione "v"
				a=vertici_ins[0][0];//associo ad a la prima informazione di buffer
				b=vertici_ins[i][d];//associo a b l'informazione della zona "v"
				vertici_ins[0][0]=b;//metto in prima zona buffer l'informazione della zona "v"
				vertici_ins[i][d]=a;//metto in zona "v" la prima informazione di buffer											
				a=vertici_ins[0][1];//associo ad a la seconda informazione di buffer
				b=vertici_ins[i][1];//associo a b l'informazione della zona "l"
				vertici_ins[0][1]=b;//metto in prima zona buffer l'informazione della zona "l"
				vertici_ins[i][1]=a;//metto in zona "l" la seconda informazione di buffer					
				a=vertici_ins[0][2];//associo ad a l'ultima informazione di buffer
				b=vertici_ins[i][0];//associo a b l'informazione della zona "g"
				vertici_ins[0][2]=b;//metto in ultima zona buffer l'informazione della zona "g"
				vertici_ins[i][0]=a;//metto in zona "g" l'ultima informazione di buffer
				rotate90();
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				action90(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				rotate90();
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				action90(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				rotate90();
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				perm();//stampa la permutazione dei vertici
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				rotate270();
				action270(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				rotate270();
				action270(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				rotate270();
				break;//esce dallo switch
			}
			case 7:{//se i è uguale a 7, avvia la risoluzione per la posizione "u"
				a=vertici_ins[0][0];//associo ad a la prima informazione di buffer
				b=vertici_ins[i][d];//associo a b l'informazione della zona "u"
				vertici_ins[0][0]=b;//metto in prima zona buffer l'informazione della zona "u"
				vertici_ins[i][d]=a;//metto in zona "u" la prima informazione di buffer											
				a=vertici_ins[0][1];//associo ad a la seconda informazione di buffer
				b=vertici_ins[i][0];//associo a b l'informazione della zona "h"
				vertici_ins[0][1]=b;//metto in prima zona buffer l'informazione della zona "h"
				vertici_ins[i][0]=a;//metto in zona "h" la seconda informazione di buffer		
				a=vertici_ins[0][2];//associo ad a l'ultima informazione di buffer
				b=vertici_ins[i][1];//associo a b l'informazione della zona "s"
				vertici_ins[0][2]=b;//metto in ultima zona buffer l'informazione della zona "s"
				vertici_ins[i][1]=a;//metto in zona "s" l'ultima informazione di buffer
				rotate90();
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				action90(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				rotate90();
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				perm();//stampa la permutazione dei vertici
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				rotate270();
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				action270(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				rotate270();
				break;//esce dallo switch
			}
			default: //se in i c'è qualcosa di diverso da questi caratteri
				printf("errore\n");
				break;//esce dallo switch
		}
	}
	return 0;	
}

//questa funzione serve a commutare e sistemare veramente i lati, stampando le informazioni utili al robot per risolverlo
int commutazioni(int d, int i){//funzione per togliere moltre stringhe di codice per capire quale ciclo sta facendo per risolvere il cubo
	if(d==0){//se la posizione scombinata è quella della prima informazione della cella
		switch(i){
			case 0:{//se i è uguale a 0, si avvia la risoluzione per la posizione a
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				action180(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				rotate180();
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				action90(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				action180(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				t_perm();//svolge la t perm
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
     				action180(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
        			action270(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
        			rotate180();
        			action180(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				break;//esce dallo switch
			}
			case 1:{//se i è uguale a 1 (impossibile ma la mettiamo lo stesso), avvia la risoluzione per la posizione b
				printf("error\n");//stampa errore
				break;//esce dallo switch
			}
			case 2:{//se i è uguale a 2,si avvia la risoluzione per la posizione c
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				action180(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
        			rotate180();
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				action270(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				action180(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				t_perm();//svolge la t perm
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
        			action180(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				action90(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				rotate180();
				action180(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				break;//esce dallo switch
			}
			case 3:{//se i è uguale a 3, si avvia la risoluzione per la posizione d
				t_perm();//svolge la t perm
				break;//esce dallo switch
			}
			case 4:{//se i è uguale a 4, si avvia la risoluzione per la posizione f
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				action180(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				action270(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				rotate180();
				t_perm();//svolge la t perm
				rotate180();
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				action90(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				action180(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				break;//esce dallo switch
			}
			case 5:{//se i è uguale a 5, si avvia la risoluzione per la posizione g
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				action270(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				rotate90();
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				action270(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				action180(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				t_perm();//svolge la t perm
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				action180(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				action90(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				rotate270();
				action90(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				break;//esce dallo switch
			}
			case 6:{//se i è uguale a 6, si avvia la risoluzione per la posizione h
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				action90(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				t_perm();//svolge la t perm
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				action270(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				break;//esce dallo switch
			}
			case 7:{//se i è uguale a 7, si avvia la risoluzione per la posizione j
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				action270(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				rotate90();
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				action270(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				t_perm();//svolge la t perm
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				action90(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				rotate270();
				action90(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);			
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				break;//esce dallo switch
			}
			case 8:{//se i è uguale a 8, si avvia la risoluzione per la posizione k
				action90(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				rotate90();
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				action270(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				rotate90();
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				action90(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				action90(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				rotate90();
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				rotate90();
				t_perm();//svolge la t perm
				rotate270();
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				rotate270();
				action270(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				action270(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				rotate270();
				action90(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				rotate270();
				action270(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				break;//esce dallo switch
			}
			case 9:{//se i è uguale a 9, si avvia la risoluzione per la posizione n
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				action270(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				t_perm();//svolge la t perm
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				action90(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				break;//esce dallo switch
			}
			case 10:{//se i è uguale a 10, si avvia la risoluzione per la posizione o
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				action90(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				rotate90();
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				action90(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				action180(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				rotate180();
				t_perm();//svolge la t perm
				rotate180();
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				action180(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				action270(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				rotate270();
				action270(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				break;//esce dallo switch
			}
			case 11:{//se i è uguale a 11, si avvia la risoluzione per la posizione s
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				action90(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				action90(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				rotate90();
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				action270(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				rotate180();
				t_perm();//svolge la t perm
				rotate180();
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				action90(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				rotate270();
				action270(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				action270(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				break;//esce dallo switch
			}
			default: //se in i c'è qualcosa di diverso da questi caratteri
				printf("errore\n");
				break;//esce dallo switch				
		}
	}
	else if(d==1){//se la posizione scombinata è quella dell'ultima informazione della cella
		switch(i){
			case 0:{//se i è uguale a 0, si avvia la risoluzione per la posizione m
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				action90(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				rotate90();
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				action270(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				action180(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				rotate180();
				t_perm();//svolge la t perm
				rotate180();
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				action180(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				action90(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				rotate270();
				action270(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				break;//esce dallo switch
			}
			case 1:{//se i è uguale a 1 (impossibile ma la mettiamo lo stesso), avvia la risoluzione per la posizione i
				printf("error\n");//stampa il cambiamento fatto per conoscere il ciclo della risoluzione del cubo
				break;//esce dallo switch
			}
			case 2:{//se i è uguale a 2, si avvia la risoluzione per la posizione e
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				action270(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				rotate90();
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				action90(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				action180(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				t_perm();//svolge la t perm
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				action180(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				action270(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				rotate270();
				action90(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				break;//esce dallo switch
			}
			case 3:{//se i è uguale a 3, si avvia la risoluzione per la posizione q
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				action270(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				action90(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				rotate90();
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				action270(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				rotate180();
				t_perm();//svolge la t perm
				rotate180();
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				action90(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				rotate270();
				action270(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				action90(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				break;//esce dallo switch
			}
			case 4:{//se i è uguale a 4, si avvia la risoluzione per la posizione l
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				action90(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				rotate90();
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				action90(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				rotate180();
				t_perm();//svolge la t perm
				rotate180();
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				action270(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				rotate270();
				action270(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				break;//esce dallo switch
			}
			case 5:{//se i è uguale a 5, si avvia la risoluzione per la soluzione u
				action90(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				action180(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				t_perm();//svolge la t perm
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				action180(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				action270(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				break;//esce dallo switch
			}
			case 6:{//se i è uguale a 6, si avvia la risoluzione per la soluzione r
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				action90(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				rotate90();
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				action270(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				rotate180();
				t_perm();//svolge la t perm
				rotate180();
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				action90(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				rotate270();
				action270(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				break;//esce dallo switch
			}
			case 7:{//se i è uguale a 7, si avvia la risoluzione per la soluzione p
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				action180(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				action90(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				rotate180();
				t_perm();//svolge la t perm
				rotate180();
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				action270(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				action180(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				break;//esce dallo switch
			}
			case 8:{//se i è uguale a 8, si avvia la risoluzione per la soluzione v
				action180(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				action180(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				t_perm();//svolge la t perm
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				action180(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				action180(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				break;//esce dallo switch
			}
			case 9:{//se i è uguale a 9, si avvia la risoluzione per la soluzione t
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				action270(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				rotate270();
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				action90(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				rotate180();
				t_perm();//svolge la t perm
				rotate180();
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				action270(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				rotate90();
				action90(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				break;//esce dallo switch
			}
			case 10:{//se i è uguale a 10, si avvia la risoluzione per la soluzione x
				action270(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				action180(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				t_perm();//svolge la t perm
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				action180(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				action90(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				break;//esce dallo switch
			}
			case 11:{//se i è uguale a 11, si avvia la risoluzione per la soluzione z
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				action180(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				t_perm();//svolge la t perm
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				action180(servo1, stepsorienta1, servo2, stepsorienta2, numStepsorienta, posizioneRiposo1, posizioneRiposo2);
				Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);Movesx(servo1, steps1, servo2, steps2, 9, 169, 8);
				break;//esce dallo switch
			}
			default: //se in i c'è qualcosa di diverso da questi caratteri
				printf("errore\n");
				break;//esce dallo switch				
		}
	}
	else{//se non dovesse funzionare nessuno dei due pezzi 
		printf("Error\n");
	}
	return 0;	
}
