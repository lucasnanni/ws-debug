#include <stdio.h>
#include <math.h>

long fact(int n)
{
    long f=1, i;
    for (i=n; i>1; i--)
        f *= i;
    return f;
}

long pwr(int x, int n)
{
    long p = 1;
    int i;
    for (i=0; i<n; i++)
        p = p * x;
    return p;
}

double fexp(int x)
{
    int i = 0;
    long xp, f;
    double e0, e1 = 0;
    do {
        xp = pwr(x, i);
        f = fact(i);
        e0 = e1;
        e1 = e0 + xp/f;
        i++;
    } while (fabs(e1-e0) > 0.000005);
    return e1;
}

int main()
{
    printf(" exp(5) = %f\n", exp(5));
    printf("fexp(5) = %f\n", fexp(5));
}