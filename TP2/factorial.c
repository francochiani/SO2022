// factorial.c
#include <stdio.h>
#include <unistd.h>

int factorial(int val);

int main(int argc,char *argv[]){
	int valor = atoi(argv[0]);
	if (valor>=1 && valor<=10){
		printf("Factorial de %d = %d\n", valor, factorial(valor));
	} else {
		printf("Numero fuera de rango: %d\n", valor);
	}
	printf("Id de Prg-Factorial: %d\n", getpid());
return 0;
}

int factorial(int val){
	if(val==0){ return 1; }
	else if (val==1) { return 1; }
	else { return val * (factorial (val-1)); }
}