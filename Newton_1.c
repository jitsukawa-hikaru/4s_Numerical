#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define eps (1.0e-11) //誤差
#define f(x) (x*x*2-8) //解を求めたい式
#define df(x) (x*4) //f(x)の微分

int main(){
	FILE *f;
	int max = 100, i = 0;
	double x, xt;

	f = fopen("graph.txt", "w"); //求める過程をファイルに書き込む
	x = (xt = 1) + 1; //初期値設定
	while(fabs(xt - x) > eps && i < max){
		x = xt;
		xt = -1 *f(x) / df(x) +x;
		i++;
		printf("[round:%2d], x = %.10lf\n", i, x);
		fprintf(f, "%.10lf %.10lf\n", x, f(x));
	}
	if(i == max) printf("Not found answer.\n");
	else printf("%.10lf\n%.10lf\n", x, f(x));
	return 0;
}
