#include <strings.h>

struct yeah{
	char line1[1024];
	char line2[1024]; 
	char line3[1024]; 
};

void getout(){
	struct yeah y;
	strcopy(y.line1, "Now get outta here, kid, ya bother me.");
	// y.line2 = "What? you're still here?";
	// y.line3 = "BEAT IT!!!";
}