#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {
	int c1, c2, c3=3, c4=4, c5=5, c6=6;		//creo le variabili che contengono l'informazione del colore dei centri
	int n=0;								//creo una variabile che utilizzerò come contatore
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
	return 0;	
}
