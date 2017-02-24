#include <stdio.h>
#include "multipleFiles.c"

int main(){
	char input[16];
	printf("What's your name? ");
	scanf("%s", input);
	howdy(input);
	return 0;
}