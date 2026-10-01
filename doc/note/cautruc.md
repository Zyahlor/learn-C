# 11-09-2026
# cấu trúc chương trình C
# 1. chương trình tối thiểu
``` c
#include <stdio.h>

int main() {
    printf("Hello World\n");

    return 0;
}
```

- trong đó:
+ `#include <stdio.h>` : nạp thư viện vào dùng `printf()`
+ `int main()` : điểm bắt đầu chương trình
+ `{}` : khối lệnh
+ `printf()` : in dữ liệu ra màn hình
+ `return 0;` : kết thúc main, trả về 0

# 2. kết thúc lệnh
- Python không yêu cầu `;` để kết thúc statement.
JavaScript cho phép bỏ `;` trong nhiều trường hợp nhờ Automatic Semicolon Insertion (ASI).
C yêu cầu `;` ở cuối các statement phù hợp.
```C
printf("Hello\n");
return 0;
```
- nếu thiếu:
```C
printf("Hello\n") // -> lỗi cú pháp
```
# 2. comment
```C
// Comment một dòng

/*
   Comment
   nhiều dòng
*/
```