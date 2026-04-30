#include <stdio.h>
#include <stdlib.h>

int main() {
    int capacity = 3;
    int count = 0;
    int *arr = (int*) malloc(capacity * sizeof(int));
    if (!arr) return 1;

    for (int i = 0; i < 3; i++) arr[count++] = (i+1) * 5;
    printf("Before realloc (%d elements): ", count);
    for (int i = 0; i < count; i++) printf("%d ", arr[i]);
    printf("\n");

    capacity = 7;
    int *tmp = (int*) realloc(arr, capacity * sizeof(int));
    if (!tmp) { free(arr); return 1; }
    arr = tmp;

    for (int i = 3; i < 7; i++) arr[count++] = (i+1) * 5;
    printf("After realloc (%d elements): ", count);
    for (int i = 0; i < count; i++) printf("%d ", arr[i]);
    printf("\n");

    free(arr);
    return 0;
}
