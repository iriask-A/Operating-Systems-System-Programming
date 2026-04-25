#include<stdio.h>
#include<fcntl.h>
#include<string.h> 
#include<unistd.h> 
#include<stdlib.h> 

int main()
{
    int sz;

    int fd = open("foo.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd < 0)
    {
        perror("r1");
        exit(1);
    }

    sz = write(fd, "hello OS&SP\n", strlen("hello OS&SP\n"));

    printf("called write(%d, \"hello OS&SP\\n\", %d)."
           " It returned %d\n", fd, (int)strlen("hello OS&SP\n"), sz);

    close(fd);
    return 0;
}