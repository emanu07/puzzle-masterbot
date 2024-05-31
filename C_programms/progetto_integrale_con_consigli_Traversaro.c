#include <stdio.h>
#include <stdlib.h>
/*per non utilizzare altri servi motori per lo scan arm bisognerà implementare al programma non il movimento dello scan arm verso up ma basterà 
ruotare di 45 gradi il cassetto per allineare solamente così il braccio ai vertici*/

struct stato_cubo
{
	//array che contiene gli insiemi delle informazioni degli array dei singoli vertici scombinati
	int vertici[8][3];
	//array che contiene gli insiemi degli array dei singoli 12 lati
	int lati[12][2];
}


int cuboERisolto(stato_cubo)
{
}


#include <stdio.h>

// Definizione della struttura con puntatori a funzioni
struct Operations {
    void (*move90)();
    void (*rotateSinistra)();
};

void algoritmo_generico(struct Operations ops)
{
	ops->move90();
	ops->rotateSinistra();
}

// Implementazione delle funzioni
int move90_umano() {
    printf("move90");
}

int rotateSinistra_umano() {
    printf("rotateSinistra");
}

int move90_arduino() {
    //
}

int v_arduino() {
    printf("rotateSinistra");
}

int main() {
	
	// 1 : umano, 2 arduino
	int operazioniDaUsare = 1;
    // Inizializzazione della struttura con le funzioni appropriate
    struct Operations ops;
    
    if (operazioniDaUsare == 1)
    {
    	ops.move90 = move90_umano;
    	ops.rotateSinistra = rotateSinistra_umano;
	}
	else
	{
    	ops.move90 = move90_arduino;
    	ops.rotateSinistra = rotateSinistra_arduino;
	}


	algoritmo_generico(ops);
    
    // Utilizzo dei puntatori a funzioni attraverso la struttura
    int x = 10, y = 5;

    printf("Addizione: %d + %d = %d\n", x, y, ops.add(x, y));
    printf("Sottrazione: %d - %d = %d\n", x, y, ops.subtract(x, y));
    printf("Moltiplicazione: %d * %d = %d\n", x, y, ops.multiply(x, y));
    printf("Divisione: %d / %d = %d\n", x, y, ops.divide(x, y));

    return 0;
}


int main(int argc, char *argv[]) {
		/*variabili prima parte*/
	int c1, c2, c3=3, c4=4, c5=5, c6=6;		//creo le variabili che contengono l'informazione del colore dei centri
	int n=0;								//creo una variabile che utilizzerò come contatore e successivamente come variabile utile per gli Array
	/*variabili seconda parte*/
	int nf;									//variabile utile per il contatore delle facce del cubo
	int ns;									//variabile utile per il contatore delle volte di pezzi da scansionare
	int lati [1][24];							//array che conterrà tutte le informazioni sui lati
	int vertici[1][24];						//array che conterrà tutte le informazioni sui vertici
	/*variabili parte di ordinamento*/
	
	
	struct stato_cubo stato_ins;
	struct stato_cubo stato_vero;

	//int vertici_ins[8][3];
	stato_vero.vertici ={{1,5,4}, {1,4,3}, {1,3,2}, {1,2,5}, {4,5,6}, {3,4,6}, {2,3,6}, {2,5,6}};//array che contiene le informazioni dei vertici giusti
	//int lati_ins [12][2];
	stato_vero.lati={{1,4}, {1,3}, {1,2}, {1,5}, {2,3}, {2,6}, {2,5}, {3,4}, {3,6}, {4,5}, {4,6}, {5,6}};//array che contiene le informazioni dei lati giusti
	
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
	printf("move to sx\n");					//sposta cubo verso sinista
	printf("rotate 270\n");				//ruota il cubo di 270° orari
	/*fine primo programma che orienta il cubo*/
	printf("Move scan arm to sx\n");		//muove il braccio che scansiona i pezzi verso sinistra
	for(nf=0; nf<6; nf++){					//crea funzione per ogni faccia del cubo
		for(ns=0; ns<4; ns++, n++){			//crea funzione per ogni scansione della faccia
			scanf("%d",& lati[0][n]);			//salva il pezzo nell'array dei lati
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
	printf("Move scan arm up\n");			//muove il braccio che scansiona verso l'alto per scansionare i vertici
	for(nf=0; nf<6; nf++){					//crea funzione per ogni faccia del cubo
		for(ns=0; ns<4; ns++, n++){			//crea funzione per ogni scansione della faccia
			scanf("%d",& vertici[0][n]);		//salva il pezzo nell'array dei vertici
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
	/*fine secondo programma che scansiona i pezzi e riorienta il cubo*/
	/*inizio parte di ordinamento dei vertici e dei lati*/
	vertici_ins[0][0]= vertici[0][0];//vertice di coordinate a,n,q che deve prendere le informazioni del 1°, del 16° e del 18° dell'array vertici
	vertici_ins[0][1]= vertici[0][15];
	vertici_ins[0][2]= vertici[0][17];
	vertici_ins[1][0]= vertici[0][3];//vertice di coordinate b,m,j che deve prendere le informazioni del 4°, del 19° e del 5° dell'array vertici
	vertici_ins[1][1]= vertici[0][18];
	vertici_ins[1][2]= vertici[0][4];
	vertici_ins[2][0]= vertici[0][2];//vertice di coordinate c,i,f che deve prendere le informazioni del 3°, del 6° e del 22° dell'array vertici
	vertici_ins[2][1]= vertici[0][5];
	vertici_ins[2][2]= vertici[0][21];
	vertici_ins[3][0]= vertici[0][1];//vertice di coordinate d,e,r che deve prendere le informazioni del 2°, del 23° e del 15° dell'array vertici
	vertici_ins[3][1]= vertici[0][22];
	vertici_ins[3][2]= vertici[0][14];
	vertici_ins[4][0]= vertici[0][16];//vertice di coordinate o,t,z che deve prendere le informazioni del 17°, del 13° e del 12° dell'array vertici
	vertici_ins[4][1]= vertici[0][12];
	vertici_ins[4][2]= vertici[0][11];
	vertici_ins[5][0]= vertici[0][7];//vertice di coordinate k,p,x che deve prendere le informazioni del 8°, del 20° e del 9° dell'array vertici
	vertici_ins[5][1]= vertici[0][19];
	vertici_ins[5][2]= vertici[0][8];
	vertici_ins[6][0]= vertici[0][20];//vertice di coordinate g,l,v che deve prendere le informazioni del 21°, del 7° e del 10° dell'array vertici
	vertici_ins[6][1]= vertici[0][6];
	vertici_ins[6][2]= vertici[0][9];
	vertici_ins[7][0]= vertici[0][23];//vertice di coordinate h,s,u che deve prendere le informazioni del 24°, del 14° e del 11° dell'array vertici
	vertici_ins[7][1]= vertici[0][13];
	vertici_ins[7][2]= vertici[0][10];
	
	lati_ins[0][0]= lati[0][3];//lato di coordinate a,m che deve prendere le informazioni del 4° e del 18° dell'array lati
	lati_ins[0][1]= lati[0][17];
	lati_ins[1][0]= lati[0][2];//lato di coordinate b,i (buffer) che deve prendere le informazioni del 3° e del 5° dell'array lati
	lati_ins[1][1]= lati[0][4];
	lati_ins[2][0]= lati[0][1];//lato di coordinate c,e che deve prendere le informazioni del 2° e del 22° dell'array lati
	lati_ins[2][1]= lati[0][21];
	lati_ins[3][0]= lati[0][0];//lato di coordinate d,q che deve prendere le informazioni del 1° e del 15° dell'array lati
	lati_ins[3][1]= lati[0][14];
	lati_ins[4][0]= lati[0][20];//lato di coordinate f,l che deve prendere le informazioni del 21° e del 6° dell'array lati
	lati_ins[4][1]= lati[0][5];
	lati_ins[5][0]= lati[0][23];//lato di coordinate g,u che deve prendere le informazioni del 24° e del 10° dell'array lati
	lati_ins[5][1]= lati[0][9];
	lati_ins[6][0]= lati[0][22];//lato di coordinate h,r che deve prendere le informazioni del 23° e del 14° dell'array lati
	lati_ins[6][1]= lati[0][13];
	lati_ins[7][0]= lati[0][7];//lato di coordinate j,p che deve prendere le informazioni del 8° e del 19° dell'array lati
	lati_ins[7][1]= lati[0][18];
	lati_ins[8][0]= lati[0][6];//lato di coordinate k,v che deve prendere le informazioni del 7° e del 9° dell'array lati
	lati_ins[8][1]= lati[0][8];
	lati_ins[9][0]= lati[0][16];//lato di coordinate n,t che deve prendere le informazioni del 17° e del 16° dell'array lati
	lati_ins[9][1]= lati[0][15];
	lati_ins[10][0]= lati[0][19];//lato di coordinate o,x che deve prendere le informazioni del 20° e del 12° dell'array lati
	lati_ins[10][1]= lati[0][11];
	lati_ins[11][0]= lati[0][12];//lato di coordinate s,z che deve prendere le informazioni del 13° e del 11° dell'array lati
	lati_ins[11][1]= lati[0][10];
	return 0;	
}
