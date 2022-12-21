#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <string.h>
#define SEGSIZE 200
#define MUTEX 0
#define CLUB1 1 
#define CLUB2 2
key_t skey;
key_t mkey;
int semaforos;
int shmem;
char *segptr;
int up(int conj_semaforos, int num_semaforo);
int down(int conj_semaforos, int num_semaforo);
void agregarColor(void);
void agregarRojo(void);
void agregarAmarillo(void);
void agregarAzul(void);
void agregar(char g);

int main(int argc, char *argv[])
{
    skey = ftok("/tmp", 10100);
    mkey = ftok("/tmp", 10101);
    semaforos = semget(skey, 3, IPC_CREAT | 0666);
    /*
    Semaforos:
    0. mutex
    1. club1
    2. club2
    */
    shmem = shmget(mkey, SEGSIZE, IPC_CREAT | 0666);
    segptr = shmat(shmem, 0, 0);
    agregarColor();
    shmctl(shmem, IPC_RMID, 0);
    return 0;
}


int up(int conj_semaforos, int num_semaforo) { // operación up para los semáforos
    struct sembuf up = {num_semaforo, 1, 0};
    return semop(conj_semaforos, &up, 1);
}

int down(int conj_semaforos, int num_semaforo) {// operación down para los semáforos
    struct sembuf down = {num_semaforo, -1, 0};
    return semop(conj_semaforos, &down, 1);
}

void agregarColor(void) {
    agregarRojo();
    agregarAmarillo();
    agregarAzul();
}

void agregarRojo(void) { // agrega el color rojo a la memoria compartida
    down(semaforos, CLUB1);
    down(semaforos, MUTEX);
    agregar('r');
    printf("Club 1 coloca color: ROJ\n");
    up(semaforos, CLUB2);
    up(semaforos, MUTEX);
}

void agregarAmarillo(void) { //agrega el color amarillo a la memoria compartida
    down(semaforos, CLUB1);
    down(semaforos, MUTEX);
    agregar('a');
    printf("Club 1 coloca color: AMA\n");
    up(semaforos, CLUB2);
    up(semaforos, MUTEX);
}

void agregarAzul(void) { // agrega el color azul a la memoria compartida
    down(semaforos, CLUB1);
    down(semaforos, MUTEX);
    agregar('z'); // se utiliza la letra z para diferenciarlo del color amarillo
    printf("Club 1 coloca color: AZU\n");
    up(semaforos, CLUB2);
    up(semaforos, MUTEX);
}

void agregar(char g) {
    char buffer[SEGSIZE];
    strcpy(buffer, segptr);
    switch (g)    {
    case 'r': // agrega rojo a la memoria compartida
        strcat(buffer, "ROJ");
        strcpy(segptr, buffer);
        break;
    case 'a': // agrega amarillo a la memoria compartida
        strcat(buffer, "AMA");
        strcpy(segptr, buffer);
        break;
    case 'z': // agrega azul a la memoria compartida
        strcat(buffer, "AZU");
        strcpy(segptr, buffer);
        break;
    }
}