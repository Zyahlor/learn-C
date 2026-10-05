# 🛡️ Lộ trình học C cho Cybersecurity / Pentest

> **Mục tiêu:** Học C đủ chắc để đọc hiểu mã nguồn, làm system programming, network programming và tiến tới binary exploitation / reverse engineering.

---

# 0. Chuẩn bị môi trường

## Công cụ

* GCC / Clang
* GDB
* Make
* Git
* Linux
* VS Code / Neovim tùy thích

## Kiểm tra

```bash
gcc --version
gdb --version
make --version
git --version
```

## Chương trình đầu tiên

```c
#include <stdio.h>

int main() {
    printf("Hello, C!\n");
    return 0;
}
```

Compile:

```bash
gcc main.c -o main
```

Chạy:

```bash
./main
```

---

# 1. Cơ bản

> **Mục tiêu:** Có thể tự viết chương trình C nhỏ mà không cần copy code.

## 1.1. Cấu trúc chương trình

* `#include`
* `main()`
* statement
* `{ }`
* `;`
* comment

## 1.2. Biến và kiểu dữ liệu

* `char`
* `int`
* `short`
* `long`
* `long long`
* `float`
* `double`
* `_Bool`

Tìm hiểu:

```c
sizeof()
```

Ví dụ:

```c
printf("%zu\n", sizeof(int));
```

### Cần hiểu

* kiểu dữ liệu là gì
* kích thước bộ nhớ
* signed / unsigned
* giới hạn của kiểu dữ liệu

---

# 2. Input / Output

## Output

```c
printf()
puts()
putchar()
```

## Input

```c
scanf()
fgets()
getchar()
```

### Bài tập

* nhập tên
* nhập tuổi
* tính tổng
* tính diện tích
* chuyển đổi đơn vị
* đọc một dòng text

> ⚠️ Đặc biệt hiểu tại sao `scanf("%s", ...)` có thể gây vấn đề với buffer.

---

# 3. Toán tử

## Arithmetic

```text
+
-
*
/
%
```

## Comparison

```text
==
!=
>
<
>=
<=
```

## Logical

```text
&&
||
!
```

## Bitwise

```text
&
|
^
~
<<
>>
```

> **Bitwise cực kỳ quan trọng với cybersecurity.**

Cần hiểu:

```text
AND
OR
XOR
NOT
LEFT SHIFT
RIGHT SHIFT
```

---

# 4. Control Flow

## if / else

```c
if (...) {
    
} else {
    
}
```

## switch

```c
switch (x) {
    case 1:
        break;

    case 2:
        break;

    default:
        break;
}
```

## Loops

```c
for
while
do while
```

## Control

```c
break
continue
return
```

### Bài tập

Viết:

* calculator
* kiểm tra số nguyên tố
* Fibonacci
* đoán số
* menu CLI

---

# 5. Function

## Cú pháp

```c
return_type function_name(parameters) {
    ...
}
```

Ví dụ:

```c
int add(int a, int b) {
    return a + b;
}
```

## Học

* parameter
* return value
* local variable
* global variable
* function prototype
* scope

## Header

```c
// math_utils.h
int add(int a, int b);
```

```c
// math_utils.c
int add(int a, int b) {
    return a + b;
}
```

---

# 6. Array

## 1D Array

```c
int numbers[5];
```

Học:

* index
* traversal
* search
* min/max
* sort
* reverse

## 2D Array

```c
int matrix[3][3];
```

### Bài tập

Viết:

* linear search
* bubble sort
* reverse array
* frequency counter
* matrix calculator

---

# 7. String

C không có kiểu `string` built-in như C++.

String thực chất là:

> **một mảng `char` kết thúc bằng `\0`.**

Ví dụ:

```c
char name[] = "Bao";
```

Trong bộ nhớ:

```text
B
a
o
\0
```

## Thư viện `<string.h>`

Học:

```c
strlen()
strcpy()
strncpy()
strcmp()
strcat()
strchr()
strstr()
```

### ⚠️ Security

Đây là phần cực kỳ quan trọng.

Hiểu:

```text
buffer
buffer overflow
null terminator
out-of-bounds
unsafe string operations
```

Không chỉ học thuộc hàm. Phải hiểu chuyện gì xảy ra trong memory.

---

# 8. Pointer ⭐⭐⭐

> Đây là bước ngoặt lớn nhất khi học C.

## Cần hiểu

```c
int x = 10;
int *p = &x;
```

Trong đó:

```text
x  = giá trị
&x = địa chỉ của x
p  = địa chỉ
*p = giá trị tại địa chỉ đó
```

## Học theo thứ tự

```text
address
&
*
pointer
dereference
pointer arithmetic
pointer + array
```

## Ví dụ

```c
int x = 10;

int *p = &x;

printf("%d\n", x);
printf("%p\n", (void *)p);
printf("%d\n", *p);
```

---

# 9. Pointer + Array

Hiểu mối quan hệ:

```c
arr[i]
```

và:

```c
*(arr + i)
```

Ví dụ:

```c
int arr[] = {10, 20, 30};

printf("%d\n", arr[1]);
printf("%d\n", *(arr + 1));
```

## Học

* pointer arithmetic
* pointer to array
* array decay
* pointer comparison

> Đây là nền móng để đọc rất nhiều C code thực tế.

---

# 10. Pointer + Function

## Pass by value

```c
void change(int x) {
    x = 100;
}
```

## Dùng pointer

```c
void change(int *x) {
    *x = 100;
}
```

### Bài tập

Viết:

```text
swap()
min()
max()
reverse()
sort()
```

bằng pointer.

---

# 11. Struct

```c
struct User {
    char name[50];
    int age;
};
```

Sử dụng:

```c
struct User user;
```

## Học

* struct
* nested struct
* array of struct
* pointer to struct
* `->`
* `.`

Ví dụ:

```c
struct User *ptr = &user;

ptr->age = 20;
```

---

# 12. Dynamic Memory ⭐⭐⭐

> Đây là lúc bắt đầu thật sự hiểu C quản lý memory như thế nào.

## Học

```c
malloc()
calloc()
realloc()
free()
```

Ví dụ:

```c
int *p = malloc(sizeof(int));

*p = 10;

free(p);
```

## Phải hiểu

```text
stack
heap
static memory
code/text segment
```

## Các lỗi quan trọng

```text
memory leak
use-after-free
double free
dangling pointer
NULL pointer dereference
heap overflow
```

> Đây là cầu nối trực tiếp sang vulnerability research.

---

# 13. File I/O

## Học

```c
fopen()
fclose()
fread()
fwrite()
fgets()
fputs()
fprintf()
fscanf()
```

## File mode

```text
r
w
a
rb
wb
```

### Project

Viết:

```text
CLI Password Manager giả lập
```

Có thể lưu dữ liệu vào file.

> Không cần làm password manager thật. Mục tiêu là luyện file handling.

---

# 14. Preprocessor

## Học

```c
#include
#define
#ifdef
#ifndef
#endif
```

Ví dụ:

```c
#define MAX 100
```

## Header guard

```c
#ifndef MY_HEADER_H
#define MY_HEADER_H

...

#endif
```

---

# 15. Compilation

> Hiểu C từ source code đến executable.

Quy trình:

```text
source code
    ↓
preprocessor
    ↓
compiler
    ↓
assembly
    ↓
assembler
    ↓
object file
    ↓
linker
    ↓
executable
```

## Thực hành

```bash
gcc -E main.c
gcc -S main.c
gcc -c main.c
gcc main.o -o main
```

### Cần hiểu

* `.c`
* `.h`
* `.o`
* executable
* linker
* static library
* shared library

---

# 16. Makefile

Học cách build project:

```text
project/
├── src/
│   ├── main.c
│   └── utils.c
├── include/
│   └── utils.h
├── Makefile
└── README.md
```

Học:

```bash
make
make clean
```

---

# 17. Debugging với GDB ⭐⭐⭐

## Các lệnh cơ bản

```bash
gdb ./program
```

```gdb
run
break main
next
step
continue
print
info registers
backtrace
x
disassemble
```

## Thực hành

Debug:

* biến
* pointer
* stack
* function
* crash
* segmentation fault

### Mục tiêu

Nhìn crash và bắt đầu trả lời được:

> "Chương trình chết ở đâu và tại sao?"

---

# 18. Linux System Programming ⭐⭐⭐

> Đây là phần cực kỳ quan trọng nếu mục tiêu là cybersecurity.

## Process

Học:

```c
fork()
exec()
wait()
exit()
```

Hiểu:

```text
process
parent
child
PID
PPID
```

## Signals

```c
signal()
kill()
```

Các signal cơ bản:

```text
SIGINT
SIGTERM
SIGKILL
SIGSEGV
SIGCHLD
```

---

# 19. File Descriptor

Hiểu:

```text
stdin  = 0
stdout = 1
stderr = 2
```

Học:

```c
open()
close()
read()
write()
```

## Quan trọng

Hiểu sự khác nhau:

```text
FILE *
file descriptor
```

---

# 20. Pipe

Học:

```c
pipe()
```

Hiểu:

```text
process A
    ↓
   pipe
    ↓
process B
```

Thực hành:

Viết chương trình:

```text
parent → child
```

truyền dữ liệu qua pipe.

---

# 21. Linux Networking ⭐⭐⭐

## Socket

Học:

```c
socket()
bind()
listen()
accept()
connect()
send()
recv()
close()
```

## TCP

Tạo:

```text
TCP Server
TCP Client
```

Ví dụ:

```text
Client
   │
   │ TCP
   ↓
Server
```

### Project

Viết:

```text
TCP Echo Server
TCP Echo Client
```

Sau đó mở rộng thành:

```text
Multi-client TCP Server
```

---

# 22. UDP

Học:

```c
sendto()
recvfrom()
```

Project:

```text
UDP Client
UDP Server
```

Hiểu sự khác nhau:

```text
TCP
vs
UDP
```

---

# 23. System Call

Hiểu:

```text
User Space
    ↓
System Call
    ↓
Kernel Space
```

Tìm hiểu:

```text
read
write
open
fork
execve
socket
connect
```

Dùng:

```bash
strace
```

để quan sát chương trình.

Ví dụ:

```bash
strace ./program
```

---

# 24. ELF ⭐⭐⭐

> Bắt đầu bước sang binary analysis.

Tìm hiểu:

```text
ELF
header
section
segment
symbol
GOT
PLT
```

Các lệnh:

```bash
file program
readelf -h program
readelf -S program
readelf -s program
objdump -d program
nm program
strings program
```

---

# 25. Assembly cơ bản

Không cần trở thành assembly wizard.

Mục tiêu:

> **Đọc được assembly đủ để hiểu chương trình C biến thành gì.**

Học:

```text
register
stack
memory
instruction
call
ret
jmp
cmp
mov
push
pop
```

x86-64:

```text
RAX
RBX
RCX
RDX
RSI
RDI
RSP
RBP
RIP
```

---

# 26. Memory Layout ⭐⭐⭐

Hiểu executable có những vùng:

```text
        ┌──────────────┐
        │    Stack     │
        ├──────────────┤
        │      ↓       │
        │              │
        │      ↑       │
        ├──────────────┤
        │     Heap     │
        ├──────────────┤
        │   BSS/Data   │
        ├──────────────┤
        │    Text      │
        └──────────────┘
```

Hiểu:

* stack frame
* return address
* local variable
* heap allocation
* function call

---

# 27. C Memory Bugs ⭐⭐⭐⭐⭐

Đây là phần bắt đầu tiến sâu vào offensive security.

## Học về

### Stack Buffer Overflow

```text
buffer
return address
```

### Heap vulnerabilities

```text
use-after-free
double free
heap overflow
```

### Memory corruption

```text
out-of-bounds read
out-of-bounds write
integer overflow
format string
```

---

# 28. Binary Exploitation

Sau khi chắc:

```text
C
↓
Pointer
↓
Memory
↓
GDB
↓
Assembly
↓
ELF
```

mới học:

```text
Buffer Overflow
NX
ASLR
Canary
PIE
RELRO
ROP
ret2libc
```

## Lab

Sử dụng môi trường CTF/lab hợp pháp.

Ví dụ:

```text
pwn.college
ROP Emporium
OverTheWire
CTF challenges
```

---

# 29. Reverse Engineering

Học:

```text
Ghidra
GDB
objdump
strings
readelf
```

## Kỹ năng

* nhận diện function
* đọc control flow
* tìm string
* phân tích input
* hiểu binary
* debug binary
* trace execution

---

# 30. Secure C Programming

Sau khi biết cách chương trình bị lỗi, học cách viết chương trình không lỗi.

## Học

```text
input validation
bounds checking
safe memory management
integer safety
secure string handling
error handling
```

Hiểu các vấn đề:

```text
CWE-120
CWE-121
CWE-122
CWE-125
CWE-190
CWE-416
CWE-787
```

---

# 🧪 Project theo từng giai đoạn

## Beginner

### Project 1

```text
CLI Calculator
```

### Project 2

```text
Student Management
```

### Project 3

```text
File-based Notes
```

---

## Intermediate

### Project 4

```text
Custom String Library
```

Tự implement một phần:

```text
strlen
strcmp
strcpy
strcat
```

### Project 5

```text
Mini Shell
```

Có:

```text
cd
pwd
ls
exit
```

### Project 6

```text
TCP Echo Server
```

---

## Advanced

### Project 7

```text
Multi-client TCP Server
```

### Project 8

```text
ELF Information Tool
```

Ví dụ:

```bash
./elfinfo program
```

hiển thị:

```text
Architecture
Entry point
Sections
Symbols
```

### Project 9

```text
Mini Debugger / Process Inspector
```

### Project 10

```text
Vulnerability Lab
```

Tự tạo các chương trình có:

```text
buffer overflow
format string
use-after-free
integer overflow
```

Sau đó:

```text
debug
→ understand
→ reproduce
→ exploit in local lab
→ fix
```

---

# 📚 Thứ tự học đề xuất

Không học tất cả cùng lúc.

```text
1. Syntax
   ↓
2. Variables / Types
   ↓
3. Control Flow
   ↓
4. Functions
   ↓
5. Array
   ↓
6. String
   ↓
7. Pointer ⭐
   ↓
8. Struct
   ↓
9. Dynamic Memory ⭐
   ↓
10. File I/O
   ↓
11. Compilation
   ↓
12. GDB ⭐
   ↓
13. Linux System Programming ⭐
   ↓
14. Socket Programming ⭐
   ↓
15. ELF
   ↓
16. Assembly
   ↓
17. Memory Layout
   ↓
18. Memory Vulnerabilities ⭐⭐⭐
   ↓
19. Binary Exploitation
   ↓
20. Reverse Engineering
```

---

# 🎯 Chuẩn đầu ra

## Level 1 — C cơ bản

Có thể:

* viết chương trình C
* dùng function
* array
* string
* struct
* pointer cơ bản

---

## Level 2 — C thực chiến

Có thể:

* quản lý memory
* đọc/ghi file
* chia project thành nhiều file
* sử dụng Makefile
* debug bằng GDB

---

## Level 3 — System Programming

Có thể:

* làm việc với process
* file descriptor
* system call
* pipe
* signal
* socket
* TCP/UDP

---

## Level 4 — Security

Có thể:

* đọc C code
* hiểu memory layout
* đọc assembly cơ bản
* phân tích ELF
* debug binary
* nhận diện memory corruption
* reproduce vulnerability trong lab

---

# 🧠 Nguyên tắc học

## 1. 20% lý thuyết + 80% thực hành

Đừng đọc 100 trang về pointer rồi tự tin rằng mình biết pointer.

Viết code.

Debug.

Làm nó crash.

Sửa nó.

Lặp lại.

---

## 2. Mỗi topic phải có bài tập

Ví dụ học pointer:

```text
Pointer
↓
10 phút lý thuyết
↓
5 bài code
↓
GDB xem memory
↓
mini challenge
```

---

## 3. Luôn hỏi "nó nằm ở đâu trong memory?"

Đặc biệt với:

```text
pointer
array
string
struct
malloc
function
stack
heap
```

Đây là thói quen cực kỳ có giá trị khi chuyển sang binary exploitation.

---

# 🗂️ Cấu trúc folder học

```text
C-learning/
│
├── 01-basic/
├── 02-control-flow/
├── 03-function/
├── 04-array/
├── 05-string/
├── 06-pointer/
├── 07-struct/
├── 08-memory/
├── 09-file/
├── 10-gdb/
├── 11-linux/
├── 12-network/
├── 13-elf/
├── 14-assembly/
├── 15-memory-bugs/
├── 16-pwn/
│
├── projects/
│
├── notes/
│
└── README.md
```

---

# 🚦 Điểm chuyển phase

Không cần hoàn thành mọi thứ một cách hoàn hảo.

### Có thể rời Beginner khi:

* tự viết được chương trình CLI
* dùng function
* xử lý array/string
* hiểu pointer cơ bản

### Có thể rời Intermediate khi:

* hiểu stack/heap
* dùng `malloc/free`
* debug được segmentation fault
* đọc được C project nhiều file

### Có thể bước vào Binary Security khi:

* hiểu pointer
* hiểu memory layout
* dùng GDB
* đọc assembly cơ bản
* hiểu ELF
* biết Linux system call

---

# 🏁 Mục tiêu cuối

Không phải:

> "Biết C."

Mà là:

```text
C source
   ↓
Compiler
   ↓
ELF binary
   ↓
Assembly
   ↓
Memory
   ↓
GDB
   ↓
Vulnerability
   ↓
Exploit
   ↓
Patch
```

Đó mới là tuyến C có giá trị lớn đối với **Cybersecurity / Pentest / Reverse Engineering / Binary Exploitation**.