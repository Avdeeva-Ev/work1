#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <math.h>
 
/**
 * @brief Считывает с клавиатуры целое число
 * @return Считанное значение
 */
int getInt();

/**
 * @brief Считывает с клавиатуры вещественное число
 * @return Считанное значение
 */
double getValue();

/**
 * @brief Проверяет, является ли n положительным
 * @param n Проверяемое число
 */
void checkPositive(const int n);

/**
 * @brief Проверяет, является ли e положительным
 * @param e Проверяемое число
 */
void checkEpsilon(const double e);

/**
 * @brief Вычисляет сумму первых n элементов ряда
 * @param n Количество элементов
 * @return Сумма n элементов
 */
double sumN(const int n);

/**
 * @brief Вычисляет сумму ряда с заданной точностью e
 * @param e Точность вычисления
 * @return Сумма элементов, пока очередной член ряда не станет меньше e
 */
double sumE(const double e);

/**
 * @brief Вычисляет коэффицент для i шага ряда
 * @param i Индекс шага
 * @return Значение коэффицента
 */
double getCoef(const int i);
 
/** 
* @brief точка входа в программу
* @return возвращает 0, если программа выполнена корректно, иначе не 0
*/
int main() 
{
    int n = getInt("Введите n: ");
    double e = getValue("Введите e: ");
    checkPositive(n);
    checkEpsilon(e);
    printf("Summ of %d elements is: %lf\n",n,sumN(n));
    printf("Summ of elements less %lf is: %lf\n",e,sumE(e));
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
int getInt()
{
    int value = 0;
    if (scanf("%d", &value) != 1 || value <= 0)
    {
        printf("\n");
        exit(1);
    }
    return value;
}
 
void checkPositive(const int n)
{
    if (n <= 0)
    {
        printf("Ошибка, n должно быть положительным\n");
        exit(1);
    }
}
 
void checkEpsilon(const double e)
{
     if (e <= 0)
    {
        printf("Ошибка, e должно быть положительным\n");
        exit(1);
    }
}
 
double sumN(const int n)
{
    double a = 1.0/12.0;
    double result = a;
    for (int i = 0; i < n; i++)
    {
        a *= getCoef(i); 
        result += a; 
    }
    return result;
}
 
double getCoef(const int i)
{
    return -1.0/(i+3)/(i+4);
}
 
double sumE(const double e)
{
    double a = 1.0/12.0;
    double result = 0;
    for (int i = 0; fabs(a) >= e - DBL_EPSILON; i++)
    {
        result += a;
        a *= getCoef(i);
    }
    return result;
}
