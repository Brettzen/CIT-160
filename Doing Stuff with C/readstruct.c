#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>

struct armorRequestFile{
	char name[16];
	int powerLevel;
	double size;
};

int findSuccess = 0;

void readRequest(char* aName){
	char line[1024];
	struct armorRequestFile newRequest;
	int nextLine = 0;
	FILE* openRequest = fopen("armor.request", "r");
	while(fgets(line, sizeof(line), openRequest) != NULL) {
		if(strcasestr(line, aName) != NULL) {
			printf("Ah, here it is! %s, right?\n", aName);
			printf("Here's your info:\n");
			printf("%s", line);
			fgets(line, sizeof(line), openRequest);
			printf("%s", line);
			fgets(line, sizeof(line), openRequest);
			printf("%s", line);
			findSuccess = 1;
			break;
		} else {
			printf("...\n");
		}
	} 
	if(findSuccess == 0) {
		printf("Nope, not here!");
	}
	fclose(openRequest);
}

int main(){
	char name[16];
	printf("Name? ");
	scanf("%s", name);
	printf("Great, hold on...\n");
	readRequest(name);

	return 0;
}