#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(void){
	int i = INT_MAX;
	float f = FLT_MAX;
	double d = DBL_MAX;

	int a = sizeof(int);
	printf("%d\n", a);
	printf("%d\n", i);
	a = sizeof(float);
	printf("%d\n", a);
	printf("%f\n", d);
	a = sizeof(double);
	printf("%d\n", a);
	printf("%f\n", f);
	return 0;
}


