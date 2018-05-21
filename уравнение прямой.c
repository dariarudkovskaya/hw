#include <stdio.h>
int main ()
{
float x1,x2,y1,y2,b,k;
printf(" A (x1;y1) : ");
scanf("%f%f", &x1 , &y1);
printf(" B (x2,y2) : ");
scanf("%f%f", &x2, &y2 );
k=(y2-y1)/(x1-x2) ;
b=y2-k*x2 ;
    printf( "уравнение прямой : y=%.2fx+%.2f\n", k , b);
           }
