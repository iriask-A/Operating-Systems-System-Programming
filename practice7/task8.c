#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]){
    
    void *currentBreak = (void *)sbrk(0);
    printf("%p\n", currentBreak);
}