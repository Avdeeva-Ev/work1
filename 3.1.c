#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
 
/**
 * @brief Считывает с клавиатуры вещественное число
 * @return Считанное значение
 */
double getValue();
 
/**
 * @brief Проверяет, является ли шаг положительным
 * @param step проверяемое значение шага
 */
void checkStep(const double step);

/**
 * @brief Проверяет правильность границ сегмента
 * @param xbegin начало сегмента
 * @param xend конец сегмента
 */
void checkSegment(const double xbegin, const double xend);

/**
 * @brief Проверяет, находится ли точка вне определения функции
 * @param x значение аргумента
 */
bool isOOF(const double x);

/**
 * @brief Вычисляет значение функции по заданной формуле
 * @param x значение аргумента
 * @return рассчитанное значение функции
 */
double getY(const double x);
/** 
* @brief точка входа в программу
* @return возвращает 0, если программа выполнена корректно, иначе не 0
*/
int main()
{
    double xbegin = getValue("Введите начало: ");
    double xend = getValue("Введите конец: ");
    double step = getValue("Введите шаг: ");
    checkStep(step);
    checkSegment(xbegin, xend);
    
    for (double x = xbegin; x < xend + step; x += step)
    {
        if (!isOOF(x))
        {
            printf("x = %lf, y = %lf\n", x, getY(x));
        }
        else
        {
            printf("x = %lf, y is not define\n", x);
        }
    }
    return 0;
}
 
double getValue()
{
    double value = 0;
    if (scanf("%lf", &value) != 1 || value <= 0)
    {
        printf("\n");
        exit(1);
    }
    return value;
}
 
void checkStep(const double step)
{
    if (step <= 0)
    {
        printf("Ошибка, шаг должен быть положительным\n");
        exit(1);
    }
}
 
void checkSegment(const double xbegin, const double xend)
{
    if (xbegin > xend)
    {
        printf("Ошибка, начало сегмента должно быть меньше или равно концу сегмента\n");
        exit(1);
    }
}
 
bool isOOF(const double x)
{
    return x < 0.0;  
}
 
double getY(const double x)
{
    return 3 * sin(pow(x,1.0/2.0)) + 0.39 * x - 3.8;
}
