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
int shmid;
char *shmptr;
int up(int conj_semaforos, int num_semaforo);
int down(int conj_semaforos, int num_semaforo);
void agregarColor(void);
void agregarNaranja(void);
void agregarVerde(void);
void agregarVioleta(void);
void agregar(char g);
union semun
{
    int val;               /* Value for SETVAL */
    struct semid_ds *buf;  /* Buffer for IPC_STAT, IPC_SET */
    unsigned short *array; /* Array for GETALL, SETALL */
    struct seminfo *__buf; /* Buffer for IPC_INF */
};


int main(int argc, char *argv[])
{
    skey = ftok("/tmp", 10100);
    mkey = ftok("/tmp", 10101);
    semaforos = semget(skey, 3, 0666 | IPC_CREAT);
    /*
    Semaforos:
    0. mutex
    1. club1
    2. club2
    */
    shmid = shmget(mkey, SEGSIZE, IPC_CREAT | 0660);
    shmptr = shmat(shmid, 0, 0);
    semctl(semaforos, MUTEX, SETVAL, 1);
    semctl(semaforos, CLUB1, SETVAL, 1);
    agregarColor();
    return 0;
}


int up(int conj_semaforos, int num_semaforo) { // operación up para los semáforos
    struct sembuf up = {num_semaforo, 1, 0};
    return semop(conj_semaforos, &up, 1);
}
int down(int conj_semaforos, int num_semaforo) { // operación down para los semáforos
    struct sembuf down = {num_semaforo, -1, 0};
    return semop(conj_semaforos, &down, 1);
}

void agregarColor(void){
    agregarNaranja();
    agregarVerde();
    agregarVioleta();
}

void agregarNaranja(void) { //agrega el color naranja a la memoria compartida
    down(semaforos, CLUB2);
    down(semaforos, MUTEX);
    agregar('n');
    printf("Club 2 coloca color: nar\n");
    up(semaforos, CLUB1);
    up(semaforos, MUTEX);
}

void agregarVerde(void) { // agrega el color verde a la memoria compartida
    down(semaforos, CLUB2);
    down(semaforos, MUTEX);
    agregar('v');
    printf("Club 2 coloca color: ver\n");
    up(semaforos, CLUB1);
    up(semaforos, MUTEX);
}

void agregarVioleta(void) { //agrega el color violeta a la memoria compartida
    down(semaforos, CLUB2);
    down(semaforos, MUTEX);
    agregar('o'); // Se utiliza la letra o para poder diferenciar violeta de verde
    printf("Club 2 coloca color: vio\n");
    up(semaforos, CLUB1);
    up(semaforos, MUTEX);

    // como agregarVioleta() es la ultima funcion a ejecutar es la que se encarga de imprimir la bandera final
    // y elimiar el conjunto de semaforos y el espacio de memoria compartida.
    printf("Bandera: %s\n", shmptr); 
    semctl(semaforos, 0, IPC_RMID, 0);
    shmctl(shmid, IPC_RMID,0);
}

void agregar(char g) {
    char buffer[SEGSIZE];
    strcpy(buffer, shmptr);
    switch (g)    {
    case 'n': // agrega naranja a la memoria compartida
        strcat(buffer, "nar");
        strcpy(shmptr, buffer);
        break;
    case 'v': // agrega verde a la memoria compartida
        strcat(buffer, "ver");
        strcpy(shmptr, buffer);
        break;
    case 'o': // agrega violeta a la memoria compartida
        strcat(buffer, "vio");
        strcpy(shmptr, buffer);
        break;
    }
}
