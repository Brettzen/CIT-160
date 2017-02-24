#include <windows.h>
#include "songFreeplay.c"

// 1.Create a Tune
// 2.Create Lyrics
// 3.Free Play

// 4.Play old Song

WINDOW *w;

int main() {
	w = initscr();
	printf("beginning\n");
	getNotes();
	freePlay();
	endwin();
	return 0;
}