#include <stdio.h>

struct newStudent {
	char firstName[16],
		 lastName[16],
		 username[16],
		 password[16],
		 beltRank[16],
		 id[16];
	int pushups,
		situps,
		pullups,
		squats,
		rKicks,
		lKicks;
	double stretch;
	// char whiteStripe[1024],
	// 	 yellowStripe[1024],
	// 	 orangeStrispe[1024],
	// 	 greenStripe[1024],
	// 	 blueStripe[1024],
	// 	 brownStripe[1024],
	// 	 redStripe[1024],
	// 	 blackStripe[1024];
};
// struct newStudent2 {
// 	char firstName[16],
// 		 lastName[16],
// 		 username[16],
// 		 password[16],
// 		 beltRank[16],
// 		 id[16];
// 	int pushups,
// 		situps,
// 		pullups,
// 		squats,
// 		rKicks,
// 		lKicks;
// 	// char whiteStripe[1024],
// 	// 	 yellowStripe[1024],
// 	// 	 orangeStrispe[1024],
// 	// 	 greenStripe[1024],
// 	// 	 blueStripe[1024],
// 	// 	 brownStripe[1024],
// 	// 	 redStripe[1024],
// 	// 	 blackStripe[1024];
// };

void saveStudent(char firstName[16],char lastName[16],char username[16],char password[16],char beltRank[16],char id[16],int pushups,int situps,int pullups,int squats,double stretch,int rKicks,int lKicks){

	FILE* newSave = fopen("student.database", "a");
	fprintf(newSave, "--------STUDENT INFO--------\nUsername: %s\nPassword: %s\nName: %s %s\nStudent ID: %s\nBelt Rank: %s\n---CURRENT STATS---\nPushups: %d\nSit-Ups: %d\nPullups: %d\nSquats: %d\nStretch Length (Sit and Reach): %lf\nRoundhouse Kicks (Right): %d\nRoundhouse Kicks (Left): %d\n", username, password, firstName, lastName, id, beltRank, pushups, situps, pullups, squats, stretch, rKicks, lKicks);
	fclose(newSave);

}
// void saveStudent2(char firstName[16],char lastName[16],char username[16],char password[16],char beltRank[16],char id[16],int pushups,int situps,int pullups,int squats,int rKicks,int lKicks){

// 	FILE* newSave = fopen("student.database", "a");
// 	fprintf(newSave, "--------STUDENT INFO--------\nName: %s %s\nStudent ID: %s\nUsername: %s\nPassword: %s\nBelt Rank: %s\n---CURRENT STATS---\nPushups: %d\nSit-Ups: %d\nPullups: %d\nSquats: %d\nRoundhouse Kicks (Right): %d\nRoundhouse Kicks (Left): %d\n", firstName, lastName, id, username, password, beltRank, pushups, situps, pullups, squats, rKicks, lKicks);
// 	fclose(newSave);

// }

int saved = 0;

int main(){


	char answer[0];
	char answer2[0];

	while(saved == 0){
		// struct newStudent student;
		struct newStudent student;
		printf("Enter Student Information. All info will be saved to student.db after the last prompt.\n");
		printf("If you make a mistake, press Ctrl(Cmd)+C to quit and restart.\n");
		printf("Please enter student's general information.\n");
		printf("Student First Name: ");
		scanf("%s", student.firstName);
		printf("Student Last Name: ");
		scanf("%s", student.lastName);
		printf("Student ID: ");
		scanf("%s", student.id);
		printf("Student Username: ");
		scanf("%s", student.username);
		printf("Student Password: ");
		scanf("%s", student.password);
		printf("Student Belt Rank: ");
		scanf("%s", student.beltRank);
		printf("Please enter student's current fitness stats.\n");
		printf("How many pushups can the student currently do in one set? ");
		scanf("%d", &student.pushups);
		printf("How many sit-ups can the student currently do in one set? ");
		scanf("%d", &student.situps);
		printf("How many pullups can the student currently do in one set? ");
		scanf("%d", &student.pullups);
		printf("How many squats can the student currently do in one set? ");
		scanf("%d", &student.squats);
		printf("How many inches foward can the student reach when sitting on the floor with legs stretched out in front of them? ");
		scanf("%lf", &student.stretch);
		printf("How many rapid-fire roundhouse kicks can the student currently do in one set on their right leg? ");
		scanf("%d", &student.rKicks);
		printf("How about the left leg? ");
		scanf("%d", &student.lKicks);
		printf("All finished. Save to database?\n");
		printf("Press y to save. Press any other key to start over. ");
		scanf("%s", &answer[0]);
		printf("you answered: %c", answer[0]);
		if(answer[0] == 'y' || answer[0] == 'Y'){
			saveStudent(student.firstName, student.lastName, student.username, student.password, student.beltRank, student.id, student.pushups, student.situps, student.pullups, student.squats, student.stretch, student.rKicks, student.lKicks);
			// saveStudent2(student.firstName, student.lastName, student.username, student.password, student.beltRank, student.id, student.pushups, student.situps, student.pullups, student.squats,student.rKicks, student.lKicks);
			printf("\nStudent saved.\n\n\n");
			printf("Exit Program?\n");
			printf("Press y to exit. Press any other key to enter another student. ");
			scanf("%s", &answer2[0]);
			if(answer2[0] == 'y' || answer2[0] =='Y') {
				saved = 1;
			} else {
				printf("\n\n\n\n\n");
			}
		}
	}

	return 0;
}