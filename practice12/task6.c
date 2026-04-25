#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define SECTOR_SIZE 512
int writeSector(int fd, int sector_number,
                const unsigned char *buf) {
    off_t offset = (off_t)sector_number * SECTOR_SIZE;
    if (lseek(fd, offset, SEEK_SET) == -1) {
        perror("lseek"); return -1;
    }
    ssize_t n = write(fd, buf, SECTOR_SIZE);
    if (n != SECTOR_SIZE) {
        perror("write"); return -1;
    }
    fsync(fd); 
    return 0;
}
int main() {
    unsigned char buf[SECTOR_SIZE];
    memset(buf, 0xAB, SECTOR_SIZE); 
    int fd = open("disk.img", O_RDWR);
    if (fd < 0) { perror("open"); return 1; }
    if (writeSector(fd, 5, buf) == 0)
        printf("Sector 5 written successfully.\n");
    close(fd);
    return 0;
}