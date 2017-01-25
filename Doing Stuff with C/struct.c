#include <stdio.h>

struct armorAcquisition {
	char name[16];
	int powerLevel;
	double size;
};

void newRequest(char aName[16], int aPowerLevel, double aSize) {
	FILE* saveRequest = fopen("armor.request","a");
	fprintf(saveRequest, "Armor Request Form\nName: %s\nPower Level: %d\nSize: %lf\n-------------------\n", aName, aPowerLevel, aSize);
	fclose(saveRequest);
}

int main() {
	struct armorAcquisition newAcquisitionRequest;
	printf("Greetings, warrior!! Need some armor, do ya?!\n");
	printf("What's your name?! ");
	scanf("%s", &newAcquisitionRequest.name);
	printf("\nGreat. Glad to meet you. What's your power level?! ");
	scanf("%d", &newAcquisitionRequest.powerLevel);
	printf("\nGood, good. I'm sure your parents are very proud.\n");
	printf("What's your armor size?! ");
	scanf("%lf", &newAcquisitionRequest.size);
	printf("\nLovely. Fabulous. I'll process your request.\n");
	printf("Now GET OUT!!!\n");
	newRequest(newAcquisitionRequest.name, newAcquisitionRequest.powerLevel, newAcquisitionRequest.size);

	return 0;
}