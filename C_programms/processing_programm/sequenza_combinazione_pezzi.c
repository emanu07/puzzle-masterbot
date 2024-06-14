#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int i=0;//contatore
	int n=0;//variabile che conterrà l'informazione del numero da mettere
	int m=0;//variabile che conterrà l'informazione del numero del buffer
	int end=0;//variabile che serve per far smettetere tutto se impostata a 1
	int lati[12]={5,3,4,9,12,1,6,10,8,11,2,7};//array scomposto
	int lati_vero[12]={1,2,3,4,5,6,7,8,9,10,11,12};//array messo bene e come vorremmo averlo
	//identifico lati [0] come zona di buffer, quando in realtà sarà la zona b;i
	
	do{
		if(lati[0]==lati_vero[0]){//se nel buffer c'è il suo colore giusto
			for(i=0;i<12;i++){
				if(lati[i]!=lati_vero[i]){//se nella posizione ci sono colori diversi-> cubo non risolto
					n=lati[i];//associo ad n l'informazione del pezzo non messo correttamente 
					m=lati[0];//associo ad m l'informazione del pezzo nel buffer
					lati[i]=m;//nel luogo dove c'era il pezzo che non andava bene metto l'inforzaione del buffer
					lati[0]=n;//metto in informazione al buffer il colore del luogo dove il colore è sbagliato
					i=i+1;//mi serve per capire in quale posizione c'è linformazione non corretta
					printf("%d\n", i);//stampo il cambiamento fatto per conoscere il ciclo della risoluzione del cubo
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
			if(lati[0]== lati_vero[i]){//se la zona di buffer ha la stessa informazione della zona confrontata
				n=lati[i];//associo ad n l'informazione del luogo dove andrà messa l'informazione del buffer
				m=lati[0];//associo ad m l'informazione del buffer
				lati[i]=m;//metto l'informazione nel buffer nel giusto luogo
				lati[0]=n;//aggiorno il buffer
				printf("%d\n", m);//stampo il cambiamento fatto per conoscere il ciclo della risoluzione del cubo
			}//funzione che serve per riordinare in base ai voleri dell'array lati_vero quello del lati
			}
		}
	} while(end!=1);
	printf("\n");
	for(i=0;i<12;i++){
		printf("%d\n", lati[i]);
	}	
	
	return 0;
}
