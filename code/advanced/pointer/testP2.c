#include <stdio.h>
// xoa phan tu dau , target chi dinh
int remove_first(int *arr, int *n, int target, int **pos) {
    for (int i = 0; i < *n; i++) {
        if (arr[i] == target) {
            for (int j = i; j < *n - 1; j++)
                arr[j] = arr[j + 1];
            (*n)--;
            *pos = arr + i;
            return 0;
        }
    }
    *pos = NULL;
    return -1;
}

void split_neg(int *arr, int n, int **first_neg, int **last_neg) {
    *first_neg = NULL;
    *last_neg = NULL;
    for (int *p = arr; p < arr + n; p++) {
        if (*p < 0) {
            if (*first_neg == NULL)
                *first_neg = p;
            *last_neg = p;
        }
    }
}

void clamp_ptr(int **pp, int *lo_bound, int *hi_bound) {
    if (*pp < lo_bound)
        *pp = lo_bound;
    else if (*pp > hi_bound)
        *pp = hi_bound;
}
int main(){
int arr[] = {1,2,3,4,5,6};
int n = sizeof(arr)/sizeof(arr[0]);
return 0;
}
