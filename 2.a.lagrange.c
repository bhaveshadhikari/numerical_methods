
#include <stdio.h>

int main()
{
    int n = 4;
    int x[] = {5, 6, 9, 11};
    int y[] = {12, 13, 14, 16};
    printf("the given data sets : \nx\ty");
    for (int i = 0; i < n; i++)
        printf("\n%d\t%d", x[i], y[i]);

    float yn = 0, xn;
    printf("\ninterpolate at xn = ");
    scanf("%f", &xn);

    for (int i = 0; i < n; i++)
    {
        float intermediate_yn = 1;
        for (int j = 0; j < n; j++)
            if (j != i)
                intermediate_yn *= ((xn - x[j]) / (x[i] - x[j]));

        yn += (intermediate_yn * y[i]);
    }
    printf("estimated y(%.2f) : %.3f", xn, yn);

    return 0;
}

/*the given data sets :
x       y
5       12
6       13
9       14
11      16
interpolate at xn = 8
estimated y(8.00) : 13.700
*/