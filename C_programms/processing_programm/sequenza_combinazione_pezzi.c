#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int i=0;//contatore
	int n=0;//variabile che conterrà l'informazione del numero da mettere
	int m=0;//variabile che conterrà l'informazione del numero del buffer
	int end=0;//variabile che serve per far smettetere tutto
	int lati[12]={5,3,4,9,12,1,6,10,8,11,2,7};//array scomposto
	int lati_vero[12]={1,2,3,4,5,6,7,8,9,10,11,12};//array messo bene e come vorremmo averlo
	//identifico lati [0] come zona di buffer
	
	do{
		if(lati[0]==lati_vero[0]){//se nel buffer c'è il suo colore giusto
			for(i=0;i<12;i++){
				if(lati[i]!=lati_vero[i]){//se nella posizione ci sono colori diversi
					n=lati[i];
					m=lati[0];
					lati[i]=m;
					lati[0]=n;//metto in informazione al buffer il colore del luogo dove il colore è sbagliato
					break;//fa smettere il for					
				}
				else if(i!=11 && lati[i]==lati_vero[i]){
					//non fa nulla se non è l'ultimo confronto e se i valori confrontati sono uguali
				}
				else{//se tutti sono giusti 
					end=1;//modifico la variabile end
					break;//faccio smettere il for
				}
				
			}
		}
		if(end!=1){//se l'array non ha finito di essere combinato
			for(i=0;i<12;i++){
			if(lati[0]== lati_vero[i]){
				n=lati[i];
				m=lati[0];
				lati[i]=m;
				lati[0]=n;
			}//funzione che serve per riordinare in base ai voleri dell'array lati_vero quello del lati
			}
		}
	} while(end!=1);
	for(i=0;i<12;i++){
		printf("%d\n", lati[i]);
	}	
	
	return 0;
}
