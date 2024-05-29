int posizione;  // 0 = 0 gradi    255 = 180 gradi 
int direzione;  // 1 = avanti   0 = indietro

const int step_motore_avanti = 10;
const int step_motore_indietro = 1;
const int delay_unitario = 10;
void setup() {
  pinMode(3, OUTPUT);
  posizione = 255;
  direzione = 0;
}

void loop() {
  analogRead(A0);
  if (direzione == 1){
  posizione += step_motore_avanti;
  if (posizione >= 260){
    direzione=0;
  }
}
else{
  posizione -= step_motore_indietro;
  if(posizione <=0){
    direzione = 1;
  }
}
//analogWrite(3, posizione);
delay(delay_unitario);
}
