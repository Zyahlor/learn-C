# 26 - 10 - 2026

## 1. FILE TRONG C LÀ GÌ?

Bình thường, bạn viết:

```
int age = 20;
```

Biến `age` lưu dữ liệu trong RAM. Khi chương trình kết thúc, dữ liệu đó không còn được giữ lại theo cách thông thường.

Nếu muốn lưu dữ liệu để lần sau mở chương trình vẫn đọc được, ta dùng file.

Ví dụ, password manager giả lập có thể lưu:

```
facebook example123
gmail hello456
```

Đóng chương trình, mở lại, dữ liệu vẫn còn.

## 2. `fopen()` và `fclose()`

- `fopen()`: mở file.
- `fclose()`: đóng file.

Trong C, cần khai báo thư viện:

```c
#include <stdio.h>
```

Thử viết chương trình này:

```c
#include <stdio.h>

int main() {
    FILE *file = fopen("data.txt", "w");

    if (file == NULL) {
        printf("Mo file that bai!\n");
        return 1;
    }

    printf("Mo file thanh cong!\n");

    fclose(file);

    return 0;
}
```

**giải thích:**
- `FILE *file`: `FILE` là kiều dữ liệu dùng để làm việc với file, `file` là con trỏ dùng để tham chiếu đến file đang mở
- `fopen("data.txt","w')`: `data.txt` - tên file cần mở, `"w"` - mở file để ghi dữ liệu
**lưu ý:** nếu file chưa có -> c sẽ tạo, nếu có rồi, nội dung cũ sẽ bị xóa !

- `fclose(file)`: Đóng file sau khi sử dụng xong. Đây là thói quen quan trọng, giúp hoàn tất các thao tác ghi và giải phóng tài nguyên.

Chạy chương trình, bạn sẽ thấy file `data.txt` được tạo trong thư mục làm việc của chương trình.

| Mode  | File chưa tồn tại | File đã tồn tại                    |
| ----- | ----------------- | ---------------------------------- |
| `"w"` | Tạo file          | Xóa nội dung cũ                    |
| `"a"` | Tạo file          | Giữ nội dung cũ, ghi thêm vào cuối |
| `"r"` | Báo lỗi           | Đọc file                           |

## Thử sức một chút

Chưa cần học hết tám hàm. Trước tiên, hãy tự tay ghi dữ liệu vào file bằng `fprintf()`.

Đây là ví dụ:

```c
#include <stdio.h>

int main() {
    FILE *file = fopen("data.txt", "w");

    if (file == NULL) {
        printf("Loi mo file!\n");
        return 1;
    }

    fprintf(file, "facebook example123\n");
    fprintf(file, "gmail hello456\n");

    fclose(file);

    return 0;
}
```

Sau khi chạy, mở `data.txt`. Bạn sẽ thấy hai dòng dữ liệu đã được lưu.

Chú ý: `fprintf()` khá giống `printf()`, nhưng thay vì in ra màn hình, nó ghi nội dung vào file.

## 3. `fgets()` VÀ `fputs()`

- `fputs()`: đọc 1 dòng từ file
> cú pháp: fputs("Hello World\n", f);
- `fgets()`: ghi chuỗi vào file
>cú pháp: fgets(buffer, sizeof(buffer), f);
## Ghép hai hàm để đọc toàn bộ file

Đây là cách thường dùng nhất:

```c
#include <stdio.h>

int main() {
    FILE *f = fopen("data.txt", "r");

    if (f == NULL) {
        return 1;
    }

    char buffer[100];

    while (fgets(buffer, sizeof(buffer), f) != NULL) {
        printf("%s", buffer);
    }

    fclose(f);
    return 0;
}
```

`while` tiếp tục đọc từng dòng cho đến khi `fgets()` không đọc được nữa, thường là khi gặp cuối file.

#### NHẬP VÀO DỮ LIỆU TỪ BÀN PHÍM

```C

#include <stdio.h>
int main() {
    FILE *f = fopen("data.txt", "a");

    if (f == NULL) {
        printf("Khong the mo file!\n");
        return 1;
    }

    char buffer[100];

    printf("Nhap noi dung: ");
    fgets(buffer, sizeof(buffer), stdin);

    fputs(buffer, f);

    fclose(f);

    printf("Da luu vao file!\n");

    return 0;
}
```

####  Giải thích phần mới
Nhập từ bàn phím:

```
fgets(buffer, sizeof(buffer), stdin);
```
- `buffer`: nơi lưu nội dung nhập vào.
- `sizeof(buffer)`: giới hạn số byte được đọc.
- `stdin`: luồng nhập chuẩn, thường là bàn phím.

Ghi vào file:

```
fputs(buffer, f);
```

Nội dung trong `buffer` được ghi vào file `data.txt`.

Tại sao dùng `"a"` thay vì `"w"`?

|Mode|Kết quả|
|---|---|
|`"w"`|Xóa nội dung cũ khi mở file thành công|
|`"a"`|Giữ nội dung cũ, ghi thêm vào cuối file|

## 4. Phân biệt nhanh

|Hàm|Chức năng|
|---|---|
|`fputs()`|Ghi chuỗi vào file|
|`fgets()`|Đọc chuỗi từ file|
|`fprintf()`|Ghi dữ liệu có định dạng|
|`fscanf()`|Đọc dữ liệu theo định dạng|

`fputs()` ghi chuỗi, còn `fprintf()` ghi dữ liệu theo định dạng. 🔥

#### 1. `fputs()` , ghi chuỗi có sẵn

```
fputs("Bao hoc C\n", f);
```

Nó ghi nguyên chuỗi `"Bao hoc C"` vào file. Không tự chuyển số thành chuỗi hay định dạng dữ liệu cho bạn.

#### 2. `fprintf()` , ghi dữ liệu có định dạng

```
int age = 20;
char name[] = "Bao";

fprintf(f, "Ten: %s, Tuoi: %d\n", name, age);
```

File sẽ chứa:

```
Ten: Bao, Tuoi: 20
```

Các ký hiệu định dạng:

- `%s`: chuỗi.
- `%d`: số nguyên.
- `%f`: số thực.

#### So sánh nhanh

| |`fputs()`|`fprintf()`|
|---|---|---|
|Ghi chuỗi có sẵn|Có|Có|
|Chèn biến vào nội dung|Không trực tiếp|Có|
|Định dạng số|Không|Có|
|Độ đơn giản|Đơn giản hơn|Linh hoạt hơn|
Một số mode cần nhớ:

|Mode|Chức năng|
|---|---|
|`"r+"`|Đọc và ghi, file phải tồn tại|
|`"w+"`|Đọc và ghi, xóa nội dung cũ|
|`"a+"`|Đọc và ghi thêm, tạo file nếu chưa tồn tại|

Với `"a+"`, dữ liệu ghi mới luôn được thêm vào cuối file.

```C
#include <stdio.h>

int main() {
    FILE *f = fopen("data.txt", "a+");

    if (f == NULL) {
        return 1;
    }

    // Thêm dữ liệu
    fprintf(f, "GitHub abc123\n");

    // Quay về đầu file để đọc
    rewind(f);

    char buffer[100];

    while (fgets(buffer, sizeof(buffer), f) != NULL) {
        printf("%s", buffer);
    }

    fclose(f);
    return 0;
}
```

#### Tại sao cần `rewind(f)`?

Vì khi ghi bằng mode `"a+"`, thao tác ghi diễn ra ở cuối file. Muốn đọc từ đầu file, ta gọi:

```c
rewind(f);
```

Nó đưa vị trí đọc về đầu file và xóa trạng thái EOF nếu có.

Lưu ý: Khi chuyển đổi giữa đọc và ghi trên cùng một luồng file, C có một số quy tắc đồng bộ vị trí cần tuân thủ. Với ví dụ này, `rewind()` thực hiện việc đồng bộ cần thiết trước khi đọc.

#### Vậy khi nào nên mở và đóng riêng?

- Mở một lần: Khi chương trình cần vừa đọc vừa ghi thường xuyên.
- Mở riêng từng lần: Khi thao tác đơn giản, dễ quản lý hoặc muốn hạn chế thời gian giữ file mở.
#### demo bài tập
```C
#include <stdio.h>
int main() {
  FILE *f = fopen("data.txt", "w");
  int n;
  printf("nhap so dong can nhap:");
  scanf("%d", &n);
  int c;
  while ((c = getchar()) != '\n' && c != EOF); 
  
  if (f == NULL) {
    printf("[!] khong the mo file!");
    return 1;
  }
  char buffer[100];
  for (int i = 0; i < n; i++) {

    printf("nhap dong [%d]:", i+1);
    fgets(buffer, sizeof(buffer), stdin);
    fputs(buffer, f);
  }

  fclose(f);
  printf("[+] da them du lieu vao file!");
  f = fopen("data.txt", "r");
  if (f == NULL) {
    printf("[!] khong the mo file!\n");
    return 1;
  }
  while (fgets(buffer, sizeof(buffer), f) != NULL) {
    printf("%s", buffer);
  }
  fclose(f);

  return 0;
}
```
>   while ((c = getchar()) != '\n' && c != EOF);  

- dùng để chặn ký tự `\n` sau khi nhập số xong
- Thực hiện hai việc:
1. `getchar()` lấy một ký tự từ luồng nhập.
2. `c = ...` lưu ký tự vừa lấy vào biến `c`.

Sau đó kiểm tra ký tự đó có khác `'\n'` không.
- Nếu khác `'\n'`, tiếp tục lặp.
- Nếu là `'\n'`, dừng lặp.
- Nếu gặp `EOF`, cũng dừng lặp.
Dấu `;` ở cuối có nghĩa là thân vòng lặp rỗng. Mỗi vòng chỉ cần đọc một ký tự và kiểm tra điều kiện, không cần câu lệnh nào khác.

```C
#include <stdio.h>
int main() {
  FILE *f = fopen("data.txt", "w+");
  int n;
  printf("nhap so dong can nhap:");
  scanf("%d", &n);
  int c;
  while ((c = getchar()) != '\n' && c != EOF); 
  
  if (f == NULL) {
    printf("[!] khong the mo file!");
    return 1;
  }
  char buffer[100];
  for (int i = 0; i < n; i++) {

    printf("nhap dong [%d]:", i+1);
    fgets(buffer, sizeof(buffer), stdin);
    fputs(buffer, f);
  }

  printf("[+] da them du lieu vao file!\n");
  rewind(f);
  if (f == NULL) {
    printf("[!] khong the mo file!\n");
    return 1;
  }
  while (fgets(buffer, sizeof(buffer), f) != NULL) {
    printf("%s", buffer);
  }
  fclose(f);

  return 0;
}
```
## 5. `fscanf()` DÙNG LÀM GÌ?

Bạn đã biết `fprintf()` dùng để ghi dữ liệu có định dạng:
```C
fprintf(f, "%s %d\n", "Facebook", 123);
```
Thì `fscanf()` làm chiều ngược lại: đọc dữ liệu từ file vào biến theo định dạng bạn chỉ định.

Ví dụ file `data.txt` chứa:
```
Facebook 123
Github 456
Google 789
```
Ta đọc như sau:
```C
char service[100];
int password;

fscanf(f, "%s %d", service, &password);
```

Sau khi đọc, `service` chứa `"Facebook"` và `password` chứa `123`.

### Thử đọc toàn bộ file

```C
#include <stdio.h>

int main() {
    FILE *f = fopen("data.txt", "r");

    if (f == NULL) {
        printf("Khong mo duoc file!\n");
        return 1;
    }

    char service[100];
    int password;

    while (fscanf(f, "%99s %d", service, &password) == 2) {
        printf("Service: %s | Password: %d\n",
               service, password);
    }

    fclose(f);
    return 0;
}
```

### Giải thích phần quan trọng

```C
while (fscanf(f, "%99s %d", service, &password) == 2)
```

- `%99s`: đọc tối đa 99 ký tự vào `service`, chừa chỗ cho `'\0'`.
- `%d`: đọc một số nguyên vào `password`.
- `== 2`: tiếp tục khi đọc thành công cả hai giá trị.
## 6. `fread()` VÀ `fwrite()`

- dùng để ghi , đọc dữ liệu nhị phân
### 1. `fwrite()`
- ghi dữ liệu
Cú pháp:

```c
fwrite(ptr, size, count, f);
```

- `ptr`: địa chỉ dữ liệu cần ghi.
- `size`: kích thước mỗi phần tử, tính bằng byte.
- `count`: số phần tử cần ghi.
- `f`: con trỏ file.

Ví dụ ghi một số nguyên vào file nhị phân:
```c
#include <stdio.h>

int main() {
    FILE *f = fopen("data.bin", "wb");

    if (f == NULL) {
        return 1;
    }

    int n = 123;

    fwrite(&n, sizeof(int), 1, f);

    fclose(f);
    return 0;
}
```

Ở đây:

- `&n`: địa chỉ của biến `n`.
- `sizeof(int)`: kích thước một số nguyên.
- `1`: ghi một phần tử.
File `data.bin` chứa biểu diễn nhị phân của số `123`, không phải chuỗi ký tự `"123"`.

### 2. `fread()` , đọc dữ liệu

Cú pháp:

```c
fread(ptr, size, count, f);
```

Ví dụ đọc lại số nguyên vừa ghi:

```c
#include <stdio.h>

int main() {
    FILE *f = fopen("data.bin", "rb");

    if (f == NULL) {
        return 1;
    }

    int n;

    if (fread(&n, sizeof(int), 1, f) == 1) {
        printf("%d\n", n);
    }

    fclose(f);
    return 0;
}
```

Kết quả:

```
123
```

`fread()` trả về số phần tử đọc thành công. Vì ta muốn đọc một số nguyên nên kiểm tra `== 1`.

### 3. Vì sao có `rb` và `wb`?

|Mode|Ý nghĩa|
|---|---|
|`"rb"`|Đọc file nhị phân|
|`"wb"`|Ghi file nhị phân, xóa nội dung cũ|
|`"ab"`|Ghi thêm vào cuối file nhị phân|

Chữ `b` là binary. Trên một số hệ điều hành như Windows, chế độ nhị phân tránh việc chuyển đổi dữ liệu văn bản đặc biệt giữa lúc đọc và ghi.

## 4. Phân biệt hai nhóm hàm

|Văn bản|Nhị phân|
|---|---|
|`fprintf()`|`fwrite()`|
|`fscanf()`|`fread()`|
|Dữ liệu thường đọc được bằng trình soạn thảo văn bản|Dữ liệu có thể không đọc được trực tiếp bằng trình soạn thảo|

Lưu ý: `fread()` và `fwrite()` không tự mã hóa hay bảo vệ dữ liệu. Chúng chỉ đọc và ghi byte.