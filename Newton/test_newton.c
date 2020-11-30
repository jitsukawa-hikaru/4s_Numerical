#include <stdio.h>
#include <math.h>

#define EPS (1.0e-10)
#define f(x) (x*x*2-8)
#define df(x) (x*4)

int main(){
	double xn, xo;
	xn = (xo = 2) + 1;
	while(fabs(xn - xo) > EPS){
		xo = xn;
		xn = -1 *f(xo) / df(xo) +xo;
	}
	printf("%.10lf\n%.10lf\n", xn, f(xn));
}
