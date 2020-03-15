 #include <stdio.h> 
 #include <unistd.h>

int main (void){

    if(fork() == 0) {  
        printf("Hello\n" ); } 
    else {  
        sleep(2);     
        printf("Goodbye\n"); 
    } 

    return 0; 
}


//Se hizo uso de la función sleep, en lugar de await