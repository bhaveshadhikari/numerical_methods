#include <stdio.h>
#include <math.h>
#define f(x) 3 * x *x - 6 * x + 2
#define g(x) (3 * x * x + 2) / 6
int main()
{
    printf("estimating one root of 3x^2 - 6x + 2 \n");
    float x, xn, error, r_error;
    printf("provide initial root and error ( x error) : ");
    scanf("%f%f", &x, &error);
    printf("\nstep \t initial(x) \t g(x)   \t error");
    int step = 1;
    do
    {

        xn = g(x);
        r_error = fabs(xn - x) / x;
        printf("\n%d \t %f \t %f \t %f", step++, x, xn, r_error);

        x = xn;

    } while (r_error > error);
    printf("\n\nthe root is : %f", x);
}

/*
estimating one root of 3x^2 - 6x + 2 
provide initial root and error ( x error) : 0.5 0.005

step     initial(x)      g(x)            error
1        0.500000        0.458333        0.083333
2        0.458333        0.438368        0.043561
3        0.438368        0.429417        0.020420
4        0.429417        0.425533        0.009045
5        0.425533        0.423872        0.003902

the root is : 0.423872
*/