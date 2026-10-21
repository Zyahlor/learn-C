# 17 - 10 - 2026
## 1. makefile là gì?
- là file cấu hình , giúp bạn build 1 project C/C++ mà ko cần gõ các nhiều lệnh, tránh lỗi do mình tạo ra như thiếu file,thừa file, viết sai lệnh
- nếu bạn chỉ sửa 1 file trong số đó, nó chỉ cần biên dịch lại chính file đó (compiler) tránh biên dịch lại cả project
### 2. Cú pháp cốt lõi của Makefile

Cả Makefile chỉ xoay quanh 1 công thức:
```makefile
Mục_tiêu: Các_file_phụ_thuộc

		Lệnh_thực_hiện
```


_(⚠️ **CỰC KỲ QUAN TRỌNG**: Trước dòng `Lệnh_thực_hiện` **bắt buộc phải là phím `TAB`**, dùng dấu cách/space sẽ bị lỗi ngay)._

## 3. bản chất biên dịch,quá trình thực hiện
### 1. máy tính biên dịch C -  từ thủ công đến makefile

1. compiler - biên dịch từng file .c thành mã máy .o
-  `main.c` $\rightarrow$ `main.o`
- `qlsv.c` $\rightarrow$ `qlsv.o`
- `tuongtac.c` $\rightarrow$ `tuongtac.o`
- `chinhsua.c` $\rightarrow$ `chinhsua.o`

2.  **Link (Gắn kết tất cả các `.o` lại thành `.exe`)**:
    - `main.o + qlsv.o + tuongtac.o + chinhsua.o` $\rightarrow$ `main.exe`.
```makefile
# Mục tiêu cuối cùng: Cần 4 file .o này để tạo ra main.exe
main.exe: main.o qlsv.o tuongtac.o chinhsua.o
	gcc main.o qlsv.o tuongtac.o chinhsua.o -o main.exe

# Để có main.o, máy tính cần main.c và qlsv.h
main.o: main.c qlsv.h
	gcc -c main.c -o main.o

# Để có qlsv.o, máy tính cần qlsv.c và qlsv.h
qlsv.o: qlsv.c qlsv.h
	gcc -c qlsv.c -o qlsv.o

# Tương tự cho các file khác...
tuongtac.o: tuongtac.c qlsv.h
	gcc -c tuongtac.c -o tuongtac.o

chinhsua.o: chinhsua.c qlsv.h
	gcc -c chinhsua.c -o chinhsua.o

```

👉 **Cơ chế hoạt động**: Khi bạn sửa file `chinhsua.c`, `make` nhìn vào mốc thời gian (timestamp). Nó thấy chỉ có `chinhsua.c` bị đổi $\rightarrow$ nó **chỉ chạy đúng lệnh `gcc -c chinhsua.c`** rồi nhảy lên link lại `main.exe`. 3 file kia giữ nguyên!

### 2. tự động hóa thế nào?

Viết từng file như Bước 1 thì 50 file sẽ chết mệt. Vì vậy Makefile có **2 chiêu bài tự động hóa**:

#### Chiêu 1: Tự động gom TẤT CẢ các file `.c` trong thư mục (Hàm `wildcard`)

Không cần liệt kê từng tên file nữa, dùng hàm này:

```makefile
SRCS = $(wildcard *.c)
```

_(Dù trong thư mục bạn có 5 file hay 500 file `.c`, nó tự động tóm hết vào biến `SRCS`)_.

#### chiêu 2: tự động đổi đuôi `.c` thành `.o` 
```makefile
OBJS = $(SRCS:.c=.o)
```
_(Nếu `SRCS` là `a.c b.c c.c`, thì `OBJS` tự động thành `a.o b.o c.o`)_.

#### Chiêu 3: Luật mẫu chung cho MỌI file (Pattern Rule `%.o: %.c`)

Thay vì viết luật riêng cho `main.o`, `qlsv.o`..., bạn viết 1 luật chung cho tất cả:
```makefile
%.o: %.c
	gcc -c $< -o $@

```

Giải mã 2 ký tự đặc biệt của Makefile:
- **`$@`**: Đại diện cho file đầu ra bên trái dấu `:` (ở đây là file `.o`).
- **`$<`**: Đại diện cho file đầu vào đầu tiên bên phải dấu `:` (ở đây là file `.c`).

### BƯỚC 3: File Makefile HOÀN CHỈNH - Cân mọi số lượng file

```text
CC = gcc
CFLAGS = -Wall

# 1. Tự động tìm tất cả file .c trong thư mục hiện tại
SRCS = $(wildcard *.c)

# 2. Tự động suy ra danh sách file .o tương ứng
OBJS = $(SRCS:.c=.o)

# 3. Tên file chạy đầu ra
TARGET = main.exe

# Luật chính: Tạo file chạy từ toàn bộ các file .o
$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

# Luật phụ: Cứ có file .c bất kỳ thì compile thành file .o
# ($< là file .c, $@ là file .o)
%.o: %.c qlsv.h
	$(CC) $(CFLAGS) -c $< -o $@

# Lệnh dọn dẹp
clean:
	del /f $(OBJS) $(TARGET)

```