#include <stdio.h>
#include <stdlib.h>

/* In questo programma troveremo il programma completo che utilizzeremo per risolvere il cubo di rubik */

int main(int argc, char *argv[]) {
	int nf;									//variabile utile per il contatore delle facce del cubo
	int ns;									//variabile utile per il contatore delle volte di pezzi da scansionare
	int lati [24];							//array che conterrà tutte le informazioni sui lati
	int vertici[24];						//array che conterrà tutte le informazioni sui vertici
	/*variabili utili per il secondo programma*/
	int c1, c2, c3=3, c4=4, c5=5, c6=6;		//creo le variabili che contengono l'informazione del colore dei centri
	int n=0;								//creo una variabile che utilizzerò come contatore e come variabile per mettere le scansioni negli Array
	scanf("%d",& c1);						//guardo che colore è il centro in cima
	printf("\n");
	while(c1 != 1){							//se il colore non è bianco
		printf("move to sx\n");				//sposta cubo verso sinistra
		scanf("%d",& c1);					//guardo che colore è il nuovo centro in cima
		printf("\n");						
		n++;								//aggiorno di uno il contatore
		if(n==3){							//se il contatore è a 3
			printf("rotate 90\n");			//ruota il cubo di 90° orari
			n=0;							//aggiorna il contatore a 0
		}
	}
	printf("centro bianco trovato\n");		//per capire se funge
	printf("move to sx\n");					//sposta cubo verso sinistra
	scanf("%d",& c2);						//guardo che colore è il centro che andrà di fronte a me
	printf("\n");
	printf("rotate 90\n");					//ruota il cubo di 90° orari
	while(c2!=2){
		printf("move to sx\n");				//sposta cubo verso sinistra
		scanf("%d",& c2);					//guardo che colore è il nuovo centro che andrà di fronte a me
		printf("\n");
	}
	printf("centro verde trovato\n");		//per capire se funge
	printf("rotate 90\n");					//ruota il cubo di 90° orari
	printf("move to sx\n");					//sposta cubo verso sinistra
	printf("rotate 270\n");				//ruota il cubo di 270° orari
	/*fine primo programma parziale che orienta il cubo*/
	printf("Move scan arm to sx\n");		//muove il braccio che scansiona i pezzi verso sinistra
	n=0;									//aggiorno la variabile a 0 e la utilizzerò per mettere le scansioni negli Array
	for(nf=0; nf<6; nf++){					//crea funzione per ogni faccia del cubo
		for(ns=0; ns<4; ns++, n++){			//crea funzione per ogni scansione della faccia
			scanf("%d",& lati[n]);			//salva il pezzo nell'array dei lati
			printf("\n");
			printf("rotate 90\n");			//ruota il cubo di 90° orari
		}
		if(nf==3){							//se il programma sta facendo la quarta faccia
			printf("rotate 90\n");			//ruota il cubo di 90° orari
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
	printf("rotate 270\n");					//ruota il cubo di 270° orari
	printf("move to sx\n");					//sposta cubo verso sinistra
	n=0;									//faccio sì che la variabile t ritorni a 0 perchè dovrò riusarla per l'altro array
	printf("rotate 315\n");					//ruota il cubo di 315° orari per far si che si allineino i vertici da soli
	for(nf=0; nf<6; nf++){					//crea funzione per ogni faccia del cubo
		for(ns=0; ns<4; ns++, n++){			//crea funzione per ogni scansione della faccia
			scanf("%d",& vertici[n]);		//salva il pezzo nell'array dei vertici
			printf("\n");
			printf("rotate 90\n");			//ruota il cubo di 90° orari
		}
		if(nf==3){							//se il programma sta facendo la quarta faccia
			printf("rotate 90\n");			//ruota il cubo di 90° orari
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
	printf("rotate 270\n");					//ruota il cubo di 270° orari
	printf("move to sx\n");					//sposta cubo verso sinistra
	/*fine secondo programma che scansiona e orienta nuovamente il cubo*/
	return 0;
}
