#include <stdio.h>
#include <stdlib.h>

/* Questa parte di programma serve a risolvere i vertici e le paritÃ , se esistenti. Deve ancora essere finito. AndrÃ  messo prima del programma "sequenza combinazione pezzi" */

int main(int argc, char *argv[]) {
	int vertici_vero[8][3]={{1,4,5}, {1,4,3}, {1,3,2}, {1,2,5}, {4,5,6}, {3,4,6}, {2,3,6}, {2,5,6}};//array che contiene le informazioni dei vertici giusti
	int vertici[8][3]={{6,2,3}, {4,1,5}, {5,2,6}, {1,3,2}, {1,4,3}, {6,4,5}, {6,3,4}, {5,2,1}};		//array che contiene gli insiemi delle informazioni degli array dei singoli vertici scombinati
	int end=0;																						//variabile che mi farÃ  uscire dal ciclo piÃ¹ grande
	int end_int=0;																					//variabile che mi farÃ  uscire dal ciclo piÃ¹ interno
	int d=0;																						//contatore
	int i=0;																						//contatore
	int n=0;																						//variabile che conterrÃƒ  l'informazione del numero da mettere
	int m=0;																						//variabile che conterrÃƒ  l'informazione del numero del buffer
		//identifico vertici[0][0], [0][1] e [0][2] come zona di buffer, quando in realtÃ   sarÃ   la zona a;n;q
	
	do{
		if (vertici_vero[0][0]==vertici[0][0] && vertici_vero[0][1]==vertici[0][1] && vertici_vero[0][2]==vertici[0][2]){	//se nel buffer ci sono i colori giusti e messi bene
			for (i=0;i<8;i++){
				for (d=0;d<3;d++){
					if (vertici_vero[i][d]!= vertici[i][d]){	//se nella posizione analizzata ci sono colori diversi -> cubo non risolto (molto probabilmente bisogna mettere anche qui il pezzo di codice di commutazione come nel cubo risolto ma messo male
						if(d==0){//se il primo pezzo osservato è quello messo male e si avvierà, di conseguenza, la commutazione ordinata da d, scambierò le informazioni in questo modo
							n=vertici[i][0];//associo ad n l'informazione del primo colore del vertice non messo correttamente, unico colore che so per certezza come deve essere perchè è quello che mi servirà per le commutazioni successive
							m=vertici[0][0];//associo ad m l'informazione del primo pezzo nel buffer
							vertici[0][0]=n;//metto in informazione al buffer il primo colore del luogo dove il colore Ã¨ sbagliato
							vertici[i][0]=m;//nel luogo dove c'era il pezzo che non andava bene metto la prima informazione del buffer
							n=vertici[i][1];//associo ad n l'informazione del secondo colore del vertice non messo correttamente
							m=vertici[0][1];//associo ad m l'informazione del secondo pezzo nel buffer
							vertici[0][1]=n;//metto in informazione al buffer il secondo colore del luogo dove il colore Ã¨ sbagliato
							vertici[i][1]=m;//nel luogo dove c'era il pezzo che non andava bene metto la seconda informazione del buffer
							n=vertici[i][2];//associo ad n l'informazione dell'ultimo colore del vertice non messo correttamente
							m=vertici[0][2];//associo ad m l'informazione dell'ultimo pezzo nel buffer
							vertici[0][2]=n;//metto in informazione al buffer l'ultimo colore del luogo dove il colore Ã¨ sbagliato
							vertici[i][2]=m;//nel luogo dove c'era il pezzo che non andava bene metto l'ultima informazione del buffer
										//vanno aggiunte le sequenze di commutazioni che deve stampare i passaggi da fare
							end_int=1;		//imposto la variabile a 1 per far si che quando usirà  dal primo for sarà  costretto ad andare nell'altro e chiudere anch'esso
							break;			//esco dal for
						}
						
						else if(d==1){//se il secondo pezzo osservato è quello messo male e si avvierà, di conseguenza, la commutazione ordinata da d, scambierò le informazioni in questo modo
							n=vertici[i][1];//associo ad n l'informazione del secondo colore del vertice non messo correttamente, unico colore che so per certezza come deve essere perchè è quello che mi servirà per le commutazioni successive
							m=vertici[0][0];//associo ad m l'informazione del primo pezzo nel buffer
							vertici[0][0]=n;//metto in informazione al buffer il primo colore del luogo dove il colore Ã¨ sbagliato
							vertici[i][1]=m;//nel luogo dove c'era il pezzo che non andava bene metto la prima informazione del buffer
							n=vertici[i][2];//associo ad n l'informazione del secondo colore del vertice non messo correttamente
							m=vertici[0][1];//associo ad m l'informazione del secondo pezzo nel buffer
							vertici[0][1]=n;//metto in informazione al buffer il secondo colore del luogo dove il colore Ã¨ sbagliato
							vertici[i][2]=m;//nel luogo dove c'era il pezzo che non andava bene metto la seconda informazione del buffer
							n=vertici[i][0];//associo ad n l'informazione dell'ultimo colore del vertice non messo correttamente
							m=vertici[0][2];//associo ad m l'informazione dell'ultimo pezzo nel buffer
							vertici[0][2]=n;//metto in informazione al buffer l'ultimo colore del luogo dove il colore Ã¨ sbagliato
							vertici[i][0]=m;//nel luogo dove c'era il pezzo che non andava bene metto l'ultima informazione del buffer
										//vanno aggiunte le sequenze di commutazioni che deve stampare i passaggi da fare
							end_int=1;		//imposto la variabile a 1 per far si che quando usirà  dal primo for sarà  costretto ad andare nell'altro e chiudere anch'esso
							break;			//esco dal for
						}
						
						else if(d==2){//se l'ultimo pezzo osservato è quello messo male e si avvierà, di conseguenza, la commutazione ordinata da d, scambierò le informazioni in questo modo
							n=vertici[i][2];//associo ad n l'informazione dell'ultimo colore del vertice non messo correttamente, unico colore che so per certezza come deve essere perchè è quello che mi servirà per le commutazioni successive
							m=vertici[0][0];//associo ad m l'informazione del primo pezzo nel buffer
							vertici[0][0]=n;//metto in informazione al buffer il primo colore del luogo dove il colore Ã¨ sbagliato
							vertici[i][2]=m;//nel luogo dove c'era il pezzo che non andava bene metto la prima informazione del buffer
							n=vertici[i][0];//associo ad n l'informazione del secondo colore del vertice non messo correttamente
							m=vertici[0][1];//associo ad m l'informazione del secondo pezzo nel buffer
							vertici[0][1]=n;//metto in informazione al buffer il secondo colore del luogo dove il colore Ã¨ sbagliato
							vertici[i][0]=m;//nel luogo dove c'era il pezzo che non andava bene metto la seconda informazione del buffer
							n=vertici[i][1];//associo ad n l'informazione dell'ultimo colore del vertice non messo correttamente
							m=vertici[0][2];//associo ad m l'informazione dell'ultimo pezzo nel buffer
							vertici[0][2]=n;//metto in informazione al buffer l'ultimo colore del luogo dove il colore Ã¨ sbagliato
							vertici[i][1]=m;//nel luogo dove c'era il pezzo che non andava bene metto l'ultima informazione del buffer
										//vanno aggiunte le sequenze di commutazioni che deve stampare i passaggi da fare
							end_int=1;		//imposto la variabile a 1 per far si che quando usirà  dal primo for sarà  costretto ad andare nell'altro e chiudere anch'esso
							break;			//esco dal for
						}		
						
					}
					else if(i!=7 && vertici[i][d]==vertici_vero[i][d]){
						//non fa nulla se non è l'ultimo confronto e se i valori confrontati sono uguali
					}
					else if (i==7 && d==2) {//se tutti sono giusti 
						end=1;				//modifico la variabile end
						end_int=1;			//imposto la variabile a 1 per far si che quando usirÃƒÂ  dal primo for sarÃƒÂ  costretto ad andare nell'altro e chiudere anch'esso
						break;				//faccio smettere il for
					}
				}
				if (end_int==1){			//se la variabile per far chiudere tutti i for ÃƒÂ¨ stata attivata
					end_int=0;				//ristabilizzo la variabile per poterla riutilizzare
					break;					//faccio smettere anche questo for
				}
			}
		}
		
		else if (vertici_vero[0][0]==vertici[0][1] && vertici_vero[0][1]==vertici[0][2] && vertici_vero[0][2]==vertici[0][0]){//se nel buffer ci sono i colori giusti ma ruotati male (rotazione vertice buffer di 120 gradi antiorari)
		
			for (i=0;i<8;i++){
				for(d=0;d<3;d++){
					if (i==0){//se i è in zona buffer 
						//non fa nulla, perchè sennò scambierebbe in loop la posizione di buffer messa male
					}
					else if(vertici[i][d]!=vertici_vero[i][d]){//se nella posizione ci sono colori diversi-> cubo non risolto (devo controllare questo if perchÃƒÂ¨ non sono convinto di come funzioni)
						if(d==0){//se il primo pezzo osservato è quello messo male e si avvierà, di conseguenza, la commutazione ordinata da d, scambierò le informazioni in questo modo
							n=vertici[i][0];//associo ad n l'informazione del primo colore del vertice non messo correttamente, unico colore che so per certezza come deve essere perchè è quello che mi servirà per le commutazioni successive
							m=vertici[0][0];//associo ad m l'informazione del primo pezzo nel buffer
							vertici[0][0]=n;//metto in informazione al buffer il primo colore del luogo dove il colore Ã¨ sbagliato
							vertici[i][0]=m;//nel luogo dove c'era il pezzo che non andava bene metto la prima informazione del buffer
							n=vertici[i][1];//associo ad n l'informazione del secondo colore del vertice non messo correttamente
							m=vertici[0][1];//associo ad m l'informazione del secondo pezzo nel buffer
							vertici[0][1]=n;//metto in informazione al buffer il secondo colore del luogo dove il colore Ã¨ sbagliato
							vertici[i][1]=m;//nel luogo dove c'era il pezzo che non andava bene metto la seconda informazione del buffer
							n=vertici[i][2];//associo ad n l'informazione dell'ultimo colore del vertice non messo correttamente
							m=vertici[0][2];//associo ad m l'informazione dell'ultimo pezzo nel buffer
							vertici[0][2]=n;//metto in informazione al buffer l'ultimo colore del luogo dove il colore Ã¨ sbagliato
							vertici[i][2]=m;//nel luogo dove c'era il pezzo che non andava bene metto l'ultima informazione del buffer
										//vanno aggiunte le sequenze di commutazioni che deve stampare i passaggi da fare
							end_int=1;		//imposto la variabile a 1 per far si che quando usirà  dal primo for sarà  costretto ad andare nell'altro e chiudere anch'esso
							break;			//esco dal for
						}
						
						else if(d==1){//se il secondo pezzo osservato è quello messo male e si avvierà, di conseguenza, la commutazione ordinata da d, scambierò le informazioni in questo modo
							n=vertici[i][1];//associo ad n l'informazione del secondo colore del vertice non messo correttamente, unico colore che so per certezza come deve essere perchè è quello che mi servirà per le commutazioni successive
							m=vertici[0][0];//associo ad m l'informazione del primo pezzo nel buffer
							vertici[0][0]=n;//metto in informazione al buffer il primo colore del luogo dove il colore Ã¨ sbagliato
							vertici[i][1]=m;//nel luogo dove c'era il pezzo che non andava bene metto la prima informazione del buffer
							n=vertici[i][2];//associo ad n l'informazione del secondo colore del vertice non messo correttamente
							m=vertici[0][1];//associo ad m l'informazione del secondo pezzo nel buffer
							vertici[0][1]=n;//metto in informazione al buffer il secondo colore del luogo dove il colore Ã¨ sbagliato
							vertici[i][2]=m;//nel luogo dove c'era il pezzo che non andava bene metto la seconda informazione del buffer
							n=vertici[i][0];//associo ad n l'informazione dell'ultimo colore del vertice non messo correttamente
							m=vertici[0][2];//associo ad m l'informazione dell'ultimo pezzo nel buffer
							vertici[0][2]=n;//metto in informazione al buffer l'ultimo colore del luogo dove il colore Ã¨ sbagliato
							vertici[i][0]=m;//nel luogo dove c'era il pezzo che non andava bene metto l'ultima informazione del buffer
										//vanno aggiunte le sequenze di commutazioni che deve stampare i passaggi da fare
							end_int=1;		//imposto la variabile a 1 per far si che quando usirà  dal primo for sarà  costretto ad andare nell'altro e chiudere anch'esso
							break;			//esco dal for
						}
						
						else if(d==2){//se l'ultimo pezzo osservato è quello messo male e si avvierà, di conseguenza, la commutazione ordinata da d, scambierò le informazioni in questo modo
							n=vertici[i][2];//associo ad n l'informazione dell'ultimo colore del vertice non messo correttamente, unico colore che so per certezza come deve essere perchè è quello che mi servirà per le commutazioni successive
							m=vertici[0][0];//associo ad m l'informazione del primo pezzo nel buffer
							vertici[0][0]=n;//metto in informazione al buffer il primo colore del luogo dove il colore Ã¨ sbagliato
							vertici[i][2]=m;//nel luogo dove c'era il pezzo che non andava bene metto la prima informazione del buffer
							n=vertici[i][0];//associo ad n l'informazione del secondo colore del vertice non messo correttamente
							m=vertici[0][1];//associo ad m l'informazione del secondo pezzo nel buffer
							vertici[0][1]=n;//metto in informazione al buffer il secondo colore del luogo dove il colore Ã¨ sbagliato
							vertici[i][0]=m;//nel luogo dove c'era il pezzo che non andava bene metto la seconda informazione del buffer
							n=vertici[i][1];//associo ad n l'informazione dell'ultimo colore del vertice non messo correttamente
							m=vertici[0][2];//associo ad m l'informazione dell'ultimo pezzo nel buffer
							vertici[0][2]=n;//metto in informazione al buffer l'ultimo colore del luogo dove il colore Ã¨ sbagliato
							vertici[i][1]=m;//nel luogo dove c'era il pezzo che non andava bene metto l'ultima informazione del buffer
										//vanno aggiunte le sequenze di commutazioni che deve stampare i passaggi da fare
							end_int=1;		//imposto la variabile a 1 per far si che quando usirà  dal primo for sarà  costretto ad andare nell'altro e chiudere anch'esso
							break;			//esco dal for
						}
							
					}
					else if(vertici[i][d]==vertici_vero[i][d]){//se nella posizione analizzata il pezzo è giusto
					//non faccio nulla e continuo con l'analisi
					} 
				}
				if (end_int==1){			//se la variabile per far chiudere tutti i for è stata attivata
					end_int=0;				//ristabilizzo la variabile per poterla riutilizzare
					break;					//faccio smettere anche questo for
				}
			}
			
		}
		
		else if (vertici_vero[0][0]==vertici[0][2] && vertici_vero[0][1]==vertici[0][0] && vertici_vero[0][2]==vertici[0][1]){//se nel buffer ci sono i colori giusti ma ruotati male (rotazione vertice buffer di 120 gradi orari)
			for (i=0;i<8;i++){
				for(d=0;d<3;d++){
					if (i==0){//se i è in zona buffer 
						//non fa nulla, perchè sennò scambierebbe in loop la posizione di buffer messa male
					}
					else if(vertici[i][d]!=vertici_vero[i][d]){//se nella posizione ci sono colori diversi-> cubo non risolto (devo controllare questo if perchÃƒÂ¨ non sono convinto di come funzioni)
						if(d==0){//se il primo pezzo osservato è quello messo male e si avvierà, di conseguenza, la commutazione ordinata da d, scambierò le informazioni in questo modo
							n=vertici[i][0];//associo ad n l'informazione del primo colore del vertice non messo correttamente, unico colore che so per certezza come deve essere perchè è quello che mi servirà per le commutazioni successive
							m=vertici[0][0];//associo ad m l'informazione del primo pezzo nel buffer
							vertici[0][0]=n;//metto in informazione al buffer il primo colore del luogo dove il colore Ã¨ sbagliato
							vertici[i][0]=m;//nel luogo dove c'era il pezzo che non andava bene metto la prima informazione del buffer
							n=vertici[i][1];//associo ad n l'informazione del secondo colore del vertice non messo correttamente
							m=vertici[0][1];//associo ad m l'informazione del secondo pezzo nel buffer
							vertici[0][1]=n;//metto in informazione al buffer il secondo colore del luogo dove il colore Ã¨ sbagliato
							vertici[i][1]=m;//nel luogo dove c'era il pezzo che non andava bene metto la seconda informazione del buffer
							n=vertici[i][2];//associo ad n l'informazione dell'ultimo colore del vertice non messo correttamente
							m=vertici[0][2];//associo ad m l'informazione dell'ultimo pezzo nel buffer
							vertici[0][2]=n;//metto in informazione al buffer l'ultimo colore del luogo dove il colore Ã¨ sbagliato
							vertici[i][2]=m;//nel luogo dove c'era il pezzo che non andava bene metto l'ultima informazione del buffer
										//vanno aggiunte le sequenze di commutazioni che deve stampare i passaggi da fare
							end_int=1;		//imposto la variabile a 1 per far si che quando usirà  dal primo for sarà  costretto ad andare nell'altro e chiudere anch'esso
							break;			//esco dal for
						}
						
						else if(d==1){//se il secondo pezzo osservato è quello messo male e si avvierà, di conseguenza, la commutazione ordinata da d, scambierò le informazioni in questo modo
							n=vertici[i][1];//associo ad n l'informazione del secondo colore del vertice non messo correttamente, unico colore che so per certezza come deve essere perchè è quello che mi servirà per le commutazioni successive
							m=vertici[0][0];//associo ad m l'informazione del primo pezzo nel buffer
							vertici[0][0]=n;//metto in informazione al buffer il primo colore del luogo dove il colore Ã¨ sbagliato
							vertici[i][1]=m;//nel luogo dove c'era il pezzo che non andava bene metto la prima informazione del buffer
							n=vertici[i][2];//associo ad n l'informazione del secondo colore del vertice non messo correttamente
							m=vertici[0][1];//associo ad m l'informazione del secondo pezzo nel buffer
							vertici[0][1]=n;//metto in informazione al buffer il secondo colore del luogo dove il colore Ã¨ sbagliato
							vertici[i][2]=m;//nel luogo dove c'era il pezzo che non andava bene metto la seconda informazione del buffer
							n=vertici[i][0];//associo ad n l'informazione dell'ultimo colore del vertice non messo correttamente
							m=vertici[0][2];//associo ad m l'informazione dell'ultimo pezzo nel buffer
							vertici[0][2]=n;//metto in informazione al buffer l'ultimo colore del luogo dove il colore Ã¨ sbagliato
							vertici[i][0]=m;//nel luogo dove c'era il pezzo che non andava bene metto l'ultima informazione del buffer
										//vanno aggiunte le sequenze di commutazioni che deve stampare i passaggi da fare
							end_int=1;		//imposto la variabile a 1 per far si che quando usirà  dal primo for sarà  costretto ad andare nell'altro e chiudere anch'esso
							break;			//esco dal for
						}
						
						else if(d==2){//se l'ultimo pezzo osservato è quello messo male e si avvierà, di conseguenza, la commutazione ordinata da d, scambierò le informazioni in questo modo
							n=vertici[i][2];//associo ad n l'informazione dell'ultimo colore del vertice non messo correttamente, unico colore che so per certezza come deve essere perchè è quello che mi servirà per le commutazioni successive
							m=vertici[0][0];//associo ad m l'informazione del primo pezzo nel buffer
							vertici[0][0]=n;//metto in informazione al buffer il primo colore del luogo dove il colore Ã¨ sbagliato
							vertici[i][2]=m;//nel luogo dove c'era il pezzo che non andava bene metto la prima informazione del buffer
							n=vertici[i][0];//associo ad n l'informazione del secondo colore del vertice non messo correttamente
							m=vertici[0][1];//associo ad m l'informazione del secondo pezzo nel buffer
							vertici[0][1]=n;//metto in informazione al buffer il secondo colore del luogo dove il colore Ã¨ sbagliato
							vertici[i][0]=m;//nel luogo dove c'era il pezzo che non andava bene metto la seconda informazione del buffer
							n=vertici[i][1];//associo ad n l'informazione dell'ultimo colore del vertice non messo correttamente
							m=vertici[0][2];//associo ad m l'informazione dell'ultimo pezzo nel buffer
							vertici[0][2]=n;//metto in informazione al buffer l'ultimo colore del luogo dove il colore Ã¨ sbagliato
							vertici[i][1]=m;//nel luogo dove c'era il pezzo che non andava bene metto l'ultima informazione del buffer
										//vanno aggiunte le sequenze di commutazioni che deve stampare i passaggi da fare
							end_int=1;		//imposto la variabile a 1 per far si che quando usirà  dal primo for sarà  costretto ad andare nell'altro e chiudere anch'esso
							break;			//esco dal for
						}
							
					}
					else if(vertici[i][d]==vertici_vero[i][d]){//se nella posizione analizzata il pezzo è giusto
					//non faccio nulla e continuo con l'analisi
					} 
				}
				if (end_int==1){			//se la variabile per far chiudere tutti i for è stata attivata
					end_int=0;				//ristabilizzo la variabile per poterla riutilizzare
					break;					//faccio smettere anche questo for
				}
			}
			
		}
		else{//se nel buffer ci sono colori completamente sbagliati
			q
			//ARRIVATO FINO A QUI!!!!
		}
		
	}while();//da aggiungere le condizioni di chiusura ciclo
/*
	int end=0;												//variabile che mi farÃ  uscire dal ciclo piÃ¹ grande
	int m=0;												//variabile di salvataggio
	int d=0;												//variabile di salvataggio
	int i=0;												//contatore
	int array[8]={{6}, {1}, {4}, {2}, {7}, {8}, {3}, {5}};	//array che contiene l'informazioni del cubo scombinato
	int avero[8]={{7}, {4}, {3}, {2}, {6}, {5}, {1}, {8}};	//array che contiene l'informazione del cubo risolto
	do{
		if (array[0]==avero[0]){								//se il pezzo nel buffer Ã¨ messo correttamente
			for(i=0;i<8;i++){
				if(array[i]==avero[i]){							//se la posizione Ã¨ uguale a quella definitiva
					if(i==7){									//se ha controllato tutte le posizioni e sono ok
						end=1;									//imposto la variabile che mi farÃ  uscire dal ciclo Ã¨ piÃ¹ grande
						break;									//esco dal for
					}
				}
				else if(array[i]!=avero[i]){					//se la posizione non Ã¨ uguale a quella definitiva
					printf("%d\n", i);							//stampo il cambiamento che ho fatto
					d=array[i];									//salvo l'informazione del luogo da permutare in una variabile			
					array[i]=array[0];							//metto nel luogo da permutare il pezzo giusto
					array[0]=d;									//salvo nel buffer l'informazione del pezzo permutato
					break;										//esce dal for
				}
			}
		}
		else if(array[0]!=avero[0]){							//se il pezzo nel buffer non Ã¨ messo bene
			for(i=0;i<8;i++){									//controllo la posizione in cui dovrebbe essere messo
				if(array[0]==avero[i]){							//se l'informazione contenuta nel buffer Ã¨ uguale a quella della posizione analizzata
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
	*/
	return 0;
}
