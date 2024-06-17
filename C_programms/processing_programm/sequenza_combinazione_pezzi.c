#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	/*int i=0;//contatore
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
	}*/
	
	
	int d=0;//contatore
	int i=0;//contatore
	int n=0;//variabile che conterrà l'informazione del numero da mettere
	int m=0;//variabile che conterrà l'informazione del numero del buffer
	int end=0;//variabile che serve per far smettetere tutto se impostata a 1
	int lati[12][2]={{6,3}, {5,6}, {6,4}, {5,1}, {1,2}, {2,6}, {5,4}, {5,2}, {3,4}, {3,2}, {1,4}, {1,3}};//array scomposto bidimensionale
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
						if(d==0){//se la posizione scombinata è quella della prima informazione della cella
							switch(i){
								case 0:{//se i è uguale a 0
									printf("a\n");//stampa il cambiamento fatto per conoscere il ciclo della risoluzione del cubo
									break;//esce dallo switch
								}
								case 1:{//se i è uguale a 1 (impossibile ma la mettiamo lo stesso)
									printf("b\n");//stampa il cambiamento fatto per conoscere il ciclo della risoluzione del cubo
									break;//esce dallo switch
								}
								case 2:{//se i è uguale a 2
									printf("c\n");//stampa il cambiamento fatto per conoscere il ciclo della risoluzione del cubo
									break;//esce dallo switch
								}
								case 3:{//se i è uguale a 3
									printf("d\n");//stampa il cambiamento fatto per conoscere il ciclo della risoluzione del cubo
									break;//esce dallo switch
								}
								case 4:{//se i è uguale a 4
									printf("f\n");//stampa il cambiamento fatto per conoscere il ciclo della risoluzione del cubo
									break;//esce dallo switch
								}
								case 5:{//se i è uguale a 5
									printf("g\n");//stampa il cambiamento fatto per conoscere il ciclo della risoluzione del cubo
									break;//esce dallo switch
								}
								case 6:{//se i è uguale a 6
									printf("h\n");//stampa il cambiamento fatto per conoscere il ciclo della risoluzione del cubo
									break;//esce dallo switch
								}
								case 7:{//se i è uguale a 7
									printf("j\n");//stampa il cambiamento fatto per conoscere il ciclo della risoluzione del cubo
									break;//esce dallo switch
								}
								case 8:{//se i è uguale a 8
									printf("k\n");//stampa il cambiamento fatto per conoscere il ciclo della risoluzione del cubo
									break;//esce dallo switch
								}
								case 9:{//se i è uguale a 9
									printf("n\n");//stampa il cambiamento fatto per conoscere il ciclo della risoluzione del cubo
									break;//esce dallo switch
								}
								case 10:{//se i è uguale a 10
									printf("o\n");//stampa il cambiamento fatto per conoscere il ciclo della risoluzione del cubo
									break;//esce dallo switch
								}
								case 11:{//se i è uguale a 11
									printf("s\n");//stampa il cambiamento fatto per conoscere il ciclo della risoluzione del cubo
									break;//esce dallo switch
								}
								default: //se in i c'è qualcosa di diverso da questi caratteri
									printf("errore\n");
									break;//esce dallo switch				
							}
						}
						else{//se la posizione scombinata è quella dell'ultima informazione della cella
							switch(i){
								case 0:{//se i è uguale a 0
									printf("m\n");//stampa il cambiamento fatto per conoscere il ciclo della risoluzione del cubo
									break;//esce dallo switch
								}
								case 1:{//se i è uguale a 1 (impossibile ma la mettiamo lo stesso)
									printf("i\n");//stampa il cambiamento fatto per conoscere il ciclo della risoluzione del cubo
									break;//esce dallo switch
								}
								case 2:{//se i è uguale a 2
									printf("e\n");//stampa il cambiamento fatto per conoscere il ciclo della risoluzione del cubo
									break;//esce dallo switch
								}
								case 3:{//se i è uguale a 3
									printf("q\n");//stampa il cambiamento fatto per conoscere il ciclo della risoluzione del cubo
									break;//esce dallo switch
								}
								case 4:{//se i è uguale a 4
									printf("l\n");//stampa il cambiamento fatto per conoscere il ciclo della risoluzione del cubo
									break;//esce dallo switch
								}
								case 5:{//se i è uguale a 5
									printf("u\n");//stampa il cambiamento fatto per conoscere il ciclo della risoluzione del cubo
									break;//esce dallo switch
								}
								case 6:{//se i è uguale a 6
									printf("r\n");//stampa il cambiamento fatto per conoscere il ciclo della risoluzione del cubo
									break;//esce dallo switch
								}
								case 7:{//se i è uguale a 7
									printf("p\n");//stampa il cambiamento fatto per conoscere il ciclo della risoluzione del cubo
									break;//esce dallo switch
								}
								case 8:{//se i è uguale a 8
									printf("v\n");//stampa il cambiamento fatto per conoscere il ciclo della risoluzione del cubo
									break;//esce dallo switch
								}
								case 9:{//se i è uguale a 9
									printf("t\n");//stampa il cambiamento fatto per conoscere il ciclo della risoluzione del cubo
									break;//esce dallo switch
								}
								case 10:{//se i è uguale a 10
									printf("x\n");//stampa il cambiamento fatto per conoscere il ciclo della risoluzione del cubo
									break;//esce dallo switch
								}
								case 11:{//se i è uguale a 11
									printf("z\n");//stampa il cambiamento fatto per conoscere il ciclo della risoluzione del cubo
									break;//esce dallo switch
								}
								default: //se in i c'è qualcosa di diverso da questi caratteri
									printf("errore\n");
									break;//esce dallo switch				
							}
							
						}
						break;//esco dal for							
					}
					else if(i!=11 && lati[i][d]==lati_vero[i][d]){
						//non fa nulla se non è l'ultimo confronto e se i valori confrontati sono uguali
					}
					else if (i==11 && d==1) {//se tutti sono giusti 
						end=1;//modifico la variabile end
						break;//faccio smettere il for
					}
			
				}
					
			}
		}
		else if(lati[1][0]==lati_vero[1][1] && lati[1][1]==lati_vero[1][0]){//se nel buffer ci sono i colori giusti ma sono messi male
			for(i=0;i<12;i++){
				for (d=0; d<2; d++){
					if (i==1){//se i è in zona buffer 
						//non fa nulla, perchè sennò scambierebbe in loop la posizione di buffer messa male
					}
					else if(lati[i][d]!=lati_vero[i][d]){//se nella posizione ci sono colori diversi-> cubo non risolto
						n=lati[i][0];//associo ad n l'informazione del primo pezzo non messo correttamente 
						m=lati[1][0];//associo ad m l'informazione del primo pezzo nel buffer
						lati[i][0]=m;//nel luogo dove c'era il pezzo che non andava bene metto la prima informazione del buffer
						lati[1][0]=n;//metto in informazione al buffer il primo colore del luogo dove il colore è sbagliato
						n=lati[i][1];//associo ad n l'informazione dell'ultimo pezzo non messo correttamente 
						m=lati[1][1];//associo ad m l'informazione dell'ultimo pezzo nel buffer
						lati[i][1]=m;//nel luogo dove c'era il pezzo che non andava bene metto l'ultima informazione del buffer
						lati[1][1]=n;//metto in informazione al buffer l'ultimo colore del luogo dove il colore è sbagliato
						if(d==0){//se la posizione scombinata è quella della prima informazione della cella
							switch(i){
								case 0:{//se i è uguale a 0
									printf("a\n");//stampa il cambiamento fatto per conoscere il ciclo della risoluzione del cubo
									break;//esce dallo switch
								}
								case 1:{//se i è uguale a 1 (impossibile ma la mettiamo lo stesso)
									printf("b\n");//stampa il cambiamento fatto per conoscere il ciclo della risoluzione del cubo
									break;//esce dallo switch
								}
								case 2:{//se i è uguale a 2
									printf("c\n");//stampa il cambiamento fatto per conoscere il ciclo della risoluzione del cubo
									break;//esce dallo switch
								}
								case 3:{//se i è uguale a 3
									printf("d\n");//stampa il cambiamento fatto per conoscere il ciclo della risoluzione del cubo
									break;//esce dallo switch
								}
								case 4:{//se i è uguale a 4
									printf("f\n");//stampa il cambiamento fatto per conoscere il ciclo della risoluzione del cubo
									break;//esce dallo switch
								}
								case 5:{//se i è uguale a 5
									printf("g\n");//stampa il cambiamento fatto per conoscere il ciclo della risoluzione del cubo
									break;//esce dallo switch
								}
								case 6:{//se i è uguale a 6
									printf("h\n");//stampa il cambiamento fatto per conoscere il ciclo della risoluzione del cubo
									break;//esce dallo switch
								}
								case 7:{//se i è uguale a 7
									printf("j\n");//stampa il cambiamento fatto per conoscere il ciclo della risoluzione del cubo
									break;//esce dallo switch
								}
								case 8:{//se i è uguale a 8
									printf("k\n");//stampa il cambiamento fatto per conoscere il ciclo della risoluzione del cubo
									break;//esce dallo switch
								}
								case 9:{//se i è uguale a 9
									printf("n\n");//stampa il cambiamento fatto per conoscere il ciclo della risoluzione del cubo
									break;//esce dallo switch
								}
								case 10:{//se i è uguale a 10
									printf("o\n");//stampa il cambiamento fatto per conoscere il ciclo della risoluzione del cubo
									break;//esce dallo switch
								}
								case 11:{//se i è uguale a 11
									printf("s\n");//stampa il cambiamento fatto per conoscere il ciclo della risoluzione del cubo
									break;//esce dallo switch
								}
								default: //se in i c'è qualcosa di diverso da questi caratteri
									printf("errore\n");
									break;//esce dallo switch				
							}
						}
						else{//se la posizione scombinata è quella dell'ultima informazione della cella
							switch(i){
								case 0:{//se i è uguale a 0
									printf("m\n");//stampa il cambiamento fatto per conoscere il ciclo della risoluzione del cubo
									break;//esce dallo switch
								}
								case 1:{//se i è uguale a 1 (impossibile ma la mettiamo lo stesso)
									printf("i\n");//stampa il cambiamento fatto per conoscere il ciclo della risoluzione del cubo
									break;//esce dallo switch
								}
								case 2:{//se i è uguale a 2
									printf("e\n");//stampa il cambiamento fatto per conoscere il ciclo della risoluzione del cubo
									break;//esce dallo switch
								}
								case 3:{//se i è uguale a 3
									printf("q\n");//stampa il cambiamento fatto per conoscere il ciclo della risoluzione del cubo
									break;//esce dallo switch
								}
								case 4:{//se i è uguale a 4
									printf("l\n");//stampa il cambiamento fatto per conoscere il ciclo della risoluzione del cubo
									break;//esce dallo switch
								}
								case 5:{//se i è uguale a 5
									printf("u\n");//stampa il cambiamento fatto per conoscere il ciclo della risoluzione del cubo
									break;//esce dallo switch
								}
								case 6:{//se i è uguale a 6
									printf("r\n");//stampa il cambiamento fatto per conoscere il ciclo della risoluzione del cubo
									break;//esce dallo switch
								}
								case 7:{//se i è uguale a 7
									printf("p\n");//stampa il cambiamento fatto per conoscere il ciclo della risoluzione del cubo
									break;//esce dallo switch
								}
								case 8:{//se i è uguale a 8
									printf("v\n");//stampa il cambiamento fatto per conoscere il ciclo della risoluzione del cubo
									break;//esce dallo switch
								}
								case 9:{//se i è uguale a 9
									printf("t\n");//stampa il cambiamento fatto per conoscere il ciclo della risoluzione del cubo
									break;//esce dallo switch
								}
								case 10:{//se i è uguale a 10
									printf("x\n");//stampa il cambiamento fatto per conoscere il ciclo della risoluzione del cubo
									break;//esce dallo switch
								}
								case 11:{//se i è uguale a 11
									printf("z\n");//stampa il cambiamento fatto per conoscere il ciclo della risoluzione del cubo
									break;//esce dallo switch
								}
								default: //se in i c'è qualcosa di diverso da questi caratteri
									printf("errore\n");
									break;//esce dallo switch				
							}
							
						}
						break;//esco dal for							
					}
					else if(i!=11 && lati[i][d]==lati_vero[i][d]){
						//non fa nulla se non è l'ultimo confronto e se i valori confrontati sono uguali
					}
					else if (i==11 && d==1 && lati[i][d]==lati_vero[i][d]) {//se tutti sono giusti 
						end=1;//modifico la variabile end
						break;//faccio smettere il for
					}
			
				}
					
			}
		}
		
		//fino a qui dovrebbe essere tutto giusto. bisognerà andare avanti a modificare il programma e bisognerebbe creare una funzione dove mettere quei giga switch e stampare
		//perchè sennò escono 30000 righe di codice
		if(end!=1){//se l'array non ha finito di essere combinato
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
					//qui metterò la parte per sapere che pezzo ha scambiato tramite funzione non scombinata
				}//funzione che serve per riordinare in base ai voleri dell'array lati_vero quello del lati
				else if(lati[1][0]== lati_vero[i][1] && lati[1][1]==lati_vero[i][0]){//se la zona di buffer ha la stessa informazione della zona confrontata ma sfasata
					n=lati[i][0];//associo ad n l'informazione del luogo dove andrà messa l'informazione del buffer
					m=lati[1][0];//associo ad m l'informazione del buffer
					lati[i][0]=m;//metto l'informazione nel buffer nel giusto luogo
					lati[1][0]=n;//aggiorno il buffer
					n=lati[i][1];//associo ad n l'informazione del luogo dove andrà messa l'informazione del buffer
					m=lati[1][1];//associo ad m l'informazione del buffer
					lati[i][1]=m;//metto l'informazione nel buffer nel giusto luogo
					lati[1][1]=n;//aggiorno il buffer
					//qui metterò la parte per sapere che pezzo ha scambiato tramite funzione scombinata
				}//funzione che serve per riordinare in base ai voleri dell'array lati_vero quello del lati	
			}
		}
	} while(end!=1);
	printf("\n");
	for(i=0;i<12;i++){
		for(d=0; d<2; d++){
			printf("%d ", lati[i][d]);
		}
		printf("\n");		
	}	
		
	
	return 0;
}
