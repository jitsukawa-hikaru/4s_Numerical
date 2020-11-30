#include <stdio.h>
#include <math.h>
#define error 0.0000000001 //収束判定定数

int i, j, k;

void initial_value( int N, double x[N] ){ //解の初期値を設定
	for( i = 0; i < N; i++ ) x[i] = 1.0;
}

void Seidel( int N, double x[N], double  y[N], double a[N][N], double b[N]){ //ザイデル法の中の計算
	for( j = 0; j < N; j++ ){
		for( k = 0; k < N; k++ ) y[k] = x[k];
		x[j] = ( (a[j][j] * y[j]) + b[j] );
		for( k = 0; k < N; k++ ) x[j] -= ( a[j][k] * y[k] );
		x[j] /= a[j][j];
	}
}

int Convergence_test( int N, double x[N], double y[N] ){ //収束判定
	for( j = 0; j < N; j++ ){
		if( error < fabs( x[j] - y[j] ))return (1);
	}
	return (0);
}

int main(){ //メイン実行
	FILE *fp; //ファイルから読み込み

	fp = fopen("gyo.txt", "r" );
	if( fp == NULL ){
		printf("gyo.txtを準備して下さい\n");
		return -1;
	}
	int N;
	fscanf( fp, "%d", &N );
	double a[N][N]; //係数行列
	double b[N]; //解行列
	for( i = 0; i < N; i++ ){
		for( j = 0; j < N; j++ ){
			fscanf( fp, "%lf", &a[i][j] );
		}
	}
	for( i = 0; i < N; i++ ){
		fscanf( fp, "%lf", &b[i] );
	}
	fclose( fp );
	double x[N], y[N];
	int c = 0;

	initial_value( N, x );
	while( Convergence_test( N, x, y ) ){ //収束判定が偽の間実行する
		Seidel( N, x, y, a, b );
		c++; //実行回数を数える
	}
	printf("[%3d週目] ", c );
	for( i = 0; i < N; i++) printf(" x%d = %.10f ", i+1, x[i] );
	putchar('\n');
	return 0;
}

/*gyo.txtの書き方

3 //行列の数を定義する

5 1 1 //任意の係数行列を順番の通り入力する
1 4 1
2 1 3

10 12 13 //解行列を入力
*/
