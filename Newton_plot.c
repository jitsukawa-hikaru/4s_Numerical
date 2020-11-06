#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define eps (1.0e-11)
#define f(x) (x*x*2-8)
#define df(x) (x*4)

int main(){
	FILE *gp;
	double xn, xo;

	gp = popen("gnuplot -persist", "w");
	fprintf(gp, "set yrange [-100: 1000]\n");
	fprintf(gp, "set xrange [-10: 60]\n");
	fprintf(gp, "plot x*x*2-8, 0\n");
	xn = (xo = 20) + 1;
	while(fabs(xn - xo) > eps){
		xo = xn;
		xn = xo - f(xo)/df(xo);
		fprintf(gp, "replot (%lf*4)*(x-%lf) + (%lf*%lf*2-8)\n", xn, xn, xn, xn);
	}
	pclose(gp);
	printf("%.10lf\n", xn);
	return 0;
}
