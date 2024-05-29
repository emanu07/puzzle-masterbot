#include <stdio.h>
#include <stdlib.h>

/*Questo programma, da implementare successivamente al programma "orientare_cubo" deve svolgere l'incarico di scansionare tutti i pezzi
del cubo di Rubik, associarli in degli Array prestabiliti e orientare nuovamente il cubo. Se possibile, questo programma dovrebbe anche iniziare
a risolvere il cubo di Rubik. */

int main(int argc, char *argv[]) {
	int nf;									//variabile utile per il contatore delle facce del cubo
	int ns;									//variabile utile per il contatore delle volte di pezzi da scansionare
	int t=0;								//variabile utile per capire in che posizione degli Array mettere i singoli pezzi
	int lati [24];							//array che conterrà tutte le informazioni sui lati
	int vertici[24];						//array che conterrà tutte le informazioni sui vertici
	printf("Move scan arm to sx\n");		//muove il braccio che scansiona i pezzi verso sinistra
	for(nf=0; nf<6; nf++){					//crea funzione per ogni faccia del cubo
		for(ns=0; ns<4; ns++, t++){			//crea funzione per ogni scansione della faccia
			scanf("%d",& lati[t]);			//salva il pezzo nell'array dei lati
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
	t=0;									//faccio sì che la variabile t ritorni a 0 perchè dovrò riusarla per l'altro array
	printf("Move scan arm up\n");			//muove il braccio che scansiona verso l'alto per scansionare i vertici
	for(nf=0; nf<6; nf++){					//crea funzione per ogni faccia del cubo
		for(ns=0; ns<4; ns++, t++){			//crea funzione per ogni scansione della faccia
			scanf("%d",& vertici[t]);		//salva il pezzo nell'array dei vertici
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
	return 0;
}
