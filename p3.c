/* CS100 Fall 2026 - HW2 Problem 3: Polynomial evaluation
 *
 * Evaluate P(x) at m given points; print each value rounded to 3 decimals.
 * An array is enough for the coefficients; do not use heap memory and do
 * not use <math.h> (your program is not linked against the math library).
 * Do not rename this file.
 */
#include <stdio.h>

int main(void)
{
     int n;
    scanf("%d", &n);
    double a[10005];
    for (int i = 0; i <= n; i++)
    {
        scanf("%lf", &a[i]);
    }
    int m;
    scanf("%d", &m);
    for (int j = 0; j < m; j++)
    {
        double x;
        scanf("%lf", &x);
        double sum = 0.0;
        double f = 1.0;
        for (int d = 0; d <= n; d++)
        {
            sum += a[d] * f;
            f *= x;
        }
        printf("%.3f\n", sum);
    }
    return 0;
}
