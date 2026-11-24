# 23 - 10 - 2026
## 1.BỘ NHỚ LÀ GÌ?
- khi chạy chương trình, pc cần RAM để lưu biến,data và những thứ chương trình đang sử dụng
Ví dụ:

```C
#include <stdio.h>

int main() {
    int a = 10;
    int b = 20;

    printf("%d\n", a + b);

    return 0;
}
```

Chương trình cần chỗ để lưu `a`, `b` và thực hiện các phép tính.

- Hãy hình dung RAM như một căn phòng có nhiều ngăn. Mỗi biến cần một vùng nhớ để lưu giá trị của nó.
- Nếu bạn muốn lưu dữ liệu mà kích thước chỉ được quyết định khi chương trình đang chạy, chẳng hạn người dùng nhập số lượng sinh viên, bạn sẽ cần một cách quản lý bộ nhớ linh hoạt hơn.

> Đó là lúc Dynamic Memory xuất hiện.

## 2. STACK VÀ HEAP
- `stack`: khu vực thường dùng cho bién cực bộ và thông tin phục vụ lời gọi hàm
- `heap` : khu vực có thể cấp phát bộ nhứo động trong lúc chương trình chạy
>lưu ý: Stack và Heap là mô hình phổ biến để hiểu chương trình C, không phải mọi chi tiết đều được chuẩn C quy định cố định.

- `static storage`: dành cho các đối tượng có thười gian lưu trữ tĩnh,tồn tại suốt thời gian chương trình chạy
  Thông thường, biến đã khởi tạo khác 0 nằm ở `.data`, còn biến toàn cục hoặc `static` khởi tạo bằng 0 nằm ở `.bss`.

- `code/Text segment`: thường chứa mã máy thực thi của chương trình 
#### Phân biệt `static` keyword và static storage duration

Đây là chỗ dễ nhầm nhất!

```c
int global = 10;  // Thời gian lưu trữ tĩnh

void demo(void) {
    int x = 10;         // Thời gian lưu trữ tự động
    static int count = 0; // Thời gian lưu trữ tĩnh
    count++;
}
```

- `global`: tồn tại suốt thời gian chạy chương trình.
- `x`: chỉ tồn tại trong thời gian thực thi của lần gọi hàm đó.
- `count`: tồn tại suốt thời gian chạy chương trình, dù chỉ được khai báo bên trong hàm.

Gọi `demo()` ba lần thì `count` lần lượt là `1`, `2`, `3`. Nó không bị tạo lại từ đầu mỗi lần gọi hàm.

Mẹo nhớ: `static` bên trong hàm không có nghĩa là biến nằm trên stack nhưng tồn tại lâu hơn. Nó có thời gian lưu trữ tĩnh, thường được đặt ở vùng dữ liệu tĩnh.

#### Một số vùng phụ thường gặp

|Vùng|Thường chứa gì?|
|---|---|
|`.data`|Biến toàn cục và `static` đã khởi tạo giá trị khác 0|
|`.bss`|Biến toàn cục và `static` được khởi tạo bằng 0 hoặc không khởi tạo tường minh|
|`.rodata`|Hằng chuỗi và dữ liệu chỉ đọc, nếu hệ thống dùng vùng này|
|`text`|Mã máy của chương trình|
|`heap`|Bộ nhớ cấp phát động|
|`stack`|Khung gọi hàm và thường là biến cục bộ|

Đây là cách phân chia phổ biến, không phải sơ đồ bắt buộc của mọi nền tảng. Biến cục bộ cũng không nhất thiết luôn nằm trên stack, vì trình biên dịch có thể giữ nó trong thanh ghi hoặc tối ưu hóa bỏ nó.
## 3. `malloc()` LÀ GÌ?

`malloc()` là hàm yêu cầu cấp phát 1 vùng nhớ có kích thước tính bằng byte
- dùng nó cần có `#include <stdlib.h>`
Ví dụ:
```C
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *p = malloc(sizeof(int));

    if (p == NULL) {
        return 1;
    }

    *p = 10;

    printf("%d\n", *p);

    free(p);

    return 0;
}
```

Kết quả:

```
10
```
- trong đó:
- `malloc(sizeof(int))` : yêu cầu vùng nhớ đủ chứa 1 đối tượng kiểu int - nếu thành công, `p` nhận địa chỉ vùng nhớ được cấp phát, thất bại trả về NULL
-  `*p` = 10 ghi giá trị vào vùng nhớ mà `p` trỏ tới
- `free(p)` giải phóng bộ nhớ,sau đó ko được truy cập vào vùng nhớ đó thông qua `p`
> sự khác nhau giữa `p` và `*p`
- `p` = địa chỉ đang lưu trong con trỏ
- `*p` = truy cập đối tượng tại địa chỉ mà con trỏ trỏ tới - tức là giá trị của đối tượng

### CẤP PHÁT ĐỘNG VỚI MALLOC()

Mảng này có chỗ chứa 5 số nguyên. Nhưng nếu người dùng nhập số lượng phần tử khi chương trình đang chạy thì sao?

Ta có thể dùng `malloc()`.

```C
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Nhap so phan tu: ");
    scanf("%d", &n);

    int *a = malloc(n * sizeof(int));

    if (a == NULL) {
        return 1;
    }

    for (int i = 0; i < n; i++) {
        a[i] = i * 10;
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    free(a);
    return 0;
}
```

Ví dụ nhập `4`, kết quả:

```
0 10 20 30
```

## Hiểu 3 điểm quan trọng

1. Cấp phát đủ chỗ cho `n` số nguyên

```C
int *a = malloc(n * sizeof(int));
```

- `sizeof(int)`: kích thước một số nguyên.
- `n * sizeof(int)`: tổng số byte cần xin.
- `a`: con trỏ trỏ đến phần tử đầu tiên.
    

2. Truy cập như mảng bình thường

```C
a[i] = i * 10;
```

Dù `a` là con trỏ, bạn vẫn có thể dùng `a[i]` để truy cập phần tử thứ `i`, miễn là vùng nhớ đủ lớn và còn hợp lệ.

3. Nhớ giải phóng

```C
free(a);
```

Khi không cần mảng nữa, giải phóng vùng nhớ. Không truy cập `a[i]` sau đó.

Lưu ý: ví dụ trên giả định `n > 0`. Chương trình thực tế cần kiểm tra dữ liệu nhập và giới hạn `n` trước khi cấp phát.

## 4. `calloc()` LÀ GÌ?

- cấp phát bộ nhớ động cho nhiều phần tử và khởi tạo tất cả các byte của vùng nhớ về 0
Cú pháp:

```c
calloc(so_phan_tu, kich_thuoc_moi_phan_tu);
```

Ví dụ:

```c
int *a = calloc(5, sizeof(int));
```

Nghĩa là xin bộ nhớ đủ chứa 5 số nguyên, các phần tử `int` ban đầu có giá trị `0`.

có gì khác nhau so với `malloc()`?
- `malloc()` cấp phát số vùng nhớ và không có giá trị ban đầu
- `calloc()` cấp phát vùng nhớ và có giá trị ban đầu là 0
```C
int *a = malloc(n*sizeof(int));  // {?,?,?,?,?} chua co gia tri mac dinh!
int *b = calloc(5,sizeof(int)); // {0,0,0,0,0}
```

cả 2 đều trả về NULL nếu cấp phát thất bại,đều cần giải phóng = `free()`
## 5. `realloc()` 
- dùng để tang thêm vùng nhớ, tức nới mảng ra
### Cú pháp

```c
realloc(con_tro_cu, kich_thuoc_moi);
```

Ví dụ:

```c
int *temp = realloc(a, 5 * sizeof(int));

if (temp != NULL) {
    a = temp;
}
```

Giải thích:
- `a`: con trỏ đến vùng nhớ đã cấp phát.
- `5 * sizeof(int)`: kích thước mới, đủ chứa 5 số nguyên.
- `temp`: nhận kết quả cấp phát lại.

Tại sao không viết luôn `a = realloc(a, ...)`?

Nếu `realloc()` thất bại với kích thước khác 0, nó trả về `NULL`. Gán thẳng vào `a` sẽ làm mất địa chỉ vùng nhớ cũ, gây rò rỉ bộ nhớ. Dùng `temp` giúp giữ lại `a` nếu thất bại.

###  Dữ liệu cũ có mất không?

Nếu yêu cầu cấp phát lại thành công, dữ liệu cũ được giữ nguyên trong phần vùng nhớ còn nằm trong kích thước mới.

`realloc()` có thể mở rộng ngay vùng nhớ cũ hoặc chuyển dữ liệu sang vùng nhớ mới. Vì vậy, hãy sử dụng con trỏ trả về sau khi thành công, không mặc định địa chỉ cũ vẫn còn đúng.

### nếu 2 con trỏ trỏ cùng 1 vùng bộ nhớ thì sao?

```C
int *tmp = calloc(5*sizeof(int));

int *a = tmp;

int *b = a;

```

 - nếu `free(a)`, `b` có dùng được địa chỉ cũ đó ko?
 - đáp án: không - vùng nhớ đó đã bị giải phóng, , các con trỏ vẫn giữ địa chỉ nhưng không được phép sử dụng để truy cập mảng nữa