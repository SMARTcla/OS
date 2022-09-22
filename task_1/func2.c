#include <stdio.h>
#include <unistd.h>
#include <math.h>

void func2(double x)
{
	double fx = exp(-fabs(x))*sin(x);
	printf("\nYour answer :\n f(x) = %.2lf \n", fx);
	printf("PID if func1.c is %d\n", getpid());
}