// tostadora.c
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>

#define PAN_BLANCO 0
#define PAN_NEGRO 1
#define NUM_HUESPEDES 30

int cantTostadas = 0;

void tostar(int tipoPan);

int main(int argc, char * argv[]){
    
    signal(SIGUSR1, &tostar);
    signal(SIGUSR2, &tostar);

    while(cantTostadas != NUM_HUESPEDES);

    return 0;
}

void tostar(int tipoPan){
    cantTostadas+=1;
    switch(tipoPan){
        case SIGUSR1:
            printf("Deseo tostadas de pan blanco. \n");
            printf("Tostadas de pan blanco. (%i) \n", cantTostadas);
            sleep(2);
            break;
        case SIGUSR2:
            printf("Deseo tostadas de pan negro. \n");
            printf("Tostadas de pan negro. (%i) \n", cantTostadas);
            sleep(1);
            break;
    }
    
    printf("Tostadas listas. \n");
    printf("Tostadora libre, esperando pan. \n");

}