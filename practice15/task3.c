#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = 6;

    double *data = (double*) calloc(n, sizeof(double));
    if (!data) { return 1; }

    printf("Initial values (all should be 0.0):\n");
    for (int i = 0; i < n; i++)
        printf(" data[%d] = %.1f\n", i, data[i]);

    data[0] = 3.14; data[1] = 2.71;
    data[2] = 1.41; data[3] = 1.73;

    printf("\nAfter assignment:\n");
    for (int i = 0; i < n; i++)
        printf(" data[%d] = %.2f\n", i, data[i]);

    free(data);
    data = NULL;
    return 0;
}
