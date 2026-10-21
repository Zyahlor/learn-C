# 07 - 10 - 2026
## 1. Pointer là gì?
- biến chứa địa chỉ bộ nhớ của biến khác
- trong 1 biến `*p` - nếu có dấu `*` trước tên biến thì sẽ cho ta truy cập vào giá trị của biến được trỏ tới, còn mỗi tên biến là lưu địa chỉ

```C
int a = 10;
int *p = &a; // p lưu địa chỉ của a

printf("%d",a);   // 10
printf("%p" ,p);  // địa chị của a 
printf("%d",*p);  // 10 (giá trị tại địa chỉ p trỏ tới)

*p = 20; // thay đổi giá trị tại địa chỉ p trỏ tới

printf("%d",a);  // 20
printf("%p" ,p); // địa chỉ như cũ
printf("%d",*p); // 20 (giá trị mới thay 20)
```
## 2. hai toán tử cần nhớ

|Ký hiệu|Tên|Ý nghĩa|
|---|---|---|
|`&x`|address-of|Lấy địa chỉ của x|
|`*p`|dereference|Lấy/ghi giá trị tại địa chỉ p|
> `*` lúc khai báo  `int *p` = "p là con trỏ"
> `*` lúc dùng `*p` = "truy cập giá trị"

## 3. Pointer & mảng
- tên mảng là địa chỉ phần tử đầu
- mảng là các ô nhà nằm liền nhau. pointer trỏ ô đầu,muốn sang ô kế thì +1
```C
int a[3] = {1,2,3};
int *p = a;  // = &a[0]
*(p+1); // = a[1] = 2
p[2]; // = a[2] = 3
```

**Pointer arithmetic:** `p + 1` nhảy `sizeof(kiểu)` byte, không phải 1 byte.

|Kiểu|`p + 1` nhảy|
|---|---|
|`char*`|1 byte|
|`int*`|4 byte|
|`double*`|8 byte|
### 4. Pass by pointer (ứng dụng chính)

C truyền tham số **theo giá trị**, nên muốn sửa biến gốc phải truyền địa chỉ.

```c
void swap(int *a, int *b) {
    int t = *a; *a = *b; *b = t;
}
int x = 1, y = 2;
swap(&x, &y);   // x=2, y=1
```

### 5. Pointer và cấp phát động

```c
int *p = malloc(5 * sizeof(int));
if (p == NULL) return 1;
p[0] = 100;
free(p);
p = NULL;
```

### 6. Lỗi kinh điển

```c
int *p;
*p = 5;          // ❌ wild pointer (chưa khởi tạo)
int *p = NULL;
*p = 5;          // ❌ NULL deref → segfault
int *p = malloc(4);
free(p);
*p = 5;          // ❌ use-after-free
free(p);         // ❌ double free
p = malloc(4);
p = NULL;        // ❌ memory leak (mất địa chỉ, chưa free)
int arr[3];
arr[5] = 1;      // ❌ out-of-bounds
```

✅ Quy tắc: khởi tạo `NULL` → kiểm tra trước khi dùng → `free` xong gán `NULL`.

### 7. Bảng tra nhanh

| Cú pháp           | Nghĩa                                      |
| ----------------- | ------------------------------------------ |
| `int *p`          | p trỏ tới int                              |
| `int **pp`        | pointer tới pointer                        |
| `const int *p`    | không sửa được `*p`                        |
| `int *const p`    | không đổi được `p`                         |
| `void *p`         | pointer tổng quát (phải ép kiểu khi dùng)  |
| `int (*fp)(int)`  | con trỏ hàm                                |
| `NULL`            | pointer không trỏ đâu cả                   |
| Phép toán         | Ý nghĩa                                    |
| `p + k`           | Dịch tới **k phần tử** (không phải k byte) |
| `p - k`           | Lùi k phần tử                              |
| `p++` / `p--`     | Dịch 1 phần tử                             |
| `q - p`           | Số **phần tử** giữa 2 con trỏ (cùng mảng)  |
| `p < q`, `p == q` | So sánh vị trí (cùng mảng)                 |
| `*p++`            | Lấy `*p` **rồi** dịch `p`                  |
| `(*p)++`          | Tăng **giá trị** tại `p`, `p` đứng yên     |

`const` đi với con trỏ có **2 thứ** có thể khóa: **giá trị** mà con trỏ chỉ tới, hoặc **chính con trỏ**.

| Khai báo             | Đổi `*p` (giá trị)? | Đổi `p` (trỏ sang chỗ khác)? |
| -------------------- | ------------------- | ---------------------------- |
| `int *p`             | ✅                   | ✅                            |
| `const int *p`       | ❌                   | ✅                            |
| `int *const p`       | ✅                   | ❌                            |
| `const int *const p` | ❌                   | ❌                            |

```c
#include <stdio.h>

int main(void) {
    int x = 1, y = 2;

    const int *p1 = &x;     // khóa giá trị
    // *p1 = 5;             // ❌ lỗi: không sửa qua p1
    p1 = &y;                // ✅ được: đổi sang trỏ y

    int *const p2 = &x;     // khóa con trỏ
    *p2 = 5;                // ✅ được: sửa x
    // p2 = &y;             // ❌ lỗi: p2 phải trỏ x mãi

    printf("%d %d\n", x, *p1);   // 5 2
    return 0;
}
```

### Dùng trong hàm (đây là chỗ hay gặp nhất)


```c
int sum(const int *a, int n)     // ✅ hàm chỉ đọc → const
{
    int s = 0;
    for (const int *p = a; p < a + n; p++)
        s += *p;
    return s;
}

void zero(int *a, int n)         // ✅ hàm sửa mảng → không const
{
    for (int *p = a; p < a + n; p++)
        *p = 0;
}
```