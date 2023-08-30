#include <stdio.h>
#include <math.h>
#define f(x) 3 * x *x - 6 * x + 2
#define df(x) 6 * x - 6
int main()
{
    printf("estimating one root of 3x^2 - 6x + 2 \n");
    float x, xn, fx, dfx, error, r_error;
    printf("provide initial root and error ( x error) : ");
    scanf("%f%f", &x, &error);
    printf("\nstep \t initial(x) \t f(x)   \t f'(x)    \t xn \t");
    int step = 1;
    do
    {
        fx = f(x);
        dfx = df(x);
        xn = x - (fx / dfx);
        printf("\n%d \t %f \t %f \t %f \t %f \t", step++, x, fx, dfx, xn);
        
        r_error = fabs(xn - x) / x;
        x = xn;

    } while (r_error > error);
    printf("\n\nthe root is : %f", x);
}

/*
estimating one root of 3x^2 - 6x + 2 
provide initial root and error ( x error) : 2 0.001

step     initial(x)      f(x)            f'(x)           xn 
1        2.000000        2.000000        6.000000        1.666667 
2        1.666667        0.333333        4.000000        1.583333 
3        1.583333        0.020833        3.500000        1.577381 
4        1.577381        0.000106        3.464285        1.577350 

the root is : 1.577350
*/