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
		case 3:
			attesa()//fase di attesa dove non fa nulla perchè il cubo è stato risolto
			break;
  }

}
void orienta(){
  if (first==true){
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
  if (first=true){
		printf("Move scan arm to dx\n");		//muove il braccio che scansiona i pezzi verso destra
		for(nf=0; nf<6; nf++){					//crea funzione per ogni faccia del cubo
			for(ns=0; ns<4; ns++, t++){			//crea funzione per ogni scansione della faccia
				scanf("%d",& lati[0][t]);			//salva il pezzo nell'array dei lati
				printf("\n");
				printf("rotate 90\n");			//ruota il cubo di 90 orari
			}
			if(nf==3){							//se il programma sta facendo la quarta faccia
				printf("rotate 90\n");			//ruota il cubo di 90 orari
				printf("move to sx\n");			//sposta cubo verso sinistra
			}
			else if(nf==4){						//se il programma sta facendo la quinta faccia
				printf("move to sx\n");			//sposta cubo verso sinistra
				printf("move to sx\n");			//sposta cubo verso sinistra			
			}
			else{								//se non è ne la quarta che la quinta faccia
				printf("move to sx\n");			//sposta cubo verso sinistra
			}	
		}
		printf("rotate 270\n");					//ruota il cubo di 270 orari
		printf("move to sx\n");					//sposta cubo verso sinistra
		t=0;									//faccio si che la variabile t ritorni a 0 perche dovrò riusarla per l'altro array
		printf("Move scan arm dx\n rotate 45\n");//muove il braccio che scansiona i vertici e ruota di 45 gradi il cassetto in modo da legere bene i vertici -->non so se debba andare così
		for(nf=0; nf<6; nf++){					//crea funzione per ogni faccia del cubo
			for(ns=0; ns<4; ns++, t++){			//crea funzione per ogni scansione della faccia
				scanf("%d",& vertici[0][t]);		//salva il pezzo nell'array dei vertici
				printf("\n");
				printf("rotate 90\n");			//ruota il cubo di 90 orari
			}
			if(nf==3){							//se il programma sta facendo la quarta faccia
				printf("rotate 90\n");			//ruota il cubo di 90 orari
				printf("move to sx\n");			//sposta cubo verso sinistra
			}
			else if(nf==4){						//se il programma sta facendo la quinta faccia
				printf("move to sx\n");			//sposta cubo verso sinistra
				printf("move to sx\n");			//sposta cubo verso sinistra			
			}
			else{								//se non è ne la quarta che la quinta faccia
				printf("move to sx\n");			//sposta cubo verso sinistra
			}	
		}
		printf("rotate 270\n");					//ruota il cubo di 270 orari
		printf("move to sx\n");					//sposta cubo verso sinistra
		first=false;
	}
	go(2);//va alla fase 2
}
void ordina(){
	if(first==true){
		vertici_ins[0][0]= vertici[0][0];//vertice di coordinate a,n,q che deve prendere le informazioni del 1Ãƒâ€šÃ‚Â°, del 16Ãƒâ€šÃ‚Â° e del 18Ãƒâ€šÃ‚Â° dell'array vertici
		vertici_ins[0][1]= vertici[0][15];
		vertici_ins[0][2]= vertici[0][17];
		vertici_ins[1][0]= vertici[0][3];//vertice di coordinate b,m,j che deve prendere le informazioni del 4Ãƒâ€šÃ‚Â°, del 19Ãƒâ€šÃ‚Â° e del 5Ãƒâ€šÃ‚Â° dell'array vertici
		vertici_ins[1][1]= vertici[0][18];
		vertici_ins[1][2]= vertici[0][4];
		vertici_ins[2][0]= vertici[0][2];//vertice di coordinate c,i,f che deve prendere le informazioni del 3Ãƒâ€šÃ‚Â°, del 6Ãƒâ€šÃ‚Â° e del 22Ãƒâ€šÃ‚Â° dell'array vertici
		vertici_ins[2][1]= vertici[0][5];
		vertici_ins[2][2]= vertici[0][21];
		vertici_ins[3][0]= vertici[0][1];//vertice di coordinate d,e,r che deve prendere le informazioni del 2Ãƒâ€šÃ‚Â°, del 23Ãƒâ€šÃ‚Â° e del 15Ãƒâ€šÃ‚Â° dell'array vertici
		vertici_ins[3][1]= vertici[0][22];
		vertici_ins[3][2]= vertici[0][14];
		vertici_ins[4][0]= vertici[0][16];//vertice di coordinate o,t,z che deve prendere le informazioni del 17Ãƒâ€šÃ‚Â°, del 13Ãƒâ€šÃ‚Â° e del 12Ãƒâ€šÃ‚Â° dell'array vertici
		vertici_ins[4][1]= vertici[0][12];
		vertici_ins[4][2]= vertici[0][11];
		vertici_ins[5][0]= vertici[0][7];//vertice di coordinate k,p,x che deve prendere le informazioni del 8Ãƒâ€šÃ‚Â°, del 20Ãƒâ€šÃ‚Â° e del 9Ãƒâ€šÃ‚Â° dell'array vertici
		vertici_ins[5][1]= vertici[0][19];
		vertici_ins[5][2]= vertici[0][8];
		vertici_ins[6][0]= vertici[0][20];//vertice di coordinate g,l,v che deve prendere le informazioni del 21Ãƒâ€šÃ‚Â°, del 7Ãƒâ€šÃ‚Â° e del 10Ãƒâ€šÃ‚Â° dell'array vertici
		vertici_ins[6][1]= vertici[0][6];
		vertici_ins[6][2]= vertici[0][9];
		vertici_ins[7][0]= vertici[0][23];//vertice di coordinate h,s,u che deve prendere le informazioni del 24Ãƒâ€šÃ‚Â°, del 14Ãƒâ€šÃ‚Â° e del 11Ãƒâ€šÃ‚Â° dell'array vertici
		vertici_ins[7][1]= vertici[0][13];
		vertici_ins[7][2]= vertici[0][10];
	
	
		/*Questa parte di programma serve per trasferire l'informazione dell'array adimensionale dei lati in un array organizzato che mi dia tutte 
		le informazioni di ogni singolo lato. In questo modo posso nominare arbitrariamente ogni posizione del cubo*/
	
		
		lati_ins[0][0]= lati[0][3];//lato di coordinate a,m che deve prendere le informazioni del 4Ã‚Â° e del 18Ã‚Â° dell'array lati
		lati_ins[0][1]= lati[0][17];
		lati_ins[1][0]= lati[0][2];//lato di coordinate b,i (buffer) che deve prendere le informazioni del 3Ã‚Â° e del 5Ã‚Â° dell'array lati
		lati_ins[1][1]= lati[0][4];
		lati_ins[2][0]= lati[0][1];//lato di coordinate c,e che deve prendere le informazioni del 2Ã‚Â° e del 22Ã‚Â° dell'array lati
		lati_ins[2][1]= lati[0][21];
		lati_ins[3][0]= lati[0][0];//lato di coordinate d,q che deve prendere le informazioni del 1Ã‚Â° e del 15Ã‚Â° dell'array lati
		lati_ins[3][1]= lati[0][14];
		lati_ins[4][0]= lati[0][20];//lato di coordinate f,l che deve prendere le informazioni del 21Ã‚Â° e del 6Ã‚Â° dell'array lati
		lati_ins[4][1]= lati[0][5];
		lati_ins[5][0]= lati[0][23];//lato di coordinate g,u che deve prendere le informazioni del 24Ã‚Â° e del 10Ã‚Â° dell'array lati
		lati_ins[5][1]= lati[0][9];
		lati_ins[6][0]= lati[0][22];//lato di coordinate h,r che deve prendere le informazioni del 23Ã‚Â° e del 14Ã‚Â° dell'array lati
		lati_ins[6][1]= lati[0][13];
		lati_ins[7][0]= lati[0][7];//lato di coordinate j,p che deve prendere le informazioni del 8Ã‚Â° e del 19Ã‚Â° dell'array lati
		lati_ins[7][1]= lati[0][18];
		lati_ins[8][0]= lati[0][6];//lato di coordinate k,v che deve prendere le informazioni del 7Ã‚Â° e del 9Ã‚Â° dell'array lati
		lati_ins[8][1]= lati[0][8];
		lati_ins[9][0]= lati[0][16];//lato di coordinate n,t che deve prendere le informazioni del 17Ã‚Â° e del 16Ã‚Â° dell'array lati
		lati_ins[9][1]= lati[0][15];
		lati_ins[10][0]= lati[0][19];//lato di coordinate o,x che deve prendere le informazioni del 20Ã‚Â° e del 12Ã‚Â° dell'array lati
		lati_ins[10][1]= lati[0][11];
		lati_ins[11][0]= lati[0][12];//lato di coordinate s,z che deve prendere le informazioni del 13Ã‚Â° e del 11Ã‚Â° dell'array lati
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
			printf("3 move to sx\n action 270\n 3 move to sx\n action 270\n move to sx\n action 90\n rotate 90\n move to sx\n action 90\n");//stampa la funzione
			printf("3 move to sx\n action 270\n rotate 90\n move to sx\n action 180\n 3 move to sx\n action 90\n move to sx\n action 180\n");//stampa la funzione
			printf("3 move to sx\n action 90\n rotate 90\n 3 move to sx\n action 270\n move to sx\n action 270\n rotate 90\n 3 move to sx\n");//stampa la funzione
			printf("action 270\n move to sx\n action 270\n 3 move to sx\n action 180\n move to sx\n action 90\n 3 move to sx\n action 90\n 2 move to sx\n");//stampa la funzione
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
