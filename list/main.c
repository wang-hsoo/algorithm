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
    //����ü �ּ� (*ptr).price
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
        printf("\m������ ������ ��ϵǾ� ���� �ʽ��ϴ�.\n");
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
        printf("\n-----���� ��ϵ� ������ �����ϴ�-----\n");
        return;

    }
    printf("\n-----���� ��ϵ� ������ �Ʒ��� �����ϴ�-----\n");

    for(i = 0; i < count; i++)
    {
          printf("%2d��° ���� : %10s - ���� %4d\n\n", i + 1, current -> name, current -> price);
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

    printf("����� ��ϵ� ������ �����ϴ�.\n");

    do
    {
        choice;
        printf("���ϴ� �۾� ����: 1-����, 2-����, 3-����Ʈ ���� ���, 4-���α׷� ������: ");
        scanf("%d", &choice);

        switch(choice)
        {

        case 1 :
            printf("\������ ���� �̸��� �Է��ϼ��� : ");
            scanf("%s", &name);
            printf("\������ ������ ������ �Է��ϼ��� : ");
            scanf("%d", &p);
            getchar();
            addnode(name,p);

            if(count != 10)
                prn();
            break;

        case 2:
            printf("\������ ���� �̸��� �Է��ϼ��� : ");
            scanf("%s", &name);
            delnode(name);
            prn();
            break;

        case 3:
            prn();
            break;

        case 4:
        default:
            printf("���α׷��� �������ϴ� \n");
            exit(0);


        }

    }while(1);
}
