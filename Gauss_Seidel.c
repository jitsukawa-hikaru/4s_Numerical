#include <stdio.h>
#include <math.h>
#define error 0.0000000001

int main(){
	double x[3] = { 1.0, 1.0, 1.0 }, y[3];
	int i= 0;

	while( error < fabs(y[0]-x[0]) && error < fabs(y[1]-x[1]) && error < fabs(y[2]-x[2]) ){
		for( int j = 0; j < 3; j++ )y[j] = x[j];
		x[0] = (10.0 - x[1] - x[2]) / 5.0;
		x[1] = (12.0 - x[0] - x[2]) / 4.0;
		x[2] = (13.0 - 2.0 * x[0] - x[1]) / 3.0;
		i++;

	}
	printf("[%3d週目] x1 = %.10f, x2 = %.10f, x3 = %.10f\n", i, x[0], x[1], x[2] );
	return 0;
}
