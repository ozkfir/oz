
#include <stdio.h>
#include <stdlib.h>
#define ARR_LEN 50

void shift_element(int *arr, int i);

void insertion_sort(int *arr, int len);

int main() {
    int *arr , i;
    arr = (int *) malloc(ARR_LEN * sizeof(int));
    for (i = 0; i < ARR_LEN; ++i) {
        scanf(" %d", (arr + i));
    }

    insertion_sort(arr, ARR_LEN);
    for (i = 0; i < ARR_LEN; i++) {
        if (i != ARR_LEN - 1)
            printf("%d,", *(arr + i));
        else
            printf("%d\n", *(arr + i));

    }
    free(arr);
    return 0;
}

void shift_element(int *arr, int i) {
    for (; i > 0;) {
        *(arr + i) = *(arr + i - 1);
        i--;
    }
}

void insertion_sort(int *arr, int len) {
    int *temp;
    temp = arr;

    while (temp < len + arr - 1)
    {
        if (*temp > *(temp + 1))
        {
            int i = 0;
            while (*(arr + i) < *(temp + 1)) {
                i++;
            }
            int swap = *(temp + 1);
            shift_element((arr + i), (temp + 1 - (arr + i)));
            *(arr + i) = swap;
        }
        temp += 1;
    }
}

