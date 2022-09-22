#include <stdio.h>
#include <unistd.h>
#include <math.h>

void func1(double x)
{
	double fx;
	fx = exp((-1)*fabs(x))*sin(x);
	double gx = exp(-fabs(x))*cos(x);
	printf("\nYour answer :\n f(x) = %.2lf \n g(x) = %.2lf\n", fx, gx);
	printf("PID if func1.c is %d\n", getpid());
}