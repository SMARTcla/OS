#include <stdio.h>

int main()
{
    printf("Enter n : ");
    int n = 0;
    scanf("%d", &n);
    while (n < 1){
        printf("Try again :");
        scanf("%d", &n);
    }
    float array[n];
    for (int i = 0 ; i < n ; i++){
        printf("Enter array[%d] :", i);
        scanf("%f", &array[i]);
    }
    float sum = 0.0;
    for (int i = 0; i < n; i++) {
        sum += array[i];
    }
    float ave = sum / n;
    int count = 0;
    for (int i = 0 ; i < n ; i++){
        if (array[i] > ave){
            count++;
        }
    }
    float suma = 0.0;
    for (int i = 0 ; i < n ; i++){
        if (array[i] < 0.0){
            for (int j = i + 1 ; j < n ; j++){
                suma +=array[j];
            }
            i = n;
        }

    }
    printf("Suma = %f \n Aver = %d", suma, count);
    return 0;
}
