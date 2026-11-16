#include <stdio.h>
#include <float.h>
#include <math.h>

/**
 * @brief Вычисляет сумму ряда с заданной точностью e для заданного x
 * @param e Точность вычисления
 * @param x Аргумент функции
 * @return Сумма элементов, пока очередной член ряда не станет меньше e
 */
double sumE(const double e, const double x);

/**
 * @brief Вычисляет коэффицент для i шага ряда
 * @param x Аргумент функции
 * @param i Индекс шага
 * @return Значение коэффицента
 */
double getCoef(const double x, const int i);

/** 
* @brief точка входа в программу
* @return возвращает 0, если программа выполнена корректно, иначе не 0
*/
int main() 
{
    const double a = 0.1;
    const double b = 1.0;
    const double h = 0.1;
    const double e = pow(10.0, -4) ;

    printf("|    x    |  y=3**x |   Sum  |\n");

    for (double x = a; x <= b + DBL_EPSILON; x += h)
    {
        double y = pow(3.0, x); 
        double s = sumE(e, x);  
        
        printf("| %7.4lf | %7.4lf | %7.4lf |\n", x, y, s);
    }

    return 0;
}

double sumE(const double e, const double x)
{
    double a = 1.0; 
    double result = a;
    
    for (int i = 0; fabs(a) >= e - DBL_EPSILON; i++)
    {
        a *= getCoef(x, i);
        result += a;
    }
    return result;
}

double getCoef(const double x, const int i)
{
    return (log(3.0) * x) / (i + 1);
}
