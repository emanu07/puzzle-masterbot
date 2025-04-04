#include <stdio.h>
#include <stdlib.h>

/* Questa parte di programma serve a risolvere i vertici e le parità, se esistenti. Deve ancora essere finito. Andrà messo prima del programma "sequenza combinazione pezzi" */

int main(int argc, char *argv[]) {
	int end=0;												//variabile che mi farà uscire dal ciclo più grande
	int m=0;												//variabile di salvataggio
	int d=0;												//variabile di salvataggio
	int i=0;												//contatore
	int array[8]={{6}, {1}, {4}, {2}, {7}, {8}, {3}, {5}};	//array che contiene l'informazioni del cubo scombinato
	int avero[8]={{7}, {4}, {3}, {2}, {6}, {5}, {1}, {8}};	//array che contiene l'informazione del cubo risolto
	do{
		if (array[0]==avero[0]){								//se il pezzo nel buffer è messo correttamente
			for(i=0;i<8;i++){
				if(array[i]==avero[i]){							//se la posizione è uguale a quella definitiva
					if(i==7){									//se ha controllato tutte le posizioni e sono ok
						end=1;									//imposto la variabile che mi farà uscire dal ciclo è più grande
						break;									//esco dal for
					}
				}
				else if(array[i]!=avero[i]){					//se la posizione non è uguale a quella definitiva
					printf("%d\n", i);							//stampo il cambiamento che ho fatto
					d=array[i];									//salvo l'informazione del luogo da permutare in una variabile			
					array[i]=array[0];							//metto nel luogo da permutare il pezzo giusto
					array[0]=d;									//salvo nel buffer l'informazione del pezzo permutato
					break;										//esce dal for
				}
			}
		}
		else if(array[0]!=avero[0]){							//se il pezzo nel buffer non è messo bene
			for(i=0;i<8;i++){									//controllo la posizione in cui dovrebbe essere messo
				if(array[0]==avero[i]){							//se l'informazione contenuta nel buffer è uguale a quella della posizione analizzata
					printf("%d\n", i);							//stampo il cambiamento che ho fatto
					d=array[i];									//salvo l'informazione del luogo da permutare in una variabile			
					array[i]=array[0];							//metto nel luogo da permutare il pezzo giusto
					array[0]=d;									//salvo nel buffer l'informazione del pezzo permutato
					break;										//esce dal for
				}
				else{
				}
			}	
		}
	}while(end!=1);
	
	return 0;
}
