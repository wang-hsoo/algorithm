#include <stdio.h>
#include <stdlib.h>

void main()
{
    char stack[20];
    int bottom = 0;
    int top = -1;
    char input[30];
    char postfix[30];
    int i, j =0;
    int d1, d2, r;
    int a, b, c, d, e, f;
    printf("������ �Է��ϼ��� :");
    scanf("%s", input);
    printf("���� ǥ�������� ��ȯ�� ��� :");
    for(i = 0; input[i] != '\0'; i++)
    {
        if(input[i] =='(')
            continue;
        else if(input[i] ==')')
        {
            printf("%c", stack[top]);
            postfix[j++] = stack[top];
            top--;
        }
        else if(input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/')
            stack[++top] = input[i];
        else
        {
            printf("%c", input[i]);
            postfix[j++] = input[i];

        }
    }
    postfix[j] ='\0';
    printf("\n ���� , a, b, c, d, e, f���� ���ʴ�� �Է��ϼ��� : ");
    scanf("%d %d %d %d %d %d",&a, &b, &c, &d, &e, &f );
    top = -1;
    for (i = 0; postfix[i] != '\0'; i++)
    {
        if(postfix[i] =='+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] =='/')
        {
            d2 = stack[top--];
            d1 = stack[top--];
            switch(postfix[i])
            {
            case '+':
                r = d1 + d2;
                break;
            case '-':
                r = d1 - d2;
            case '*':
                r = d1 * d2;
                break;
            case '/':
                r = d1 / d2;
                break;
            default:
                printf("111111\n");

            }
            stack[++top] = r;

        }
        else

        switch(postfix[i])
        {
        case 'a' :
            stack[++top] =a;
            break;
        case 'b':
             stack[++top] =b;
             break;
        case 'c':
             stack[++top] =c;
             break;
        case 'd':
             stack[++top] =d;
             break;
        case 'e':
             stack[++top] =e;
             break;
        case 'f':
             stack[++top] =f;
        default :
            stack[++top] = postfix[i] - 48;
        }
        }
        printf("������ ����� %d�Դϴ�.  \n", stack[top--]);
        printf("\n\n ���α׷� ��\n");
}
