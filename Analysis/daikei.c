#include <stdio.h>
#include <math.h>
#define N 100
double f(double x){
	return x*x + 2*x - 1;
}

int main(){
	double x, y, sum, a = 0, b = 4, n;
	sum = 0;
	n = (b - a) / N;
	for( x = a+n; x < b; x += n) sum = sum +f(x);
	printf("%lf\n", n / 2.*(f(a) + f(b) + 2.*sum));
	return 0;
}
