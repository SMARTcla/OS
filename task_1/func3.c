#include <stdio.h>
#include <unistd.h>
#include <math.h>

void func3(double x)
{
	double gx = exp(-fabs(x))*cos(x);
	printf("\nYour answer :\n g(x) = %.2lf\n", gx);
	printf("PID if func1.c is %d\n", getpid());
}
