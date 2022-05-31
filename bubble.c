
#include <stdio.h>
#include <stdlib.h>
#define NUM 10 // �����Ϸ��� �ڷ��� ����

void bubble(int data[])
{
   int i, j, round;
   int temp; // �ڷ� ��ȯ�� ���� ��
   int flag; // �ڷ� ��ȯ�� �ѹ��̶� �Ͼ�� 1, �ѹ��� �Ͼ�� ������ 0

   printf("-------- �� �ڷ�� ������ �����ϴ�. --------\n");
   for(i=0; i < NUM; i++)
      printf("%3d ", data[i]);
   printf("\n\n");

   for(round = 1; round < NUM; round++) // NUM -1 ���� ����
   {
      flag = 0;
      for(j=0; j < (NUM-round); j++)
      {
         if(data[j] > data[j+1]) // �ڷ� ��ȯ�Ͽ��� �Ѵ�.
         {
            temp = data[j];
            data[j] = data[j+1];
            data[j+1] = temp;
            flag = 1; // �ڷ� ��ȯ�� �Ͼ���� ǥ��
         }
      }
      printf("----- %d ���� ����� ������ �����ϴ�. -----\n", round);
      for(i=0; i < NUM; i++)
        printf("%3d ", data[i]);
      printf("\n\n");
      if(flag == 0) // �ڷ� ��ȯ�� �ѹ��� �� �Ͼ����,
      {
         printf("============= ������ �������ϴ�.=============\n");
         break;
      }
   }
}

void main()
{
   int src[NUM];
   int x;
   printf("������ ������ ���� %d���� �Է��ϼ��� : ", NUM);
   for(x=0; x < NUM; x++)
      scanf("%d", &src[x]);
   printf("\n\n");
   bubble(src);
}
