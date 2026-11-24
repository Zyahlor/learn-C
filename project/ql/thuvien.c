#include "thuvien.h"
#include <stdio.h>
#include <stdlib.h>
void menu() {
  printf("==== menu ====\n");
  printf("1. them sinh vien\n");
  printf("2. xoa sinh vien\n");
  printf("3. tim sinh vien theo ma\n");
  printf("4. hien thi danh sach\n");
  printf("5. luu danh sach vao file\n");
  printf("6. doc danh sach tu file\n");
  printf("0. thoat\n");
  printf("================\n");
}

void themSinhVien(sv **ds, int *soLuong, int *sucChua) {
  if (*sucChua == 0) {
    sv *tmp = malloc(2 * sizeof(sv));
    if (tmp == NULL) {
      printf("[!] khong the cap phat bo nho!\n");
      return;
    }
    *ds = tmp;
    *sucChua = 2;
  }
  if (*soLuong == *sucChua) {
    sv *tmp = realloc(*ds, (*sucChua * 2) * sizeof(sv));
    if (tmp == NULL) {
      printf("[!] khong the cap phat bo nho!\n");
      return;
    }
    *ds = tmp;
    *sucChua *= 2;
  }
}
