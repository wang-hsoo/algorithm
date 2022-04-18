struct Node{
    char name[20];
    int price;
    struct Node *next;
};

struct Node head;
int count = 0;

struct Node *getnode()
{
    struct Node *p;
    p = (struct Node *)malloc(sizeof(struct Node));
    return(p);
};

void retnode(struct Node* ptr)
{
    free(ptr);
}

void addnode(char f[], int p)
{
    int i;
    struct Node *ptr;
    struct Node *current, *previous;
    current = head.next;
    previous = &head;

    for(i = 0; i < count; i++)
    {
        if(strcmp(f, current -> name) > 0)
        {
            previous = current;
            current = current -> next;
            continue;
        }
        else break;
    }

    ptr = getnode();
    strcpy(ptr -> name, f);
    ptr -> price = p;
    //구조체 주소 (*ptr).price
    ptr -> next = previous -> next;
    previous -> next = ptr;
    count += 1;
}

void delnode(char f[])
{

    int i;
    struct Node *current, *previous;
    current = head.next;
    previous = &head;

    for(i = 0; i < count; i++)
    {
        if(strcmp(f, current -> name) == 0)
            break;
        else
        {
            previous = current;
            current = current -> next;
            continue;
        }
    }

    if(current == NULL)
        printf("\m삭제할 과일이 등록되어 있지 않습니다.\n");
    else
    {

        previous-> next = current -> next;
        retnode(current);
    }

    count -= 1;
}

void prn()
{

    int i;
    struct Node *current = head.next;

     if(count == 0)
    {
        printf("\n-----현재 등록된 과일이 없습니다-----\n");
        return;

    }
    printf("\n-----현재 등록된 과일은 아래와 같습니다-----\n");

    for(i = 0; i < count; i++)
    {
          printf("%2d번째 과일 : %10s - 가격 %4d\n\n", i + 1, current -> name, current -> price);
          current = current -> next;
    }

    printf("----------------------------------------------------------\n\n");
}


void main()
{
    int choice;
    char name[20];
    int p;
    int i;

    head.next = NULL;

    printf("현재는 등록된 과일이 없습니다.\n");

    do
    {
        choice;
        printf("원하는 작업 선택: 1-삽입, 2-삭제, 3-리스트 내용 출력, 4-프로그램 끝내기: ");
        scanf("%d", &choice);

        switch(choice)
        {

        case 1 :
            printf("\삽입할 과일 이름을 입력하세요 : ");
            scanf("%s", &name);
            printf("\삽입할 과일의 가격을 입력하세요 : ");
            scanf("%d", &p);
            getchar();
            addnode(name,p);

            if(count != 10)
                prn();
            break;

        case 2:
            printf("\삭제할 과일 이름을 입력하세요 : ");
            scanf("%s", &name);
            delnode(name);
            prn();
            break;

        case 3:
            prn();
            break;

        case 4:
        default:
            printf("프로그램이 끝났습니다 \n");
            exit(0);


        }

    }while(1);
}
