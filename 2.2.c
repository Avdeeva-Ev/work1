#include <stdio.h>
#include <math.h>
#include <float.h>
#include <stdlib.h>
 /**
 * @brief Считывает с клавиатуры значение с плавающей точкой
 * @return Считанное значение
 */
double getDouble();
/**
 * @brief Вычисляет функции y по заданной формуле
 * @param x значение параметра x
 * @param a значение параметра a
 * @return рассчитанное значение
 */
double y(const double x, const double a);
 /** 
* @brief точка входа в программу
* @return возвращает 0, если программа выполнена корректно, иначе не 0
*/
int main()
{
    const double a = 2.5;
    printf("Введите x: \n");
    double x = getDouble();
    
    printf("y = %lf",y(x,a));
    return 0;
}
 
double getDouble()
{
    double value = 0.0;
    if (scanf("%lf",&value) != 1)
        {
            printf("Error");
            exit(1);
        }
    return value;
}
 
double y(const double x, const double a)
{
    if (x>a)
        {
            return x*pow(x-a,1.0/3.0);
        }
    if (x<=a)
        {
            return  x*sin(a)*x;
        }
}
