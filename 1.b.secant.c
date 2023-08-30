#include <stdio.h>
#include <math.h>

#define f(x) 3 * x *x - 6 * x + 2

int main(){
    printf("estimating one root of 3x^2 - 6x + 2 \n");
    float a, b, x, fa, fb, error, r_error;
    printf("enter initial roots and error ( a  b error) : ");
    scanf("%f%f%f", &a, &b, &error);

    printf("\nstep \t first(a) \t second(b) \t f(a)    \t f(b)    \t root(x) \t");
    int step = 1;
    do
    {
        fa = f(a);
        fb = f(b);
        x = a - (fa*(a-b))/(fa-fb);

        printf("\n%d \t %f \t %f \t %f \t %f \t %f \t",step++,a,b,fa,fb,x);
        a=b;
        b=x;

        r_error = fabs(b-a)/x;
        
    } while (r_error > error);

    printf("\n\nthe root is %f",x);
    
    return 0;
}

/*
estimating one root of 3x^2 - 6x + 2 
enter initial roots and error ( a  b error) : 1 2 0.005

step     first(a)        second(b)       f(a)            f(b)            root(x) 
1        1.000000        2.000000        -1.000000       2.000000        1.333333 
2        2.000000        1.333333        2.000000        -0.666667       1.500000 
3        1.333333        1.500000        -0.666667       -0.250000       1.600000 
4        1.500000        1.600000        -0.250000       0.080000        1.575758 
5        1.600000        1.575758        0.080000        -0.005509       1.577320 

the root is 1.577320
*/