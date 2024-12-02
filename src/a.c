#include <stdio.h>

int main()
{
    float rx;
    float rx2;
    float px = 240;
    rx = (((int)px >> 6) << 6) + 64;
    printf("%f\n", rx);
    rx2 = (((int)px >> 6) << 6) -0.0001;
    printf("%f\n", rx2);
    printf("%d\n", (int)px);
}