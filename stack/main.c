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
        printf("\n������ �� á���ϴ�\n");
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
    printf("\n----------------���� ������ ���-----------------------\n");
    if(top == -1)
        printf("\n���罺���� ��� �ֽ��ϴ�\n");
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

    printf("����� �������� ������ �����ϴ�.\n");

    do
    {
        choice = 0;
        printf("\n\n ���ϴ� �۾� ���� :1 - push, 2 - pop, 3 - ���� ���, 4 - ���α׷� ������ : ");
        scanf("%d", &choice);
        getchar();

        switch(choice)
        {
        case 1:
            printf("\n push�� ���� �̸��� �Է��ϼ��� : ");
            scanf("%c", &train);
            getchar();
            push(train);
            prn();
            break;

        case 2:
            pop_result = pop();
            if(pop_result != 'Q')
                printf("\n pop�� ������ %d �Դϴ�.\n", pop_result);
            prn();
            break;

        case 3:
            prn();
            break;

        case 4:
        default:
            printf("���α׷��� �������ϴ�. \n");
            exit(0);
        }
    }while(1);
}
