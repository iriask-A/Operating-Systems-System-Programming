#include <stdio.h>
#include <string.h>

struct Course {
    int price;
    char name[100];
};

int main(){
    FILE *ptr = fopen("file.bin", "rb");

    struct Course fileData;

    while (fread(&fileData, sizeof(struct Course), 1, ptr)) {
        printf("Course Name = %s, Price = %d\n", fileData.name, fileData.price);
    }
    fclose(ptr);
    return 0;
}