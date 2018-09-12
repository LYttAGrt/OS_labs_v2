#include "ex3.h"

void type_prompt(){
	printf("> ");
}
void parse(char *cmd_store){
	scanf("%s", cmd_store);
}
int main(void){
	char cmd[64];
	int cond = 1;
	while(cond){
		type_prompt();
		parse(cmd);
		system(cmd);
	}
	return 0;
}
