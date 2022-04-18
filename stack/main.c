#include <stdio.h>
#include <stdlib.h>
#define MAX 10

char stack [MAX];
int top = -1;
int bottom = 0;

void push(char t)
{
    if(top == (MAX -1))
    {
        printf("\n스택이 꽉 찼습니다\n");
        return;
    }else
        stack[++top] = t;

}

char pop()
{
    if (top == -1)
        return 'Q';
    else
        return (stack[top--]);
}

void prn()
{
    int i;
    printf("\n----------------현재 스택의 모습-----------------------\n");
    if(top == -1)
        printf("\n현재스택은 비어 있습니다\n");
    else
    {
        for( i = bottom; i <= top; i++)
            printf("%c", stack[i]);
    }

    printf("\n-------------------------------------------------------\n");
}

void main()
{
    int choice;
    char train;
    char pop_result;

    printf("현재는 종착역에 열차가 없습니다.\n");

    do
    {
        choice = 0;
        printf("\n\n 원하는 작업 선택 :1 - push, 2 - pop, 3 - 스택 출력, 4 - 프로그램 끝내기 : ");
        scanf("%d", &choice);
        getchar();

        switch(choice)
        {
        case 1:
            printf("\n push할 열차 이름을 입력하세요 : ");
            scanf("%c", &train);
            getchar();
            push(train);
            prn();
            break;

        case 2:
            pop_result = pop();
            if(pop_result != 'Q')
                printf("\n pop된 열차는 %d 입니다.\n", pop_result);
            prn();
            break;

        case 3:
            prn();
            break;

        case 4:
        default:
            printf("프로그램이 끝났습니다. \n");
            exit(0);
        }
    }while(1);
}
