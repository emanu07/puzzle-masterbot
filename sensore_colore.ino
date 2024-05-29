#define S0 4
#define S1 5
#define S2 6
#define S3 7
#define OUT 8


void setup() {
  Serial.begin(9600);
  pinMode(S0,OUTPUT);
  pinMode(S1,OUTPUT);
  pinMode(S2,OUTPUT);
  pinMode(S3,OUTPUT);
  pinMode(OUT,INPUT);
  digitalWrite(S0,HIGH);
  digitalWrite(S1,HIGH);//definiscono la qualità dei colori. così è al 100%
}
unsigned long r, g, b;//definisco le variabili che conterranno le informazioni dei singoli colori
void loop() {
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);//leggeremo il rosso
  r= pulseIn(OUT,LOW);//legge il tempo di risposta del segnale e lo associa al rosso
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);//leggeremo il verde
  g= pulseIn(OUT,LOW);//legge il tempo di risposta del segnale e lo associa al verde
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);//leggeremo il blu
  b= pulseIn(OUT,LOW);//legge il tempo di risposta del segnale e lo associa al blu

  Serial.print("R= ");
  Serial.print(r);
  Serial.print("G= ");
  Serial.print(g);
  Serial.print("B= ");
  Serial.println(b);
  delay(1000);
}
