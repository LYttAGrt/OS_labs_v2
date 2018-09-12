#include "ex4.h"

void type_prompt(){
	printf("> ");
}
void parse(char *cmd_store){
	gets(cmd_store);
}

void type_stick(){
	printf(" | ");
}

int main(){
	char cmd[64];
	int cond = 1;
	system("man fork");
	system("man execve");
	while(cond){
		type_prompt();
		parse(cmd);
		if(cmd=="exit"){
			cond = 0;
		}
		system(cmd);
	}
	return 0;
}
