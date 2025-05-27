#include <stdio.h>
#include <stdlib.h>

/* Questa parte di programma serve a risolvere i vertici e le parità, se esistenti. Andrà  messo prima del programma "sequenza combinazione pezzi"*/
int perm(){//perm che scambia ilvertice di buffer con quello preso in considerazioone 
	printf("3 move to sx\n action 270\n 3 move to sx\n action 90\n move to sx\n action 90\n 3 move to sx\n action 90\n move to sx\n");//stampa la funzione
	printf("action 270\n 3 move to sx\n action 270\n move to sx\n action 90\n rotate 90\n move to sx\n action 90\n 3 move to sx\n");//stampa la funzione 
	printf("action 270\n rotate 90\n move to sx\n action 270\n 3 move to sx\n action 90\n move to sx\n action 90\n 3 move to sx\n");//stampa la funzione
	printf("action 90\n rotate 90\n 3 move to sx\n action 270\n move to sx\n action 270\n rotate 90\n move to sx\n ");//stampa la funzione
}
int commutazioni_ver(int d, int i, int vertici[8][3]){//parte di programma che identifica come permutare ogni singolo vertice in base alla posizione e che mi restituirÃ  l'informazione per risolvere i vertici uno ad uno
	int a=0;//variabile che conterrÃ  l'informazione da mettere
	int b=0;//variabile che conterrÃ  l'informazione del buffer
	if(d==0){//se la prima posizione scombinata che troviamo Ã¨ quella relativa alla prima postazione codificata del vertice
		switch(i){
			case 0:{//se i Ã¨ uguale a 0 (impossibile ma la mettiamo lo stesso, non puÃ² commutare la stessa zona di buffer), avvia la risoluzione per la posizione "a"
				printf("error\n");//stampa errore
				break;//esce dallo switch
			}
			case 1:{//se i Ã¨ uguale a 1, avvia la risoluzione per la posizione "b"
				a=vertici[0][0];//associo ad a la prima informazione di buffer
				b=vertici[i][d];//associo a b l'informazione della zona "b"
				vertici[0][0]=b;//metto in prima zona buffer l'informazione della zona "b"
				vertici[i][d]=a;//metto in zona "b" la prima informazione di buffer
				a=vertici[0][1];//associo ad a la seconda informazione di buffer
				b=vertici[i][2];//associo a b l'informazione della zona "j"
				vertici[0][1]=b;//metto in prima zona buffer l'informazione della zona "j"
				vertici[i][2]=a;//metto in zona "j" la seconda informazione di buffer
				a=vertici[0][2];//associo ad a l'ultima informazione di buffer
				b=vertici[i][1];//associo a b l'informazione della zona "m"
				vertici[0][2]=b;//metto in ultima zona buffer l'informazione della zona "m"
				vertici[i][1]=a;//metto in zona "m" l'ultima informazione di buffer
				printf("3 move to sx\n action 270\n move to sx\n action 90\n");//stampa i movimenti per portare l'obiettivo
				perm();//stampa la permutazione dei vertici
				printf("action 270\n 3 move to sx\n action 90\n move to sx\n");//stampa i movimenti per portare l'obiettivo a posto
				break;//esce dallo switch
			}
			case 2:{//se i Ã¨ uguale a 2, avvia la risoluzione per la posizione "c"
				a=vertici[0][0];//associo ad a la prima informazione di buffer
				b=vertici[i][d];//associo a b l'informazione della zona "c"
				vertici[0][0]=b;//metto in prima zona buffer l'informazione della zona "c"
				vertici[i][d]=a;//metto in zona "c" la prima informazione di buffer
				a=vertici[0][1];//associo ad a la seconda informazione di buffer
				b=vertici[i][2];//associo a b l'informazione della zona "f"
				vertici[0][1]=b;//metto in seconda zona buffer l'informazione della zona "f"
				vertici[i][2]=a;//metto in zona "f" la seconda informazione di buffer
				a=vertici[0][2];//associo ad a l'ultima informazione di buffer
				b=vertici[i][1];//associo a b l'informazione della zona "i"
				vertici[0][2]=b;//metto in ultima zona buffer l'informazione della zona "i"
				vertici[i][1]=a;//metto in zona "i" l'ultima informazione di buffer
				printf("rotate 90\n move to sx\n action 270\n 3 move to sx\n rotate 270\n");//stampa i movimenti per portare l'obiettivo
				perm();//stampa la permutazione dei vertici
				printf("rotate 90\n move to sx\n action 90\n 3 move to sx\n rotate 270\n ");//stampa i movimenti per portare l'obiettivo a posto
				break;//esce dallo switch
			}
			case 3:{//se i Ã¨ uguale a 3, avvia la risoluzione per la posizione "d"
				a=vertici[0][0];//associo ad a la prima informazione di buffer
				b=vertici[i][d];//associo a b l'informazione della zona "d"
				vertici[0][0]=b;//metto in prima zona buffer l'informazione della zona "d"
				vertici[i][d]=a;//metto in zona "d" la prima informazione di buffer
				a=vertici[0][1];//associo ad a la seconda informazione di buffer
				b=vertici[i][2];//associo a b l'informazione della zona "r"
				vertici[0][1]=b;//metto in seconda zona buffer l'informazione della zona "r"
				vertici[i][2]=a;//metto in zona "r" la seconda informazione di buffer
				a=vertici[0][2];//associo ad a l'ultima informazione di buffer
				b=vertici[i][1];//associo a b l'informazione della zona "e"
				vertici[0][2]=b;//metto in ultima zona buffer l'informazione della zona "e"
				vertici[i][1]=a;//metto in zona "e" l'ultima informazione di buffer
				printf("rotate 90\n move to sx\n action 270\n rotate 90\n move to sx\n action 90\n rotate 90\n move to sx\n");//stampa i movimenti per portare l'obiettivo
				perm();//stampa la permutazione dei vertici
				printf("3 move to sx\n rotate 270\n action 270\n 3 move to sx\n rotate 270\n action 90\n 3 move to sx\n rotate 270\n");//stampa i movimenti per portare l'obiettivo a posto
				break;//esce dallo switch
			}
			case 4:{//se i Ã¨ uguale a 4, avvia la risoluzione per la posizione "o"
				a=vertici[0][0];//associo ad a la prima informazione di buffer
				b=vertici[i][d];//associo a b l'informazione della zona "o"
				vertici[0][0]=b;//metto in prima zona buffer l'informazione della zona "o"
				vertici[i][d]=a;//metto in zona "o" la prima informazione di buffer
				a=vertici[0][1];//associo ad a la seconda informazione di buffer
				b=vertici[i][2];//associo a b l'informazione della zona "z"
				vertici[0][1]=b;//metto in seconda zona buffer l'informazione della zona "z"
				vertici[i][2]=a;//metto in zona "z" la seconda informazione di buffer
				a=vertici[0][2];//associo ad a l'ultima informazione di buffer
				b=vertici[i][1];//associo a b l'informazione della zona "t"
				vertici[0][2]=b;//metto in ultima zona buffer l'informazione della zona "t"
				vertici[i][1]=a;//metto in zona "t" l'ultima informazione di buffer
				printf("action 90\n 3 move to sx\n action 270\n move to sx\n");//stampa i movimenti per portare l'obiettivo
				perm();//stampa la permutazione dei vertici
				printf("3 move to sx\n action 90\n move to sx\n action 270\n");//stampa i movimenti per portare l'obiettivo a posto
				break;//esce dallo switch
			}
			case 5:{//se i Ã¨ uguale a 5, avvia la risoluzione per la posizione "k"
				a=vertici[0][0];//associo ad a la prima informazione di buffer
				b=vertici[i][d];//associo a b l'informazione della zona "k"
				vertici[0][0]=b;//metto in prima zona buffer l'informazione della zona "k"
				vertici[i][d]=a;//metto in zona "k" la prima informazione di buffer			
				a=vertici[0][1];//associo ad a la seconda informazione di buffer
				b=vertici[i][2];//associo a b l'informazione della zona "x"
				vertici[0][1]=b;//metto in seconda zona buffer l'informazione della zona "x"
				vertici[i][2]=a;//metto in zona "x" la seconda informazione di buffer
				a=vertici[0][2];//associo ad a l'ultima informazione di buffer
				b=vertici[i][1];//associo a b l'informazione della zona "p"
				vertici[0][2]=b;//metto in ultima zona buffer l'informazione della zona "p"
				vertici[i][1]=a;//metto in zona "p" l'ultima informazione di buffer
				printf("3 move to sx\n action 270\n move to sx\n");//stampa i movimenti per portare l'obiettivo
				perm();//stampa la permutazione dei vertici
				printf("3 move to sx\n action 90\n move to sx\n");//stampa i movimenti per portare l'obiettivo a posto
				break;//esce dallo switch
			}
			case 6:{//se i Ã¨ uguale a 6, avvia la risoluzione per la posizione "g"
				a=vertici[0][0];//associo ad a la prima informazione di buffer
				b=vertici[i][d];//associo a b l'informazione della zona "g"
				vertici[0][0]=b;//metto in prima zona buffer l'informazione della zona "g"
				vertici[i][d]=a;//metto in zona "g" la prima informazione di buffer
				a=vertici[0][1];//associo ad a la seconda informazione di buffer
				b=vertici[i][2];//associo a b l'informazione della zona "v"
				vertici[0][1]=b;//metto in seconda zona buffer l'informazione della zona "v"
				vertici[i][2]=a;//metto in zona "v" la seconda informazione di buffer				
				a=vertici[0][2];//associo ad a l'ultima informazione di buffer
				b=vertici[i][1];//associo a b l'informazione della zona "l"
				vertici[0][2]=b;//metto in ultima zona buffer l'informazione della zona "l"
				vertici[i][1]=a;//metto in zona "l" l'ultima informazione di buffer
				printf("rotate 90\n move to sx\n action 270\n 3 move to sx\n action 270\n rotate 270\n");//stampa i movimenti per portare l'obiettivo
				perm();//stampa la permutazione dei vertici
				printf("rotate 90\n action 90\n move to sx\n action 90\n 3 move to sx\n rotate 270\n ");//stampa i movimenti per portare l'obiettivo a posto
				break;//esce dallo switch
			}
			case 7:{//se i Ã¨ uguale a 7, avvia la risoluzione per la posizione "h"
				a=vertici[0][0];//associo ad a la prima informazione di buffer
				b=vertici[i][d];//associo a b l'informazione della zona "h"
				vertici[0][0]=b;//metto in prima zona buffer l'informazione della zona "h"
				vertici[i][d]=a;//metto in zona "h" la prima informazione di buffer				
				a=vertici[0][1];//associo ad a la seconda informazione di buffer
				b=vertici[i][1];//associo a b l'informazione della zona "s"
				vertici[0][1]=b;//metto in seconda zona buffer l'informazione della zona "s"
				vertici[i][1]=a;//metto in zona "s" la seconda informazione di buffer			
				a=vertici[0][2];//associo ad a l'ultima informazione di buffer
				b=vertici[i][2];//associo a b l'informazione della zona "u"
				vertici[0][2]=b;//metto in ultima zona buffer l'informazione della zona "u"
				vertici[i][2]=a;//metto in zona "u" l'ultima informazione di buffer
				printf("action 270\n");//stampa i movimenti per portare l'obiettivo
				perm();//stampa la permutazione dei vertici
				printf("action 90\n");//stampa i movimenti per portare l'obiettivo a posto
				break;//esce dallo switch
			}
			default: //se in i c'Ã¨ qualcosa di diverso da questi caratteri
				printf("errore\n");
				break;//esce dallo switch
			
		}
	}
	
	else if  (d==1){//se la prima posizione scombinata che troviamo Ã¨ quella relativa alla seconda postazione codificata del vertice
		switch(i){
			case 0:{//se i Ã¨ uguale a 0 (impossibile ma la mettiamo lo stesso, non puÃ² commutare la stessa zona di buffer), avvia la risoluzione per la posizione "n"
				printf("error\n");//stampa errore
				break;//esce dallo switch
			}
			case 1:{//se i Ã¨ uguale a 1, avvia la risoluzione per la posizione "m"
				a=vertici[0][0];//associo ad a la prima informazione di buffer
				b=vertici[i][d];//associo a b l'informazione della zona "m"
				vertici[0][0]=b;//metto in prima zona buffer l'informazione della zona "m"
				vertici[i][d]=a;//metto in zona "m" la prima informazione di buffer				
				a=vertici[0][1];//associo ad a la seconda informazione di buffer
				b=vertici[i][0];//associo a b l'informazione della zona "b"
				vertici[0][1]=b;//metto in prima zona buffer l'informazione della zona "b"
				vertici[i][0]=a;//metto in zona "b" la seconda informazione di buffer		
				a=vertici[0][2];//associo ad a l'ultima informazione di buffer
				b=vertici[i][2];//associo a b l'informazione della zona "j"
				vertici[0][2]=b;//metto in ultima zona buffer l'informazione della zona "j"
				vertici[i][2]=a;//metto in zona "j" l'ultima informazione di buffer
				printf("3 move to sx\n action 90\n rotate 90\n move to sx\n action 270\n rotate 90\n 3 move to sx\n rotate 270\n");//stampa i movimenti per portare l'obiettivo
				perm();//stampa la permutazione dei vertici
				printf("rotate 90\n move to sx\n rotate 270\n action 90\n 3 move to sx\n rotate 270\n action 270\n move to sx\n");//stampa i movimenti per portare l'obiettivo a posto
				break;//esce dallo switch
			}
			case 2:{//se i Ã¨ uguale a 2, avvia la risoluzione per la posizione "i"
				a=vertici[0][0];//associo ad a la prima informazione di buffer
				b=vertici[i][d];//associo a b l'informazione della zona "i"
				vertici[0][0]=b;//metto in prima zona buffer l'informazione della zona "i"
				vertici[i][d]=a;//metto in zona "i" la prima informazione di buffer					
				a=vertici[0][1];//associo ad a la seconda informazione di buffer
				b=vertici[i][0];//associo a b l'informazione della zona "c"
				vertici[0][1]=b;//metto in prima zona buffer l'informazione della zona "c"
				vertici[i][0]=a;//metto in zona "c" la seconda informazione di buffer			
				a=vertici[0][2];//associo ad a l'ultima informazione di buffer
				b=vertici[i][2];//associo a b l'informazione della zona "f"
				vertici[0][2]=b;//metto in ultima zona buffer l'informazione della zona "f"
				vertici[i][2]=a;//metto in zona "f" l'ultima informazione di buffer
				printf("3 move to sx\n action 90\n move to sx\n ");//stampa i movimenti per portare l'obiettivo
				perm();//stampa la permutazione dei vertici
				printf("3 move to sx\n action 270\n move to sx\n");//stampa i movimenti per portare l'obiettivo a posto
				break;//esce dallo switch
			}
			case 3:{//se i Ã¨ uguale a 3, avvia la risoluzione per la posizione "e"
				a=vertici[0][0];//associo ad a la prima informazione di buffer
				b=vertici[i][d];//associo a b l'informazione della zona "e"
				vertici[0][0]=b;//metto in prima zona buffer l'informazione della zona "e"
				vertici[i][d]=a;//metto in zona "e" la prima informazione di buffer						
				a=vertici[0][1];//associo ad a la seconda informazione di buffer
				b=vertici[i][0];//associo a b l'informazione della zona "d"
				vertici[0][1]=b;//metto in prima zona buffer l'informazione della zona "d"
				vertici[i][0]=a;//metto in zona "d" la seconda informazione di buffer				
				a=vertici[0][2];//associo ad a l'ultima informazione di buffer
				b=vertici[i][2];//associo a b l'informazione della zona "r"
				vertici[0][2]=b;//metto in ultima zona buffer l'informazione della zona "r"
				vertici[i][2]=a;//metto in zona "r" l'ultima informazione di buffer
				printf("rotate 90\n move to sx\n action 90\n 3 move to sx\n action 270\n rotate 270\n");//stampa i movimenti per portare l'obiettivo
				perm();//stampa la permutazione dei vertici
				printf("rotate 90\n action 90\n move to sx\n action 270\n 3 move to sx\n rotate 270\n");//stampa i movimenti per portare l'obiettivo a posto
				break;//esce dallo switch
			}
			case 4:{//se i Ã¨ uguale a 4, avvia la risoluzione per la posizione "t"
				a=vertici[0][0];//associo ad a la prima informazione di buffer
				b=vertici[i][d];//associo a b l'informazione della zona "t"
				vertici[0][0]=b;//metto in prima zona buffer l'informazione della zona "t"
				vertici[i][d]=a;//metto in zona "t" la prima informazione di buffer							
				a=vertici[0][1];//associo ad a la seconda informazione di buffer
				b=vertici[i][0];//associo a b l'informazione della zona "o"
				vertici[0][1]=b;//metto in prima zona buffer l'informazione della zona "o"
				vertici[i][0]=a;//metto in zona "o" la seconda informazione di buffer				
				a=vertici[0][2];//associo ad a l'ultima informazione di buffer
				b=vertici[i][2];//associo a b l'informazione della zona "z"
				vertici[0][2]=b;//metto in ultima zona buffer l'informazione della zona "z"
				vertici[i][2]=a;//metto in zona "z" l'ultima informazione di buffer
				printf("action 180\n");//stampa i movimenti per portare l'obiettivo
				perm();//stampa la permutazione dei vertici
				printf("action 180\n");//stampa i movimenti per portare l'obiettivo a posto
				break;//esce dallo switch
			}
			case 5:{//se i Ã¨ uguale a 5, avvia la risoluzione per la posizione "p"
				a=vertici[0][0];//associo ad a la prima informazione di buffer
				b=vertici[i][d];//associo a b l'informazione della zona "p"
				vertici[0][0]=b;//metto in prima zona buffer l'informazione della zona "p"
				vertici[i][d]=a;//metto in zona "p" la prima informazione di buffer								
				a=vertici[0][1];//associo ad a la seconda informazione di buffer
				b=vertici[i][0];//associo a b l'informazione della zona "k"
				vertici[0][1]=b;//metto in prima zona buffer l'informazione della zona "k"
				vertici[i][0]=a;//metto in zona "k" la seconda informazione di buffer					
				a=vertici[0][2];//associo ad a l'ultima informazione di buffer
				b=vertici[i][2];//associo a b l'informazione della zona "x"
				vertici[0][2]=b;//metto in ultima zona buffer l'informazione della zona "x"
				vertici[i][2]=a;//metto in zona "x" l'ultima informazione di buffer
				printf("action 90\n");//stampa i movimenti per portare l'obiettivo
				perm();//stampa la permutazione dei vertici
				printf("action 270\n");//stampa i movimenti per portare l'obiettivo a posto
				break;//esce dallo switch
			}
			case 6:{//se i Ã¨ uguale a 6, avvia la risoluzione per la posizione "l"
				a=vertici[0][0];//associo ad a la prima informazione di buffer
				b=vertici[i][d];//associo a b l'informazione della zona "l"
				vertici[0][0]=b;//metto in prima zona buffer l'informazione della zona "l"
				vertici[i][d]=a;//metto in zona "l" la prima informazione di buffer			
				a=vertici[0][1];//associo ad a la seconda informazione di buffer
				b=vertici[i][0];//associo a b l'informazione della zona "g"
				vertici[0][1]=b;//metto in prima zona buffer l'informazione della zona "g"
				vertici[i][0]=a;//metto in zona "g" la seconda informazione di buffer		
				a=vertici[0][2];//associo ad a l'ultima informazione di buffer
				b=vertici[i][2];//associo a b l'informazione della zona "v"
				vertici[0][2]=b;//metto in ultima zona buffer l'informazione della zona "v"
				vertici[i][2]=a;//metto in zona "v" l'ultima informazione di buffer
				//cubo già in posizione
				perm();//stampa la permutazione dei vertici
				//cubo già rimesso a posto
				break;//esce dallo switch
			}
			case 7:{//se i Ã¨ uguale a 7, avvia la risoluzione per la posizione "s"
				a=vertici[0][0];//associo ad a la prima informazione di buffer
				b=vertici[i][d];//associo a b l'informazione della zona "s"
				vertici[0][0]=b;//metto in prima zona buffer l'informazione della zona "s"
				vertici[i][d]=a;//metto in zona "s" la prima informazione di buffer				
				a=vertici[0][1];//associo ad a la seconda informazione di buffer
				b=vertici[i][2];//associo a b l'informazione della zona "u"
				vertici[0][1]=b;//metto in prima zona buffer l'informazione della zona "u"
				vertici[i][2]=a;//metto in zona "u" la seconda informazione di buffer		
				a=vertici[0][2];//associo ad a l'ultima informazione di buffer
				b=vertici[i][0];//associo a b l'informazione della zona "h"
				vertici[0][2]=b;//metto in ultima zona buffer l'informazione della zona "h"
				vertici[i][0]=a;//metto in zona "h" l'ultima informazione di buffer
				printf("rotate 90\n move to sx\n action 180\n rotate 90\n move to sx\n action 90\n rotate 90\n move to sx\n");//stampa i movimenti per portare l'obiettivo
				perm();//stampa la permutazione dei vertici
				printf("3 move to sx\n rotate 270\n action 270\n 3 move to sx\n rotate 270\n action 180\n 3 move to sx\n rotate 270\n");//stampa i movimenti per portare l'obiettivo a posto
				break;//esce dallo switch
			}
			default: //se in i c'Ã¨ qualcosa di diverso da questi caratteri
				printf("errore\n");
				break;//esce dallo switch
		}
	}
	
	else if(d==2){//se la prima posizione scombinata che troviamo Ã¨ quella relativa all'ultima postazione codificata del vertice
		switch(i){
			case 0:{//se i Ã¨ uguale a 0 (impossibile ma la mettiamo lo stesso, non puÃ² commutare la stessa zona di buffer), avvia la risoluzione per la posizione "q"
				printf("error\n");//stampa errore
				break;//esce dallo switch
			}
			case 1:{//se i Ã¨ uguale a 1, avvia la risoluzione per la posizione "j"
				a=vertici[0][0];//associo ad a la prima informazione di buffer
				b=vertici[i][d];//associo a b l'informazione della zona "j"
				vertici[0][0]=b;//metto in prima zona buffer l'informazione della zona "j"
				vertici[i][d]=a;//metto in zona "j" la prima informazione di buffer								
				a=vertici[0][1];//associo ad a la seconda informazione di buffer
				b=vertici[i][1];//associo a b l'informazione della zona "m"
				vertici[0][1]=b;//metto in prima zona buffer l'informazione della zona "m"
				vertici[i][1]=a;//metto in zona "m" la seconda informazione di buffer		
				a=vertici[0][2];//associo ad a l'ultima informazione di buffer
				b=vertici[i][0];//associo a b l'informazione della zona "b"
				vertici[0][2]=b;//metto in ultima zona buffer l'informazione della zona "b"
				vertici[i][0]=a;//metto in zona "b" l'ultima informazione di buffer
				printf("3 move to sx\n action 180\n move to sx\n");//stampa i movimenti per portare l'obiettivo
				perm();//stampa la permutazione dei vertici
				printf("3 move to sx\n action 180\n move to sx\n");//stampa i movimenti per portare l'obiettivo a posto
				break;//esce dallo switch
			}
			case 2:{//se i Ã¨ uguale a 2, avvia la risoluzione per la posizione "f"
				a=vertici[0][0];//associo ad a la prima informazione di buffer
				b=vertici[i][d];//associo a b l'informazione della zona "f"
				vertici[0][0]=b;//metto in prima zona buffer l'informazione della zona "f"
				vertici[i][d]=a;//metto in zona "f" la prima informazione di buffer								
				a=vertici[0][1];//associo ad a la seconda informazione di buffer
				b=vertici[i][1];//associo a b l'informazione della zona "i"
				vertici[0][1]=b;//metto in prima zona buffer l'informazione della zona "i"
				vertici[i][1]=a;//metto in zona "i" la seconda informazione di buffer		
				a=vertici[0][2];//associo ad a l'ultima informazione di buffer
				b=vertici[i][0];//associo a b l'informazione della zona "c"
				vertici[0][2]=b;//metto in ultima zona buffer l'informazione della zona "c"
				vertici[i][0]=a;//metto in zona "c" l'ultima informazione di buffer
				printf("3 move to sx\n action 180\n move to sx\n action 90\n");//stampa i movimenti per portare l'obiettivo
				perm();//stampa la permutazione dei vertici
				printf("action 270\n 3 move to sx\n action 180\n move to sx\n");//stampa i movimenti per portare l'obiettivo a posto
				break;//esce dallo switch
			}
			case 3:{//se i Ã¨ uguale a 3, avvia la risoluzione per la posizione "r"
				a=vertici[0][0];//associo ad a la prima informazione di buffer
				b=vertici[i][d];//associo a b l'informazione della zona "r"
				vertici[0][0]=b;//metto in prima zona buffer l'informazione della zona "r"
				vertici[i][d]=a;//metto in zona "r" la prima informazione di buffer						
				a=vertici[0][1];//associo ad a la seconda informazione di buffer
				b=vertici[i][1];//associo a b l'informazione della zona "e"
				vertici[0][1]=b;//metto in prima zona buffer l'informazione della zona "e"
				vertici[i][1]=a;//metto in zona "e" la seconda informazione di buffer		
				a=vertici[0][2];//associo ad a l'ultima informazione di buffer
				b=vertici[i][0];//associo a b l'informazione della zona "d"
				vertici[0][2]=b;//metto in ultima zona buffer l'informazione della zona "d"
				vertici[i][0]=a;//metto in zona "d" l'ultima informazione di buffer
				printf("rotate 90\n move to sx\n action 180\n 3 move to sx\n rotate 270\n");//stampa i movimenti per portare l'obiettivo
				perm();//stampa la permutazione dei vertici
				printf("rotate 90\n move to sx\n action 180\n 3 move to sx\nrotate 270\n");//stampa i movimenti per portare l'obiettivo a posto
				break;//esce dallo switch
			}
			case 4:{//se i Ã¨ uguale a 4, avvia la risoluzione per la posizione "z"
				a=vertici[0][0];//associo ad a la prima informazione di buffer
				b=vertici[i][d];//associo a b l'informazione della zona "z"
				vertici[0][0]=b;//metto in prima zona buffer l'informazione della zona "z"
				vertici[i][d]=a;//metto in zona "z" la prima informazione di buffer											
				a=vertici[0][1];//associo ad a la seconda informazione di buffer
				b=vertici[i][1];//associo a b l'informazione della zona "t"
				vertici[0][1]=b;//metto in prima zona buffer l'informazione della zona "t"
				vertici[i][1]=a;//metto in zona "t" la seconda informazione di buffer					
				a=vertici[0][2];//associo ad a l'ultima informazione di buffer
				b=vertici[i][0];//associo a b l'informazione della zona "o"
				vertici[0][2]=b;//metto in ultima zona buffer l'informazione della zona "o"
				vertici[i][0]=a;//metto in zona "o" l'ultima informazione di buffer
				printf("action 270\n rotate 90\n move to sx\n action 90\n 3 move to sx\n rotate 270\n");//stampa i movimenti per portare l'obiettivo
				perm();//stampa la permutazione dei vertici
				printf("rotate 90\n move to sx\n action 270\n 3 move to sx\n rotate 270\n action 90\n");//stampa i movimenti per portare l'obiettivo a posto
				break;//esce dallo switch
			}
			case 5:{//se i Ã¨ uguale a 5, avvia la risoluzione per la posizione "x"
				a=vertici[0][0];//associo ad a la prima informazione di buffer
				b=vertici[i][d];//associo a b l'informazione della zona "x"
				vertici[0][0]=b;//metto in prima zona buffer l'informazione della zona "x"
				vertici[i][d]=a;//metto in zona "x" la prima informazione di buffer											
				a=vertici[0][1];//associo ad a la seconda informazione di buffer
				b=vertici[i][1];//associo a b l'informazione della zona "p"
				vertici[0][1]=b;//metto in prima zona buffer l'informazione della zona "p"
				vertici[i][1]=a;//metto in zona "p" la seconda informazione di buffer					
				a=vertici[0][2];//associo ad a l'ultima informazione di buffer
				b=vertici[i][0];//associo a b l'informazione della zona "k"
				vertici[0][2]=b;//metto in ultima zona buffer l'informazione della zona "k"
				vertici[i][0]=a;//metto in zona "k" l'ultima informazione di buffer
				printf("3 move to sx\n action 180\n rotate 90\n move to sx\n action 270\n move to sx\n rotate 90\n 3 move to sx\n");//stampa i movimenti per portare l'obiettivo
				perm();//stampa la permutazione dei vertici
				printf("move to sx\n rotate 270\n 3 move to sx\n action 90\n 3 move to sx\n rotate 270\n action 180\n move to sx\n");//stampa i movimenti per portare l'obiettivo a posto
				break;//esce dallo switch
			}
			case 6:{//se i Ã¨ uguale a 6, avvia la risoluzione per la posizione "v"
				a=vertici[0][0];//associo ad a la prima informazione di buffer
				b=vertici[i][d];//associo a b l'informazione della zona "v"
				vertici[0][0]=b;//metto in prima zona buffer l'informazione della zona "v"
				vertici[i][d]=a;//metto in zona "v" la prima informazione di buffer											
				a=vertici[0][1];//associo ad a la seconda informazione di buffer
				b=vertici[i][1];//associo a b l'informazione della zona "l"
				vertici[0][1]=b;//metto in prima zona buffer l'informazione della zona "l"
				vertici[i][1]=a;//metto in zona "l" la seconda informazione di buffer					
				a=vertici[0][2];//associo ad a l'ultima informazione di buffer
				b=vertici[i][0];//associo a b l'informazione della zona "g"
				vertici[0][2]=b;//metto in ultima zona buffer l'informazione della zona "g"
				vertici[i][0]=a;//metto in zona "g" l'ultima informazione di buffer
				printf("rotate 90\n move to sx\n action 90\n rotate 90\n move to sx\n action 90\n rotate 90\n move to sx\n");//stampa i movimenti per portare l'obiettivo
				perm();//stampa la permutazione dei vertici
				printf("3 move to sx\n rotate 270\n action 270\n 3 move to sx\n rotate 270\n action 270\n 3 move to sx\n rotate 270\n");//stampa i movimenti per portare l'obiettivo a posto
				break;//esce dallo switch
			}
			case 7:{//se i Ã¨ uguale a 7, avvia la risoluzione per la posizione "u"
				a=vertici[0][0];//associo ad a la prima informazione di buffer
				b=vertici[i][d];//associo a b l'informazione della zona "u"
				vertici[0][0]=b;//metto in prima zona buffer l'informazione della zona "u"
				vertici[i][d]=a;//metto in zona "u" la prima informazione di buffer											
				a=vertici[0][1];//associo ad a la seconda informazione di buffer
				b=vertici[i][0];//associo a b l'informazione della zona "h"
				vertici[0][1]=b;//metto in prima zona buffer l'informazione della zona "h"
				vertici[i][0]=a;//metto in zona "h" la seconda informazione di buffer		
				a=vertici[0][2];//associo ad a l'ultima informazione di buffer
				b=vertici[i][1];//associo a b l'informazione della zona "s"
				vertici[0][2]=b;//metto in ultima zona buffer l'informazione della zona "s"
				vertici[i][1]=a;//metto in zona "s" l'ultima informazione di buffer
				printf("rotate 90\n move to sx\n action 90\n move to sx\n rotate 90\n 2 move to sx\n");//stampa i movimenti per portare l'obiettivo
				perm();//stampa la permutazione dei vertici
				printf("2 move to sx\n rotate 270\n 3 move to sx\n action 270\n 3 move to sx\n rotate 270\n");//stampa i movimenti per portare l'obiettivo a posto
				break;//esce dallo switch
			}
			default: //se in i c'Ã¨ qualcosa di diverso da questi caratteri
				printf("errore\n");
				break;//esce dallo switch
		}
	}
	return 0;	
}
int main(int argc, char *argv[]) {
	int vertici_vero[8][3]={{1,4,5}, {1,4,3}, {1,3,2}, {1,2,5}, {4,5,6}, {3,4,6}, {2,3,6}, {2,5,6}};//array che contiene le informazioni dei vertici giusti
	int vertici[8][3]={{6,3,2}, {4,1,5}, {5,2,6}, {1,3,2}, {1,4,3}, {6,4,5}, {6,3,4}, {5,2,1}};		//array che contiene gli insiemi delle informazioni degli array dei singoli vertici scombinati
	int end=0;																						//variabile che mi farÃƒÆ’Ã‚Â  uscire dal ciclo piÃƒÆ’Ã‚Â¹ grande
	int end_int=0;																					//variabile che mi farÃƒÆ’Ã‚Â  uscire dal ciclo piÃƒÆ’Ã‚Â¹ interno
	int d=0;																						//contatore
	int i=0;																						//contatore
	int n=0;																						//variabile che conterrÃ   l'informazione del numero da mettere
	int m=0;																						//variabile che conterrÃ   l'informazione del numero del buffer
	int parita=0;																					//contatore per vedere quante volte permuta i vertici, in modo da capire se eseguire una parità o meno
		//identifico vertici[0][0], [0][1] e [0][2] come zona di buffer, quando in realtà   sarà   la zona a;n;q
	
	do{

		if (vertici_vero[0][0]==vertici[0][0] && vertici_vero[0][1]==vertici[0][1] && vertici_vero[0][2]==vertici[0][2]){	//se nel buffer ci sono i colori giusti e messi bene
			for (i=0;i<8;i++){
				for (d=0;d<3;d++){
					if (vertici_vero[i][d]!= vertici[i][d]){	//se nella posizione analizzata ci sono colori diversi -> cubo non risolto (molto probabilmente bisogna mettere anche qui il pezzo di codice di commutazione come nel cubo risolto ma messo male
						commutazioni_ver(d, i, vertici);//avvia la funzione commutazioni_ver
						parita=parita+1;//aggiorno il contatore delle parità 
						end_int=1;		//imposto la variabile a 1 per far si che quando uscirà dal primo for sarà costretto ad andare nell'altro e chiudere anch'esso
						break;			//esco dal for
					}
					else if(i!=7 && vertici[i][d]==vertici_vero[i][d]){
						//non fa nulla se non ÃƒÂ¨ l'ultimo confronto e se i valori confrontati sono uguali
					}
					else if (i==7 && d==2) {//se tutti sono giusti 
						end=1;				//modifico la variabile end
						end_int=1;			//imposto la variabile a 1 per far si che quando usirà  dal primo for sarà costretto ad andare nell'altro e chiudere anch'esso
						break;				//faccio smettere il for
					}
				}
				if (end_int==1){			//se la variabile per far chiudere tutti i for è stata attivata
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
					else if(vertici[i][d]!=vertici_vero[i][d]){//se nella posizione ci sono colori diversi-> cubo non risolto (devo controllare questo if perchè non sono convinto di come funzioni)
						commutazioni_ver(d, i, vertici);//avvia la funzione commutazioni_ver
						parita=parita+1;//aggiorno il contatore delle parità
						end_int=1;		//imposto la variabile a 1 per far si che quando uscirà dal primo for sarà costretto ad andare nell'altro e chiudere anch'esso
						break;			//esco dal for							
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
					else if(vertici[i][d]!=vertici_vero[i][d]){//se nella posizione ci sono colori diversi-> cubo non risolto (devo controllare questo if perchè non sono convinto di come funzioni)
						commutazioni_ver(d, i, vertici);//avvia la funzione commutazioni_ver
						parita=parita+1;//aggiorno il contatore delle parità
						end_int=1;		//imposto la variabile a 1 per far si che quando uscirà dal primo for sarà costretto ad andare nell'altro e chiudere anch'esso
						break;			//esco dal for							
					}
					else if(vertici[i][d]==vertici_vero[i][d]){//se nella posizione analizzata il pezzo ÃƒÂ¨ giusto
					//non faccio nulla e continuo con l'analisi
					} 
				}
				if (end_int==1){			//se la variabile per far chiudere tutti i for ÃƒÂ¨ stata attivata
					end_int=0;				//ristabilizzo la variabile per poterla riutilizzare
					break;					//faccio smettere anche questo for
				}
			}
			
		}
		
		else if (end!=1){//se il cubo non è risolto --> nel buffer ci sono colori completamente sbagliati
			for(i=0;i<8;i++){//confronta ogni vertice
				if(vertici[0][0]==vertici_vero[i][0] || vertici[0][0]==vertici_vero[i][1] || vertici[0][0]==vertici_vero[i][2] ){//se nel vertice analizzato c'Ã¨ anche solo un colore che combacia con quello della prima posizione del buffer
					if(vertici[0][1]==vertici_vero[i][0] || vertici[0][1]==vertici_vero[i][1] || vertici[0][1]==vertici_vero[i][2]){//se nel vertice analizzato c'Ã¨ anche solo un colore che combacia con quello dell seconda posizione del buffer
						if(vertici[0][2]==vertici_vero[i][0] || vertici[0][2]==vertici_vero[i][1] || vertici[0][2]==vertici_vero[i][2]){//se nel vertice analizzato c'Ã¨ anche solo un colore che combacia con quello dell'ultima posizione del buffer --> trovato vertice dove permutare il pezzo
							if (vertici[0][0]==vertici_vero[i][0]){//se la prima informazione di buffer va messa nella prima informazione del vertice analizzato
								d=0;//salvo la posizione dove deve andare la prima informazione di buffer
								commutazioni_ver(d, i, vertici);//avvia la funzione commutazioni_ver
								parita=parita+1;//aggiorno il contatore delle parità
								break;//esce dal for (spero lo faccia)
							}
							else if(vertici[0][0]==vertici_vero[i][1]){//se la prima informazione di buffer va messa nella seconda informazione del vertice analizzato
								d=1;//salvo la posizione dove deve andare la prima informazione di buffer
								commutazioni_ver(d, i, vertici);//avvia la funzione commutazioni_ver
								parita=parita+1;//aggiorno il contatore delle parità
								break;//esce dal for (spero lo faccia)								
							}
							else if(vertici[0][0]==vertici_vero[i][2]){//se la prima informazione di buffer va messa nell'ultima informazione del vertice analizzato
								d=2;//salvo la posizione dove deve andare la prima informazione di buffer
								commutazioni_ver(d, i, vertici);//avvia la funzione commutazioni_ver
								parita=parita+1;//aggiorno il contatore delle parità
								break;//esce dal for (spero lo faccia)
							}
							
						}
					}
				}
			}
		}
		
	}while(end!=1);
	if(parita%2==0){//se sono state eseguite un numero pari di commutazioni
		//non fa nulla
	}
	else if(parita%2==1){//se sono state eseguite un numero dispari di commutazioni --> svolge l'algoritmo di parità
		printf("3 move to sx\n action 270\n 3 move to sx\n action 270\n move to sx\n action 90\n rotate 90\n move to sx\n action 90\n");//stampa la funzione
		printf("3 move to sx\n action 270\n rotate 90\n move to sx\n action 180\n 3 move to sx\n action 90\n move to sx\n action 180\n");//stampa la funzione
		printf("3 move to sx\n action 90\n rotate 90\n 3 move to sx\n action 270\n move to sx\n action 270\n rotate 90\n 3 move to sx\n");//stampa la funzione
		printf("action 270\n move to sx\n action 270\n 3 move to sx\n action 180\n move to sx\n action 90\n 3 move to sx\n action 90\n 2 move to sx\n");//stampa la funzione
	}
	return 0;
}
