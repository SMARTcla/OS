
#include <stdio.h>
#include <string.h>
#include <math.h>

struct Point_in_space {
   int weight;
   int x;
   int y;
   int z;
   int speed_x;
   int speed_y;
   int speed_z;
};

int main()
{
   int temp = 4;
   // printf("How much dot u want to add :\n");
   // scanf("%d", &temp);
   struct Point_in_space dots[10] = {55, -1, -100, -100, 1, 1, 1, 23, 6, -6, 7, 1, 1, 1, 78, 8, -10, 34, 1, 1, 1, 2, 67, 23, 56, 1, 1, 1,};
   int n = sizeof(dots)/sizeof(dots[0]);
   // for (int i = 0 ; i < temp ; i++){
   //   printf("Enter new weigh : ");
   //   scanf("%d", &dots[i].weight);
   //   printf("Enter new X : ");
   //   scanf("%d", &dots[i].x);
   //   printf("Enter new Y : ");
   //   scanf("%d", &dots[i].y);
   //   printf("Enter new Z : ");
   //   scanf("%d", &dots[i].z);
   //   printf("Enter new speed_x : ");
   //   scanf("%d", &dots[i].speed_x);
   //   printf("Enter new speed_y : ");
   //   scanf("%d", &dots[i].speed_y);
   //   printf("Enter new speed_z : ");
   //   scanf("%d", &dots[i].speed_z);
   // }
   int remaining_points[temp];
   for (int i = 0 ; i < temp ; i++){
      remaining_points[i] = i;
   }
   for(int i = 0 ; i < temp; i++){
        for (int i = 0 ; i < temp ; i++){
            dots[i].x += dots[i].speed_x;
            dots[i].y += dots[i].speed_y;
            dots[i].z += dots[i].speed_z;
        }
        int min = 1000000;
        int min_dot = 0;
        for ( int i = 0 ; i < temp ; i++){
            if (dots[i].weight != 0){
                if ( dots[i].weight < min){
                    min = dots[i].weight;
                    min_dot = i;
                }
            }
        }
      float array[temp];
      for ( int i = 0 ; i < temp ; i++){
         array[i] = -1.0;
      }
      float min_leght = 100000.0;
      int min_leght_dot = 0;
      for (int i = 0 ; i < temp ; i++){
         if(i != min_dot){
            if (dots[i].weight != 0){
               array[i] = sqrt(pow((dots[i].x - dots[min_dot].x), 2) + pow((dots[i].y - dots[min_dot].y), 2) + pow((dots[i].z - dots[min_dot].z), 2));
               if (min_leght > array[i]){
                  min_leght = array[i];
                  min_leght_dot = i;
               }
            }
         }
      }
    //   printf("weight1 = %d \n", dots[min_leght_dot].weight);
    //   printf("weight2 = %d \n", dots[min_dot].weight);
      dots[min_leght_dot].weight += dots[min_dot].weight;
      dots[min_dot].weight = 0;
    //   printf("weight3 = %d \n", dots[min_leght_dot].weight);
    //   printf("weight4 = %d \n", dots[min_dot].weight);
   }
   for (int i = 0 ; i < temp ; i++){         
      if (dots[i].weight != 0){
        printf("weight = %d \n with x = %d \n with y = %d \n with z = %d", dots[i].weight, dots[i].x, dots[i].y, dots[i].z);
      }
   }
   return 0;
 }