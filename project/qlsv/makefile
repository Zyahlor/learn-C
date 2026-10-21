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
