#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double f(double x){ //関数の設定
	return x+cos(x);
}

void initial_value(double x[2] ){ //初期値を設定
	while( (f(x[0])>0 || f(x[1])<0) && (f(x[0])<0 || f(x[1])>0) ){
		x[0] += 100;
		x[1] -= 100;
	}
}

void dichotomy(double x[2] ){ //二分法の計算
	double c;
	while(1){
		c = (x[0] + x[1]) / 2;
		if(f(c)*f(x[0]) < 0) x[1] = c;
		else x[0] = c;
		if(fabs(x[0]-x[1])<0.0000000001){
			printf("x = %.10lf\n",c);
			exit(1);
		}
	}
}

int main(){ //メイン文
	double x[2] = { 0, 0};
	initial_value(x);
	dichotomy(x);
	return 0;
}
