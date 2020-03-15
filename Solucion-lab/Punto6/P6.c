#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main (void){
    int estado;
    printf("Empezando proceso %d\n", getpid());  
    if(fork() == 0) {
        int pid_h_espera = waitpid(-1, &estado, 0);
        printf("pid espera en proceso hijo: %d\n", pid_h_espera); 
    } else {
        int pid_h_espera = waitpid(-1, &estado, 0);
        printf("pid espera en proceso padre: %d\n", pid_h_espera);   
    }
    printf("Finalizando proceso %d\n", getpid());
    return 0;
}