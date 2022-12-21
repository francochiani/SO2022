// huesped.c
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
int main (int argc, char *argv[])
{
int pid_c, i;
pid_c = atoi(argv[1]);
for(i=1; i<=30; i++){
if(i%5!=0){
printf("Pedido de tostada de Pan Blanco. Huesped: %d\n", i);
kill(pid_c, SIGUSR1);
}
else{
printf("Pedido de tostada de Pan Negro. Huesped: %d\n", i);
kill(pid_c, SIGUSR2);
}
sleep(3);
}
return 0;
}