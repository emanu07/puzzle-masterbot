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

void setup() {


}
void go(int st){
  stato=st;//va alla fase che ho detto io
  first=false;//per riutilizzare la variabile first anche nelle altre fasi
}
void loop() {
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
  }

}
void orienta(){
  if (first=true){
    scanf("%d",& c1);						//guardo che colore è il centro in cima
	  printf("\n");
  	while(c1 != 1){							//se il colore non è bianco
	  	printf("move to sx\n");				//sposta cubo verso sinistra
		  scanf("%d",& c1);					//guardo che colore è il nuovo centro in cima
	  	printf("\n");						
		  n++;								//aggiorno di uno il contatore
  		if(n==3){							//se il contatore è a 3
	  		printf("rotate 90\n");			//ruota il cubo di 90 orari
		  	n=0;							//aggiorna il contatore a 0
  		}
  	}
	  printf("centro bianco trovato\n");		//per capire se funge
	  printf("move to sx\n");					//sposta cubo verso sinistra
  	scanf("%d",& c2);						//guardo che colore è il centro che andrà di fronte a me
	  printf("\n");
  	printf("rotate 90\n");					//ruota il cubo di 90 orari
	  while(c2!=2){
	   	printf("move to sx\n");				//sposta cubo verso sinistra
		  scanf("%d",& c2);					//guardo che colore è il nuovo centro che andrà di fronte a me
		  printf("\n");
	  }
  	printf("centro verde trovato\n");		//per capire se funge
	  printf("rotate 90\n");					//ruota il cubo di 90 orari
  	printf("move to sx\n");					//sposta cubo verso sinistra
	  printf("rotate 270\n");				//ruota il cubo di 270 orari
    first=false;
  }
  go(1);//va alla fase 1
}
void scansiona(){
  if (first=true)
}
void ordina(){

}