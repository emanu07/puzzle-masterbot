#include <stdio.h>
#include <stdlib.h>
//questa parte di programma serve per risolvere i lati o pezzi. --> qui mancano le funzioni di parità, vanno aggiunte nel programma che risolve i vertici --> questa parte non è ancora presente nel programma integrale

//printf("");//stampa i movimenti per portare l'obbiettivo
//t_perm();//svolge la t perm
//printf("");//stampa i movimenti per portare l'obbiettivo a posto

int t_perm(){//funzione che stampa le mosse che svolgono la T perm
	printf("3 move to sx\n action 270\n 3 move to sx\n action 270\n move to sx\n action 90\n 3 move to sx\n");//stampa la funzione
	printf("action 90\n move to sx\n action 90\n rotate 90\n move to sx\n action 270\n rotate 90\n");//stampa la funzione
	printf("move to sx\n rotate 90\n move to sx\n action 180\n 3 move to sx\n action 90\n move to sx\n");//stampa la funzione
	printf("action 90\n 3 move to sx\n action 90\n move to sx\n action 270\n 3 move to sx\n action 270\n");//stampa la funzione
	printf("move to sx\n action 90\n rotate 90\n move to sx\n action 90\n rotate 90\n 3 move to sx\n rotate 270\n\n");//stampa la funzione
}
int commutazioni(int d, int i){//funzione per togliere moltre stringhe di codice per capire quale ciclo sta facendo per risolvere il cubo
	if(d==0){//se la posizione scombinata è quella della prima informazione della cella
		switch(i){
			case 0:{//se i è uguale a 0, si avvia la risoluzione per la posizione a
				printf("3 move to sx\n action 180\n rotate 180\n move to sx\n action 90\n move to sx\n action 180\n 3 move to sx\n\n");//stampa i movimenti per portare l'obbiettivo
				t_perm();//svolge la t perm
				printf("rotate to sx\n action 180\n 3 move to sx\n action 270\n 3 move to sx\n rotate 180\n action 180\n rotate to sx\n\n");//stampa i movimenti per portare l'obbiettivo a posto
				break;//esce dallo switch
			}
			case 1:{//se i è uguale a 1 (impossibile ma la mettiamo lo stesso), avvia la risoluzione per la posizione b
				printf("error\n");//stampa errore
				break;//esce dallo switch
			}
			case 2:{//se i è uguale a 2,si avvia la risoluzione per la posizione c
				printf("3 move to sx\n action 180\n rotate 180\n move to sx\n action 270\n move to sx\n action 180\n 3 move to sx\n\n");//stampa i movimenti per portare l'obbiettivo
				t_perm();//svolge la t perm
				printf("move to sx\n action 180\n 3 move to sx\n action 90\n 3 move to sx\n rotate 180\n action 180\n move to sx\n\n");//stampa i movimenti per portare l'obbiettivo a posto
				break;//esce dallo switch
			}
			case 3:{//se i è uguale a 3, si avvia la risoluzione per la posizione d
				t_perm();//svolge la t perm
				break;//esce dallo switch
			}
			case 4:{//se i è uguale a 4, si avvia la risoluzione per la posizione f
				printf("2 move to sx\n action 180\n move to sx\n action 270\n move to sx\n rotate 180\n\n");//stampa i movimenti per portare l'obbiettivo
				t_perm();//svolge la t perm
				printf("rotate 180\n 3 move to sx\n action 90\n 3 move to sx\n action 180\n 2 move to sx\n\n");//stampa i movimenti per portare l'obbiettivo a posto
				break;//esce dallo switch
			}
			case 5:{//se i è uguale a 5, si avvia la risoluzione per la posizione g
				printf("3 move to sx\n action 270\n rotate 90\n move to sx\n action 270\n move to sx\n action 180\n 3 move to sx\n\n");//stampa i movimenti per portare l'obbiettivo
				t_perm();//svolge la t perm
				printf("move to sx\n action 180\n 3 move to sx\n action 90\n 3 move to sx\n rotate 270\n action 90\n move to sx\n\n");//stampa i movimenti per portare l'obbiettivo a posto
				break;//esce dallo switch
			}
			case 6:{//se i è uguale a 6, si avvia la risoluzione per la posizione h
				printf("move to sx\n action 90\n 3 move to sx\n\n");//stampa i movimenti per portare l'obbiettivo
				t_perm();//svolge la t perm
				printf("move to sx\n action 270\n 3 move to sx\n\n");//stampa i movimenti per portare l'obbiettivo a posto
				break;//esce dallo switch
			}
			case 7:{//se i è uguale a 7, si avvia la risoluzione per la posizione j
				printf("2 move to sx\naction 270\n rotate 90\n 3 move to sx\n action 270\n 3 move to sx\n\n");//stampa i movimenti per portare l'obbiettivo
				t_perm();//svolge la t perm
				printf("move to sx\n action 90\n move to sx\n rotate 270\n action 90\n 2 move to sx\n\n");//stampa i movimenti per portare l'obbiettivo a posto
				break;//esce dallo switch
			}
			case 8:{//se i è uguale a 8, si avvia la risoluzione per la posizione k
				printf("action 90\n rotate 90\n move to sx\n action 270\n rotate 90\n 3 move to sx\n action 90\n move to sx\n action 90\n rotate 90\n move to sx\n rotate 90\n\n");//stampa i movimenti per portare l'obbiettivo
				t_perm();//svolge la t perm
				printf("rotate 270\n 3 move to sx\n rotate 270\n action 270\n 3 move to sx\n action 270\n move to sx\n rotate 270\n action 90\n 3 move to sx\n rotate 270\n action 270\n\n");//stampa i movimenti per portare l'obbiettivo a posto
				break;//esce dallo switch
			}
			case 9:{//se i è uguale a 9, si avvia la risoluzione per la posizione n
				printf("move to sx\n action 270\n 3 move to sx\n\n ");//stampa i movimenti per portare l'obbiettivo
				t_perm();//svolge la t perm
				printf("move to sx\n action 90\n 3 move to sx\n\n");//stampa i movimenti per portare l'obbiettivo a posto
				break;//esce dallo switch
			}
			case 10:{//se i è uguale a 10, si avvia la risoluzione per la posizione o
				printf("3 move to sx\n action 90\n rotate 90\n 3 move to sx\n action 90\n 3 move to sx\n action 180\n move to sx\n rotate 180\n\n");//stampa i movimenti per portare l'obbiettivo
				t_perm();//svolge la t perm
				printf("rotate 180\n 3 move to sx\n action 180\n move to sx\n action 270\n move to sx\n rotate 270\n action 270\n move to sx\n\n");//stampa i movimenti per portare l'obbiettivo a posto
				break;//esce dallo switch
			}
			case 11:{//se i è uguale a 11, si avvia la risoluzione per la posizione s
				printf("move to sx\n action 90\n move to sx\n action 90\n rotate 90\n move to sx\n action 270\n move to sx\n rotate 180\n\n");//stampa i movimenti per portare l'obbiettivo
				t_perm();//svolge la t perm
				printf("rotate 180\n 3 move to sx\n action 90\n 3 move to sx\n rotate 270\n action 270\n 3 move to sx\n action 270\n 3 move to sx\n\n");//stampa i movimenti per portare l'obbiettivo a posto
				break;//esce dallo switch
			}
			default: //se in i c'è qualcosa di diverso da questi caratteri
				printf("errore\n");
				break;//esce dallo switch				
		}
	}
	else if(d==1){//se la posizione scombinata è quella dell'ultima informazione della cella
		switch(i){
			case 0:{//se i è uguale a 0, si avvia la risoluzione per la posizione m
				printf("3 move to sx\n action 90\n rotate 90\n 3 move to sx\n action 270\n 3 move to sx\n action 180\n move to sx\n rotate 180\n\n");//stampa i movimenti per portare l'obbiettivo
				t_perm();//svolge la t perm
				printf("rotate 180\n 3 move to sx\n action 180\n move to sx\n action 90\n move to sx\n rotate 270\n action 270\n move to sx\n\n");//stampa i movimenti per portare l'obbiettivo a posto
				break;//esce dallo switch
			}
			case 1:{//se i è uguale a 1 (impossibile ma la mettiamo lo stesso), avvia la risoluzione per la posizione i
				printf("error\n");//stampa il cambiamento fatto per conoscere il ciclo della risoluzione del cubo
				break;//esce dallo switch
			}
			case 2:{//se i è uguale a 2, si avvia la risoluzione per la posizione e
				printf("3 move to sx\n action 270\n rotate 90\n move to sx\n action 90\n move to sx\n action 180\n 3 move to sx\n\n");//stampa i movimenti per portare l'obbiettivo
				t_perm();//svolge la t perm
				printf("move to sx\n action 180\n 3 move to sx\n action 270\n 3 move to sx\n rotate 270\n action 90\n move to sx\n\n");//stampa i movimenti per portare l'obbiettivo a posto
				break;//esce dallo switch
			}
			case 3:{//se i è uguale a 3, si avvia la risoluzione per la posizione q
				printf("move to sx\n action 270\n move to sx\n action 90\n rotate 90\n move to sx\n action 270\n move to sx\n rotate 180\n\n");//stampa i movimenti per portare l'obbiettivo
				t_perm();//svolge la t perm
				printf("rotate 180\n 3 move to sx\n action 90\n 3 move to sx\n rotate 270\n action 270\n 3 move to sx\n action 90\n 3 move to sx\n\n");//stampa i movimenti per portare l'obbiettivo a posto
				break;//esce dallo switch
			}
			case 4:{//se i è uguale a 4, si avvia la risoluzione per la posizione l
				printf("2 move to sx\n action 90\n rotate 90\n move to sx\n action 90\n move to sx\n rotate 180\n\n");//stampa i movimenti per portare l'obbiettivo
				t_perm();//svolge la t perm
				printf("rotate 180\n 3 move to sx\n action 270\n 3 move to sx\n rotate 270\n action 270\n 2 move to sx\n\n");//stampa i movimenti per portare l'obbiettivo a posto
				break;//esce dallo switch
			}
			case 5:{//se i è uguale a 5, si avvia la risoluzione per la soluzione u
				printf("action 90\n move to sx\n action 180\n 3 move to sx\n\n");//stampa i movimenti per portare l'obbiettivo
				t_perm();//svolge la t perm
				printf("move to sx\n action 180\n 3 move to sx\n action 270\n\n");//stampa i movimenti per portare l'obbiettivo a posto
				break;//esce dallo switch
			}
			case 6:{//se i è uguale a 6, si avvia la risoluzione per la soluzione r
				printf("2 move to sx\n action 90\n rotate 90\n move to sx\n action 270\n move to sx\n rotate 180\n\n");//stampa i movimenti per portare l'obbiettivo
				t_perm();//svolge la t perm
				printf("rotate 180\n 3 move to sx\n action 90\n 3 move to sx\n rotate 270\n action 270\n 2 move to sx\n\n");//stampa i movimenti per portare l'obbiettivo a posto
				break;//esce dallo switch
			}
			case 7:{//se i è uguale a 7, si avvia la risoluzione per la soluzione p
				printf("2 move to sx\n action 180\n move to sx\n action 90\n move to sx\n rotate 180\n\n");//stampa i movimenti per portare l'obbiettivo
				t_perm();//svolge la t perm
				printf("rotate 180\n 3 move to sx\n action 270\n 3 move to sx\n action 180\n 2 move to sx\n\n");//stampa i movimenti per portare l'obbiettivo a posto
				break;//esce dallo switch
			}
			case 8:{//se i è uguale a 8, si avvia la risoluzione per la soluzione v
				printf("action 180\n move to sx\n action 180\n 3 move to sx\n\n");//stampa i movimenti per portare l'obbiettivo
				t_perm();//svolge la t perm
				printf("move to sx\n action 180\n 3 move to sx\n action 180\n\n");//stampa i movimenti per portare l'obbiettivo a posto
				break;//esce dallo switch
			}
			case 9:{//se i è uguale a 9, si avvia la risoluzione per la soluzione t
				printf("2 move to sx\n action 270\n rotate 270\n move to sx\n action 90\n move to sx\n rotate 180\n\n");//stampa i movimenti per portare l'obbiettivo
				t_perm();//svolge la t perm
				printf("rotate 180\n 3 move to sx\n action 270\n 3 move to sx\n rotate 90\n action 90\n 2 move to sx\n\n");//stampa i movimenti per portare l'obbiettivo a posto
				break;//esce dallo switch
			}
			case 10:{//se i è uguale a 10, si avvia la risoluzione per la soluzione x
				printf("action 270\n move to sx\n action 180\n 3 move to sx\n\n");//stampa i movimenti per portare l'obbiettivo
				t_perm();//svolge la t perm
				printf("move to sx\n action 180\n 3 move to sx\n action 90\n\n");//stampa i movimenti per portare l'obbiettivo a posto
				break;//esce dallo switch
			}
			case 11:{//se i è uguale a 11, si avvia la risoluzione per la soluzione z
				printf("move to sx\n action 180\n 3 move to sx\n\n");//stampa i movimenti per portare l'obbiettivo
				t_perm();//svolge la t perm
				printf("move to sx\n action 180\n 3 move to sx\n\n");//stampa i movimenti per portare l'obbiettivo a posto
				break;//esce dallo switch
			}
			default: //se in i c'è qualcosa di diverso da questi caratteri
				printf("errore\n");
				break;//esce dallo switch				
		}
	}
	else{//se non dovesse funzionare nessuno dei due pezzi 
		printf("Error\n");
	}
	return 0;	
}

int main(int argc, char *argv[]) {

	int d=0;//contatore
	int i=0;//contatore
	int n=0;//variabile che conterrà l'informazione del numero da mettere
	int m=0;//variabile che conterrà l'informazione del numero del buffer
	int end=0;//variabile che serve per far smettetere tutto se impostata a 1
	int end_int=0;//variabile che serve per fare smettere i for (per i problema dei due for per array bidimensionali)
	int lati[12][2]={{2,1}, {6,4}, {6,5}, {5,2}, {3,1}, {2,6}, {5,4}, {1,5}, {4,1}, {3,6}, {4,3}, {2,3}};//array scomposto bidimensionale
	int lati_vero[12][2]={{1,4}, {1,3}, {1,2}, {1,5}, {2,3}, {2,6}, {2,5}, {3,4}, {3,6}, {4,5}, {4,6}, {5,6}};//array messo bene e come vorremmo averlo (prendo quello del programma "ordinare pezzi")
	//identifico lati [1][0] e [1][1] come zona di buffer, quando in realtà sarà la zona b;i
	
	do{
		if(lati[1][0]==lati_vero[1][0] && lati[1][1]==lati_vero[1][1]){//se nel buffer c'è il suo colore giusto e messo bene
			for(i=0;i<12;i++){
				for (d=0; d<2; d++){
					if(lati[i][d]!=lati_vero[i][d]){//se nella posizione ci sono colori diversi-> cubo non risolto
						n=lati[i][0];//associo ad n l'informazione del primo pezzo non messo correttamente 
						m=lati[1][0];//associo ad m l'informazione del primo pezzo nel buffer
						lati[i][0]=m;//nel luogo dove c'era il pezzo che non andava bene metto la prima informazione del buffer
						lati[1][0]=n;//metto in informazione al buffer il primo colore del luogo dove il colore è sbagliato
						n=lati[i][1];//associo ad n l'informazione dell'ultimo pezzo non messo correttamente 
						m=lati[1][1];//associo ad m l'informazione dell'ultimo pezzo nel buffer
						lati[i][1]=m;//nel luogo dove c'era il pezzo che non andava bene metto l'ultima informazione del buffer
						lati[1][1]=n;//metto in informazione al buffer l'ultimo colore del luogo dove il colore è sbagliato
						commutazioni(d,i);//avvia la funzione "commutazioni"		
						end_int=1;//imposto la variabile a 1 per far si che quando usirà dal primo for sarà costretto ad andare nell'altro e chiudere anch'esso
						break;//esco dal for							
					}
					else if(i!=11 && lati[i][d]==lati_vero[i][d]){
						//non fa nulla se non è l'ultimo confronto e se i valori confrontati sono uguali
					}
					else if (i==11 && d==1) {//se tutti sono giusti 
						end=1;//modifico la variabile end
						end_int=1;//imposto la variabile a 1 per far si che quando usirà dal primo for sarà costretto ad andare nell'altro e chiudere anch'esso
						break;//faccio smettere il for
					}
			
				}
				if (end_int==1){//se la variabile per far chiudere tutti i for è stata attivata
					end_int=0;//ristabilizzo la variabile per poterla riutilizzare
					break;//faccio smettere anche questo for
				}
					
			}
		}
		else if(lati[1][0]==lati_vero[1][1] && lati[1][1]==lati_vero[1][0]){//se nel buffer ci sono i colori giusti ma sono messi male
			for(i=0;i<12;i++){
				for (d=0; d<2; d++){
					if (i==1){//se i è in zona buffer 
						//non fa nulla, perchè sennò scambierebbe in loop la posizione di buffer messa male
					}
					else if(lati[i][d]!=lati_vero[i][d]){//se nella posizione ci sono colori diversi-> cubo non risolto (devo controllare questo if perchè non sono convinto di come funzioni)
						m=lati[1][0];//associo ad m l'informazione del primo luogo del buffer
						n=lati[1][1];//associo ad m l'informazione dell'ultimo luogo del buffer
						lati[1][0]=n;//scambio l'informazione
						lati[1][1]=m;//scambio l'informazione
						m=lati[i][0];//associo ad m l'informazione del primo luogo della zona da permutare
						n=lati[i][1];//associo ad m l'informazione dell'ultimo luogo della zona da permutare
						lati[i][0]=n;//scambio l'informazione
						lati[i][1]=m;//scambio l'informazione
						n=lati[i][0];//associo ad n l'informazione del luogo dove andrà messa l'informazione del buffer
						m=lati[1][0];//associo ad m l'informazione del buffer
						lati[i][0]=m;//metto l'informazione nel buffer nel giusto luogo
						lati[1][0]=n;//aggiorno il buffer
						n=lati[i][1];//associo ad n l'informazione del luogo dove andrà messa l'informazione del buffer
						m=lati[1][1];//associo ad m l'informazione del buffer
						lati[i][1]=m;//metto l'informazione nel buffer nel giusto luogo
						lati[1][1]=n;//aggiorno il buffer
						d=1;
						commutazioni(d,i);//avvia la funzione "commutazioni"
						end_int=1;//imposto la variabile a 1 per far si che quando usirà dal primo for sarà costretto ad andare nell'altro e chiudere anch'esso
						break;//esco dal for							
					}
					else if(i!=11 && lati[i][d]==lati_vero[i][d]){
						//non fa nulla se non è l'ultimo confronto e se i valori confrontati sono uguali
					}
					else if (i==11 && d==1 && lati[i][d]==lati_vero[i][d]) {//se tutti sono giusti 
						end=1;//modifico la variabile end
						end_int=1;//imposto la variabile a 1 per far si che quando usirà dal primo for sarà costretto ad andare nell'altro e chiudere anch'esso
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
				if(lati[1][0]== lati_vero[i][0] && lati[1][1]==lati_vero[i][1]){//se la zona di buffer ha la stessa informazione della zona confrontata
					n=lati[i][0];//associo ad n l'informazione del luogo dove andrà messa l'informazione del buffer
					m=lati[1][0];//associo ad m l'informazione del buffer
					lati[i][0]=m;//metto l'informazione nel buffer nel giusto luogo
					lati[1][0]=n;//aggiorno il buffer
					n=lati[i][1];//associo ad n l'informazione del luogo dove andrà messa l'informazione del buffer
					m=lati[1][1];//associo ad m l'informazione del buffer
					lati[i][1]=m;//metto l'informazione nel buffer nel giusto luogo
					lati[1][1]=n;//aggiorno il buffer
					d=0;
					commutazioni(d,i);//avvia la funzione "commutazioni"
					break;//esce dal for
				}//funzione che serve per riordinare in base ai voleri dell'array lati_vero quello del lati
				
				//funzione che dovrebbe essere giusta e da copiare per tutte le parti con sfasamenti
				else if(lati[1][0]== lati_vero[i][1] && lati[1][1]==lati_vero[i][0]){//se la zona di buffer ha la stessa informazione della zona confrontata ma sfasata
					m=lati[1][0];//associo ad m l'informazione del primo luogo del buffer
					n=lati[1][1];//associo ad m l'informazione dell'ultimo luogo del buffer
					lati[1][0]=n;//scambio l'informazione
					lati[1][1]=m;//scambio l'informazione
					m=lati[i][0];//associo ad m l'informazione del primo luogo della zona da permutare
					n=lati[i][1];//associo ad m l'informazione dell'ultimo luogo della zona da permutare
					lati[i][0]=n;//scambio l'informazione
					lati[i][1]=m;//scambio l'informazione
					n=lati[i][0];//associo ad n l'informazione del luogo dove andrà messa l'informazione del buffer
					m=lati[1][0];//associo ad m l'informazione del buffer
					lati[i][0]=m;//metto l'informazione nel buffer nel giusto luogo
					lati[1][0]=n;//aggiorno il buffer
					n=lati[i][1];//associo ad n l'informazione del luogo dove andrà messa l'informazione del buffer
					m=lati[1][1];//associo ad m l'informazione del buffer
					lati[i][1]=m;//metto l'informazione nel buffer nel giusto luogo
					lati[1][1]=n;//aggiorno il buffer
					d=1;
					commutazioni(d,i);//avvia la funzione "commutazioni"
					break;//esce dal for
				}//funzione che serve per riordinare in base ai voleri dell'array lati_vero quello del lati	
			}
		}
	} while(end!=1);
/*	printf("\n");
	for(i=0;i<12;i++){
		for(d=0; d<2; d++){
			printf("%d ", lati[i][d]);
		}
		printf("\n");		
	}*/	
		
	
	return 0;
}
