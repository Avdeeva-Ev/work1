#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
 
/**
 * @brief Вычисляет объем шара
 * @param r радиус
 * @return рассчитанное значение
 */
double V(const double r);
 
/**
 * @brief Вычисляет площадь поверхности шара
 * @param r радиус
 * @return рассчитанное значение
 */
double S(const double r);
 
/**
 * @brief Считывает с клавиатуры значение с плавающей точкой
 * @return Считанное значение
 */
double getDouble();
 
/**
 * @brief Проверяет, что радиус — положительное число
 * @param r считанное значение радиуса
 */
void checkRadius(const double r);
 
/**
 * @brief Точка входа в программу
 * @return 0, если программа выполнена корректно, иначе не 0
 */
int main()
{
    printf("Введите радиус: ");
    double r = getDouble();
    checkRadius(r);
 
    printf("Объем шара: %.3lf\n", V(r));
    printf("Площадь поверхности шара: %.3lf\n", S(r));
 
    return 0;
}
 
double V(const double r)
{
    return 4.0 / 3.0 * M_PI * pow(r, 3);
}
 
double S(const double r)
{
    return 4.0 * M_PI * pow(r, 2);
}
 
double getDouble()
{
    double value = 0.0;
    if (scanf("%lf", &value) != 1)
    {
        printf("Error");
        exit(1);
    }
    return value;
}
 
void checkRadius(const double r)
{
    if (r <= 0)
    {
        printf("Error");
        exit(1);
    }
}
