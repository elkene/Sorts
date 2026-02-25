#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sorts.h"

void print_lista(int *arr, int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\n");
}

int comp_int(const void *a, const void *b)
{
    int x = *(const int*)a;
    int y = *(const int*)b;
    return (x > y) - (x < y);   // forma segura sin overflow
}

int main(int argc, char **argv)
{
    if (argc < 2) {
        printf("Uso: %s [insert|select|bubble]\n", argv[0]);
        return 1;
    }

    char *tipo = argv[1];

    int a[] = {10, 5, 9, 4, 1};
    int n = sizeof(a) / sizeof(a[0]);

    if (strcmp(tipo, "insert") == 0)
        insert_sort(a, n, sizeof(int), comp_int);

    else if (strcmp(tipo, "select") == 0)
        select_sort(a, n, sizeof(int), comp_int);

    else if (strcmp(tipo, "bubble") == 0)
        bubble_sort(a, n, sizeof(int), comp_int);

    else {
        printf("Algoritmo no válido.\n");
        return 1;
    }

    print_lista(a, n);

    return 0;
}