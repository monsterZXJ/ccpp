#include <stdio.h>
#include <stdlib.h>

int i = 1;

void hanoi( int n, char x, char y, char z)
{
    if( 1 == n )
    {
        printf("step %d move %c to %c \n", i++, x, z);
    }
    else
    {
        hanoi( n-1, x, z, y );
        printf("step %d move %c to %c \n", i++, x, z);
        hanoi( n-1, y, x, z );
    }
}

int main()
{
    int n;
    char a = 'X', b = 'Y', c = 'Z';

    printf("ÇëÊäÈëººÅµËşµÄ²ãÊı£º");
    scanf("%d", &n);
    hanoi( n, a, b, c );
    return 0;
}
