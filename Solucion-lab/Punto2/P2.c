#include <unistd.h>
#include <stdio.h>
#include <fcntl.h> 
#include<string.h> 

int main(int argc, char *argv[]) {
    int sz;
    int fd = open("foo.txt", O_WRONLY | O_CREAT);  
    printf("fd = %d\n", fd); 

    if(fork() == 0) {
        sz = write(fd, "Proceso hijo\n", strlen("Proceso hijo\n")); 
        printf("File descriptor desde el proceso hijo: %d\n", fd);
        printf("Número de bytes en proceso hijo: %d\n", sz);

    } else {
        sz = write(fd, "Proceso padre\n", strlen("Proceso padre\n")); 
        printf("File descriptor desde el proceso padre: %d\n", fd);
        printf("Número de bytes en el proceso padre: %d\n", sz);
    } 

    return 0;
}
