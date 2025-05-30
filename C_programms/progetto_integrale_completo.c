#include <stdio.h>
#include <stdlib.h>

/*Questa funzione serve a permutare i vertici di buffer con quello da sistemare*/
int perm(){//perm che scambia ilvertice di buffer con quello preso in considerazione 
	printf("3 move to sx\n action 270\n 3 move to sx\n action 90\n move to sx\n action 90\n 3 move to sx\n action 90\n move to sx\n");//stampa la funzione
	printf("action 270\n 3 move to sx\n action 270\n move to sx\n action 90\n rotate 90\n move to sx\n action 90\n 3 move to sx\n");//stampa la funzione 
	printf("action 270\n rotate 90\n move to sx\n action 270\n 3 move to sx\n action 90\n move to sx\n action 90\n 3 move to sx\n");//stampa la funzione
	printf("action 90\n rotate 90\n 3 move to sx\n action 270\n move to sx\n action 270\n rotate 90\n move to sx\n ");//stampa la funzione
}
/*Questa funzione serve a permutare veramente le informazioni dei vertici e stampa le informazioni che servono a spostare i singoli vertici*/
int commutazioni_ver(int d, int i, int vertici_ins[8][3]){//parte di programma che identifica come permutare ogni singolo vertice in base alla posizione e che mi restituirÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â  l'informazione per risolvere i vertici uno ad uno
	int a=0;//variabile che conterrÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â  l'informazione da mettere
	int b=0;//variabile che conterrÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â  l'informazione del buffer
	if(d==0){//se la prima posizione scombinata che troviamo ÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â¨ quella relativa alla prima postazione codificata del vertice
		switch(i){
			case 0:{//se i ÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â¨ uguale a 0 (impossibile ma la mettiamo lo stesso, non puÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â² commutare la stessa zona di buffer), avvia la risoluzione per la posizione "a"
				printf("error\n");//stampa errore
				break;//esce dallo switch
			}
			case 1:{//se i ÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â¨ uguale a 1, avvia la risoluzione per la posizione "b"
				a=vertici_ins[0][0];//associo ad a la prima informazione di buffer
				b=vertici_ins[i][d];//associo a b l'informazione della zona "b"
				vertici_ins[0][0]=b;//metto in prima zona buffer l'informazione della zona "b"
				vertici_ins[i][d]=a;//metto in zona "b" la prima informazione di buffer
				a=vertici_ins[0][1];//associo ad a la seconda informazione di buffer
				b=vertici_ins[i][2];//associo a b l'informazione della zona "j"
				vertici_ins[0][1]=b;//metto in prima zona buffer l'informazione della zona "j"
				vertici_ins[i][2]=a;//metto in zona "j" la seconda informazione di buffer
				a=vertici_ins[0][2];//associo ad a l'ultima informazione di buffer
				b=vertici_ins[i][1];//associo a b l'informazione della zona "m"
				vertici_ins[0][2]=b;//metto in ultima zona buffer l'informazione della zona "m"
				vertici_ins[i][1]=a;//metto in zona "m" l'ultima informazione di buffer
				printf("3 move to sx\n action 270\n move to sx\n action 90\n");//stampa i movimenti per portare l'obiettivo
				perm();//stampa la permutazione dei vertici
				printf("action 270\n 3 move to sx\n action 90\n move to sx\n");//stampa i movimenti per portare l'obiettivo a posto
				break;//esce dallo switch
			}
			case 2:{//se i ÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â¨ uguale a 2, avvia la risoluzione per la posizione "c"
				a=vertici_ins[0][0];//associo ad a la prima informazione di buffer
				b=vertici_ins[i][d];//associo a b l'informazione della zona "c"
				vertici_ins[0][0]=b;//metto in prima zona buffer l'informazione della zona "c"
				vertici_ins[i][d]=a;//metto in zona "c" la prima informazione di buffer
				a=vertici_ins[0][1];//associo ad a la seconda informazione di buffer
				b=vertici_ins[i][2];//associo a b l'informazione della zona "f"
				vertici_ins[0][1]=b;//metto in seconda zona buffer l'informazione della zona "f"
				vertici_ins[i][2]=a;//metto in zona "f" la seconda informazione di buffer
				a=vertici_ins[0][2];//associo ad a l'ultima informazione di buffer
				b=vertici_ins[i][1];//associo a b l'informazione della zona "i"
				vertici_ins[0][2]=b;//metto in ultima zona buffer l'informazione della zona "i"
				vertici_ins[i][1]=a;//metto in zona "i" l'ultima informazione di buffer
				printf("rotate 90\n move to sx\n action 270\n 3 move to sx\n rotate 270\n");//stampa i movimenti per portare l'obiettivo
				perm();//stampa la permutazione dei vertici
				printf("rotate 90\n move to sx\n action 90\n 3 move to sx\n rotate 270\n ");//stampa i movimenti per portare l'obiettivo a posto
				break;//esce dallo switch
			}
			case 3:{//se i ÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â¨ uguale a 3, avvia la risoluzione per la posizione "d"
				a=vertici_ins[0][0];//associo ad a la prima informazione di buffer
				b=vertici_ins[i][d];//associo a b l'informazione della zona "d"
				vertici_ins[0][0]=b;//metto in prima zona buffer l'informazione della zona "d"
				vertici_ins[i][d]=a;//metto in zona "d" la prima informazione di buffer
				a=vertici_ins[0][1];//associo ad a la seconda informazione di buffer
				b=vertici_ins[i][2];//associo a b l'informazione della zona "r"
				vertici_ins[0][1]=b;//metto in seconda zona buffer l'informazione della zona "r"
				vertici_ins[i][2]=a;//metto in zona "r" la seconda informazione di buffer
				a=vertici_ins[0][2];//associo ad a l'ultima informazione di buffer
				b=vertici_ins[i][1];//associo a b l'informazione della zona "e"
				vertici_ins[0][2]=b;//metto in ultima zona buffer l'informazione della zona "e"
				vertici_ins[i][1]=a;//metto in zona "e" l'ultima informazione di buffer
				printf("rotate 90\n move to sx\n action 270\n rotate 90\n move to sx\n action 90\n rotate 90\n move to sx\n");//stampa i movimenti per portare l'obiettivo
				perm();//stampa la permutazione dei vertici
				printf("3 move to sx\n rotate 270\n action 270\n 3 move to sx\n rotate 270\n action 90\n 3 move to sx\n rotate 270\n");//stampa i movimenti per portare l'obiettivo a posto
				break;//esce dallo switch
			}
			case 4:{//se i ÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â¨ uguale a 4, avvia la risoluzione per la posizione "o"
				a=vertici_ins[0][0];//associo ad a la prima informazione di buffer
				b=vertici_ins[i][d];//associo a b l'informazione della zona "o"
				vertici_ins[0][0]=b;//metto in prima zona buffer l'informazione della zona "o"
				vertici_ins[i][d]=a;//metto in zona "o" la prima informazione di buffer
				a=vertici_ins[0][1];//associo ad a la seconda informazione di buffer
				b=vertici_ins[i][2];//associo a b l'informazione della zona "z"
				vertici_ins[0][1]=b;//metto in seconda zona buffer l'informazione della zona "z"
				vertici_ins[i][2]=a;//metto in zona "z" la seconda informazione di buffer
				a=vertici_ins[0][2];//associo ad a l'ultima informazione di buffer
				b=vertici_ins[i][1];//associo a b l'informazione della zona "t"
				vertici_ins[0][2]=b;//metto in ultima zona buffer l'informazione della zona "t"
				vertici_ins[i][1]=a;//metto in zona "t" l'ultima informazione di buffer
				printf("action 90\n 3 move to sx\n action 270\n move to sx\n");//stampa i movimenti per portare l'obiettivo
				perm();//stampa la permutazione dei vertici
				printf("3 move to sx\n action 90\n move to sx\n action 270\n");//stampa i movimenti per portare l'obiettivo a posto
				break;//esce dallo switch
			}
			case 5:{//se i ÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â¨ uguale a 5, avvia la risoluzione per la posizione "k"
				a=vertici_ins[0][0];//associo ad a la prima informazione di buffer
				b=vertici_ins[i][d];//associo a b l'informazione della zona "k"
				vertici_ins[0][0]=b;//metto in prima zona buffer l'informazione della zona "k"
				vertici_ins[i][d]=a;//metto in zona "k" la prima informazione di buffer			
				a=vertici_ins[0][1];//associo ad a la seconda informazione di buffer
				b=vertici_ins[i][2];//associo a b l'informazione della zona "x"
				vertici_ins[0][1]=b;//metto in seconda zona buffer l'informazione della zona "x"
				vertici_ins[i][2]=a;//metto in zona "x" la seconda informazione di buffer
				a=vertici_ins[0][2];//associo ad a l'ultima informazione di buffer
				b=vertici_ins[i][1];//associo a b l'informazione della zona "p"
				vertici_ins[0][2]=b;//metto in ultima zona buffer l'informazione della zona "p"
				vertici_ins[i][1]=a;//metto in zona "p" l'ultima informazione di buffer
				printf("3 move to sx\n action 270\n move to sx\n");//stampa i movimenti per portare l'obiettivo
				perm();//stampa la permutazione dei vertici
				printf("3 move to sx\n action 90\n move to sx\n");//stampa i movimenti per portare l'obiettivo a posto
				break;//esce dallo switch
			}
			case 6:{//se i ÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â¨ uguale a 6, avvia la risoluzione per la posizione "g"
				a=vertici_ins[0][0];//associo ad a la prima informazione di buffer
				b=vertici_ins[i][d];//associo a b l'informazione della zona "g"
				vertici_ins[0][0]=b;//metto in prima zona buffer l'informazione della zona "g"
				vertici_ins[i][d]=a;//metto in zona "g" la prima informazione di buffer
				a=vertici_ins[0][1];//associo ad a la seconda informazione di buffer
				b=vertici_ins[i][2];//associo a b l'informazione della zona "v"
				vertici_ins[0][1]=b;//metto in seconda zona buffer l'informazione della zona "v"
				vertici_ins[i][2]=a;//metto in zona "v" la seconda informazione di buffer				
				a=vertici_ins[0][2];//associo ad a l'ultima informazione di buffer
				b=vertici_ins[i][1];//associo a b l'informazione della zona "l"
				vertici_ins[0][2]=b;//metto in ultima zona buffer l'informazione della zona "l"
				vertici_ins[i][1]=a;//metto in zona "l" l'ultima informazione di buffer
				printf("rotate 90\n move to sx\n action 270\n 3 move to sx\n action 270\n rotate 270\n");//stampa i movimenti per portare l'obiettivo
				perm();//stampa la permutazione dei vertici
				printf("rotate 90\n action 90\n move to sx\n action 90\n 3 move to sx\n rotate 270\n ");//stampa i movimenti per portare l'obiettivo a posto
				break;//esce dallo switch
			}
			case 7:{//se i ÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â¨ uguale a 7, avvia la risoluzione per la posizione "h"
				a=vertici_ins[0][0];//associo ad a la prima informazione di buffer
				b=vertici_ins[i][d];//associo a b l'informazione della zona "h"
				vertici_ins[0][0]=b;//metto in prima zona buffer l'informazione della zona "h"
				vertici_ins[i][d]=a;//metto in zona "h" la prima informazione di buffer				
				a=vertici_ins[0][1];//associo ad a la seconda informazione di buffer
				b=vertici_ins[i][1];//associo a b l'informazione della zona "s"
				vertici_ins[0][1]=b;//metto in seconda zona buffer l'informazione della zona "s"
				vertici_ins[i][1]=a;//metto in zona "s" la seconda informazione di buffer			
				a=vertici_ins[0][2];//associo ad a l'ultima informazione di buffer
				b=vertici_ins[i][2];//associo a b l'informazione della zona "u"
				vertici_ins[0][2]=b;//metto in ultima zona buffer l'informazione della zona "u"
				vertici_ins[i][2]=a;//metto in zona "u" l'ultima informazione di buffer
				printf("action 270\n");//stampa i movimenti per portare l'obiettivo
				perm();//stampa la permutazione dei vertici
				printf("action 90\n");//stampa i movimenti per portare l'obiettivo a posto
				break;//esce dallo switch
			}
			default: //se in i c'ÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â¨ qualcosa di diverso da questi caratteri
				printf("errore\n");
				break;//esce dallo switch
			
		}
	}
	
	else if  (d==1){//se la prima posizione scombinata che troviamo ÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â¨ quella relativa alla seconda postazione codificata del vertice
		switch(i){
			case 0:{//se i ÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â¨ uguale a 0 (impossibile ma la mettiamo lo stesso, non puÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â² commutare la stessa zona di buffer), avvia la risoluzione per la posizione "n"
				printf("error\n");//stampa errore
				break;//esce dallo switch
			}
			case 1:{//se i ÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â¨ uguale a 1, avvia la risoluzione per la posizione "m"
				a=vertici_ins[0][0];//associo ad a la prima informazione di buffer
				b=vertici_ins[i][d];//associo a b l'informazione della zona "m"
				vertici_ins[0][0]=b;//metto in prima zona buffer l'informazione della zona "m"
				vertici_ins[i][d]=a;//metto in zona "m" la prima informazione di buffer				
				a=vertici_ins[0][1];//associo ad a la seconda informazione di buffer
				b=vertici_ins[i][0];//associo a b l'informazione della zona "b"
				vertici_ins[0][1]=b;//metto in prima zona buffer l'informazione della zona "b"
				vertici_ins[i][0]=a;//metto in zona "b" la seconda informazione di buffer		
				a=vertici_ins[0][2];//associo ad a l'ultima informazione di buffer
				b=vertici_ins[i][2];//associo a b l'informazione della zona "j"
				vertici_ins[0][2]=b;//metto in ultima zona buffer l'informazione della zona "j"
				vertici_ins[i][2]=a;//metto in zona "j" l'ultima informazione di buffer
				printf("3 move to sx\n action 90\n rotate 90\n move to sx\n action 270\n rotate 90\n 3 move to sx\n rotate 270\n");//stampa i movimenti per portare l'obiettivo
				perm();//stampa la permutazione dei vertici
				printf("rotate 90\n move to sx\n rotate 270\n action 90\n 3 move to sx\n rotate 270\n action 270\n move to sx\n");//stampa i movimenti per portare l'obiettivo a posto
				break;//esce dallo switch
			}
			case 2:{//se i ÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â¨ uguale a 2, avvia la risoluzione per la posizione "i"
				a=vertici_ins[0][0];//associo ad a la prima informazione di buffer
				b=vertici_ins[i][d];//associo a b l'informazione della zona "i"
				vertici_ins[0][0]=b;//metto in prima zona buffer l'informazione della zona "i"
				vertici_ins[i][d]=a;//metto in zona "i" la prima informazione di buffer					
				a=vertici_ins[0][1];//associo ad a la seconda informazione di buffer
				b=vertici_ins[i][0];//associo a b l'informazione della zona "c"
				vertici_ins[0][1]=b;//metto in prima zona buffer l'informazione della zona "c"
				vertici_ins[i][0]=a;//metto in zona "c" la seconda informazione di buffer			
				a=vertici_ins[0][2];//associo ad a l'ultima informazione di buffer
				b=vertici_ins[i][2];//associo a b l'informazione della zona "f"
				vertici_ins[0][2]=b;//metto in ultima zona buffer l'informazione della zona "f"
				vertici_ins[i][2]=a;//metto in zona "f" l'ultima informazione di buffer
				printf("3 move to sx\n action 90\n move to sx\n ");//stampa i movimenti per portare l'obiettivo
				perm();//stampa la permutazione dei vertici
				printf("3 move to sx\n action 270\n move to sx\n");//stampa i movimenti per portare l'obiettivo a posto
				break;//esce dallo switch
			}
			case 3:{//se i ÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â¨ uguale a 3, avvia la risoluzione per la posizione "e"
				a=vertici_ins[0][0];//associo ad a la prima informazione di buffer
				b=vertici_ins[i][d];//associo a b l'informazione della zona "e"
				vertici_ins[0][0]=b;//metto in prima zona buffer l'informazione della zona "e"
				vertici_ins[i][d]=a;//metto in zona "e" la prima informazione di buffer						
				a=vertici_ins[0][1];//associo ad a la seconda informazione di buffer
				b=vertici_ins[i][0];//associo a b l'informazione della zona "d"
				vertici_ins[0][1]=b;//metto in prima zona buffer l'informazione della zona "d"
				vertici_ins[i][0]=a;//metto in zona "d" la seconda informazione di buffer				
				a=vertici_ins[0][2];//associo ad a l'ultima informazione di buffer
				b=vertici_ins[i][2];//associo a b l'informazione della zona "r"
				vertici_ins[0][2]=b;//metto in ultima zona buffer l'informazione della zona "r"
				vertici_ins[i][2]=a;//metto in zona "r" l'ultima informazione di buffer
				printf("rotate 90\n move to sx\n action 90\n 3 move to sx\n action 270\n rotate 270\n");//stampa i movimenti per portare l'obiettivo
				perm();//stampa la permutazione dei vertici
				printf("rotate 90\n action 90\n move to sx\n action 270\n 3 move to sx\n rotate 270\n");//stampa i movimenti per portare l'obiettivo a posto
				break;//esce dallo switch
			}
			case 4:{//se i ÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â¨ uguale a 4, avvia la risoluzione per la posizione "t"
				a=vertici_ins[0][0];//associo ad a la prima informazione di buffer
				b=vertici_ins[i][d];//associo a b l'informazione della zona "t"
				vertici_ins[0][0]=b;//metto in prima zona buffer l'informazione della zona "t"
				vertici_ins[i][d]=a;//metto in zona "t" la prima informazione di buffer							
				a=vertici_ins[0][1];//associo ad a la seconda informazione di buffer
				b=vertici_ins[i][0];//associo a b l'informazione della zona "o"
				vertici_ins[0][1]=b;//metto in prima zona buffer l'informazione della zona "o"
				vertici_ins[i][0]=a;//metto in zona "o" la seconda informazione di buffer				
				a=vertici_ins[0][2];//associo ad a l'ultima informazione di buffer
				b=vertici_ins[i][2];//associo a b l'informazione della zona "z"
				vertici_ins[0][2]=b;//metto in ultima zona buffer l'informazione della zona "z"
				vertici_ins[i][2]=a;//metto in zona "z" l'ultima informazione di buffer
				printf("action 180\n");//stampa i movimenti per portare l'obiettivo
				perm();//stampa la permutazione dei vertici
				printf("action 180\n");//stampa i movimenti per portare l'obiettivo a posto
				break;//esce dallo switch
			}
			case 5:{//se i ÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â¨ uguale a 5, avvia la risoluzione per la posizione "p"
				a=vertici_ins[0][0];//associo ad a la prima informazione di buffer
				b=vertici_ins[i][d];//associo a b l'informazione della zona "p"
				vertici_ins[0][0]=b;//metto in prima zona buffer l'informazione della zona "p"
				vertici_ins[i][d]=a;//metto in zona "p" la prima informazione di buffer								
				a=vertici_ins[0][1];//associo ad a la seconda informazione di buffer
				b=vertici_ins[i][0];//associo a b l'informazione della zona "k"
				vertici_ins[0][1]=b;//metto in prima zona buffer l'informazione della zona "k"
				vertici_ins[i][0]=a;//metto in zona "k" la seconda informazione di buffer					
				a=vertici_ins[0][2];//associo ad a l'ultima informazione di buffer
				b=vertici_ins[i][2];//associo a b l'informazione della zona "x"
				vertici_ins[0][2]=b;//metto in ultima zona buffer l'informazione della zona "x"
				vertici_ins[i][2]=a;//metto in zona "x" l'ultima informazione di buffer
				printf("action 90\n");//stampa i movimenti per portare l'obiettivo
				perm();//stampa la permutazione dei vertici
				printf("action 270\n");//stampa i movimenti per portare l'obiettivo a posto
				break;//esce dallo switch
			}
			case 6:{//se i ÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â¨ uguale a 6, avvia la risoluzione per la posizione "l"
				a=vertici_ins[0][0];//associo ad a la prima informazione di buffer
				b=vertici_ins[i][d];//associo a b l'informazione della zona "l"
				vertici_ins[0][0]=b;//metto in prima zona buffer l'informazione della zona "l"
				vertici_ins[i][d]=a;//metto in zona "l" la prima informazione di buffer			
				a=vertici_ins[0][1];//associo ad a la seconda informazione di buffer
				b=vertici_ins[i][0];//associo a b l'informazione della zona "g"
				vertici_ins[0][1]=b;//metto in prima zona buffer l'informazione della zona "g"
				vertici_ins[i][0]=a;//metto in zona "g" la seconda informazione di buffer		
				a=vertici_ins[0][2];//associo ad a l'ultima informazione di buffer
				b=vertici_ins[i][2];//associo a b l'informazione della zona "v"
				vertici_ins[0][2]=b;//metto in ultima zona buffer l'informazione della zona "v"
				vertici_ins[i][2]=a;//metto in zona "v" l'ultima informazione di buffer
				//cubo giÃƒÆ’Ã‚Â  in posizione
				perm();//stampa la permutazione dei vertici
				//cubo giÃƒÆ’Ã‚Â  rimesso a posto
				break;//esce dallo switch
			}
			case 7:{//se i ÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â¨ uguale a 7, avvia la risoluzione per la posizione "s"
				a=vertici_ins[0][0];//associo ad a la prima informazione di buffer
				b=vertici_ins[i][d];//associo a b l'informazione della zona "s"
				vertici_ins[0][0]=b;//metto in prima zona buffer l'informazione della zona "s"
				vertici_ins[i][d]=a;//metto in zona "s" la prima informazione di buffer				
				a=vertici_ins[0][1];//associo ad a la seconda informazione di buffer
				b=vertici_ins[i][2];//associo a b l'informazione della zona "u"
				vertici_ins[0][1]=b;//metto in prima zona buffer l'informazione della zona "u"
				vertici_ins[i][2]=a;//metto in zona "u" la seconda informazione di buffer		
				a=vertici_ins[0][2];//associo ad a l'ultima informazione di buffer
				b=vertici_ins[i][0];//associo a b l'informazione della zona "h"
				vertici_ins[0][2]=b;//metto in ultima zona buffer l'informazione della zona "h"
				vertici_ins[i][0]=a;//metto in zona "h" l'ultima informazione di buffer
				printf("rotate 90\n move to sx\n action 180\n rotate 90\n move to sx\n action 90\n rotate 90\n move to sx\n");//stampa i movimenti per portare l'obiettivo
				perm();//stampa la permutazione dei vertici
				printf("3 move to sx\n rotate 270\n action 270\n 3 move to sx\n rotate 270\n action 180\n 3 move to sx\n rotate 270\n");//stampa i movimenti per portare l'obiettivo a posto
				break;//esce dallo switch
			}
			default: //se in i c'ÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â¨ qualcosa di diverso da questi caratteri
				printf("errore\n");
				break;//esce dallo switch
		}
	}
	
	else if(d==2){//se la prima posizione scombinata che troviamo ÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â¨ quella relativa all'ultima postazione codificata del vertice
		switch(i){
			case 0:{//se i ÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â¨ uguale a 0 (impossibile ma la mettiamo lo stesso, non puÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â² commutare la stessa zona di buffer), avvia la risoluzione per la posizione "q"
				printf("error\n");//stampa errore
				break;//esce dallo switch
			}
			case 1:{//se i ÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â¨ uguale a 1, avvia la risoluzione per la posizione "j"
				a=vertici_ins[0][0];//associo ad a la prima informazione di buffer
				b=vertici_ins[i][d];//associo a b l'informazione della zona "j"
				vertici_ins[0][0]=b;//metto in prima zona buffer l'informazione della zona "j"
				vertici_ins[i][d]=a;//metto in zona "j" la prima informazione di buffer								
				a=vertici_ins[0][1];//associo ad a la seconda informazione di buffer
				b=vertici_ins[i][1];//associo a b l'informazione della zona "m"
				vertici_ins[0][1]=b;//metto in prima zona buffer l'informazione della zona "m"
				vertici_ins[i][1]=a;//metto in zona "m" la seconda informazione di buffer		
				a=vertici_ins[0][2];//associo ad a l'ultima informazione di buffer
				b=vertici_ins[i][0];//associo a b l'informazione della zona "b"
				vertici_ins[0][2]=b;//metto in ultima zona buffer l'informazione della zona "b"
				vertici_ins[i][0]=a;//metto in zona "b" l'ultima informazione di buffer
				printf("3 move to sx\n action 180\n move to sx\n");//stampa i movimenti per portare l'obiettivo
				perm();//stampa la permutazione dei vertici
				printf("3 move to sx\n action 180\n move to sx\n");//stampa i movimenti per portare l'obiettivo a posto
				break;//esce dallo switch
			}
			case 2:{//se i ÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â¨ uguale a 2, avvia la risoluzione per la posizione "f"
				a=vertici_ins[0][0];//associo ad a la prima informazione di buffer
				b=vertici_ins[i][d];//associo a b l'informazione della zona "f"
				vertici_ins[0][0]=b;//metto in prima zona buffer l'informazione della zona "f"
				vertici_ins[i][d]=a;//metto in zona "f" la prima informazione di buffer								
				a=vertici_ins[0][1];//associo ad a la seconda informazione di buffer
				b=vertici_ins[i][1];//associo a b l'informazione della zona "i"
				vertici_ins[0][1]=b;//metto in prima zona buffer l'informazione della zona "i"
				vertici_ins[i][1]=a;//metto in zona "i" la seconda informazione di buffer		
				a=vertici_ins[0][2];//associo ad a l'ultima informazione di buffer
				b=vertici_ins[i][0];//associo a b l'informazione della zona "c"
				vertici_ins[0][2]=b;//metto in ultima zona buffer l'informazione della zona "c"
				vertici_ins[i][0]=a;//metto in zona "c" l'ultima informazione di buffer
				printf("3 move to sx\n action 180\n move to sx\n action 90\n");//stampa i movimenti per portare l'obiettivo
				perm();//stampa la permutazione dei vertici
				printf("action 270\n 3 move to sx\n action 180\n move to sx\n");//stampa i movimenti per portare l'obiettivo a posto
				break;//esce dallo switch
			}
			case 3:{//se i ÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â¨ uguale a 3, avvia la risoluzione per la posizione "r"
				a=vertici_ins[0][0];//associo ad a la prima informazione di buffer
				b=vertici_ins[i][d];//associo a b l'informazione della zona "r"
				vertici_ins[0][0]=b;//metto in prima zona buffer l'informazione della zona "r"
				vertici_ins[i][d]=a;//metto in zona "r" la prima informazione di buffer						
				a=vertici_ins[0][1];//associo ad a la seconda informazione di buffer
				b=vertici_ins[i][1];//associo a b l'informazione della zona "e"
				vertici_ins[0][1]=b;//metto in prima zona buffer l'informazione della zona "e"
				vertici_ins[i][1]=a;//metto in zona "e" la seconda informazione di buffer		
				a=vertici_ins[0][2];//associo ad a l'ultima informazione di buffer
				b=vertici_ins[i][0];//associo a b l'informazione della zona "d"
				vertici_ins[0][2]=b;//metto in ultima zona buffer l'informazione della zona "d"
				vertici_ins[i][0]=a;//metto in zona "d" l'ultima informazione di buffer
				printf("rotate 90\n move to sx\n action 180\n 3 move to sx\n rotate 270\n");//stampa i movimenti per portare l'obiettivo
				perm();//stampa la permutazione dei vertici
				printf("rotate 90\n move to sx\n action 180\n 3 move to sx\nrotate 270\n");//stampa i movimenti per portare l'obiettivo a posto
				break;//esce dallo switch
			}
			case 4:{//se i ÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â¨ uguale a 4, avvia la risoluzione per la posizione "z"
				a=vertici_ins[0][0];//associo ad a la prima informazione di buffer
				b=vertici_ins[i][d];//associo a b l'informazione della zona "z"
				vertici_ins[0][0]=b;//metto in prima zona buffer l'informazione della zona "z"
				vertici_ins[i][d]=a;//metto in zona "z" la prima informazione di buffer											
				a=vertici_ins[0][1];//associo ad a la seconda informazione di buffer
				b=vertici_ins[i][1];//associo a b l'informazione della zona "t"
				vertici_ins[0][1]=b;//metto in prima zona buffer l'informazione della zona "t"
				vertici_ins[i][1]=a;//metto in zona "t" la seconda informazione di buffer					
				a=vertici_ins[0][2];//associo ad a l'ultima informazione di buffer
				b=vertici_ins[i][0];//associo a b l'informazione della zona "o"
				vertici_ins[0][2]=b;//metto in ultima zona buffer l'informazione della zona "o"
				vertici_ins[i][0]=a;//metto in zona "o" l'ultima informazione di buffer
				printf("action 270\n rotate 90\n move to sx\n action 90\n 3 move to sx\n rotate 270\n");//stampa i movimenti per portare l'obiettivo
				perm();//stampa la permutazione dei vertici
				printf("rotate 90\n move to sx\n action 270\n 3 move to sx\n rotate 270\n action 90\n");//stampa i movimenti per portare l'obiettivo a posto
				break;//esce dallo switch
			}
			case 5:{//se i ÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â¨ uguale a 5, avvia la risoluzione per la posizione "x"
				a=vertici_ins[0][0];//associo ad a la prima informazione di buffer
				b=vertici_ins[i][d];//associo a b l'informazione della zona "x"
				vertici_ins[0][0]=b;//metto in prima zona buffer l'informazione della zona "x"
				vertici_ins[i][d]=a;//metto in zona "x" la prima informazione di buffer											
				a=vertici_ins[0][1];//associo ad a la seconda informazione di buffer
				b=vertici_ins[i][1];//associo a b l'informazione della zona "p"
				vertici_ins[0][1]=b;//metto in prima zona buffer l'informazione della zona "p"
				vertici_ins[i][1]=a;//metto in zona "p" la seconda informazione di buffer					
				a=vertici_ins[0][2];//associo ad a l'ultima informazione di buffer
				b=vertici_ins[i][0];//associo a b l'informazione della zona "k"
				vertici_ins[0][2]=b;//metto in ultima zona buffer l'informazione della zona "k"
				vertici_ins[i][0]=a;//metto in zona "k" l'ultima informazione di buffer
				printf("3 move to sx\n action 180\n rotate 90\n move to sx\n action 270\n move to sx\n rotate 90\n 3 move to sx\n");//stampa i movimenti per portare l'obiettivo
				perm();//stampa la permutazione dei vertici
				printf("move to sx\n rotate 270\n 3 move to sx\n action 90\n 3 move to sx\n rotate 270\n action 180\n move to sx\n");//stampa i movimenti per portare l'obiettivo a posto
				break;//esce dallo switch
			}
			case 6:{//se i ÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â¨ uguale a 6, avvia la risoluzione per la posizione "v"
				a=vertici_ins[0][0];//associo ad a la prima informazione di buffer
				b=vertici_ins[i][d];//associo a b l'informazione della zona "v"
				vertici_ins[0][0]=b;//metto in prima zona buffer l'informazione della zona "v"
				vertici_ins[i][d]=a;//metto in zona "v" la prima informazione di buffer											
				a=vertici_ins[0][1];//associo ad a la seconda informazione di buffer
				b=vertici_ins[i][1];//associo a b l'informazione della zona "l"
				vertici_ins[0][1]=b;//metto in prima zona buffer l'informazione della zona "l"
				vertici_ins[i][1]=a;//metto in zona "l" la seconda informazione di buffer					
				a=vertici_ins[0][2];//associo ad a l'ultima informazione di buffer
				b=vertici_ins[i][0];//associo a b l'informazione della zona "g"
				vertici_ins[0][2]=b;//metto in ultima zona buffer l'informazione della zona "g"
				vertici_ins[i][0]=a;//metto in zona "g" l'ultima informazione di buffer
				printf("rotate 90\n move to sx\n action 90\n rotate 90\n move to sx\n action 90\n rotate 90\n move to sx\n");//stampa i movimenti per portare l'obiettivo
				perm();//stampa la permutazione dei vertici
				printf("3 move to sx\n rotate 270\n action 270\n 3 move to sx\n rotate 270\n action 270\n 3 move to sx\n rotate 270\n");//stampa i movimenti per portare l'obiettivo a posto
				break;//esce dallo switch
			}
			case 7:{//se i ÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â¨ uguale a 7, avvia la risoluzione per la posizione "u"
				a=vertici_ins[0][0];//associo ad a la prima informazione di buffer
				b=vertici_ins[i][d];//associo a b l'informazione della zona "u"
				vertici_ins[0][0]=b;//metto in prima zona buffer l'informazione della zona "u"
				vertici_ins[i][d]=a;//metto in zona "u" la prima informazione di buffer											
				a=vertici_ins[0][1];//associo ad a la seconda informazione di buffer
				b=vertici_ins[i][0];//associo a b l'informazione della zona "h"
				vertici_ins[0][1]=b;//metto in prima zona buffer l'informazione della zona "h"
				vertici_ins[i][0]=a;//metto in zona "h" la seconda informazione di buffer		
				a=vertici_ins[0][2];//associo ad a l'ultima informazione di buffer
				b=vertici_ins[i][1];//associo a b l'informazione della zona "s"
				vertici_ins[0][2]=b;//metto in ultima zona buffer l'informazione della zona "s"
				vertici_ins[i][1]=a;//metto in zona "s" l'ultima informazione di buffer
				printf("rotate 90\n move to sx\n action 90\n move to sx\n rotate 90\n 2 move to sx\n");//stampa i movimenti per portare l'obiettivo
				perm();//stampa la permutazione dei vertici
				printf("2 move to sx\n rotate 270\n 3 move to sx\n action 270\n 3 move to sx\n rotate 270\n");//stampa i movimenti per portare l'obiettivo a posto
				break;//esce dallo switch
			}
			default: //se in i c'ÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â¨ qualcosa di diverso da questi caratteri
				printf("errore\n");
				break;//esce dallo switch
		}
	}
	return 0;	
}
//Questa funzione serve a permutare il lato di buffer con quello da sistemare
int t_perm(){//funzione che stampa le mosse che svolgono la T perm
	printf("3 move to sx\n action 270\n 3 move to sx\n action 270\n move to sx\n action 90\n 3 move to sx\n");//stampa la funzione
	printf("action 90\n move to sx\n action 90\n rotate 90\n move to sx\n action 270\n rotate 90\n");//stampa la funzione
	printf("move to sx\n rotate 90\n move to sx\n action 180\n 3 move to sx\n action 90\n move to sx\n");//stampa la funzione
	printf("action 90\n 3 move to sx\n action 90\n move to sx\n action 270\n 3 move to sx\n action 270\n");//stampa la funzione
	printf("move to sx\n action 90\n rotate 90\n move to sx\n action 90\n rotate 90\n 3 move to sx\n rotate 270\n\n");//stampa la funzione
}
//questa funzione serve a commutare e sistemare veramente i lati, stampando le informazioni utili al robot per risolverlo
int commutazioni(int d, int i){//funzione per togliere moltre stringhe di codice per capire quale ciclo sta facendo per risolvere il cubo
	if(d==0){//se la posizione scombinata ÃƒÆ’Ã‚Â¨ quella della prima informazione della cella
		switch(i){
			case 0:{//se i ÃƒÆ’Ã‚Â¨ uguale a 0, si avvia la risoluzione per la posizione a
				printf("3 move to sx\n action 180\n rotate 180\n move to sx\n action 90\n move to sx\n action 180\n 3 move to sx\n\n");//stampa i movimenti per portare l'obbiettivo
				t_perm();//svolge la t perm
				printf("rotate to sx\n action 180\n 3 move to sx\n action 270\n 3 move to sx\n rotate 180\n action 180\n rotate to sx\n\n");//stampa i movimenti per portare l'obbiettivo a posto
				break;//esce dallo switch
			}
			case 1:{//se i ÃƒÆ’Ã‚Â¨ uguale a 1 (impossibile ma la mettiamo lo stesso), avvia la risoluzione per la posizione b
				printf("error\n");//stampa errore
				break;//esce dallo switch
			}
			case 2:{//se i ÃƒÆ’Ã‚Â¨ uguale a 2,si avvia la risoluzione per la posizione c
				printf("3 move to sx\n action 180\n rotate 180\n move to sx\n action 270\n move to sx\n action 180\n 3 move to sx\n\n");//stampa i movimenti per portare l'obbiettivo
				t_perm();//svolge la t perm
				printf("move to sx\n action 180\n 3 move to sx\n action 90\n 3 move to sx\n rotate 180\n action 180\n move to sx\n\n");//stampa i movimenti per portare l'obbiettivo a posto
				break;//esce dallo switch
			}
			case 3:{//se i ÃƒÆ’Ã‚Â¨ uguale a 3, si avvia la risoluzione per la posizione d
				t_perm();//svolge la t perm
				break;//esce dallo switch
			}
			case 4:{//se i ÃƒÆ’Ã‚Â¨ uguale a 4, si avvia la risoluzione per la posizione f
				printf("2 move to sx\n action 180\n move to sx\n action 270\n move to sx\n rotate 180\n\n");//stampa i movimenti per portare l'obbiettivo
				t_perm();//svolge la t perm
				printf("rotate 180\n 3 move to sx\n action 90\n 3 move to sx\n action 180\n 2 move to sx\n\n");//stampa i movimenti per portare l'obbiettivo a posto
				break;//esce dallo switch
			}
			case 5:{//se i ÃƒÆ’Ã‚Â¨ uguale a 5, si avvia la risoluzione per la posizione g
				printf("3 move to sx\n action 270\n rotate 90\n move to sx\n action 270\n move to sx\n action 180\n 3 move to sx\n\n");//stampa i movimenti per portare l'obbiettivo
				t_perm();//svolge la t perm
				printf("move to sx\n action 180\n 3 move to sx\n action 90\n 3 move to sx\n rotate 270\n action 90\n move to sx\n\n");//stampa i movimenti per portare l'obbiettivo a posto
				break;//esce dallo switch
			}
			case 6:{//se i ÃƒÆ’Ã‚Â¨ uguale a 6, si avvia la risoluzione per la posizione h
				printf("move to sx\n action 90\n 3 move to sx\n\n");//stampa i movimenti per portare l'obbiettivo
				t_perm();//svolge la t perm
				printf("move to sx\n action 270\n 3 move to sx\n\n");//stampa i movimenti per portare l'obbiettivo a posto
				break;//esce dallo switch
			}
			case 7:{//se i ÃƒÆ’Ã‚Â¨ uguale a 7, si avvia la risoluzione per la posizione j
				printf("2 move to sx\naction 270\n rotate 90\n 3 move to sx\n action 270\n 3 move to sx\n\n");//stampa i movimenti per portare l'obbiettivo
				t_perm();//svolge la t perm
				printf("move to sx\n action 90\n move to sx\n rotate 270\n action 90\n 2 move to sx\n\n");//stampa i movimenti per portare l'obbiettivo a posto
				break;//esce dallo switch
			}
			case 8:{//se i ÃƒÆ’Ã‚Â¨ uguale a 8, si avvia la risoluzione per la posizione k
				printf("action 90\n rotate 90\n move to sx\n action 270\n rotate 90\n 3 move to sx\n action 90\n move to sx\n action 90\n rotate 90\n move to sx\n rotate 90\n\n");//stampa i movimenti per portare l'obbiettivo
				t_perm();//svolge la t perm
				printf("rotate 270\n 3 move to sx\n rotate 270\n action 270\n 3 move to sx\n action 270\n move to sx\n rotate 270\n action 90\n 3 move to sx\n rotate 270\n action 270\n\n");//stampa i movimenti per portare l'obbiettivo a posto
				break;//esce dallo switch
			}
			case 9:{//se i ÃƒÆ’Ã‚Â¨ uguale a 9, si avvia la risoluzione per la posizione n
				printf("move to sx\n action 270\n 3 move to sx\n\n ");//stampa i movimenti per portare l'obbiettivo
				t_perm();//svolge la t perm
				printf("move to sx\n action 90\n 3 move to sx\n\n");//stampa i movimenti per portare l'obbiettivo a posto
				break;//esce dallo switch
			}
			case 10:{//se i ÃƒÆ’Ã‚Â¨ uguale a 10, si avvia la risoluzione per la posizione o
				printf("3 move to sx\n action 90\n rotate 90\n 3 move to sx\n action 90\n 3 move to sx\n action 180\n move to sx\n rotate 180\n\n");//stampa i movimenti per portare l'obbiettivo
				t_perm();//svolge la t perm
				printf("rotate 180\n 3 move to sx\n action 180\n move to sx\n action 270\n move to sx\n rotate 270\n action 270\n move to sx\n\n");//stampa i movimenti per portare l'obbiettivo a posto
				break;//esce dallo switch
			}
			case 11:{//se i ÃƒÆ’Ã‚Â¨ uguale a 11, si avvia la risoluzione per la posizione s
				printf("move to sx\n action 90\n move to sx\n action 90\n rotate 90\n move to sx\n action 270\n move to sx\n rotate 180\n\n");//stampa i movimenti per portare l'obbiettivo
				t_perm();//svolge la t perm
				printf("rotate 180\n 3 move to sx\n action 90\n 3 move to sx\n rotate 270\n action 270\n 3 move to sx\n action 270\n 3 move to sx\n\n");//stampa i movimenti per portare l'obbiettivo a posto
				break;//esce dallo switch
			}
			default: //se in i c'ÃƒÆ’Ã‚Â¨ qualcosa di diverso da questi caratteri
				printf("errore\n");
				break;//esce dallo switch				
		}
	}
	else if(d==1){//se la posizione scombinata ÃƒÆ’Ã‚Â¨ quella dell'ultima informazione della cella
		switch(i){
			case 0:{//se i ÃƒÆ’Ã‚Â¨ uguale a 0, si avvia la risoluzione per la posizione m
				printf("3 move to sx\n action 90\n rotate 90\n 3 move to sx\n action 270\n 3 move to sx\n action 180\n move to sx\n rotate 180\n\n");//stampa i movimenti per portare l'obbiettivo
				t_perm();//svolge la t perm
				printf("rotate 180\n 3 move to sx\n action 180\n move to sx\n action 90\n move to sx\n rotate 270\n action 270\n move to sx\n\n");//stampa i movimenti per portare l'obbiettivo a posto
				break;//esce dallo switch
			}
			case 1:{//se i ÃƒÆ’Ã‚Â¨ uguale a 1 (impossibile ma la mettiamo lo stesso), avvia la risoluzione per la posizione i
				printf("error\n");//stampa il cambiamento fatto per conoscere il ciclo della risoluzione del cubo
				break;//esce dallo switch
			}
			case 2:{//se i ÃƒÆ’Ã‚Â¨ uguale a 2, si avvia la risoluzione per la posizione e
				printf("3 move to sx\n action 270\n rotate 90\n move to sx\n action 90\n move to sx\n action 180\n 3 move to sx\n\n");//stampa i movimenti per portare l'obbiettivo
				t_perm();//svolge la t perm
				printf("move to sx\n action 180\n 3 move to sx\n action 270\n 3 move to sx\n rotate 270\n action 90\n move to sx\n\n");//stampa i movimenti per portare l'obbiettivo a posto
				break;//esce dallo switch
			}
			case 3:{//se i ÃƒÆ’Ã‚Â¨ uguale a 3, si avvia la risoluzione per la posizione q
				printf("move to sx\n action 270\n move to sx\n action 90\n rotate 90\n move to sx\n action 270\n move to sx\n rotate 180\n\n");//stampa i movimenti per portare l'obbiettivo
				t_perm();//svolge la t perm
				printf("rotate 180\n 3 move to sx\n action 90\n 3 move to sx\n rotate 270\n action 270\n 3 move to sx\n action 90\n 3 move to sx\n\n");//stampa i movimenti per portare l'obbiettivo a posto
				break;//esce dallo switch
			}
			case 4:{//se i ÃƒÆ’Ã‚Â¨ uguale a 4, si avvia la risoluzione per la posizione l
				printf("2 move to sx\n action 90\n rotate 90\n move to sx\n action 90\n move to sx\n rotate 180\n\n");//stampa i movimenti per portare l'obbiettivo
				t_perm();//svolge la t perm
				printf("rotate 180\n 3 move to sx\n action 270\n 3 move to sx\n rotate 270\n action 270\n 2 move to sx\n\n");//stampa i movimenti per portare l'obbiettivo a posto
				break;//esce dallo switch
			}
			case 5:{//se i ÃƒÆ’Ã‚Â¨ uguale a 5, si avvia la risoluzione per la soluzione u
				printf("action 90\n move to sx\n action 180\n 3 move to sx\n\n");//stampa i movimenti per portare l'obbiettivo
				t_perm();//svolge la t perm
				printf("move to sx\n action 180\n 3 move to sx\n action 270\n\n");//stampa i movimenti per portare l'obbiettivo a posto
				break;//esce dallo switch
			}
			case 6:{//se i ÃƒÆ’Ã‚Â¨ uguale a 6, si avvia la risoluzione per la soluzione r
				printf("2 move to sx\n action 90\n rotate 90\n move to sx\n action 270\n move to sx\n rotate 180\n\n");//stampa i movimenti per portare l'obbiettivo
				t_perm();//svolge la t perm
				printf("rotate 180\n 3 move to sx\n action 90\n 3 move to sx\n rotate 270\n action 270\n 2 move to sx\n\n");//stampa i movimenti per portare l'obbiettivo a posto
				break;//esce dallo switch
			}
			case 7:{//se i ÃƒÆ’Ã‚Â¨ uguale a 7, si avvia la risoluzione per la soluzione p
				printf("2 move to sx\n action 180\n move to sx\n action 90\n move to sx\n rotate 180\n\n");//stampa i movimenti per portare l'obbiettivo
				t_perm();//svolge la t perm
				printf("rotate 180\n 3 move to sx\n action 270\n 3 move to sx\n action 180\n 2 move to sx\n\n");//stampa i movimenti per portare l'obbiettivo a posto
				break;//esce dallo switch
			}
			case 8:{//se i ÃƒÆ’Ã‚Â¨ uguale a 8, si avvia la risoluzione per la soluzione v
				printf("action 180\n move to sx\n action 180\n 3 move to sx\n\n");//stampa i movimenti per portare l'obbiettivo
				t_perm();//svolge la t perm
				printf("move to sx\n action 180\n 3 move to sx\n action 180\n\n");//stampa i movimenti per portare l'obbiettivo a posto
				break;//esce dallo switch
			}
			case 9:{//se i ÃƒÆ’Ã‚Â¨ uguale a 9, si avvia la risoluzione per la soluzione t
				printf("2 move to sx\n action 270\n rotate 270\n move to sx\n action 90\n move to sx\n rotate 180\n\n");//stampa i movimenti per portare l'obbiettivo
				t_perm();//svolge la t perm
				printf("rotate 180\n 3 move to sx\n action 270\n 3 move to sx\n rotate 90\n action 90\n 2 move to sx\n\n");//stampa i movimenti per portare l'obbiettivo a posto
				break;//esce dallo switch
			}
			case 10:{//se i ÃƒÆ’Ã‚Â¨ uguale a 10, si avvia la risoluzione per la soluzione x
				printf("action 270\n move to sx\n action 180\n 3 move to sx\n\n");//stampa i movimenti per portare l'obbiettivo
				t_perm();//svolge la t perm
				printf("move to sx\n action 180\n 3 move to sx\n action 90\n\n");//stampa i movimenti per portare l'obbiettivo a posto
				break;//esce dallo switch
			}
			case 11:{//se i ÃƒÆ’Ã‚Â¨ uguale a 11, si avvia la risoluzione per la soluzione z
				printf("move to sx\n action 180\n 3 move to sx\n\n");//stampa i movimenti per portare l'obbiettivo
				t_perm();//svolge la t perm
				printf("move to sx\n action 180\n 3 move to sx\n\n");//stampa i movimenti per portare l'obbiettivo a posto
				break;//esce dallo switch
			}
			default: //se in i c'ÃƒÆ’Ã‚Â¨ qualcosa di diverso da questi caratteri
				printf("errore\n");
				break;//esce dallo switch				
		}
	}
	else{//se non dovesse funzionare nessuno dei due pezzi 
		printf("Error\n");
	}
	return 0;	
}

/*per non utilizzare altri servi motori per lo scan arm bisognerà implementare al programma non il movimento dello scan arm verso up ma basterà  
ruotare di 45 gradi il cassetto per allineare solamente il braccio ai vertici*/

int main(int argc, char *argv[]) {
	//variabili utili per la parte di programma "orientare_cubo"
	int c1, c2, c3=3, c4=4, c5=5, c6=6;		//creo le variabili che contengono l'informazione del colore dei centri
	int n=0;								//creo una variabile che utilizzerÃƒÂ² come contatore
	//variabili utili per la parte di programma "scansione_pezzi"
	int nf;									//variabile utile per il contatore delle facce del cubo
	int ns;									//variabile utile per il contatore delle volte di pezzi da scansionare
	int t=0;								//variabile utile per capire in che posizione degli Array mettere i singoli pezzi
	int lati [1][24];						//array che conterrÃƒÂ  tutte le informazioni sui lati scombinati e adimensionali
	int vertici[1][24];						//array che conterrÃƒÂ  tutte le informazioni sui vertici scombinati e adimensonali
	//variabili utili per la parte di programma "ordinare_vertici"
	int vertici_ins[8][3];//array che contiene gli insiemi delle informazioni degli array dei singoli vertici scombinati
	int vertici_vero[8][3]={{1,4,5}, {1,4,3}, {1,3,2}, {1,2,5}, {4,5,6}, {3,4,6}, {2,3,6}, {2,5,6}};//array che contiene le informazioni dei vertici giusti
	//variabili utili per la parte di programma "ordinare_pezzi"
	int lati_ins [12][2];//array che contiene gli insiemi degli array dei singoli 12 lati
	int lati_vero [12][2]={{1,4}, {1,3}, {1,2}, {1,5}, {2,3}, {2,6}, {2,5}, {3,4}, {3,6}, {4,5}, {4,6}, {5,6}};//array che contiene le informazioni dei lati giusti
	//variabili utili per la parte di programma "sequenza_combinazione_vertici_definitiva"
	//vertici deve in realtÃƒÂ  chiamarsi vertici_ins per combaciare col programma precedente
	int end=0;																						//variabile che mi farà uscire dal ciclo più grande
	int end_int=0;																					//variabile che mi farà uscire dal ciclo più interno
	int d=0;																						//contatore
	int i=0;																						//contatore
	//int n=0;																						//variabile che conterrà l'informazione del numero da mettere --> basta rinominarlo =0 all'inizio della parte di programma
	int m=0;																						//variabile che conterrà l'informazione del numero del buffer
	int parita=0;																					//contatore per vedere quante volte permuta i vertici, in modo da capire se eseguire una paritÃƒÆ’Ã‚Â  o meno
	//variabili utili per la parte di programma "sequenza_combinazione_pezzi"
	//int d=0;//contatore --> basta rinominarlo =0 all'inizio della parte di programma
	//int i=0;//contatore --> basta rinominarlo =0 all'inizio della parte di programma
	//int n=0;//variabile che conterrÃƒÆ’Ã‚Â  l'informazione del numero da mettere --> basta rinominarlo =0 all'inizio della parte di programma
	//int m=0;//variabile che conterrÃƒÆ’Ã‚Â  l'informazione del numero del buffer --> basta rinominarlo =0 all'inizio della parte di programma
	//int end=0;//variabile che serve per far smettetere tutto se impostata a 1 --> basta rinominarlo =0 all'inizio della parte di programma
	//int end_int=0;//variabile che serve per fare smettere i for (per i problema dei due for per array bidimensionali) --> basta rinominarlo =0 all'inizio della parte di programma
	
	scanf("%d",& c1);						//guardo che colore ÃƒÂ¨ il centro in cima
	printf("\n");
	while(c1 != 1){							//se il colore non ÃƒÂ¨ bianco
		printf("move to sx\n");				//sposta cubo verso sinistra
		scanf("%d",& c1);					//guardo che colore ÃƒÂ¨ il nuovo centro in cima
		printf("\n");						
		n++;								//aggiorno di uno il contatore
		if(n==3){							//se il contatore ÃƒÂ¨ a 3
			printf("rotate 90\n");			//ruota il cubo di 90Ã‚Â° orari
			n=0;							//aggiorna il contatore a 0
		}
	}
	printf("centro bianco trovato\n");		//per capire se funge
	printf("move to sx\n");					//sposta cubo verso sinistra
	scanf("%d",& c2);						//guardo che colore ÃƒÂ¨ il centro che andrÃƒÂ  di fronte a me
	printf("\n");
	printf("rotate 90\n");					//ruota il cubo di 90Ã‚Â° orari
	while(c2!=2){
		printf("move to sx\n");				//sposta cubo verso sinistra
		scanf("%d",& c2);					//guardo che colore ÃƒÂ¨ il nuovo centro che andrÃƒÂ  di fronte a me
		printf("\n");
	}
	printf("centro verde trovato\n");		//per capire se funge
	printf("rotate 90\n");					//ruota il cubo di 90Ã‚Â° orari
	printf("move to sx\n");					//sposta cubo verso sinistra
	printf("rotate 270\n");				//ruota il cubo di 270Ã‚Â° orari
	
	/*Questa parte di programma svolge la scansione integrale del cubo di rubik e la suddivide in array adimensionali*/
	
	printf("Move scan arm to dx\n");		//muove il braccio che scansiona i pezzi verso destra
	for(nf=0; nf<6; nf++){					//crea funzione per ogni faccia del cubo
		for(ns=0; ns<4; ns++, t++){			//crea funzione per ogni scansione della faccia
			scanf("%d",& lati[0][t]);			//salva il pezzo nell'array dei lati
			printf("\n");
			printf("rotate 90\n");			//ruota il cubo di 90Ã‚Â° orari
		}
		if(nf==3){							//se il programma sta facendo la quarta faccia
			printf("rotate 90\n");			//ruota il cubo di 90Ã‚Â° orari
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
	printf("rotate 270\n");					//ruota il cubo di 270Ã‚Â° orari
	printf("move to sx\n");					//sposta cubo verso sinistra
	t=0;									//faccio sÃƒÂ¬ che la variabile t ritorni a 0 perchÃƒÂ¨ dovrÃƒÂ² riusarla per l'altro array
	printf("Move scan arm dx\n rotate 45\n");//muove il braccio che scansiona i vertici e ruota di 45 gradi il cassetto in modo da legere bene i vertici -->non so se debba andare così
	for(nf=0; nf<6; nf++){					//crea funzione per ogni faccia del cubo
		for(ns=0; ns<4; ns++, t++){			//crea funzione per ogni scansione della faccia
			scanf("%d",& vertici[0][t]);		//salva il pezzo nell'array dei vertici
			printf("\n");
			printf("rotate 90\n");			//ruota il cubo di 90Ã‚Â° orari
		}
		if(nf==3){							//se il programma sta facendo la quarta faccia
			printf("rotate 90\n");			//ruota il cubo di 90Ã‚Â° orari
			printf("move to sx\n");			//sposta cubo verso sinistra
		}
		else if(nf==4){						//se il programma sta facendo la quinta faccia
			printf("move to sx\n");			//sposta cubo verso sinistra
			printf("move to sx\n");			//sposta cubo verso sinistra			
		}
		else{								//se non ÃƒÂ¨ ne la quarta che la quinta faccia
			printf("move to sx\n");			//sposta cubo verso sinistra
		}	
	}
	printf("rotate 270\n");					//ruota il cubo di 270Ã‚Â° orari
	printf("move to sx\n");					//sposta cubo verso sinistra
	
	
	/*Questa parte di programma serve per trasferire l'informazione dell'array adimensionale dei vertici in un array organizzato che mi dia tutte 
	le informazioni di ogni singolo vertice. In questo modo posso nominare arbitrariamente ogni posizione del cubo*/
	
	vertici_ins[0][0]= vertici[0][0];//vertice di coordinate a,n,q che deve prendere le informazioni del 1Ãƒâ€šÃ‚Â°, del 16Ãƒâ€šÃ‚Â° e del 18Ãƒâ€šÃ‚Â° dell'array vertici
	vertici_ins[0][1]= vertici[0][15];
	vertici_ins[0][2]= vertici[0][17];
	vertici_ins[1][0]= vertici[0][3];//vertice di coordinate b,m,j che deve prendere le informazioni del 4Ãƒâ€šÃ‚Â°, del 19Ãƒâ€šÃ‚Â° e del 5Ãƒâ€šÃ‚Â° dell'array vertici
	vertici_ins[1][1]= vertici[0][18];
	vertici_ins[1][2]= vertici[0][4];
	vertici_ins[2][0]= vertici[0][2];//vertice di coordinate c,i,f che deve prendere le informazioni del 3Ãƒâ€šÃ‚Â°, del 6Ãƒâ€šÃ‚Â° e del 22Ãƒâ€šÃ‚Â° dell'array vertici
	vertici_ins[2][1]= vertici[0][5];
	vertici_ins[2][2]= vertici[0][21];
	vertici_ins[3][0]= vertici[0][1];//vertice di coordinate d,e,r che deve prendere le informazioni del 2Ãƒâ€šÃ‚Â°, del 23Ãƒâ€šÃ‚Â° e del 15Ãƒâ€šÃ‚Â° dell'array vertici
	vertici_ins[3][1]= vertici[0][22];
	vertici_ins[3][2]= vertici[0][14];
	vertici_ins[4][0]= vertici[0][16];//vertice di coordinate o,t,z che deve prendere le informazioni del 17Ãƒâ€šÃ‚Â°, del 13Ãƒâ€šÃ‚Â° e del 12Ãƒâ€šÃ‚Â° dell'array vertici
	vertici_ins[4][1]= vertici[0][12];
	vertici_ins[4][2]= vertici[0][11];
	vertici_ins[5][0]= vertici[0][7];//vertice di coordinate k,p,x che deve prendere le informazioni del 8Ãƒâ€šÃ‚Â°, del 20Ãƒâ€šÃ‚Â° e del 9Ãƒâ€šÃ‚Â° dell'array vertici
	vertici_ins[5][1]= vertici[0][19];
	vertici_ins[5][2]= vertici[0][8];
	vertici_ins[6][0]= vertici[0][20];//vertice di coordinate g,l,v che deve prendere le informazioni del 21Ãƒâ€šÃ‚Â°, del 7Ãƒâ€šÃ‚Â° e del 10Ãƒâ€šÃ‚Â° dell'array vertici
	vertici_ins[6][1]= vertici[0][6];
	vertici_ins[6][2]= vertici[0][9];
	vertici_ins[7][0]= vertici[0][23];//vertice di coordinate h,s,u che deve prendere le informazioni del 24Ãƒâ€šÃ‚Â°, del 14Ãƒâ€šÃ‚Â° e del 11Ãƒâ€šÃ‚Â° dell'array vertici
	vertici_ins[7][1]= vertici[0][13];
	vertici_ins[7][2]= vertici[0][10];
	
	
	/*Questa parte di programma serve per trasferire l'informazione dell'array adimensionale dei lati in un array organizzato che mi dia tutte 
	le informazioni di ogni singolo lato. In questo modo posso nominare arbitrariamente ogni posizione del cubo*/
	
		
	lati_ins[0][0]= lati[0][3];//lato di coordinate a,m che deve prendere le informazioni del 4Ã‚Â° e del 18Ã‚Â° dell'array lati
	lati_ins[0][1]= lati[0][17];
	lati_ins[1][0]= lati[0][2];//lato di coordinate b,i (buffer) che deve prendere le informazioni del 3Ã‚Â° e del 5Ã‚Â° dell'array lati
	lati_ins[1][1]= lati[0][4];
	lati_ins[2][0]= lati[0][1];//lato di coordinate c,e che deve prendere le informazioni del 2Ã‚Â° e del 22Ã‚Â° dell'array lati
	lati_ins[2][1]= lati[0][21];
	lati_ins[3][0]= lati[0][0];//lato di coordinate d,q che deve prendere le informazioni del 1Ã‚Â° e del 15Ã‚Â° dell'array lati
	lati_ins[3][1]= lati[0][14];
	lati_ins[4][0]= lati[0][20];//lato di coordinate f,l che deve prendere le informazioni del 21Ã‚Â° e del 6Ã‚Â° dell'array lati
	lati_ins[4][1]= lati[0][5];
	lati_ins[5][0]= lati[0][23];//lato di coordinate g,u che deve prendere le informazioni del 24Ã‚Â° e del 10Ã‚Â° dell'array lati
	lati_ins[5][1]= lati[0][9];
	lati_ins[6][0]= lati[0][22];//lato di coordinate h,r che deve prendere le informazioni del 23Ã‚Â° e del 14Ã‚Â° dell'array lati
	lati_ins[6][1]= lati[0][13];
	lati_ins[7][0]= lati[0][7];//lato di coordinate j,p che deve prendere le informazioni del 8Ã‚Â° e del 19Ã‚Â° dell'array lati
	lati_ins[7][1]= lati[0][18];
	lati_ins[8][0]= lati[0][6];//lato di coordinate k,v che deve prendere le informazioni del 7Ã‚Â° e del 9Ã‚Â° dell'array lati
	lati_ins[8][1]= lati[0][8];
	lati_ins[9][0]= lati[0][16];//lato di coordinate n,t che deve prendere le informazioni del 17Ã‚Â° e del 16Ã‚Â° dell'array lati
	lati_ins[9][1]= lati[0][15];
	lati_ins[10][0]= lati[0][19];//lato di coordinate o,x che deve prendere le informazioni del 20Ã‚Â° e del 12Ã‚Â° dell'array lati
	lati_ins[10][1]= lati[0][11];
	lati_ins[11][0]= lati[0][12];//lato di coordinate s,z che deve prendere le informazioni del 13Ã‚Â° e del 11Ã‚Â° dell'array lati
	lati_ins[11][1]= lati[0][10];
	
	
	/*Questa parte di programma serve a risolvere i vertici e ad effettuare le paritÃƒÂ */
	
	
	//identifico vertici[0][0], [0][1] e [0][2] come zona di buffer, quando in realtÃƒÆ’Ã‚Â Ãƒâ€šÃ‚Â   sarÃƒÆ’Ã‚Â Ãƒâ€šÃ‚Â   la zona a;n;q
	n=0;//rimetto n=0 perchÃƒÂ¨ ÃƒÂ¨ stata usata da numerosi programmi	
	do{

		if (vertici_vero[0][0]==vertici_ins[0][0] && vertici_vero[0][1]==vertici_ins[0][1] && vertici_vero[0][2]==vertici_ins[0][2]){	//se nel buffer ci sono i colori giusti e messi bene
			for (i=0;i<8;i++){
				for (d=0;d<3;d++){
					if (vertici_vero[i][d]!= vertici_ins[i][d]){	//se nella posizione analizzata ci sono colori diversi -> cubo non risolto (molto probabilmente bisogna mettere anche qui il pezzo di codice di commutazione come nel cubo risolto ma messo male
						commutazioni_ver(d, i, vertici_ins);//avvia la funzione commutazioni_ver
						parita=parita+1;//aggiorno il contatore delle paritÃƒÆ’Ã‚Â  
						end_int=1;		//imposto la variabile a 1 per far si che quando uscirÃƒÆ’Ã‚Â  dal primo for sarÃƒÆ’Ã‚Â  costretto ad andare nell'altro e chiudere anch'esso
						break;			//esco dal for
					}
					else if(i!=7 && vertici_ins[i][d]==vertici_vero[i][d]){
						//non fa nulla se non ÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â¨ l'ultimo confronto e se i valori confrontati sono uguali
					}
					else if (i==7 && d==2) {//se tutti sono giusti 
						end=1;				//modifico la variabile end
						end_int=1;			//imposto la variabile a 1 per far si che quando usirÃƒÆ’Ã‚Â Ãƒâ€šÃ‚Â  dal primo for sarÃƒÆ’Ã‚Â  costretto ad andare nell'altro e chiudere anch'esso
						break;				//faccio smettere il for
					}
				}
				if (end_int==1){			//se la variabile per far chiudere tutti i for ÃƒÆ’Ã‚Â¨ stata attivata
					end_int=0;				//ristabilizzo la variabile per poterla riutilizzare
					break;					//faccio smettere anche questo for
				}
			}
		}
		
		else if (vertici_vero[0][0]==vertici_ins[0][1] && vertici_vero[0][1]==vertici_ins[0][2] && vertici_vero[0][2]==vertici_ins[0][0]){//se nel buffer ci sono i colori giusti ma ruotati male (rotazione vertice buffer di 120 gradi antiorari)
		
			for (i=0;i<8;i++){
				for(d=0;d<3;d++){
					if (i==0){//se i ÃƒÆ’Ã‚Â¨ in zona buffer 
						//non fa nulla, perchÃƒÆ’Ã‚Â¨ sennÃƒÆ’Ã‚Â² scambierebbe in loop la posizione di buffer messa male
					}
					else if(vertici_ins[i][d]!=vertici_vero[i][d]){//se nella posizione ci sono colori diversi-> cubo non risolto (devo controllare questo if perchÃƒÆ’Ã‚Â¨ non sono convinto di come funzioni)
						commutazioni_ver(d, i, vertici_ins);//avvia la funzione commutazioni_ver
						parita=parita+1;//aggiorno il contatore delle paritÃƒÆ’Ã‚Â 
						end_int=1;		//imposto la variabile a 1 per far si che quando uscirÃƒÆ’Ã‚Â  dal primo for sarÃƒÆ’Ã‚Â  costretto ad andare nell'altro e chiudere anch'esso
						break;			//esco dal for							
					}
					else if(vertici_ins[i][d]==vertici_vero[i][d]){//se nella posizione analizzata il pezzo ÃƒÆ’Ã‚Â¨ giusto
					//non faccio nulla e continuo con l'analisi
					} 
				}
				if (end_int==1){			//se la variabile per far chiudere tutti i for ÃƒÆ’Ã‚Â¨ stata attivata
					end_int=0;				//ristabilizzo la variabile per poterla riutilizzare
					break;					//faccio smettere anche questo for
				}
			}
			
		}
		
		else if (vertici_vero[0][0]==vertici_ins[0][2] && vertici_vero[0][1]==vertici_ins[0][0] && vertici_vero[0][2]==vertici_ins[0][1]){//se nel buffer ci sono i colori giusti ma ruotati male (rotazione vertice buffer di 120 gradi orari)
			for (i=0;i<8;i++){
				for(d=0;d<3;d++){
					if (i==0){//se i ÃƒÆ’Ã‚Â¨ in zona buffer 
						//non fa nulla, perchÃƒÆ’Ã‚Â¨ sennÃƒÆ’Ã‚Â² scambierebbe in loop la posizione di buffer messa male
					}
					else if(vertici_ins[i][d]!=vertici_vero[i][d]){//se nella posizione ci sono colori diversi-> cubo non risolto (devo controllare questo if perchÃƒÆ’Ã‚Â¨ non sono convinto di come funzioni)
						commutazioni_ver(d, i, vertici_ins);//avvia la funzione commutazioni_ver
						parita=parita+1;//aggiorno il contatore delle paritÃƒÆ’Ã‚Â 
						end_int=1;		//imposto la variabile a 1 per far si che quando uscirÃƒÆ’Ã‚Â  dal primo for sarÃƒÆ’Ã‚Â  costretto ad andare nell'altro e chiudere anch'esso
						break;			//esco dal for							
					}
					else if(vertici_ins[i][d]==vertici_vero[i][d]){//se nella posizione analizzata il pezzo ÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â¨ giusto
					//non faccio nulla e continuo con l'analisi
					} 
				}
				if (end_int==1){			//se la variabile per far chiudere tutti i for ÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â¨ stata attivata
					end_int=0;				//ristabilizzo la variabile per poterla riutilizzare
					break;					//faccio smettere anche questo for
				}
			}
			
		}
		
		else if (end!=1){//se il cubo non ÃƒÆ’Ã‚Â¨ risolto --> nel buffer ci sono colori completamente sbagliati
			for(i=0;i<8;i++){//confronta ogni vertice
				if(vertici_ins[0][0]==vertici_vero[i][0] || vertici_ins[0][0]==vertici_vero[i][1] || vertici_ins[0][0]==vertici_vero[i][2] ){//se nel vertice analizzato c'ÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â¨ anche solo un colore che combacia con quello della prima posizione del buffer
					if(vertici_ins[0][1]==vertici_vero[i][0] || vertici_ins[0][1]==vertici_vero[i][1] || vertici_ins[0][1]==vertici_vero[i][2]){//se nel vertice analizzato c'ÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â¨ anche solo un colore che combacia con quello dell seconda posizione del buffer
						if(vertici_ins[0][2]==vertici_vero[i][0] || vertici_ins[0][2]==vertici_vero[i][1] || vertici_ins[0][2]==vertici_vero[i][2]){//se nel vertice analizzato c'ÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â¨ anche solo un colore che combacia con quello dell'ultima posizione del buffer --> trovato vertice dove permutare il pezzo
							if (vertici_ins[0][0]==vertici_vero[i][0]){//se la prima informazione di buffer va messa nella prima informazione del vertice analizzato
								d=0;//salvo la posizione dove deve andare la prima informazione di buffer
								commutazioni_ver(d, i, vertici_ins);//avvia la funzione commutazioni_ver
								parita=parita+1;//aggiorno il contatore delle paritÃƒÆ’Ã‚Â 
								break;//esce dal for (spero lo faccia)
							}
							else if(vertici_ins[0][0]==vertici_vero[i][1]){//se la prima informazione di buffer va messa nella seconda informazione del vertice analizzato
								d=1;//salvo la posizione dove deve andare la prima informazione di buffer
								commutazioni_ver(d, i, vertici_ins);//avvia la funzione commutazioni_ver
								parita=parita+1;//aggiorno il contatore delle paritÃƒÆ’Ã‚Â 
								break;//esce dal for (spero lo faccia)								
							}
							else if(vertici_ins[0][0]==vertici_vero[i][2]){//se la prima informazione di buffer va messa nell'ultima informazione del vertice analizzato
								d=2;//salvo la posizione dove deve andare la prima informazione di buffer
								commutazioni_ver(d, i, vertici_ins);//avvia la funzione commutazioni_ver
								parita=parita+1;//aggiorno il contatore delle paritÃƒÆ’Ã‚Â 
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
	else if(parita%2==1){//se sono state eseguite un numero dispari di commutazioni --> svolge l'algoritmo di paritÃƒÆ’Ã‚Â 
		printf("3 move to sx\n action 270\n 3 move to sx\n action 270\n move to sx\n action 90\n rotate 90\n move to sx\n action 90\n");//stampa la funzione
		printf("3 move to sx\n action 270\n rotate 90\n move to sx\n action 180\n 3 move to sx\n action 90\n move to sx\n action 180\n");//stampa la funzione
		printf("3 move to sx\n action 90\n rotate 90\n 3 move to sx\n action 270\n move to sx\n action 270\n rotate 90\n 3 move to sx\n");//stampa la funzione
		printf("action 270\n move to sx\n action 270\n 3 move to sx\n action 180\n move to sx\n action 90\n 3 move to sx\n action 90\n 2 move to sx\n");//stampa la funzione
	}
	
	
	/*Questa parte di programma serve a sistemare i lati*/
	//identifico lati [1][0] e [1][1] come zona di buffer, quando in realtÃƒÆ’Ã‚Â  sarÃƒÆ’Ã‚Â  la zona b;i
	d=0;//rimetto d=0 perchÃƒÂ¨ ÃƒÂ¨ stata usata da numerosi programmi
	i=0;//rimetto i=0 perchÃƒÂ¨ ÃƒÂ¨ stata usata da numerosi programmi
	n=0;//rimetto n=0 perchÃƒÂ¨ ÃƒÂ¨ stata usata da numerosi programmi
	m=0;//rimetto m=0 perchÃƒÂ¨ ÃƒÂ¨ stata usata da numerosi programmi
	end=0;//rimetto end=0 perchÃƒÂ¨ ÃƒÂ¨ stata usata da numerosi programmi
	end_int=0;//rimetto end_int=0 perchÃƒÂ¨ ÃƒÂ¨ stata usata da numerosi programmi
	do{
		if(lati_ins[1][0]==lati_vero[1][0] && lati_ins[1][1]==lati_vero[1][1]){//se nel buffer c'è il suo colore giusto e messo bene
			for(i=0;i<12;i++){
				for (d=0; d<2; d++){
					if(lati_ins[i][d]!=lati_vero[i][d]){//se nella posizione ci sono colori diversi-> cubo non risolto
						n=lati_ins[i][0];//associo ad n l'informazione del primo pezzo non messo correttamente 
						m=lati_ins[1][0];//associo ad m l'informazione del primo pezzo nel buffer
						lati_ins[i][0]=m;//nel luogo dove c'era il pezzo che non andava bene metto la prima informazione del buffer
						lati_ins[1][0]=n;//metto in informazione al buffer il primo colore del luogo dove il colore ÃƒÆ’Ã‚Â¨ sbagliato
						n=lati_ins[i][1];//associo ad n l'informazione dell'ultimo pezzo non messo correttamente 
						m=lati_ins[1][1];//associo ad m l'informazione dell'ultimo pezzo nel buffer
						lati_ins[i][1]=m;//nel luogo dove c'era il pezzo che non andava bene metto l'ultima informazione del buffer
						lati_ins[1][1]=n;//metto in informazione al buffer l'ultimo colore del luogo dove il colore ÃƒÆ’Ã‚Â¨ sbagliato
						commutazioni(d,i);//avvia la funzione "commutazioni"		
						end_int=1;//imposto la variabile a 1 per far si che quando usirÃƒÆ’Ã‚Â  dal primo for sarÃƒÆ’Ã‚Â  costretto ad andare nell'altro e chiudere anch'esso
						break;//esco dal for							
					}
					else if(i!=11 && lati_ins[i][d]==lati_vero[i][d]){
						//non fa nulla se non ÃƒÆ’Ã‚Â¨ l'ultimo confronto e se i valori confrontati sono uguali
					}
					else if (i==11 && d==1) {//se tutti sono giusti 
						end=1;//modifico la variabile end
						end_int=1;//imposto la variabile a 1 per far si che quando usirÃƒÆ’Ã‚Â  dal primo for sarÃƒÆ’Ã‚Â  costretto ad andare nell'altro e chiudere anch'esso
						break;//faccio smettere il for
					}
			
				}
				if (end_int==1){//se la variabile per far chiudere tutti i for ÃƒÆ’Ã‚Â¨ stata attivata
					end_int=0;//ristabilizzo la variabile per poterla riutilizzare
					break;//faccio smettere anche questo for
				}
					
			}
		}
		else if(lati_ins[1][0]==lati_vero[1][1] && lati_ins[1][1]==lati_vero[1][0]){//se nel buffer ci sono i colori giusti ma sono messi male
			for(i=0;i<12;i++){
				for (d=0; d<2; d++){
					if (i==1){//se i ÃƒÆ’Ã‚Â¨ in zona buffer 
						//non fa nulla, perchÃƒÆ’Ã‚Â¨ sennÃƒÆ’Ã‚Â² scambierebbe in loop la posizione di buffer messa male
					}
					else if(lati_ins[i][d]!=lati_vero[i][d]){//se nella posizione ci sono colori diversi-> cubo non risolto (devo controllare questo if perchÃƒÆ’Ã‚Â¨ non sono convinto di come funzioni)
						m=lati_ins[1][0];//associo ad m l'informazione del primo luogo del buffer
						n=lati_ins[1][1];//associo ad m l'informazione dell'ultimo luogo del buffer
						lati_ins[1][0]=n;//scambio l'informazione
						lati_ins[1][1]=m;//scambio l'informazione
						m=lati_ins[i][0];//associo ad m l'informazione del primo luogo della zona da permutare
						n=lati_ins[i][1];//associo ad m l'informazione dell'ultimo luogo della zona da permutare
						lati_ins[i][0]=n;//scambio l'informazione
						lati_ins[i][1]=m;//scambio l'informazione
						n=lati_ins[i][0];//associo ad n l'informazione del luogo dove andrÃƒÆ’Ã‚Â  messa l'informazione del buffer
						m=lati_ins[1][0];//associo ad m l'informazione del buffer
						lati_ins[i][0]=m;//metto l'informazione nel buffer nel giusto luogo
						lati_ins[1][0]=n;//aggiorno il buffer
						n=lati_ins[i][1];//associo ad n l'informazione del luogo dove andrÃƒÆ’Ã‚Â  messa l'informazione del buffer
						m=lati_ins[1][1];//associo ad m l'informazione del buffer
						lati_ins[i][1]=m;//metto l'informazione nel buffer nel giusto luogo
						lati_ins[1][1]=n;//aggiorno il buffer
						d=1;
						commutazioni(d,i);//avvia la funzione "commutazioni"
						end_int=1;//imposto la variabile a 1 per far si che quando usirÃƒÆ’Ã‚Â  dal primo for sarÃƒÆ’Ã‚Â  costretto ad andare nell'altro e chiudere anch'esso
						break;//esco dal for							
					}
					else if(i!=11 && lati_ins[i][d]==lati_vero[i][d]){
						//non fa nulla se non ÃƒÆ’Ã‚Â¨ l'ultimo confronto e se i valori confrontati sono uguali
					}
					else if (i==11 && d==1 && lati_ins[i][d]==lati_vero[i][d]) {//se tutti sono giusti 
						end=1;//modifico la variabile end
						end_int=1;//imposto la variabile a 1 per far si che quando usirÃƒÆ’Ã‚Â  dal primo for sarÃƒÆ’Ã‚Â  costretto ad andare nell'altro e chiudere anch'esso
						break;//faccio smettere il for
					}
			
				}
				if (end_int==1){//se la variabile per far chiudere tutti i for ÃƒÆ’Ã‚Â¨ stata attivata
					end_int=0;//ristabilizzo la variabile per poterla riutilizzare
					break;//faccio smettere anche questo for
				}		
			}
		}
		
		else if(end!=1){//se l'array non ha finito di essere combinato
			for(i=0;i<12;i++){
				//bisognerÃƒÆ’Ã‚Â  fare di nuovo degli if sia per il caso che siano nel modo corretto per la posizione o che siano messi al rovescio
				if(lati_ins[1][0]== lati_vero[i][0] && lati_ins[1][1]==lati_vero[i][1]){//se la zona di buffer ha la stessa informazione della zona confrontata
					n=lati_ins[i][0];//associo ad n l'informazione del luogo dove andrÃƒÆ’Ã‚Â  messa l'informazione del buffer
					m=lati_ins[1][0];//associo ad m l'informazione del buffer
					lati_ins[i][0]=m;//metto l'informazione nel buffer nel giusto luogo
					lati_ins[1][0]=n;//aggiorno il buffer
					n=lati_ins[i][1];//associo ad n l'informazione del luogo dove andrÃƒÆ’Ã‚Â  messa l'informazione del buffer
					m=lati_ins[1][1];//associo ad m l'informazione del buffer
					lati_ins[i][1]=m;//metto l'informazione nel buffer nel giusto luogo
					lati_ins[1][1]=n;//aggiorno il buffer
					d=0;
					commutazioni(d,i);//avvia la funzione "commutazioni"
					break;//esce dal for
				}//funzione che serve per riordinare in base ai voleri dell'array lati_vero quello del lati
				
				//funzione che dovrebbe essere giusta e da copiare per tutte le parti con sfasamenti
				else if(lati_ins[1][0]== lati_vero[i][1] && lati_ins[1][1]==lati_vero[i][0]){//se la zona di buffer ha la stessa informazione della zona confrontata ma sfasata
					m=lati_ins[1][0];//associo ad m l'informazione del primo luogo del buffer
					n=lati_ins[1][1];//associo ad m l'informazione dell'ultimo luogo del buffer
					lati_ins[1][0]=n;//scambio l'informazione
					lati_ins[1][1]=m;//scambio l'informazione
					m=lati_ins[i][0];//associo ad m l'informazione del primo luogo della zona da permutare
					n=lati_ins[i][1];//associo ad m l'informazione dell'ultimo luogo della zona da permutare
					lati_ins[i][0]=n;//scambio l'informazione
					lati_ins[i][1]=m;//scambio l'informazione
					n=lati_ins[i][0];//associo ad n l'informazione del luogo dove andrà messa l'informazione del buffer
					m=lati_ins[1][0];//associo ad m l'informazione del buffer
					lati_ins[i][0]=m;//metto l'informazione nel buffer nel giusto luogo
					lati_ins[1][0]=n;//aggiorno il buffer
					n=lati_ins[i][1];//associo ad n l'informazione del luogo dove andrà  messa l'informazione del buffer
					m=lati_ins[1][1];//associo ad m l'informazione del buffer
					lati_ins[i][1]=m;//metto l'informazione nel buffer nel giusto luogo
					lati_ins[1][1]=n;//aggiorno il buffer
					d=1;
					commutazioni(d,i);//avvia la funzione "commutazioni"
					break;//esce dal for
				}//funzione che serve per riordinare in base ai voleri dell'array lati_vero quello del lati	
			}
		}
	} while(end!=1);
	//programma finito spero :)
	return 0;
}
