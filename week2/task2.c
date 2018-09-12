#include <stdio.h>
#include <string.h>

int main(void){
	char str[64];
	printf("Enter: ");
	gets(str);
	int a = strlen(str);
	printf("Result: %s", str);
	return 0;
}
