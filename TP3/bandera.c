#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

pid_t pid;

    int main(int argc,char *argv[]){

    pid = fork();
    if(pid){ 
        execv("./club2",NULL); 
    }else{ 
        execv("./club1",NULL); 
    }
    
return 0;
}