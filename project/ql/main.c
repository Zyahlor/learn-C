#include "thuvien.h"
#include <stdio.h>
#include <stdlib.h>
void menu(void);
int main() {
    sv *ds =NULL;
    int soluong = 0;
    int succhua = 0;
  while (true) {
    menu();
    int chon;
    printf("hay lua chon:");
    scanf("%d", &chon);
    switch (chon) {
    case 0: {
      printf("[+] ket thuc chuong trinh\n");
      return 0;
    }
    case 1: {
      printf("[+] 1. them sinh vien\n");

      break;
    }
    case 2: {
      printf("[+] 2. xoa sinh vien\n");

      break;
    }

    case 3: {
      printf("[+] 3. tim sinh vien theo ma\n");

      break;
    }
    case 4: {
      printf("[+] 4. hien thi danh sach\n");

      break;
    }
    case 5: {
      printf("[+] 5. luu danh sach vao file\n");

      break;
    }
    case 6: {
      printf("[+] 6. doc danh sach tu file\n");

      break;
    }
    default:
      printf("[!] chon sai gia tri can chon!\n");
    }
  }
  return 0;
}

