#include <stdio.h>
int main ()
{
    int array[6];
    int i = 0;

    while (i < 6)
    {
        array[i] = 0;
        i++;
    }
    i = -1;
    while (++i < 6)
    {
        printf("i before is %d\n", i);
        printf("array before is %d\n", array[i]);
        array[i] = 1;
        printf("i after is %d\n", i);
        printf("array after is %d\n", array[i]);
        // i++;
    }
}