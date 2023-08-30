#include<stdio.h>

int main(){
    int n = 4;
    int x[]={5,6,9,11};
    int y[]={12,13,14,16};
    printf("the given data sets : \n\nx\ty");
    for (int i = 0; i < n; i++)
        printf("\n%d\t%d",x[i],y[i]);


    float sumX=0, sumY=0, sumXY=0, sumX_sq=0, b, a;

    for (int i = 0; i < n; i++)
    {   
        sumX += x[i];
        sumY += y[i];
        sumX_sq += (x[i]*x[i]);
        sumXY += (x[i]*y[i]);
    }

    b = (n*sumXY - sumX*sumY)/(n*sumX_sq - sumX*sumX);
    a = (sumY/n)-(b*sumX/n);

    printf("\n\nregression equation of Y on X is :");
    printf("\nY = %.3f + %.3f X",a,b);
    float yn=0 , xn;
    printf("\nestimate y at xn = ");
    scanf("%f",&xn);

    yn = a + b * xn ;
    printf("estimated y(%.2f) : %.3f",xn,yn);

    return 0;
    
}

/*
the given data sets : 

x       y
5       12
6       13
9       14
11      16

regression equation of Y on X is :
Y = 9.066 + 0.604 X
estimate y at xn = 8
estimated y(8.00) : 13.901
*/