#include <stdio.h>

int main() {
    FILE * fp;
    char c;
    printf(" File Handling\n");
    fp = fopen("demo.txt", "w");
    while ((c = getchar()) != EOF) {
        fputc(c, fp);
    }
    fclose(fp);
    printf("Data Entered:\n");

    fp = fopen("demo.txt", "r");
    while ((c = fgetc(fp)) != EOF) {
        printf("%c", c);
    }
    fclose(fp);
    return 0;
}