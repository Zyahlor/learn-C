# 30 - 10 - 2026

## 1. Preprocessor là gì?

- Preprocessor - bộ tiền xử lý: là phần chạy trước khi compiler biên dịch mã C
- nó xử lý những chỉ thị bắt đầu = `#`
Ví dụ:

```c
#include <stdio.h>

#define MAX 100

int main() {
    printf("%d\n", MAX);
    return 0;
}
```

Quá trình xử lý:
```text
1. Source code (.c) - Mã nguồn ban đầu

2. Preprocessor - Xử lý #include, #define, #ifdef...

3. Compiler - Biên dịch mã C

4. Executable - Chương trình thực thi
```
>Hãy nhớ: Preprocessor không phải compiler. Nó chuẩn bị mã nguồn trước khi compiler làm việc.

## 2. `#include`

Bạn đã gặp nó rất nhiều lần:

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
```

Nó yêu cầu Preprocessor đưa nội dung của một file header vào vị trí chỉ thị `#include`.
Có hai cách viết phổ biến:

Cách 1:

```c
#include <stdio.h>
```

Dùng cho header thư viện hệ thống hoặc thư viện được cấu hình trong môi trường biên dịch.

Cách 2:

```c
#include "thuvien.h"
```

Thường dùng cho header do bạn tự tạo trong project.
Ví dụ cấu trúc:

```
project/
├── main.c
├── thuvien.c
└── thuvien.h
```

Trong `main.c`:

```c
#include "thuvien.h"
```

Nghĩa là bạn muốn sử dụng những khai báo được cung cấp từ `thuvien.h`.
>Lưu ý: `#include` không tự động biên dịch file `.c` đi kèm. File `.c` vẫn cần được biên dịch và liên kết riêng.

## 3. `define`
- Đây là một trong những chỉ thị quan trọng nhất.
- #Macro: Tên đại diện cho văn bản được thay thế trong quá trình tiền xử lý.
- `#define` dùng để định nghĩa macro.
Ví dụ:
```c
#define MAX 100
```

Khi Preprocessor gặp `MAX`, nó thay thế bằng `100`.
```c
#include <stdio.h>
#define MAX 100

int main() {
    int arr[MAX];

    printf("%d", MAX);

    return 0;
}
```

Sau khi xử lý, đoạn mã tương đương:

```c
#include <stdio.h>

int main() {
    int arr[100];

    printf("%d", 100);

    return 0;
}
```

Một số ví dụ khác:
```c
#define PI 3.14159
#define NAME "Bao"
#define VERSION 1
```
### Macro có tham số

`#define` còn có thể tạo macro giống hàm:

```c
#define SQUARE(x) ((x) * (x))
```
Sử dụng:
```c
int a = SQUARE(5);
```
Sau khi thay thế:
```c
int a = ((5) * (5));
```

Kết quả là `25`.
**Tại sao phải có nhiều dấu ngoặc?**
- Vì macro chỉ thay thế văn bản, không hoạt động giống một hàm C thông thường.
Ví dụ macro nguy hiểm:

```c
#define SQUARE(x) x * x

int a = SQUARE(2 + 3);
```
Nó trở thành:
```c
int a = 2 + 3 * 2 + 3;
```
Kết quả là `11`, không phải `25`.

Vì vậy hãy nhớ quy tắc: Macro có tham số nên bọc tham số và toàn bộ biểu thức bằng ngoặc.

## 4. `ifdef`, `#ifndef`, `#endif`
- Đây là nhóm chỉ thị giúp kiểm tra một macro có được định nghĩa hay chưa.
### 1.`#ifdef`
- nếu macro đã được định nghĩa -> biên dịch phần code bên trong

```C
#define DEBUG

#ifdef DEBUG
    printf("Debug mode\n");
#endif
```
- Nếu `DEBUG` tồn tại, đoạn `printf` được giữ lại sau tiền xử lý.
Nếu xóa:
```c
// #define DEBUG
```

Thì đoạn code bên trong `#ifdef` bị loại bỏ.

### 2. `ifndef`
- ngược lại với `#ifdef`
- nếu marco chưa được định nghĩa - xử lý phần code bên trong
```C
#ifndef DEBUG
    printf("Debug is disabled\n");
#endif
```

### 3. `#endif`
- đánh dấu kết thúc khối điều kiện tiền xử lý
Ví dụ:
```c
#define WINDOWS

#ifdef WINDOWS
    printf("Windows\n");
#endif
```

Bạn có thể hình dung:

|Chỉ thị|Ý nghĩa|
|---|---|
|`#ifdef`|Nếu đã định nghĩa|
|`#ifndef`|Nếu chưa định nghĩa|
|`#endif`|Kết thúc điều kiện|
## 5. Header Guard

Giả sử project có:

```
project/
├── main.c
├── a.h
└── b.h
```

Trong `a.h`:

```c
#include "b.h"
```

Trong `main.c`:

```c
#include "a.h"
#include "b.h"
```

- Lúc này `b.h` có thể bị include nhiều lần.

**Việc include header nhiều lần có thể gây lỗi khai báo lại, đặc biệt với `struct`, `enum`, `typedef`.**

Giải pháp: Header Guard.

```c
#ifndef MY_HEADER_H
#define MY_HEADER_H

typedef struct {
    int id;
    int age;
} Student;

#endif
```

Cơ chế hoạt động:

1. Kiểm tra `MY_HEADER_H` đã tồn tại chưa.
2. Nếu chưa tồn tại, tiếp tục xử lý.
3. Định nghĩa `MY_HEADER_H`.
4. Đọc nội dung header.
5. Kết thúc tại `#endif`.

## MỞ RỘNG

### 1. `#if`, `#elseif` , `else`
- Bạn đã biết `#ifdef` kiểm tra macro có tồn tại không.
- Còn `#if` cho phép kiểm tra điều kiện dựa trên giá trị macro.
Ví dụ:
```c
#include <stdio.h>

#define VERSION 2

int main() {
    #if VERSION == 1
        printf("Version 1");
    #elif VERSION == 2
        printf("Version 2");
    #else
        printf("Unknown version");
    #endif

    return 0;
}
```
Kết quả:
```
Version 2
```

Điểm khác biệt:
- `#ifdef`: Kiểm tra macro có tồn tại.
- `#if`: Kiểm tra biểu thức có đúng không.
### 2. `undef`
- Dùng để hủy định nghĩa một macro đã được tạo bằng `#define`.
Ví dụ:
```c
#include <stdio.h>

#define DEBUG

int main() {
    #ifdef DEBUG
        printf("Debug ON\n");
    #endif

    #undef DEBUG

    #ifdef DEBUG
        printf("Debug ON\n");
    #else
        printf("Debug OFF\n");
    #endif

    return 0;
}
```
Kết quả:
```
Debug ON
Debug OFF
```

`#undef DEBUG` không xóa code hay biến. Nó chỉ xóa định nghĩa macro `DEBUG` khỏi quá trình tiền xử lý tại vị trí đó.
### 3. `__FILE__` VÀ `__LINE__`
Đây là hai macro có sẵn của C.

- `__FILE__`: Trả về tên file đang được biên dịch.
- `__LINE__`: Trả về số dòng hiện tại trong source code.
Ví dụ:
```C
#include <stdio.h>

int main() {
    printf("File: %s\n", __FILE__);
    printf("Line: %d\n", __LINE__);

    return 0;
}
```

Ví dụ kết quả:

```
File: main.c
Line: 5
```

- Ứng dụng: Khi chương trình có lỗi, bạn có thể biết thông báo được tạo ra từ file nào và dòng nào.
- Kết hợp thành macro logging:

```C
#include <stdio.h>

#define LOG(msg) \
    printf("[%s:%d] %s\n", __FILE__, __LINE__, msg)

int main() {
    LOG("Program started");
    LOG("Connecting to server");

    return 0;
}
```

Kết quả:

```
[main.c:8] Program started
[main.c:9] Connecting to server
```

Đây là kỹ thuật khá hữu ích khi viết các công cụ C.

### 4.`extern`

Giả sử project có 2 file:

```
project/
├── main.c
└── config.c
```

Trong `config.c`, bạn có biến:

```
int version = 2;
```

Bây giờ bạn muốn sử dụng biến `version` trong `main.c`.

Nếu viết:

```c
#include <stdio.h>

int main(void) {
    printf("%d", version);
    return 0;
}
```

Compiler sẽ báo lỗi vì `main.c` chưa biết `version` là gì.
- dùng `extern`:

Trong `main.c`:

```c
#include <stdio.h>

extern int version;

int main(void) {
    printf("Version: %d\n", version);
    return 0;
}
```

Trong `config.c`:

```c
int version = 2;
```

Biên dịch:

```
gcc main.c config.c -o program
```

Kết quả:

```
Version: 2
```

- Hiểu bản chất

```c
extern int version;
```

Nó có nghĩa:

> Biến `version` được định nghĩa ở một nơi khác. Tôi muốn sử dụng nó ở đây.

### 2.`static`
Khái niệm:
- `static` là từ khóa trong C, có ý nghĩa khác nhau tùy vị trí sử dụng. Khi khai báo biến hoặc hàm ở phạm vi file (global scope), `static` giới hạn khả năng liên kết (linkage) của chúng trong chính file `.c` đó.

Nói đơn giản: `static` ở cấp độ file giúp che giấu biến và hàm, không cho file `.c` khác truy cập trực tiếp.
#### 1. `static` với biến toàn cục

```c
// config.c
static int age = 20;
```

- Biến chỉ có internal linkage.
- Chỉ được truy cập trực tiếp trong `config.c`.
- File `.c` khác không thể truy cập biến này bằng `extern`.

#### 2. `static` với hàm

```c
// config.c
static void secret(void) {
    printf("Secret\n");
}
```

- Hàm chỉ có internal linkage.
- Chỉ được gọi trực tiếp trong `config.c`.
- File `.c` khác không thể liên kết đến hàm này.
#### 3. So sánh `static` và `extern`

|Từ khóa|Ý nghĩa|
|---|---|
|`static` ở cấp độ file|Internal linkage, giới hạn trong file|
|`extern`|Khai báo một biến/hàm có external linkage được định nghĩa ở nơi khác|

#### 4. Lưu ý

`static` còn có cách sử dụng khác khi khai báo biến bên trong hàm:

```c
void counter(void) {
    static int count = 0;
    count++;
    printf("%d\n", count);
}
```

Biến `count`:

- Chỉ có phạm vi truy cập bên trong hàm `counter()`.
- Tồn tại trong suốt thời gian chương trình chạy.
- Giữ nguyên giá trị giữa các lần gọi hàm.

Ghi nhớ: `static` không chỉ đơn giản là giới hạn phạm vi. Nó còn ảnh hưởng đến thời gian tồn tại của biến tùy vị trí khai báo.

### 3.static variable
#### 1. Local variable thông thường

```c
void counter(void) {
    int count = 0;
    count++;
    printf("%d\n", count);
}
```

Gọi 3 lần:

```c
counter();
counter();
counter();
```

Kết quả:

```
1
1
1
```

Vì mỗi lần gọi hàm, `count` được tạo mới và khởi tạo lại bằng `0`.

#### 2. Static local variable

```c
void counter(void) {
    static int count = 0;
    count++;
    printf("%d\n", count);
}
```

Gọi 3 lần:

```
1
2
3
```

Vì `count` chỉ được khởi tạo một lần và giữ nguyên giá trị giữa các lần gọi hàm.

#### 3. So sánh

|Đặc điểm|Local thông thường|Static local|
|---|---|---|
|Phạm vi truy cập|Trong block/hàm|Trong block/hàm|
|Thời gian tồn tại|Trong lần thực thi block|Suốt chương trình|
|Khởi tạo|Mỗi lần vào block|Một lần|
|Giữ giá trị sau khi hàm kết thúc|Không|Có|