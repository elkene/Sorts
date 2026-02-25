#include "sorts.h"
#include <string.h>

int comparar(const void *a, const void *b){
    int x = *(const int*)a;
    int y = *(const int*)b;

    if (x > y) return 1;
    if (x < y) return -1;
    return 0;
}

int select_sort(void *arr, size_t n, size_t s_item, fn_comparar comparar)
{
    size_t i, j, min;
    char *base = (char*)arr;
    char temp[s_item];

    for (i = 0; i < n - 1; i++) {
        min = i;

        for (j = i + 1; j < n; j++) {

            void *a = base + (j * s_item);
            void *b = base + (min * s_item);

            if (comparar(a, b) < 0) {
                min = j;
            }
        }

        if (min != i) {
            void *a = base + (i * s_item);
            void *b = base + (min * s_item);

            memcpy(temp, a, s_item);
            memcpy(a, b, s_item);
            memcpy(b, temp, s_item);
        }
    }

    return 0;
}

int bubble_sort(void *arr, size_t n, size_t s_item, fn_comparar comparar)
{
    size_t i, j;
    char *base = (char*)arr;
    char temp[s_item];

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {

            void *a = base + (j * s_item);
            void *b = base + ((j + 1) * s_item);

            if (comparar(a, b) > 0) {

                memcpy(temp, a, s_item);
                memcpy(a, b, s_item);
                memcpy(b, temp, s_item);
            }
        }
    }

    return 0;
}

int insert_sort(void *arr, size_t n, size_t s_item, fn_comparar comparar)
{
    size_t i, j;
    char *base = (char*)arr;
    char temp[s_item];

    for (i = 1; i < n; i++) {
        j = i;

        while (j > 0) {

            void *a = base + (j * s_item);
            void *b = base + ((j - 1) * s_item);

            if (comparar(a, b) < 0) {

                memcpy(temp, a, s_item);
                memcpy(a, b, s_item);
                memcpy(b, temp, s_item);

                j--;
            } else {
                break;
            }
        }
    }

    return 0;
}
