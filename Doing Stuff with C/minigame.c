#include <stdio.h>

void setName(char userName[16]){
	FILE* usernameFile = fopen("user.name", "w");
	fprintf(usernameFile, "%s", userName);
	fclose(usernameFile);
}

void getName(char* userName[16]) {
	FILE* usernameFile = fopen("user.name", "r");
	fscanf(usernameFile, "%s", userName);
	fclose(usernameFile);
}

int main() {	
	char answer[0];
	char name[16];
	int guess = 0;
	getName(&name);
	// Game Start
	printf("Welcome, Adventurer!\n");
	printf("I am a fortune teller. Allow me to read you.\n");
	while(guess == 0) {
		printf("Is your name.... %s?\n",name);
		printf("(Type 'y' or 'n' to answer):");
		scanf("%s", &answer[0]);
		printf("Your answer was %s\n",answer);
		if(answer[0] == 'y') {
			printf("Haha! I knew it! Welcome, %s!\n", name);
			printf("Well then... let us commence our journey!\n");
			guess = 1;
		} else if (answer[0] == 'n') {
			printf("No? Hmmm... well, no matter. \nWhat is your name?");
			scanf("%s", &name);
			setName(name);
			printf("Got it. Thanks, %s!\n", name);
			guess = 1;
		} else {
			printf("Hmmm. It seems you may have an issue following basic commands.\n");
			printf("No matter! Let's try this again.\n");
			guess = 0;
		}
	}
	printf("~~~~~~\n");
	printf("~~~~~~\n");
	printf("~~~~~~\n");
	printf("HERO'S QUEST\n");
	printf("Written by Min\n");
	printf("All Rights Reserved\n");

	return 0;
}