#include <stdio.h>
#include <string.h>

int count_n = 4;
int grade_duty = 50;
int grade_good = 70;
int grade_perfect = 90;

struct Student {
   char surname[50];
   int grades_web;
   int grades_ua;
   int grades_pr;
   int group;
};

void duty(struct Student *students){
    int array_duty[30];
    int tmp = 0;
    for ( int i = 0 ; i < count_n ; i++){
        if (students[i].grades_web < grade_duty || students[i].grades_ua < grade_duty || students[i].grades_pr < grade_duty ){
            array_duty[tmp] = i;
            tmp++;
        }
    }
    printf("Students with debt: \n");
    for (int i = 0 ; i < tmp ; i++){
        printf("%s %d : %d - %d - %d \n", students[array_duty[i]].surname, students[array_duty[i]].group, students[array_duty[i]].grades_web, students[array_duty[i]].grades_ua, students[array_duty[i]].grades_pr);
    }
}

void perf(struct Student *students){
    int array_duty[30];
    int tmp = 0;
    for ( int i = 0 ; i < count_n ; i++){
        if (students[i].grades_web > grade_good && students[i].grades_ua > grade_good  && students[i].grades_pr > grade_good){
            array_duty[tmp] = i;
            tmp++;
        }
    }
    printf("Students with perfect grades: \n");
    for (int i = 0 ; i < tmp ; i++){
        printf("%s %d : %d - %d - %d \n", students[array_duty[i]].surname, students[array_duty[i]].group, students[array_duty[i]].grades_web, students[array_duty[i]].grades_ua, students[array_duty[i]].grades_pr);
    }
}

int main()
{
    struct Student students[30] = {"Kononenko", 56, 45, 12, 1, "Max", 81, 9, 100, 1, "Key", 96, 99 ,76, 1, "Smart", 96, 99 ,6, 1};
    int n = sizeof(students)/sizeof(students[0]);
    for ( int i = 0 ; i < count_n ; i++){
        printf("%s %d : %d - %d - %d \n", students[i].surname, students[i].group, students[i].grades_web, students[i].grades_ua, students[i].grades_pr);
    }
    duty(students);
    perf(students);
    return 0;
}
