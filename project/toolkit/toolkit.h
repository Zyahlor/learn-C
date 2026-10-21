#ifndef TOOLKIT_H
#define TOOLKIT_H
void swap(int *a,int *b);
void printArr(const int *a, int n);
void fill(int *a, int n, int v);
int *find(int *a, int n, int x);
void reverse(int *a, int n);
int *findMax(int *a, int n);
// các hàm sau thêm ở đợt 2: rotateLeft, bubbleSort, removeDup
void rotateLeft(int *a, int n, int k);
void bubbleSort(int *a, int n);
void removeDup(int *a, int *n);
#endif
