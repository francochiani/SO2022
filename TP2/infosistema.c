// infosistema.c
#include <sys/utsname.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char * argv[]){

    struct utsname unameData;
    uname(&unameData);

    printf("Tipo de Sistema: %s\n", unameData.sysname);
    printf("Nombre del Equipo: %s\n", unameData.nodename);
    printf("Version del Kernel: %s\n", unameData.release);
    printf("Version del S.O.: %s\n", unameData.version);
    printf("Arquitectura: %s\n", unameData.machine);

    return 0;
}