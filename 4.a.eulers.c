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
    float xn = 2.5; //y(2.5)=?
    float yn = y0;
    int steps = 0; 
    printf("steps\tx_n\t\ty_n\t\n");
    for (float x = x0; x < xn; x+=h)
    {
        printf("%d\t%f\t%f\n",steps++,x,yn);
        yn = yn + (f(x,yn))*h;
    }
    printf("\ny(%.2f) = %.4f",xn,yn);
    return 0;
}

/*
steps   x_n             y_n
0       1.000000        2.000000
1       1.250000        1.000000
2       1.500000        1.039063
3       1.750000        1.557617
4       2.000000        2.192932
5       2.250000        2.903534

y(2.50) = 3.6991      

*/