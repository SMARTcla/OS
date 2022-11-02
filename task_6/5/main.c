#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <errno.h>
#include <unistd.h>

int my_system(const char *something) 
{
    pid_t PID;
    int current_status;

    if (something == NULL){
        return (1);
    }

    if ((PID = fork()) < 0) 
    {
        current_status = -1;
    } 
    else if (PID == 0) 
    {
        execl("/bin/sh", "sh", "-c", something, (char *)0);
        _exit(127);
    } 

    else 
    {
        while (waitpid(PID, &current_status, 0) < 0) 
        {
            if (errno != EINTR) 
            {
                current_status = -1;
                break;
            }
        }
    }

    return (current_status);
}

int main(void) 
{
    int current_status;

    if ((current_status = my_system("date")) < 0) 
    {
        fprintf(stderr, "%s\n", "Exec error");
    }

    fprintf(stderr, "Code: %d\n", current_status);

    if ((current_status = my_system("nosuchcommand")) < 0) 
    {
        fprintf(stderr, "%s\n", "Exec error");
    }

    fprintf(stderr, "Code: %d\n", current_status);

    if ((current_status = my_system("who; exit 44")) < 0)  
    {
        fprintf(stderr, "%s\n", "Exec error");
    }

    fprintf(stderr, "Code: %d\n", current_status);

    return 0;
}