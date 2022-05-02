/*#include <stdio.h>
#include <stdlib.h>
#define MAX 10


char queue[MAX];

int front = 0;
int rear = 0;

void enqueue(char t)
{
    if ((rear+1)%MAX == front)
    {
        printf("\n ť�� �� á���ϴ�. \n");
        return;
    }
    else
    {
        rear = (rear + 1) % MAX;
        queue[rear] = t;
    }
}


char dequeue()
{

    char r;
    if (front == rear)
        return '@';
    else
    {
        front = (front + 1) % MAX;
        r = queue[front];
        queue[front] = ' ';
        return(r);
    }
}


void prn()
{

    int i;

    printf("\n ------���� ť�� ���---------\n");
    printf("              ");
    for(i = 0 ; i < MAX; i++)
        printf("[%d]", i);
    printf("\n");
    printf("        ");
    for(i = 0; i < MAX; i++)
        printf("%4c", queue[i]);
    printf("\n-----------------front=%d----------rear=%d--------\n", front, rear);
}

void main()
{
    int choice;
    char data;
    char result;

    printf("------------front=%d ����� ť�� �ڷᰡ �����ϴ�.----rear=%d------\n", front , rear);

    do
    {
        int choice;
        char data;
        char result;
        printf("\n\n  ���ϴ� �۾� ����:1-enQ(����), 2 -deQ(����), 3-ť���, 4-���α׷� ������");
        scanf("%d", &choice);
        getchar();
        switch(choice)
        {
        case 1:
            printf("\n������ ���ڸ� �Է� �ϼ���: ");
            scanf("%c", &data);
            getchar();
            enqueue(data);
            prn();
            break;

        case 2:
            result = dequeue();
            if(result != 'Q')
                printf("������ �ڷ�� %c �Դϴ�.\n", result);
            else
                printf("\nť�� ��� �ֽ��ϴ�\n");
            prn();
            break;

        case 3:
            prn();
            break;

        case 4:
        default:
            printf("���α׷��� �������ϴ�.\n");
            exit(0);
        }
    }while(1);
}*/
#include <stdio.h>
#include <stdlib.h>

struct Node
{

    char val;
    struct Node * next;
};

struct Node q;
int count = 0;

struct Node * getnode()
{
    struct Node *p;
    p = (struct Node*)malloc(sizeof(struct Node));
    return(p);
};

void retnode(struct Node* ptr)
{
    free(ptr);
}

void enqueue(char item)
{
    struct Node *ptr;
    ptr = getnode();
    ptr -> val = item;
    ptr -> next = q.next;
    q.next = ptr;
    count += 1;
}

char dequeue()
{
    int i;
    struct Node * current, *previous;
    current = q.next;
    previous = &q;

    if(q.next == NULL)
    {
        printf("ť�� ��� �ֽ��ϴ�.");
        return('@');
    }
    else
    {
        for( i = 1; i < count; i++)
        {
            previous = current;
            current = current -> next;
        }
    }

    previous -> next = NULL;
    retnode(current);
    count -= 1;

}

void prn()
{
    int i;
    struct Node *current = q.next;
    if(count == 0)
    {
        printf("\n ---���� ť�� ��� �ֽ��ϴ�.-------\n\n");
        return;
    }

    printf("\n---���� ť�� ������ �Ʒ��� �����ϴ�.----\n\n");
    for( i = 0; i < count; i++)
    {
        printf("%c", current -> val);
        current = current -> next;
    }

    printf("\n--------------------\n\n");
}

void main()
{
    int choice;
    char item;
    int i;
    char result;

    q.next = NULL;

    printf("------------����� ť�� �ڷᰡ �����ϴ�.----------\n");

    do
    {
        choice = 0;
        printf("\n\n  ���ϴ� �۾� ����:1-enQ(����), 2 -deQ(����), 3-ť���, 4-���α׷� ������");
        scanf("%d", &choice);
        getchar();
        switch(choice)
        {
        case 1:
            printf("\n������ ���ڸ� �Է� �ϼ���: ");
            scanf("%c", &item);
            getchar();
            enqueue(item);
            prn();
            break;

        case 2:
            result = dequeue();
            if(result != 'Q')
                printf("������ �ڷ�� %c �Դϴ�.\n", result);
            else
                printf("\nť�� ��� �ֽ��ϴ�\n");
            prn();
            break;

        case 3:
            prn();
            break;

        case 4:
        default:
            printf("���α׷��� �������ϴ�.\n");
            exit(0);
        }
    }while(1);
}

