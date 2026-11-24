#ifndef THUVIEN_H
#define THUVIEN_H
typedef struct{
    int ngay;
    int thang;
    int nam;
} date;
typedef struct {
    int masv;
    char name[30];
    char lop[30];
    int tuoi;
    float diem;
    date ngaysinh;
}sv;

void themSinhVien(sv **ds, int *soLuong, int *sucChua);
void menu();
#endif // !THUVIEN_H
