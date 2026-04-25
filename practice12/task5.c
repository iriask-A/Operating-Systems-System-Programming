#include <stdio.h>
#include <fcntl.h>      
#include <unistd.h>

#define SECTOR_SIZE 512
int readSector(int fd, int sector_number, unsigned char *buf) { 
    off_t offset = (off_t)sector_number * SECTOR_SIZE;           
    if (lseek(fd, offset, SEEK_SET) == -1) {   
        perror("lseek");                    
        return -1;
    }
    ssize_t n = read(fd, buf, SECTOR_SIZE);    
    if (n != SECTOR_SIZE) {              
        perror("read");
        return -1;
    }                                         
    return 0;
}                                            
int main() {                                  
    unsigned char buf[SECTOR_SIZE];
    int fd = open("disk.img", O_RDONLY);
    if (fd < 0) { perror("open"); return 1; }  
    if (readSector(fd, 0, buf) == 0) {     
        printf("Sector 0 first 4 bytes: %02X %02X %02X %02X\n",
            buf[0], buf[1], buf[2], buf[3]);  }

    close(fd);
    return 0;
}