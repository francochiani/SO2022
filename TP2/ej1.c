#include <stdio.h>
#include <unistd.h>
#include <getopt.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char* argv[]){
	int valor;
	if(argc==1) printf("Uso: %s [-cl] [-s nombre_archivo]\n", argv[0]); // Si no hay parametros

	while(valor=getopt(argc, argv, "cls:")){
		if(valor==-1) break;

			switch(valor){

				case 'c': printf("Cantidad de argumentos: %i\n", argc);  // Si se invoca con -c
				break;

				case 'l': ;	// Si se invoca con -l
					int i;
					for(i=0;i<argc;i++){
					printf("Argumento: %i- %s.\n", i, argv[i]);
				}
				break;

				case 's': ; // Si se invoca con -s
					int fd;
					fd = creat(optarg, 0600);
					fd = open(optarg, O_WRONLY | O_APPEND | O_CREAT, 0644);				
					int j;
					for(j=0;j<argc;j++){
						write(fd, argv[j], strlen(argv[j]));
					}
					close(fd);
 				break;
			}	
		}
}
