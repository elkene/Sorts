#include <stdio.h>
#include <stdlib.h>
#include "sorts.h"

/* Comparación manual de strings */
int str_igual(const char *a, const char *b)
{
    while (*a && *b) {
        if (*a != *b)
            return 0;
        a++;
        b++;
    }

    /* ambas deben terminar al mismo tiempo */
    return (*a == '\0' && *b == '\0');
}

void print_lista(int *arr, int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\n");
}

int comp_int(const void *a, const void *b)
{
    int x = *(const int*)a;
    int y = *(const int*)b;

    if (x > y) return 1;
    if (x < y) return -1;
    return 0;
}

int main(int argc, char **argv)
{
    if (argc < 2) {
        printf("Uso: %s [insert|select|bubble]\n", argv[0]);
        return 1;
    }

    int a[] = {10, 5, 9, 4, 1};
    int n = sizeof(a) / sizeof(a[0]);

    if (str_igual(argv[1], "insert"))
        insert_sort(a, n, sizeof(int), comp_int);

    else if (str_igual(argv[1], "select"))
        select_sort(a, n, sizeof(int), comp_int);

    else if (str_igual(argv[1], "bubble"))
        bubble_sort(a, n, sizeof(int), comp_int);

    else {
        printf("Algoritmo no valido.\n");
        return 1;
    }

    print_lista(a, n);

    return 0;
}
