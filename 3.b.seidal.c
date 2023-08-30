#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define A(x,y,z) (17-y+2*z)/20
#define B(x,y,z) (z-3*x-18)/20
#define C(x,y,z) (25-2*x+3*y)/20

int main(){
    float x0,y0,z0,x1,y1,z1,ex,ey,ez;
    x0 = y0 = z0 = 0;
    int steps = 0;
    printf("steps\tx_n\t\ty_n\t\tz_n\n");
    do
    {
        printf("%d\t%f\t%f\t%f\n",steps++,x0,y0,z0);

        x1 = A(x0,y0,z0);
        y1 = B(x1,y0,z0);
        z1 = C(x1,y1,z0);
        
        ex = fabs(x1-x0);
        ey = fabs(y1-y0);
        ez = fabs(z1-z0);

        x0 = x1;
        y0 = y1;
        z0 = z1;
    } while (ex >= 0.001 || ey >= 0.001 || ez >= 0.001);

    printf("\nx = %.4f , y = %.4f , z = %.4f",x0,y0,z0);
    return 0;
}

/*
steps   x_n             y_n             z_n
0       0.000000        0.000000        0.000000
1       0.850000        -1.027500       1.010875
2       1.002463        -0.999826       0.999780
3       0.999969        -1.000006       1.000002

x = 1.0000 , y = -1.0000 , z = 1.0000
*/