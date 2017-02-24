#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>

struct getStudentFile {
	char firstName[16],
		 lastName[16],
		 id[16],
		 username[16],
		 password[16],
		 beltRank[16];
	int  pushups,
		 situps,
		 pullups,
		 squats,
		 rKicks,
		 lKicks;
	double stretch;
};

//openStudentFile global variables
int userFound = 0;
char usernameLine[1024],
	 passwordLine[1024],
	 nameLine[1024],
	 idLine[1024],
	 beltLine[1024],
	 pushupsLine[1024],
	 situpsLine[1024],
	 pullupsLine[1024],
	 squatsLine[1024],
	 stretchLine[1024],
	 rKicksLine[1024],
	 lKicksLine[1024];
//openCurriculum global variables
int beltFound = 0;
char belt[1024],
	 whiteStripe[1024],
	 yellowStripe[1024],
	 orangeStripe[1024],
	 greenStripe[1024],
	 blueStripe[1024],
	 brownStripe[1024],
	 redStripe[1024],
	 blackStripe[1024];

void studentChoice(){
	int choice;
	int num = 0;
	while(num < 4) {
		printf("\n\n--------------------------------\n");
		printf("MAIN MENU\n");
		printf("--------------------------------\n");
		printf("Please choose a number from the following options: \n");
		printf("1. View Physical Stats\n");
		printf("2. View Belt Curriculum\n");
		printf("3. Update Physical Stats\n");
	 	printf("0. Exit\n");
	 	scanf("%d", &choice);
	 	if(choice == 1){
	 		int newChoice;
	 		int goBack = 0;
	 		printf("\n\n--------------------------------\n");
	 		printf("Physical Stats\n");
	 		printf("--------------------------------\n");
	 		printf("Please choose a number from the following options: \n");
	 		printf("1. View Pushups\n");
			printf("2. View Sit-ups\n");
			printf("3. View Pullups\n");
 			printf("4. View Squats\n");
 			printf("5. View Left Kicks\n");
 			printf("6. View Right Kicks\n");
 			printf("7. View Sit and Reach Test Results\n");
 			printf("8. View All Physical Statistics\n");
 			printf("0. Previous Menu\n");
 			scanf("%d", &newChoice);
 			while(goBack == 0) {
	 			switch(newChoice){
	 				case 1:
	 					printf("This is the current recorded amount of pushups you could perform in a single set.\n");
	 					printf("%s\n", pushupsLine);
	 					printf("\nMake another choice from the options above.\n\n");
	 					scanf("%d", &newChoice);
	 					break;
	 				case 2:
	 					printf("This is the current recorded amount of sit-ups you could perform in a single set.\n");
	 					printf("%s\n", situpsLine);
	 					printf("\nMake another choice from the options above.\n\n");
	 					scanf("%d", &newChoice);
	 					break;
	 				case 3:
	 					printf("This is the current recorded amount of pullups you could perform in a single set.\n");
	 					printf("%s\n", pullupsLine);
	 					printf("\nMake another choice from the options above.\n\n");
	 					scanf("%d", &newChoice);
	 					break;
	 				case 4:
	 					printf("This is the current recorded amount of bodyweight squats you could perform in a single set.\n");
	 					printf("%s\n", squatsLine);
	 					printf("\nMake another choice from the options above.\n\n");
	 					scanf("%d", &newChoice);
	 					break;
	 				case 5:
	 					printf("This is the current recorded amount of roundhouse kicks you could perform on your left leg in 60 seconds.\n");
	 					printf("Please note that only roundhouse kicks with proper form and technique were counted.\n");
	 					printf("%s\n", lKicksLine);
	 					printf("\nMake another choice from the options above.\n\n");
	 					scanf("%d", &newChoice);
	 					break;
	 				case 6:
	 					printf("This is the current recorded amount of roundhouse kicks you could perform on your right leg in 60 seconds.\n");
	 					printf("Please note that only roundhouse kicks with proper form and technique were counted.\n");
	 					printf("%s\n", rKicksLine);
	 					printf("\nMake another choice from the options above.\n\n");
	 					scanf("%d", &newChoice);
	 					break;
	 				case 7:
	 					printf("This is the current recorded number of inches you could reach while performing the Sit-and-Stretch Test.\n");
	 					printf("%s\n", stretchLine);
	 					printf("\nMake another choice from the options above.\n\n");
	 					scanf("%d", &newChoice);
	 					break;
	 				case 8:
	 					printf("\nHere are your results from your last physical fitness test:\n\n%s\n\n%s\n\n%s\n\n%s\n\n%s\n\n%s\n\n%s\n\n", pushupsLine, situpsLine, pullupsLine, squatsLine, lKicksLine, rKicksLine, stretchLine);
	 					printf("\nMake another choice from the options above.\n\n");
	 					scanf("%d", &newChoice);
	 					break;
	 				case 0:
	 					goBack = 1;
	 					break;
	 				default:
	 					printf("That's not a valid choice. Please try again.\n\n");
	 					scanf("%d", &newChoice);
	 					break;
 				} 		
 			}
	 	} else if(choice == 2) {
	 		if(beltFound == 0) {
	 			printf("\nThis option is disabled.\n\n");
	 		} else {
	 			int newChoice;
		 		int goBack = 0;
		 		printf("\n\n--------------------------------\n");
		 		printf("Belt Curriculum\n");
		 		printf("--------------------------------\n");
		 		printf("Please choose a number from the following options: \n");
		 		printf("1. View Vocabulary/Weapons Techniques\n");
				printf("2. View Physical Fitness Requirements\n");
				printf("3. View Close Quarters Combat Techniques\n");
	 			printf("4. View Self-Defense Techniques\n");
	 			printf("5. View Sparring Techniques\n");
	 			printf("6. View Board Breaking Techniques\n");
	 			printf("7. View Kicking Techniques\n");
	 			printf("8. View Form\n");
	 			printf("9. View All Curriculum for Current Belt Level\n");
	 			printf("0. Previous Menu\n");
	 			scanf("%d", &newChoice);
	 			while(goBack == 0) {
		 			switch(newChoice){
		 				case 1:
		 					printf("This is what you will need to pass off to earn your white stripe.\n");
		 					printf("%s\n", whiteStripe);
		 					printf("\nMake another choice from the options above.\n\n");
		 					scanf("%d", &newChoice);
		 					break;
		 				case 2:
		 					printf("These are what you will be tested on to earn your yellow stripe.\n");
		 					printf("%s\n", yellowStripe);
		 					printf("\nMake another choice from the options above.\n\n");
		 					scanf("%d", &newChoice);
		 					break;
		 				case 3:
		 					printf("You will need to show proficiency in these techniques to earn your orange stripe.\n");
		 					printf("%s\n", orangeStripe);
		 					printf("\nMake another choice from the options above.\n\n");
		 					scanf("%d", &newChoice);
		 					break;
		 				case 4:
		 					printf("You will need to show proficiency in these techniques to earn your green stripe.\n");
		 					printf("%s\n", greenStripe);
		 					printf("\nMake another choice from the options above.\n\n");
		 					scanf("%d", &newChoice);
		 					break;
		 				case 5:
		 					printf("You will need to show proficiency in these techniques to earn your blue stripe.\n");
		 					printf("Please note that you will need to demonstrate this both inside and outside of sparring matches.\n");
		 					printf("%s\n", blueStripe);
		 					printf("\nMake another choice from the options above.\n\n");
		 					scanf("%d", &newChoice);
		 					break;
		 				case 6:
		 					printf("You will need to successfully break boards using these techniques as well as learn the Korean terminology for each technique to earn your brown stripe.\n");
		 					printf("%s\n", brownStripe);
		 					printf("\nMake another choice from the options above.\n\n");
		 					scanf("%d", &newChoice);
		 					break;
		 				case 7:
		 					printf("You will need to show proficiency in these techniques to earn your red stripe.\n");
		 					printf("%s\n", redStripe);
		 					printf("\nMake another choice from the options above.\n\n");
		 					scanf("%d", &newChoice);
		 					break;
		 				case 8:
		 					printf("You will need to perform this form with good technique and proper focus to earn your black stripe.\n");
		 					printf("%s\n", blackStripe);
		 					printf("\nMake another choice from the options above.\n\n");
		 					scanf("%d", &newChoice);
		 					break;
		 				case 9:
		 					printf("\nListed below is your entire curriculum to test for your next belt rank:\n\n%s\n\n%s\n\n%s\n\n%s\n\n%s\n\n%s\n\n%s\n\n%s\n\n", whiteStripe, yellowStripe, orangeStripe, greenStripe, blueStripe, brownStripe, redStripe, blackStripe);
		 					printf("\nMake another choice from the options above.\n\n");
		 					scanf("%d", &newChoice);
		 					break;
		 				case 0:
		 					goBack = 1;
		 					break;
		 				default:
		 					printf("That's not a valid choice. Please try again.\n");
		 					scanf("%d", &newChoice);
		 					break;
	 				} 		
	 			}
	 		}
	 	} else if(choice == 3){
	 		printf("\nThis option is not yet available. Please choose another number.\n");
	 	} else if(choice == 0){
	 		printf("\nYou have succesfully logged out.\n");
	 		break;
	 	} else {
	 		printf("\nThat was not an acceptable choice. Please try again.\n");
	 		num++;
	 	}
	 }
	 if(num > 3) {
	 	printf("User logged out due to too many incorrect choices.\n");		
	 }
}

void openCurriculum(char* beltRank) {
	FILE* curriculum = fopen("belt.curriculum", "r");
	while(fgets(belt, sizeof(belt), curriculum) != NULL){
		// printf("%s\n", belt);
		if(strcasestr(belt, beltRank) != NULL) {
			// printf("belt found.\n");
			// printf("%s\n", belt);
			// printf("%s\n", beltRank);
			belt[strlen(belt)-1] = 0;
			fgets(whiteStripe, sizeof(whiteStripe), curriculum);
			whiteStripe[strlen(whiteStripe)-1] = 0;
			fgets(yellowStripe, sizeof(yellowStripe), curriculum);
			yellowStripe[strlen(yellowStripe)-1] = 0;
			fgets(orangeStripe, sizeof(orangeStripe), curriculum);
			orangeStripe[strlen(orangeStripe)-1] = 0;
			fgets(greenStripe, sizeof(greenStripe), curriculum);
			greenStripe[strlen(greenStripe)-1] = 0;
			fgets(blueStripe, sizeof(blueStripe), curriculum);
			blueStripe[strlen(blueStripe)-1] = 0;
			fgets(brownStripe, sizeof(brownStripe), curriculum);
			brownStripe[strlen(brownStripe)-1] = 0;
			fgets(redStripe, sizeof(redStripe), curriculum);
			redStripe[strlen(redStripe)-1] = 0;
			fgets(blackStripe, sizeof(blackStripe), curriculum);
			blackStripe[strlen(blackStripe)-1] = 0;
			// printf("%s\n", whiteStripe);
			// printf("%s\n", yellowStripe);
			// printf("%s\n", orangeStripe);
			// printf("%s\n", greenStripe);
			// printf("%s\n", blueStripe);
			// printf("%s\n", brownStripe);
			// printf("%s\n", redStripe);
			// printf("%s\n", blackStripe);
			beltFound = 1;
			break;
			
		}
	}
	if(beltFound == 0) {
		printf("\n\nNo curriculum was found for your belt. View Curriculum will be disabled.\n");
	}
	studentChoice();
	fclose(curriculum);
}

void openStudentFile(char* username, char* password){
	struct getStudentFile student;
	FILE* getStudent = fopen("student.database", "r");
	while(fgets(usernameLine, sizeof(usernameLine), getStudent) != NULL){
		// printf("%s", line);
		if(strcasestr(usernameLine, username) != NULL){
			// strcopy(usernameLine, line, sizeof(line));
			fgets(passwordLine, sizeof(passwordLine),getStudent);
			if(strstr(passwordLine,password) != NULL) {
				printf("You have successfully logged in.\n");
				
				// printf("%s", usernameLine);
				// printf("%s", passwordLine);
				fgets(nameLine, sizeof(nameLine), getStudent);
				nameLine[strlen(nameLine)-1] = 0;
				// printf("%s", nameLine);
				fgets(idLine, sizeof(idLine), getStudent);
				idLine[strlen(idLine)-1] = 0;
				// printf("%s", idLine);
				fgets(beltLine, sizeof(beltLine), getStudent);
				beltLine[strlen(beltLine)-1] = 0;
				// printf("%s", beltLine);
				fgets(pushupsLine, sizeof(pushupsLine), getStudent);
				fgets(pushupsLine, sizeof(pushupsLine), getStudent);
				pushupsLine[strlen(pushupsLine)-1] = 0;
				// printf("%s", pushupsLine);
				fgets(situpsLine, sizeof(situpsLine), getStudent);
				situpsLine[strlen(situpsLine)-1] = 0;
				// printf("%s", situpsLine);
				fgets(pullupsLine, sizeof(pullupsLine), getStudent);
				pullupsLine[strlen(pullupsLine)-1] = 0;
				// printf("%s", pullupsLine);
				fgets(squatsLine, sizeof(squatsLine), getStudent);
				squatsLine[strlen(squatsLine)-1] = 0;
				// printf("%s", stretchLine);
				fgets(stretchLine, sizeof(stretchLine), getStudent);
				stretchLine[strlen(stretchLine)-1] = 0;
				// printf("%s", squatsLine);
				fgets(rKicksLine, sizeof(rKicksLine), getStudent);
				rKicksLine[strlen(rKicksLine)-1] = 0;
				// printf("%s", rKicksLine);
				fgets(lKicksLine, sizeof(lKicksLine), getStudent);
				lKicksLine[strlen(lKicksLine)-1] = 0;
				// printf("%s", lKicksLine);
				
				openCurriculum(beltLine);
				userFound = 1;
				break;
			}
			// if(strstr(line, password) != NULL){
			// 	printf("Success. Printing Student information.\n");
			// 	userFound = 1;
			// 	break;
			// }
			
		} 
	}
	if(userFound == 0) {
		printf("Username or Password incorrect. Please try again.\n");
	}
	fclose(getStudent);
	
}

void getCurriculum(){
	FILE* getBelt = fopen("belt.curriculum", "r");
	fclose(getBelt);
}

int main(){
	char username1[16],
		 password1[16];
	printf("Student Login\n");
	printf("Username: ");
	scanf("%s", username1);
	printf("Password: ");
	scanf("%s", password1);
	printf("%s %s\n", username1, password1);
	openStudentFile(username1, password1);
	return 0;
}