#include <stdio.h>
#define f(x) (cos(x)+x)

int main(){
	FILE *gp;
	int x = 0;


	gp = popen("gnuplot -persist", "w");
	fprintf(gp, "plot %d\n", x);
	fprintf(gp, "replot cos(x)+x\n");
	//fprintf(gp, "plot f(x)\n");

	pclose(gp);

	return 0;
}

