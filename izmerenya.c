//Пользователь вводит число - количество измерений (от 2 до 10). После этого вводит все измерения. Программа
// выдаёт среднее значение, дисперсию, погрешность.
#include <stdio.h>
#include <math.h>
 
#define SIZE 20u
 
int main() {
    //Коэффициенты Стьюдента идут начиная с двух измерений
    const float student[9] = {12.7, 4.3, 3.2, 2.8, 2.6, 2.4, 2.4, 2.3, 2.3};
    float A[SIZE];
    unsigned i;
    unsigned limit;
    float tmp;
    float sum = .0f;
    float mean;
    float disp;
    float absError;
    float relError;
 
    do {
        printf("Enter number of measurements ");
        scanf("%u", &limit);
 
        if (limit > 1 && limit < 11) {
            break;
        }
    } while(1);
 
    for (i = 0; i < limit; i++) {
        printf("#%d: ", i);
        scanf("%f", &A[i]);
        sum += A[i];
    }
 
    mean = sum / (float)limit;
 
    sum = .0f;
    for (i = 0; i < limit; i++) {
        tmp = A[i] - mean;
        sum += tmp * tmp;
    }
    disp = sum / (float)limit;
    absError = student[limit - 2] * sqrt(sum / (float)(limit - 1));
    relError = absError / mean * 100;
 
    printf("Mean = %.6f\n", mean);
    printf("Dispertion = %.6f\n", disp);
    printf("Abs. Error = %.6f\n", absError);
    printf("Rel. Error = %.4f\n", relError);
 
}
