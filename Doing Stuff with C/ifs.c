#include <stdio.h>
#include <ctype.h>

void saveName(char aName[16]) {
	FILE* userNameFile = fopen("user.name","w");
	fprintf(userNameFile, "%s", aName);
	fclose(userNameFile);
}

int main() {
	char name[16];
	printf("What's your name, stranger? ");
	int tryAgain = 0;
	while(tryAgain == 0) {
		scanf("%s", name);
		if(isalpha(name[0])) {
			saveName(name);
			printf("\nGot it. Thanks, %s!",name);
			tryAgain = 1;
		} else {
			printf("Maybe you didn't hear me... I said WHAT'S YOUR NAME, STRANGER?!?!");
		}
	}
	return 0;
}