#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int i=0;//contatore
	int lati[1][24];//array che conterrà le scansioni dei lati scombinati
	int lati_ins [12][2];//array che contiene gli insiemi degli array dei singoli 12 lati
	int lati_vero [12][2]={{1,4}, {1,3}, {1,2}, {1,5}, {2,3}, {2,6}, {2,5}, {3,4}, {3,6}, {4,5}, {4,6}, {5,6}};//array che contiene le informazioni dei lati giusti
	printf("Inserire lati\n");
	for(i=0; i<24; i++){
		scanf("%d",& lati[0][i]);//mette i valori messi da me negli array dei lati
	}
	
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
