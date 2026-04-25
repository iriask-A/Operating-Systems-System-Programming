// C program to illustrate close system Call
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
    // assume that foo.txt is already created
    int fd1 = open("foo.txt", O_RDONLY, 0);
    printf("fd1 = %d\n", fd1);
    close(fd1);

    // assume that bar.txt is already created
    int fd2 = open("bar.txt", O_RDONLY, 0);

    printf("fd2 = %d\n", fd2);
    exit(0);
}