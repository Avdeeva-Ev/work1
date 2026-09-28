#include <stdio.h>
#include <math.h>
 
/**
 * @brief Вычисляет длину второй стороны прямоугольника
 * @param a Длина первой стороны
 * @param n Коэффициент в процентах
 * @return Рассчитаное значение
 */
double B(const double a, const double n);
 
/**
 * @brief Вычисляет площадь прямоугольника
 * @param a Длина первой стороны
 * @param b Длина второй стороны
 * @return Рассчитаное значение
 */
double S(const double a, const double b);
 
/**
 * @brief Вычисляет периметр прямоугольника
 * @param a Длина первой стороны
 * @param b Длина второй стороны
 * @return Рассчитаное значение
 */
double P(const double a, const double b);
 
/**
 * @brief Считывает с клавиатуры значение с плавающей точкой
 * @return Считанное значение
 */
double getDouble();
 
/**
 * @brief Точка входа в программу
 * @return 0, если программа выполнена корректно, иначе не 0
 */
int main() {
    double a = getDouble();
    double n = getDouble();
    double b = B(a, n);
 
    printf("Сторона a: %.3lf\n", a);
    printf("Сторона b: %.3lf\n", b);
    printf("Площадь: %.3lf\n", S(a,b));
    printf("Периметр: %.3lf\n", P(a,b));
 
    return 0;
}
 
double B(const double a, const double n) 
{
    return a * n / 100;
}
 
double S(const double a, const double b) 
{
    return a * b;
}
 
double P(const double a, const double b)
{
    return 2 * (a + b);
}
 
double getDouble() 
{
    double value = 0.0;
    scanf("%lf", &value);
    return value;
}
 
