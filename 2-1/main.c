#include <stdio.h>
#include <stdlib.h>

void main(){
    int num[10];
    int i, max;
    printf("10개의 정수를 입력하세요: ");

    for(i = 0; i < 10; i++){
        scanf("%d", &num[i]);
    }
    max = num[0];

    for(i = 0; i < 10; i++){
        printf("%d\n",num[i]);
        if(num[i] > max)
            max = num[i];
    }

    printf("\n위 10개 수 중에서 최대값은 %d입니다.\n", max);

}
