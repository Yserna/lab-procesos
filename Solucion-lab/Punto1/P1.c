#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    int x = 100;
    if(fork() == 0) {
        x =+ 1;
        printf("El valor de x en el proceso hijo es: %d\n", x);
    } else {
        x =+ 2;
        printf("El valor de x en el proceso padre es: %d\n", x);
    } 
    return 0;
}