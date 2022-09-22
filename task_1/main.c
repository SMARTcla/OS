#include <stdio.h>
#include "header.h"
#include <math.h>
void main()
{
    printf("\nThis is homework №1\n");
	printf("\nCalling first task\n");
	printf("Please enter some data : ");
	double x;
	scanf("%lf", &x);
	func1(x);
	printf("\nCalling second task\n");
	func2(x);
	func3(x);
	printf("\nIt's all");
}