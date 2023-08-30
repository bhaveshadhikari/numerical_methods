#include<stdio.h>
#include<math.h>
#include<stdlib.h>

// y' = 2x^3 - 3xy
// y(1)   = 2
// y(2.5) = ?
#define f(x,y) (2*x*x*x - 3*x*y)
#define y0 2
#define x0 1

int main(){
    float h = 0.25;
    float xn = 2.5;
    float yn = y0;
    int steps = 0;
    printf("steps\tx_n\t\ty_n\t\n");
    for (float x = x0; x < xn; x+=h)
    {
        printf("%d\t%f\t%f\n",steps++,x,yn);

        float k1 = f(x,yn);
        float k2 = f((x+h/2),(yn+k1*h/2));
        float k3 = f((x+h/2),(yn+k2*h/2));
        float k4 = f((x+h),(yn+k3*h));
        yn = yn + (k1+2*k2+2*k3+k4)*h/6;  
    }
    printf("\ny(%.2f) = %.4f", xn, yn);
    return 0;
}

/*
steps   x_n             y_n
0       1.000000        2.000000
1       1.250000        1.367630
2       1.500000        1.337528
3       1.750000        1.687539
4       2.000000        2.250428
5       2.250000        2.942136

y(2.50) = 3.7309
*/