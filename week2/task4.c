#include <stdio.h>

int main(void){
	int x, y;
	char str[3];
	printf("Enter 2 digits <digit1, space, digit2>");
	gets(str);
	sscanf(str, "%d%d", &x, &y);
	
	int *c = &x, *d = &y;
	printf("%d\n", *c);
	printf("%d\n", *d);
	// swap
	int *tmp = c;
	c = d;
	d = tmp;
	// show
	printf("%d\n", *c);
	printf("%d\n", *d);
	return 0;
}
