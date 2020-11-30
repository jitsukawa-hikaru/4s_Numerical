#include <stdio.h>
#include <math.h>
#define error 0.0000000001 //収束判定定数
#define N 3 //行列の数

int i, j, k;

void initial_value( double x[N] ){ //解の初期値を設定
	for( i = 0; i < N; i++ ) x[i] = 1.0;
}

void Seidel( double x[N], double  y[N], double a[N][N], double b[N]){ //ザイデル法の中の計算
	for( j = 0; j < N; j++ ){
		for( k = 0; k < N; k++ ) y[k] = x[k];
		x[j] = ( (a[j][j] * y[j]) + b[j] );
		for( k = 0; k < N; k++ ) x[j] -= ( a[j][k] * y[k] );
		x[j] /= a[j][j];
	}
}

int Convergence_test( double x[N], double y[N] ){ //収束判定
	for( j = 0; j < N; j++ ){
		if( error < fabs( x[j] - y[j] ))return (1);
	}
	return (0);
}

int main(){ //メイン実行
	double a[N][N] = { { 5.0, 1.0, 1.0 }, { 1.0, 4.0, 1.0 }, { 2.0, 1.0, 3.0 } }; //任意の行列
	double b[N] = { 10.0, 12.0, 13.0 };
	double x[N], y[N];
	int c = 0;

	initial_value( x );

	while( Convergence_test( x, y) ){ //収束判定が偽の間実行する
		Seidel( x, y, a, b );
		c++; //実行回数を数える
	}
	printf("[%3d週目] ", c ); //何週で収束したか表示する
	for( i = 0; i < N; i++) printf(" x%d = %.10f ", i+1, x[i] );
	printf("\n");
	return 0;
}
