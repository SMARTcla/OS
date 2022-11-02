#include <stdio.h>
#include <unistd.h>
#include <wait.h>

int main() 
{
    setbuf(stdout, NULL);
    int local_variable = 0;
    pid_t PID[2];
    PID[0] = fork();

    if (PID[0] == 0) 
    {
        local_variable++;
        printf("\n--------------\n Variable = %d\n Address = %p\n Parent PID = %d\n PID = %d\n--------------\n", local_variable, &local_variable, getppid(), getpid());

        pid_t temp_pid[2];
        temp_pid[0] = fork();

        if (temp_pid[0] == 0) 
        {

            local_variable++;
            printf("\n--------------\n Variable = %d\n Address = %p\n Parent PID = %d\n PID = %d\n--------------\n", local_variable, &local_variable, getppid(), getpid());
        } 

        else if (temp_pid[0] > 0) 
        {
            temp_pid[1] = fork();
            if (temp_pid[1] == 0) 
            {
                local_variable++;
                printf("\n--------------\n Variable = %d\n Address = %p\n Parent PID = %d\n PID = %d\n--------------\n", local_variable, &local_variable, getppid(), getpid());
            } 
            else if (temp_pid[1] > 0) 
            {
                printf("\n--------------\n Second identifier 1 = %d identifier 2 = %d\n--------------\n", temp_pid[0], temp_pid[1]);
                wait(NULL);
            }
        }
    } 
    else if (PID[0] > 0) 
    {
        PID[1] = fork();
        if (PID[1] == 0) 
        {
            local_variable++;
            printf("\n--------------\n Variable = %d\n Address = %p\n Parent PID = %d\n PID = %d\n--------------\n", local_variable, &local_variable, getppid(), getpid());
            pid_t temp_pid[2];
            temp_pid[0] = fork();
            if (temp_pid[0] == 0) 
            {
                local_variable++;
                printf("\n--------------\n Variable = %d\n Address = %p\n Parent PID = %d\n PID = %d\n--------------\n", local_variable, &local_variable, getppid(), getpid());
            } 

            else if (temp_pid[0] > 0) 
            {
                temp_pid[1] = fork();

                if (temp_pid[1] == 0) 
                {
                    local_variable++;
                    printf("\n--------------\n Variable = %d\n Address = %p\n Parent PID = %d\n PID = %d\n--------------\n", local_variable, &local_variable, getppid(), getpid());
                } 
                else if (temp_pid[1] > 0) 
                {
                    printf("\n--------------\n Second identifier 1 = %d identifier 2 = %d\n--------------\n", temp_pid[0], temp_pid[1]);
                }
            }

        } 
        else if (PID[1] > 0) 
        {
            printf("\n--------------\n Main identifier 1 = %d identifier 2 = %d\n--------------\n", PID[0], PID[1]);
            wait(NULL);
        }
    }

    return 0;
}