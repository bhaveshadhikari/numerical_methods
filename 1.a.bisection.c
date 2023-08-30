#include <stdio.h>
#include <math.h>

#define f(x) 3 * x *x - 6 * x + 2

int main()
{
    printf("estimating one root of 3x^2 - 6x + 2 \n");
    float l, u, m, fl, fu, fm, error; //relative_error;

start:
    printf("enter initial bounds and error ( xl  xu error) : ");
    scanf("%f%f%f", &l, &u, &error);

    if ((f(l)) * (f(u)) > 0.0)
        goto start;

    printf("\nstep \t lower(xl) \t upper(xu) \t mid(x_m) \t f(x_m)");

    int step = 1;
    do
    {
        fl = f(l);
        fu = f(u);
        m = (l + u) / 2;
        fm = f(m);

        printf("\n%d \t %f \t %f \t %f \t %f \t", step++, l, u, m, fm);

        if (fm == 0)
        {
            printf("\n the root is %f", m);
            return 0;
        }

        u = fl * fm < 0 ? m : u; //  the root lies in betn l and m
        l = fm * fu < 0 ? m : l; //  the root lies in betn m and u
 
        // relative_error = (fabs( - l)) / m;
        // printf(" %f\t",relative_error);
    } while (fabs(fm) > error);

    printf("\n\nthe root is %f", m);
    return 0;
}

/*
estimating one root of 3x^2 - 6x + 2
enter initial bounds and error ( xl  xu error) : 1 2 0.05

step     lower(xl)       upper(xu)       mid(x_m)        f(x_m)
1        1.000000        2.000000        1.500000        -0.250000
2        1.500000        2.000000        1.750000        0.687500
3        1.500000        1.750000        1.625000        0.171875
4        1.500000        1.625000        1.562500        -0.050781
5        1.562500        1.625000        1.593750        0.057617
6        1.562500        1.593750        1.578125        0.002686

the root is 1.578125
*/