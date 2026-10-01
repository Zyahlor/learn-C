#include<stdio.h>
void nhap(int a[],int n){
 for(int i =0;i<n ;i++){
printf("nhap gia tri:");
scanf("%d",&a[i]);
 }

}
void xuat(int a[],int n){
for(int i =0;i<n;i++){
    printf("[%d]",a[i]);
}
printf("\n");
}
int lonnhat(int a[],int n)
{
   int max = a[0] ;
   for (int i =0;i<n;i++){
       if (max < a[i]){
           max = a[i];
       }
   }
   return max;


}
void hoanvi(int *a ,int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
void doichott(int a[],int n){
    for(int i =0 ;i < n -1;i++){
        for(int j = i+1;j<n;j++){
            if(a[i]>a[j]){
                hoanvi(&a[i],&a[j]);
            }
        }
    }
}
int linear_search(int a[],int n,int x){
    for(int i = 0 ;i<n ;i++){
        if(a[i] == x){
            return i;
        }
    }
    return -1;
}
int main(){

printf("hello ");
printf("world\n");
int a[100],n;
printf("nhap so phan tu trong mang:");
scanf("%d",&n);
nhap(a,n);
xuat(a, n);
doichott(a, n );
xuat(a,n);
int new;
printf("nhap gia tri can tim:");
scanf("%d",&new);
if(linear_search(a,n,new)>-1){
    printf("so tim duoc o vi tri:[%d]\n",linear_search(a,n,new));
}
else{
    printf("khong tim thay so o trong mang!\n");
}
return 0;
}
