#include <stdio.h>

int main()
{
    float rx;
    float rx2;
    int mx;
    float px = 240;
    rx = (((int)px >> 6) << 6) + 64;
    printf("%f\n", rx);
    mx = (int)rx / 64;
    printf("%d\n", mx);
    rx2 = (((int)px >> 6) << 6) -0.0001;
    printf("%f\n", rx2);
    mx = (int)rx2 / 64;
    printf("%d\n", mx);
}