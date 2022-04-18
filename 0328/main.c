#include <stdio.h>
#include <stdlib.h>

int main()
{

    int num[10] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int i;

    for(i = 0; i < 10; i++)
        printf("%2d 이(가) 보관된 배열은 %d이다.\n", num[i], &num[i]);
}
