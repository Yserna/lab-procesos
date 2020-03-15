#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

    int fd[2];
    char buffer[30];

    pipe(fd); 

    switch(fork()){
    
        case -1:
            printf("No se ha podido crear un hijo \n");
            exit(-1);
            break;
        case 0: 
            close(fd[0]);
            printf("El proceso hijo escribe en el PIPE... \n");
            write(fd[1], "Proceso hijo ha escrito", 25);
            break;
        default:
            close(fd[1]);
            printf("El proceso padre lee el PIPE \n");
            read(fd[0], buffer, 25);
            printf("Mensaje leido: %s \n", buffer);
    }
    return 0;
}