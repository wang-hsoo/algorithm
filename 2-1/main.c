#include <stdio.h>
#include <stdlib.h>

void main(){
    int num[10];
    int i, max;
    printf("10���� ������ �Է��ϼ���: ");

    for(i = 0; i < 10; i++){
        scanf("%d", &num[i]);
    }
    max = num[0];

    for(i = 0; i < 10; i++){
        printf("%d\n",num[i]);
        if(num[i] > max)
            max = num[i];
    }

    printf("\n�� 10�� �� �߿��� �ִ밪�� %d�Դϴ�.\n", max);

}
