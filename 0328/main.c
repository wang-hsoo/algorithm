#include <stdio.h>
#include <stdlib.h>

int main()
{

    int num[10] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int i;

    for(i = 0; i < 10; i++)
        printf("%2d ��(��) ������ �迭�� %d�̴�.\n", num[i], &num[i]);
}
