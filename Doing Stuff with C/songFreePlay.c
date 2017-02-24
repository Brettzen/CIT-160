#include <windows.h>
#include <stdio.h>
#include <ncurses.h>
#include "noteStruct.c"

// struct noteSheet note;
double note[32];
char c;
// for(int i = 0; i > 33; i++) {
// 	note._[i];

// }

void getNotes() {
	printf("getNotes has begun.\n");
	FILE* getNotes = fopen("note.file", "r");
	for(int i = 0; i < 33; i++) {
		// printf("Attempting to get a note.\n");
		fscanf(getNotes, "%lf", &note[i]);
		// printf("%3.2lf\n", note[i]);
	}
	fclose(getNotes);
}

void freePlay() {
	int play = 1;
	printf("Play your keyboard like a new wave piano!\n");
	while(play == 1) {
		c = getch();
		switch(c) {
			case 'q':
				Beep(note[0], 300);
				break;
			case 'w':
				Beep(note[1], 300);
				break;
			case 'e':
				Beep(note[2], 300);
				break;
			case 'r':
				Beep(note[3], 300);
				break;
			case 't':
				Beep(note[4], 300);
				break;
			case 'y':
				Beep(note[5], 300);
				break;
			case 'u':
				Beep(note[6], 300);
				break;
			case 'i':
				Beep(note[7], 300);
				break;
			case 'o':
				Beep(note[8], 300);
				break;
			case 'p':
				Beep(note[9], 300);
				break;
			case '[':
				Beep(note[10], 300);
				break;
			case ']':
				Beep(note[11], 300);
				break;
			case 'a':
				Beep(note[12], 300);
				break;
			case 's':
				Beep(note[13], 300);
				break;
			case 'd':
				Beep(note[14], 300);
				break;
			case 'f':
				Beep(note[15], 300);
				break;
			case 'g':
				Beep(note[16], 300);
				break;
			case 'h':
				Beep(note[17], 300);
				break;
			case 'j':
				Beep(note[18], 300);
				break;
			case 'k':
				Beep(note[19], 300);
				break;
			case 'l':
				Beep(note[20], 300);
				break;
			case ';':
				Beep(note[21], 300);
				break;
			case '\'':
				Beep(note[22], 300);
				break;
			case 'z':
				Beep(note[23], 300);
				break;
			case 'x':
				Beep(note[24], 300);
				break;
			case 'c':
				Beep(note[25], 300);
				break;
			case 'v':
				Beep(note[26], 300);
				break;
			case 'b':
				Beep(note[27], 300);
				break;
			case 'n':
				Beep(note[28], 300);
				break;
			case 'm':
				Beep(note[29], 300);
				break;
			case ',':
				Beep(note[30], 300);
				break;
			case '.':
				Beep(note[31], 300);
				break;
			case '/':
				Beep(note[32], 300);
				break;
			default:
				printf("not a key.\n");
				play = 0;
				break;
			// case '27':
			// 	printf("Program terminated.");		
		}
	}
}

// Beep();