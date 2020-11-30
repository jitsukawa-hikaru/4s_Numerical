#include <stdio.h>
#include <math.h>
#define N 100.

double f( double x){
	return x*x + 2*x -1;
}

int main (){
	double x, y, value, a = 0, b = 4, delta;
	int i = 1;

	value = f(a) + f(b);
	delta = (b - a) / N;
	for( x = a+delta; x < b; x += delta){
		if(i%2 == 0){
			value = value + 2.*f(x);
		}else{
			value = value + 4.*f(x);
		}
		i++;
	}
	printf("%lf\n", delta / 3.*value);
	return 0;
}
