#include <stdio.h>

void readNumbers(int* aNumber, int* anotherNumber) {
	FILE* userNumbersFile = fopen("user.data", "r");
	fscanf(userNumbersFile, "%d %d", aNumber, anotherNumber);
	fclose(userNumbersFile);
}

int main() {
	int firstInt;
	int secondInt;
	readNumbers(&firstInt, &secondInt);
	printf("%d is the first number pulled and %d is the second!\n",firstInt,secondInt);
	printf("the PRODUCT of these numbers is %d!\n",firstInt*secondInt);	
	return 0;
}