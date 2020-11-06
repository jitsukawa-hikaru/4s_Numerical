#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define eps (1.0e-11)
#define f(x) (log(x)-1)
#define df(x) (1/x)

int main(){
	FILE *gp;
	double xn, xo;

	gp = popen("gnuplot -persist", "w");
	fprintf(gp, "set yrange [-2: 2]\n");
	fprintf(gp, "set xrange [0.5: 5]\n");
	fprintf(gp, "plot log(x)-1, 0\n");
	xn = (xo = 0) + 1;
	while(fabs(xn - xo) > eps){
		xo = xn;
		xn = xo - f(xo)/df(xo);
		fprintf(gp, "replot (1/%lf)*(x-%lf) + (log(%lf)-1)\n", xn, xn, xn);
	}
	pclose(gp);
	printf("%.10lf\n", xn);
	return 0;
}
