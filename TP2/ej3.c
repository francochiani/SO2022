// ej3.c
#include <stdio.h>
#include <unistd.h>
int main(int argc,char *argv[]){

	printf("Id proceso que invoca: %d\n", getpid());

	if (argc==1){ printf("Error. Usar ./Nombre_pgr_invoca [numero]\n"); }
	else {

		char* arg_list[] = {argv[1], NULL};
		execv("./factorial", arg_list);
		printf("No se pudo\n");

	}
return -1;
}