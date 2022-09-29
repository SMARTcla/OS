#include <stdio.h>
#include <string.h>

int count_n = 5;
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

void best(struct Student *students){
    int ua = 0;
    int pr = 0;
    int web = 0;
    int array_duty[30];
    int tmp = 0;
    for ( int i = 0 ; i < count_n ; i++){
        ua += students[array_duty[i]].grades_ua;
        pr += students[array_duty[i]].grades_pr;
        web += students[array_duty[i]].grades_web;
    }
    if (web > ua && web > pr){
        printf("Web is best\n");
    }
    if (ua > web && ua > pr){
        printf("Web is best\n");
    }
    if (pr > ua && pr > web){
        printf("Web is best\n");
    }
}

void worst(struct Student *students){
    int count_g[5];
    for (int i = 0 ; i < count_n ; i++){
        count_g[i] = 0;
    }
    float ua[4];
    float pr[4];
    float web[4];
    int tm = 0;
    for (int i = 0 ; i < count_n +1; i++){
        ua[i] = 0;
        pr[i] = 0;
        web[i] = 0;
    }
    int tmp = 0;
    for ( int i = 0 ; i < count_n ; i++){
        if (students[i].group == 1){
            count_g[0]++;
        }
        if (students[i].group == 2){
            count_g[1]++;
        }
        if (students[i].group == 3){
            count_g[2]++;
        }
        if (students[i].group == 4){
            count_g[3]++;
        }
        tm++;
        web[students[i].group] += students[i].grades_web;
        ua[students[i].group] += students[i].grades_ua;
        pr[students[i].group] += students[i].grades_pr;
    }
    printf("Count - %d\n",count_g[0]);
    printf("Count2 - %d\n",count_g[1]);
    for (int i = 0 ; i < count_n ; i++){
        if (count_g[i] != 0){
            printf("ua(%d) - %f\n", i, ua[i + 1]);
            printf("web(%d) - %f\n",i,  web[i + 1]);
            printf("pr(%d) - %f\n", i, pr[i + 1]);
        }
    }
    for (int i = 0 ; i < count_n ; i++){
        if (count_g[i] != 0){
            ua[i + 1] = ua[i + 1] / count_g[i];
            pr[i + 1] = pr[i + 1] / count_g[i];
            web[i + 1] = (web[i + 1] / count_g[i]);
        }
    }
    for (int i = 0 ; i < count_n ; i++){
        if (count_g[i] != 0){
            printf("ua(%d) - %f\n", i, ua[i + 1]);
            printf("web(%d) - %f\n",i,  web[i + 1]);
            printf("pr(%d) - %f\n", i, pr[i + 1]);
        }
    }
    float suma[count_n + 1];
    for ( int i = 0 ; i < count_n ; i++){
        printf("Sum %d = %f\n",i, suma[i]);
    }
    for ( int i = 0 ; i < count_n ; i++){
        suma[i] = 0;
    }
    for ( int i = 0 ; i < count_n ; i++){
        suma[i + 1] += ua[i + 1] + pr[i + 1] + web[i + 1]; 
    }
    for ( int i = 0 ; i < count_n ; i++){
        printf("Sum %d = %f\n",i, suma[i]);
    }
    float min = suma[1];
    int min_g = 1;
    for ( int i = 1 ; i < count_n + 1 ; i++){
        if (suma[i] > 1.0){
            if (suma[i] < min){
                if (suma[i] != (float)0.0){
                    min = suma[i];
                    min_g = i;
                    printf("suma min = %f min_g = %d\n", min, min_g);
                }
            }
        }
    }
    printf("Minimum = %d", min_g);

}

int main()
{
    struct Student students[30] = {"Kononenko", 56, 45, 12, 1, "Max", 81, 9, 100, 1, "Key", 96, 99 ,76, 1, "Smart", 96, 99 ,6, 1, "Klon", 1, 1 ,1, 2};
    int n = sizeof(students)/sizeof(students[0]);
    for ( int i = 0 ; i < count_n ; i++){
        printf("%s %d : %d - %d - %d \n", students[i].surname, students[i].group, students[i].grades_web, students[i].grades_ua, students[i].grades_pr);
    }
    printf("------------Menu--------------\n");
    duty(students);
    perf(students);
    best(students);
    worst(students);
    return 0;
}
