#include <stdio.h>
#include <windows.h>

void setName(char userName[16]){
	FILE* usernameFile = fopen("user.name", "w");
	fprintf(usernameFile, "%s", userName);
	fclose(usernameFile);
}

void getName(char* userName) {
	FILE* usernameFile = fopen("user.name", "r");
	fscanf(usernameFile, "%s", userName);
	fclose(usernameFile);
}

int main() {	
	char answer[0];
	char name[16];
	int guess = 0;
	getName(name);
	// Game Start
	printf("Welcome, Adventurer!\n");
	Sleep(800);
	printf("I am a fortune teller. Allow me to read you.\n");
	while(guess == 0) {
		printf("Is your name.... %s?\n",name);
		printf("(Type 'y' or 'n' to answer):");
		scanf("%s", &answer[0]);
		printf("Your answer was %s\n",answer);
		Sleep(800);
		if(answer[0] == 'y') {
			printf("Haha! I knew it! Welcome, %s!\n", name);
			Sleep(800);
			printf("Well then... let us commence our journey!\n");
			Sleep(800);
			guess = 1;
		} else if (answer[0] == 'n') {
			printf("No? Hmmm... well, no matter. \nWhat is your name?");
			scanf("%s", &name);
			setName(name);
			printf("Got it. Thanks, %s!\n", name);
			Sleep(800);
			guess = 1;
		} else {
			printf("Hmmm. It seems you may have an issue following basic commands.\n");
			Sleep(800);
			printf("No matter! Let's try this again.\n");
			Sleep(800);
			guess = 0;
		}
	}
	printf("~~~~~~\n");
	Sleep(800);
	printf("~~~~~~\n");
	Sleep(800);
	printf("~~~~~~\n");
	Sleep(800);
	printf("HERO'S QUEST\n");
	Sleep(800);
	printf("Written by Min\n");
	Sleep(800);
	printf("All Rights Reserved\n");
	Sleep(800);

	return 0;
}