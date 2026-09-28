#include <stdio.h>
#include <math.h>

/**
 * @brief Вычисляет кинетическую энергию
 * @param m масса
 * @param v скорость
 * @return рассчитанное значение
 */
double E(const double m, const double v);

/**
 * @brief Считывает с клавиатуры значение с плавающей точкой
 * @return Считанное значение
 */
double getDouble();

/**
 * @brief Точка входа в программу
 * @return 0, если программа выполнена корректно, иначе не 0
 */
int main() 
{
    double m = getDouble();
    double v = getDouble();
  
    printf("Кинетическая энергия: %.3lf\n", E(m, v));
  
    return 0;
}

double E(const double m, const double v) 
{
    return m * pow(v, 2) / 2;
}

double getDouble() 
{
    double value = 0.0;
    scanf("%lf", &value);
    return value;
}
