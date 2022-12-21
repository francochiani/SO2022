// controlc.c
#include <stdio.h>
#include <signal.h>

int main(){
	int i;
	signal(SIGINT, SIG_IGN);
	printf("Iteracion INICIADA. Presionar Ctrl-C NO tiene efecto....\n");
	for(i=1;i<=10000;i++){
		if(i%1000==0){
			printf("Iteracion %i\n", i);
			sleep(1);
		}
	}
	printf("Computation is done.\n\n");
	signal(SIGINT, SIG_DFL);
	printf("REINICIO de la Iteracion. Presionar Ctrl-C AHORA tiene efecto....\n");

	for(i=1;i<=10000;i++){
		if(i%1000==0){
			printf("Iteracion %i \n", i);
			sleep(1);
		}
	}
}