#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFSIZE 4096

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s src dst\n", argv[0]);
        return 1;
    }

    int src = open(argv[1], O_RDONLY);
    if (src < 0) { perror("open src"); return 1; }

    int dst = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (dst < 0) { perror("open dst"); return 1; }

    char buf[BUFSIZE];
    ssize_t n;
    while ((n = read(src, buf, BUFSIZE)) > 0) {
        if (write(dst, buf, n) != n) {
            perror("write"); return 1;
        }
    }

    printf("Copy complete.\n");
    close(src);
    close(dst);
    return 0;
}