#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int i=0;//contatore
	int n=0;//contatore
	int vertici_ins[8][3];//array che contiene gli insiemi delle informazioni degli array dei singoli vertici scombinati
	int vertici[1][24];//array che conterrà le scansioni dei vertici scombinati
	int vertici_vero[8][3]={{1,4,5}, {1,4,3}, {1,3,2}, {1,2,5}, {4,5,6}, {3,4,6}, {2,3,6}, {2,5,6}};//array che contiene le informazioni dei vertici giusti
	printf("inserire vertici\n");
	for(i=0; i<24; i++){
		scanf("%d",& vertici[0][i]);//mette i valori messi da me negli array dei vertici
	}
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
	return 0;
}
