# 8 - 10 - 2026
## 1. Đệ quy là gì?
- là kỹ thuật lập trình tạo hàm tự gọi chính nó nhiều lần đến điều kiện ngừng.
- hàm tự gọi là hàm đệ quy,mỗi lần hàm tự gọi được gọi là 1 lời gọi đệ quy
```C
#include <stdio.h>

void rec(int n) {
    
    // Base Case
    if (n == 6) return;

    printf("Recursion Level %d\n", n);
    rec(n + 1);
}

int main() {
    rec(1);
    return 0;
}
```

## 2. cách thức hoạt đđộng

>GIAI ĐOẠN ĐI LÊN -  CHỒNG STACK
- hoạt động của đệ quy dựa trên 1 khái niệm gọi là ngăn xếp cuộc gọi (call stack)
- mỗi khi hàm tự gọi chính nó,trạng thái hiện tại được lưu vào ngăn xếp và lời gọi mới bắt đầu.
- khi đạt đến điều kiện, hàm bắt đầu trả về từng lời gọi 1
>GIAI ĐOẠN ĐI XUỐNG -  THỰC HIỆN CÔNG VIỆC

```C
#include <stdio.h>
void f(int n) {
  printf("ngan xep f(%d) duoc day vao!\n", n);
  if (n > 1) {
    f(n - 1); // gọi lại lần 1
    f(n - 1); // gọi lại lần 2
  }
  printf("ngan xep f(%d) bi xoa!\n", n);
}
int main() {
  f(3);
  return 0;
}
// OUTUPUT
// gọi lần 1 ở hàm main - f(3)
ngan xep f(3) duoc day vao!
// gọi lần 1 ở hàm f(3) - f(n-1) = f(2)
ngan xep f(2) duoc day vao!
// gọi lần 1 ở hàm f(2) - f(n-1) = f(1)
ngan xep f(1) duoc day vao!
// thực hiện công việc của lần gọi f(1)
ngan xep f(1) bi xoa!
// gọi lần 2 ở hàm f(2) - f(n-1) = f(1)
ngan xep f(1) duoc day vao!
ngan xep f(1) bi xoa!
// f(2) lần 1 thực hiện xong công việc
ngan xep f(2) bi xoa!
// f(3) gọi f(2) lần 2
ngan xep f(2) duoc day vao!
// f(2) gọi f(1) lần 1
ngan xep f(1) duoc day vao!
ngan xep f(1) bi xoa!
// f(2) gọi f(1) lần 2
ngan xep f(1) duoc day vao!
// f(1) lần 2 thực hiện xong công việc
ngan xep f(1) bi xoa!
// f(2) thực hiện xong
ngan xep f(2) bi xoa!
// f(3) thực hiện công việc xong - xử lý cuối cùng
ngan xep f(3) bi xoa!

```
- lời gọi đầu tiên chính là trả về cuối cùng - thg nào vô đầu thì sẽ xử lý cuối cùng
- Quy tắc duy nhất cần nhớ: ✅ **gọi ai thì chờ người đó xong hẳn rồi mới làm tiếp.**

Bắt đầu với `f(1)` cho dễ, vì nó không gọi ai cả:

```
f(1): in "vào" → in "xóa"
```

Xong. Giờ `f(2)` chỉ là: "vào" → chạy `f(1)` trọn vẹn → chạy `f(1)` trọn vẹn → "xóa":

```
f(2) vào
  f(1) vào, f(1) xóa
  f(1) vào, f(1) xóa
f(2) xóa
```

Còn `f(3)` là: "vào" → chạy `f(2)` trọn vẹn → chạy `f(2)` trọn vẹn → "xóa". Chỉ cần thay khối `f(2)` ở trên vào 2 lần là ra hết output.

```text
                    f(3)
                 ┌───┴───┐
               f(2)     f(2)
              ┌─┴─┐    ┌─┴─┐
            f(1) f(1) f(1) f(1)
```

```text
                      ①f(3)
                  ┌─────┴─────┐
               ②f(2)         ⑤f(2)
              ┌──┴──┐       ┌──┴──┐
          ③f(1)  ④f(1)  ⑥f(1)  ⑦f(1)
```

**Cách đọc cây để ra output:**

```
Đi xuống 1 nút   → in "vào"
Hết nhánh dưới   → in "xóa", rồi bò lên cha
Cha còn nhánh phải chưa đi → sang nhánh phải
```
## 3. Quản lý bộ nhớ trong đệ quy

- được lưu trữ trong bộ nhớ ngăn xếp (stack memory) dưới dạng khung ngăn xếp (stack frame) - ngăn xếp này sẽ xóa sau khi hàm trả về 1 giá trị
- gọi hàm trước khi trả về values - các stack frame mỗi lần gọi đệ quy được đặt lên stack hiện có trong memory
- khi stack frame ở cao nhất - mới nhất trả về giá trị , nó sẽ bị xóa và lời gọi trước nó sẽ được thực hiện
- trình biên dịch (compiler) sử dụng con trỏ lệnh để theo dõi vị trí cần quay lại sau khi quá trình hoàn tất
- khác với phép lặp, đệ quy dựa trên ngăn xếp lệnh gọi (call stack), quản lý bộ nhớ là yếu tốc quan trọng 