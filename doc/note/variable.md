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
-  char   : ký tự
-  int    : số nguyên
-  float  : số thực
-  double : số thực độ chính xác cao hơn

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
+ int    : `%d`
+ float  : `%f`
+ char   : `%c`
+ double : `%lf`
> printf() không tự biết kiểu dữ liệu của các giá trị/dữ liệu phía sau, nên cần ký hiệu để biết cách diễn giải và in dữ liệu.