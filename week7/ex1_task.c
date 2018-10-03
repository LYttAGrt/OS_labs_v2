#include <stdio.h>

int main(void){
	int param;
	char str[1];
	gets(str);
	sscanf(str, "%d", &param);
	
	char result[(2*param-1)*(2*param-1) + param];
	int count = 0;
	int lvl = param - 1;
	int stars = 1;
	int i;
	for(i=0; i < param; i++){
		int k;
		for(k=0;k<lvl;k++){
			result[count] = ' ';
			count += 1;
		}
		for(k=0;k<stars;k++){
			result[count] = '*';
			count += 1;
		}
		for(k=0;k<lvl;k++){
			result[count] = ' ';
			count += 1;
		}
		stars += 2;
		lvl -= 1;
		result[count] = '\n';
		count += 1;
	}
	printf(result);
	return 0;
}
