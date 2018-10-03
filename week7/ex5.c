#include <stdio.h>
int main(){
	char **s;
	char foo[] = "Hello World";
	// OK. We need to assign pointer to string,
	// print the line, re-assign
	// and print first symbol via pointer. 
	
	// Let's declare a "buffer" or inter-pointer
	char *ss = &foo;
	s = &ss;
	printf("s is %s\n", s);
	// Good, it works.
	
	s[0] = foo;
	printf("s[0] is %s\n", s[0]);
	// Well, I don't know the expectations, but this code does not crash
	return 0;
}

// Crash source lines: #5, #7, #8
// *s = foo; --> added inter-pointer 'ss'
// s[0] = foo; --> ss = foo; s[0] = &ss;
// printf("s[0] is %s\n", s[0]); --> it stays
