# 14 - 10 - 2026
## 1. STRUCT là gì?
- dùng đẻ gom nhiều biến,kiểu dữ liệu khác nhau vào cùng 1 kiểu dữ liệu mà mình định nghĩa

Ví dụ: Một sinh viên có mã số, tuổi và điểm.
- Nếu không dùng `struct`, ta phải quản lý từng biến riêng lẻ. Dùng `struct`, ta gom chúng thành một đối tượng logic duy nhất.
## 2. khai báo
```C
struct sinhvien{
int tuoi;
float diem;
};
```

trong đó:
- struct sinhvien: tên kiểu dữ liệu
- tuoi,diem: thành viên trong kiểu dữ liệu
## 3. Khởi tạo và truy cập thành viên

```C
struct SinhVien sv1 = {18, 8.5};

printf("%d\n", sv1.tuoi);
printf("%.1f\n", sv1.diem);
```

Dùng toán tử `.` để truy cập thành viên qua biến struct.

Thay đổi giá trị:

```C
sv1.diem = 9.0;
```

## 4. Mảng `struct`

Dùng khi cần quản lý nhiều sinh viên.

```C
struct SinhVien ds[3] = {
    {18, 7.5},
    {19, 8.0},
    {20, 9.0}
};

for (int i = 0; i < 3; i++) {
    printf("%d %.1f\n", ds[i].tuoi, ds[i].diem);
}
```

## 5. Con trỏ `struct`

Đây là phần quan trọng khi kết hợp với pointer.

```
struct SinhVien sv = {18, 8.5};
struct SinhVien *p = &sv;

printf("%d\n", p->tuoi);
printf("%.1f\n", p->diem);
```

Có hai cách truy cập thành viên qua con trỏ:

```
p->tuoi
(*p).tuoi
```

Hai cách trên tương đương nhau.

 - Quy tắc nhớ nhanh:

|Cách viết|Ý nghĩa|
|---|---|
|`sv.tuoi`|Truy cập qua biến struct|
|`p->tuoi`|Truy cập qua con trỏ struct|
|`&sv`|Địa chỉ của biến struct|
|`p = &sv`|Cho con trỏ trỏ đến `sv`|
```C
struct SinhVien ds[3] = {
    {18, 7.5},
    {19, 8.0},
    {20, 9.0}
};

struct SinhVien *p = ds;

printf("%.1f\n", (p + 1)->diem);
```

## 6. `typedef struct` là gì?

Cho phép đặt bí danh để không phải viết từ khóa `struct` mỗi lần khai báo biến.

```
typedef struct {
    int tuoi;
    float diem;
} SinhVien;

SinhVien sv1 = {18, 8.5};
```

Thay vì viết `struct SinhVien sv1`, ta chỉ cần viết `SinhVien sv1`.