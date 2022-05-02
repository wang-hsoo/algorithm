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
        printf("\n 큐가 꽉 찼습니다. \n");
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

    printf("\n ------현재 큐의 모습---------\n");
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

    printf("------------front=%d 현재는 큐에 자료가 없습니다.----rear=%d------\n", front , rear);

    do
    {
        int choice;
        char data;
        char result;
        printf("\n\n  원하는 작업 선택:1-enQ(삽입), 2 -deQ(삭제), 3-큐출력, 4-프로그램 끝내기");
        scanf("%d", &choice);
        getchar();
        switch(choice)
        {
        case 1:
            printf("\n삽입할 문자를 입력 하세요: ");
            scanf("%c", &data);
            getchar();
            enqueue(data);
            prn();
            break;

        case 2:
            result = dequeue();
            if(result != 'Q')
                printf("삭제된 자료는 %c 입니다.\n", result);
            else
                printf("\n큐가 비어 있습니다\n");
            prn();
            break;

        case 3:
            prn();
            break;

        case 4:
        default:
            printf("프로그램이 끝났습니다.\n");
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
        printf("큐가 비어 있습니다.");
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
        printf("\n ---현재 큐가 비어 있습니다.-------\n\n");
        return;
    }

    printf("\n---현재 큐의 내용은 아래와 같습니다.----\n\n");
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

    printf("------------현재는 큐에 자료가 없습니다.----------\n");

    do
    {
        choice = 0;
        printf("\n\n  원하는 작업 선택:1-enQ(삽입), 2 -deQ(삭제), 3-큐출력, 4-프로그램 끝내기");
        scanf("%d", &choice);
        getchar();
        switch(choice)
        {
        case 1:
            printf("\n삽입할 문자를 입력 하세요: ");
            scanf("%c", &item);
            getchar();
            enqueue(item);
            prn();
            break;

        case 2:
            result = dequeue();
            if(result != 'Q')
                printf("삭제된 자료는 %c 입니다.\n", result);
            else
                printf("\n큐가 비어 있습니다\n");
            prn();
            break;

        case 3:
            prn();
            break;

        case 4:
        default:
            printf("프로그램이 끝났습니다.\n");
            exit(0);
        }
    }while(1);
}

