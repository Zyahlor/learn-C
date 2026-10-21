#ifndef QLSV_H 
#define QLSV_H
typedef struct sv {
    int masv;
    int tuoi;
    float diem;
}sv;
void nhap(sv *x,int n);
void xuat(sv *x,int n);
float tb(sv *x,int n);
int max_diem(sv *x,int n);
void tang_diem(sv *x,int n);
// tuong tac
void hoandoi_diem(float *a, float *b);
int tim(sv *x,int n,int masv);
void hoandoi(sv *x,int n,int masv1,int masv2);
void giamdan(sv *x,int n);
void maxmin(sv *x,int n,int *max,int *min);
// chinh sua 
void sua(sv *x,int n,int massv, int luachon);
sv *out_max(sv *s,int n);
int kha(sv *x,int n);
sv *out_massv(sv *x,int n,int masv);
#endif 
