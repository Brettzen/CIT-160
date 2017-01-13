#include <stdio.h>

int multiply(int firstNum, int secondNum){
	return firstNum * secondNum;
}

int main(){
	int firstInt;
	int secondInt;
	printf("Enter an integer: ");
	scanf("%d",&firstInt);
	printf("Enter a second integer: ");
	scanf("%d",&secondInt);
	int product = multiply(firstInt, secondInt);
	printf("%d * %d is... \n",firstInt,secondInt);
	printf("...\n");
	printf("...\n");
	printf("...\n");
	printf("%d!\n",product);
	printf("You done did good, A-A-Ron!");
	return 0;
}