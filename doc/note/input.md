# 11-09-2026
# INPUT
- ta đã biết xuất dữ liệu = printf(), bây giờ sẽ học nhập dữ liệu từ bàn phím

## 1. scanf()
- dùng để đọc dữ liệu user nhập vào
```C
#include <stdio.h>

int main() {
    int age;

    printf("Nhap tuoi: ");
    scanf("%d", &age);

    printf("Tuoi cua ban: %d\n", age);

    return 0;
}
```
**tại sao có &age ?**
 - age => tên biến được khai báo
 - &age  => lấy địa chỉ của biến age

khi có địa chỉ của biến, scanf() ghi lên vùng bộ nhớ đc cấp của biến 
