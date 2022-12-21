#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc,char *argv[]){
	
	int valor = atoi(argv[1]);
	printf("NODO R - VALOR = %d\n", valor);
	printf("ID proceso raiz: %d\n" , getpid());
	int nodo2;
	int nodo1 = fork();
	
	if(nodo1==0){
		int nodo12;
		printf("NODO 1 - VALOR = %d\n", valor+100);
		printf("ID NODO 1: %d - ID padre NODO 1(NODO R): %d\n", getpid(), getppid());
	
		int nodo11 = fork();
			if(nodo11==0){
				printf("NODO 1.1 - VALOR = %d\n", (valor+100)*2);
				printf("ID NODO 1.1: %d - ID padre NODO 1.1(NODO 1): %d\n", getpid(), getppid());
			} else { nodo12 = fork(); }

			if(nodo12==0){
				printf("NODO 1.2 - VALOR = %d\n", (valor+100)/2);
				printf("ID NODO 1.2: %d - ID padre NODO 1.2(NODO 1): %d\n", getpid(), getppid());
			}	

	} else { nodo2 = fork(); }
	
	if(nodo2==0){
		printf("NODO 2 - VALOR = %d\n", valor-100);
		printf("ID NODO 2: %d - ID padre NODO 2(NODO R): %d\n", getpid(), getppid());
	};

return 0;
}