#include <stdio.h>
#include <stdlib.h>

extern char **environ;
int main (int argc, char* argv[], const char *envp[]) {
    printf("envirop : %s\n", environ);
    printf("envp: %s\n", envp);

    setenv(argv[1], argv[2], 1);
    puts("-------Added NEW_VAR-----");

    printf("envirop : %s\n", environ);
    printf("envp: %s\n", envp);


    exit(EXIT_SUCCESS);
}