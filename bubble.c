
#include <stdio.h>
#include <stdlib.h>
#define NUM 10 // 정렬하려는 자료의 개수

void bubble(int data[])
{
   int i, j, round;
   int temp; // 자료 교환을 위한 것
   int flag; // 자료 교환이 한번이라도 일어나면 1, 한번도 일어나지 않으면 0

   printf("-------- 원 자료는 다음과 같습니다. --------\n");
   for(i=0; i < NUM; i++)
      printf("%3d ", data[i]);
   printf("\n\n");

   for(round = 1; round < NUM; round++) // NUM -1 라운드 실행
   {
      flag = 0;
      for(j=0; j < (NUM-round); j++)
      {
         if(data[j] > data[j+1]) // 자료 교환하여야 한다.
         {
            temp = data[j];
            data[j] = data[j+1];
            data[j+1] = temp;
            flag = 1; // 자료 교환이 일어났음을 표시
         }
      }
      printf("----- %d 라운드 결과는 다음과 같습니다. -----\n", round);
      for(i=0; i < NUM; i++)
        printf("%3d ", data[i]);
      printf("\n\n");
      if(flag == 0) // 자료 교환이 한번도 안 일어났으면,
      {
         printf("============= 정렬이 끝났습니다.=============\n");
         break;
      }
   }
}

void main()
{
   int src[NUM];
   int x;
   printf("정렬할 임의의 정수 %d개를 입력하세요 : ", NUM);
   for(x=0; x < NUM; x++)
      scanf("%d", &src[x]);
   printf("\n\n");
   bubble(src);
}
