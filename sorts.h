#pragma once
#include <stdlib.h>

typedef int (*fn_comparar)(const void*,const void*);
int comparar(const void *a,const void *b);

int select_sort(void *arr, size_t n, size_t s_item, fn_comparar comparar);
int bubble_sort(void *arr, size_t n, size_t s_item, fn_comparar comparar);
int insert_sort(void *arr, size_t n, size_t s_item, fn_comparar comparar);