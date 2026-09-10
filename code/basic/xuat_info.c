#include<stdio.h>

int main(){
    char name = 'b';
    int age = 19;
    float score = 10;
    double height = 99.9;
    printf("%c\n",name);
    printf("%d\n",age);
    printf("%f\n",score);
    printf("%lf\n",height);

    printf("kiem tra so byte cua cac kieu du lieu:\n");
    printf("kieu du lieu int:%zu byte\n",sizeof(int));
    printf("kieu du lieu float:%zu byte\n",sizeof(float));
    printf("kieu du lieu char:%zu byte\n",sizeof(char));
    printf("kieu du lieu double:%zu byte\n",sizeof(double));
    printf("kieu du lieu long:%zu byte\n",sizeof(long));
    printf("kieu du lieu short:%zu byte\n",sizeof(short));
    printf("kieu du lieu long long:%zu byte\n",sizeof(long long));


    return 0;
}