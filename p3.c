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
    scanf("%d",&n);
    double a[n+1];
    double p;
    for(int i=0;i <= n;i++){
        scanf("%lf",&p);
        a[i]=p;
    }
    int m;
    scanf("%d",&m);
    double b[m];
    double q;
    for(int j=0;j<m;j++){
        scanf("%lf",&q);
        b[j]=q;
    }
    for(int c=0;c<m;c++){
        double x =b[c];
        double sum=0.0;
        for(int d=0;d<=n;d++){
            double f=1.0;
            for(int e=0;e<d;e++){
                f*=x;
            }
            sum +=a[d]*f;
        }
        printf("%.3f\n",sum);
    }
    return 0;
}
