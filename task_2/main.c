#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main()
{
    srand(time(NULL));
    int secret1 = rand() % 7 + 1;
    int secret2 = rand() % 7 + 1;
    int secret3 = rand() % 7 + 1;
    int kredits = 5000;
    printf("This is a new game!\n");
    printf("We invite you to play roulette.\n");
    printf("You have 5000 credits in your account.\n");
    printf("For each spin, 50 points are deducted from your credit!\n");
    printf("If you hit 6-6-6, you lose!\n");
    printf("If you get 7-7-7, you win!\n");
    printf("If you have combinations of 5-X-X, you win 50 credits!\n");
    printf("If you have combinations of 5-5-X, you win 100 credits!\n");
    printf("If you have combinations of 5-5-5, you win 400 credits!\n");
    printf("If you have combinations of 7-X-X, you win 100 credits!\n");
    printf("If you have combinations of 7-7-X, you win 200 credits!\n");  
    printf("Do you want to start?(y/n)\n");
    char str1[100];
    scanf("%19s", str1);
    printf("I am sorry, but you dont have another variants :( \n");
    int i = 5;
    while (i == 5) {
        int secret1 = rand() % 7 + 1;
        int secret2 = rand() % 7 + 1;
        int secret3 = rand() % 7 + 1;
        
        printf("%d-%d-%d", secret1, secret2, secret3);
        kredits = kredits - 25;
        if (secret1 == 5){
            if (secret2 == 5){
                if (secret3 == 5){
                    printf("You won 400 kredits!\n");
                    kredits = kredits + 400;
                }
                else{
                    printf("You won 100 kredits!\n");
                    kredits = kredits + 100;
                }
            }
            else{
                printf("You won 50 kredits!\n");
                kredits = kredits + 50;
            }
        }
        if (secret1 == 7){
            if (secret2 == 7){
                if (secret3 == 7){
                    printf("You won the game!\n");
                    return 0;
                }
                else{
                    printf("You won 200 kredits!\n");
                    kredits = kredits + 100;
                }
            }
            else{
                printf("You won 100 kredits!\n");
                kredits = kredits + 50;
            }
        }
        if (secret1 == 6 && secret2 == 6 && secret3 == 6){
            printf("You lost the game!!!");
            return 0;
        }
        if (kredits == 0){
            printf("You lost the game!!!");
            return 0;
        } 
        printf("Your kredits is %d\n", kredits);
        int str2;
        printf("Enter smth to continue : ");
        scanf("%d", &str2);
    }
    return 0;
}