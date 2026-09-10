# 11-09-2026
# **VARIABLE**

# 1. biến là gì?
- là 1 vùng nhớ được đặt tên để lưu trữ dữ liệu
- khác vs python là biến trỏ vào object và kiểu dữ liệu động, C khai báo với một kiểu dữ liệu cố định và vùng nhớ tương ứng, kiểu của biến không thể thay đổi.
```C
int age = 19;

age = 20;       // ✅ đổi giá trị
age = "Bao";    // ❌ sai kiểu
```
# 2. kiểu dữ liệu cơ bản
-  char     : ký tự
-  int      : số nguyên
-  float    : số thực
-  double   : số thực độ chính xác cao hơn
-  signed   : số chứa cả âm và dương
-  unsigned : số chỉ chứa số dương
```C
char grade = 'A';
int age = 19;
float height = 1.75f;
double pi = 3.141592;
```
**chú ý:**
- char dùng nháy đơn: ` 'a' `
- string dùng nháy kép: ` 'bao' `
# 3. cách xuất dữ liệu
- tùy thuộc vào loại kiểu dữ liệu có cách xuất khác nhau:
+ int      : `%d`
+ float    : `%f`
+ char     : `%c`
+ double   : `%lf`
+ sizeof   : `%zu`
+ signed   : `%d`
+ unsigned : `%u`

> printf() không tự biết kiểu dữ liệu của các giá trị/dữ liệu phía sau, nên cần ký hiệu để biết cách diễn giải và in dữ liệu.
# 3. sizerof() là gì?
- dùng để kiểm tra kích thước của 1 kiểu dữ liệu,biến đơn vị là byte
```C
#include <stdio.h>

int main() {
    int age = 19;

    printf("%zu\n", sizeof(age)); // => 4 byte
    printf("%zu\n", sizeof(int)); // => 4 byte
                                // vì sao? vì ta khai báo age thuộc kiểu int, int có 4 byte bộ nhớ => age cũng vậy, có 4 byte bộ nhớ
    return 0;
}
```

**lưu ý:**⚠️ Không được mặc định mọi máy đều giống hệt nhau. Kích thước một số kiểu phụ thuộc implementation/compiler/platform, riêng char luôn = 1 byte theo chuẩn C