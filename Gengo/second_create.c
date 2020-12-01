#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void Create(){
	FILE *rf;
	double sum = .0, a, kakuritu[27][27];
	int i, n, o, frg = 0;

	srand(time(NULL));
	rf = fopen("probability2.txt", "r");
	for(i = 0; i < 27; i++){
		for(n = 0; n < 27; n++){
			fscanf(rf, "%lf\n", &kakuritu[i][n]);
		}
	}
	for(i = 0; i < 50; i++){
		a = (rand() % 995134 + 1);
		a /= 1000000;
		for(sum = n = 0; n < 27; n++){
			for(o = 0; o < 27; o++){
				sum += kakuritu[n][o];
				if(a < sum){
					if(n == 26){
						if(o == 26){
							printf("%c%c", 0X20, 0X20);
							frg = 1;
							break;
						}else{
							printf("%c%c", 0X20, o+65);
							frg = 1;
							break;
						}
					}else if(o == 26){
						printf("%c%c", n+65, 0X20);
						frg = 1;
						break;
					}else{
						printf("%c%c", n+65, o+65);
						frg = 1;
						break;
					}
				}
			}
			if(frg == 1){
				frg = 0;
				break;
			}
		}
	}
	printf("\n");
}

int main(){
	Create();
	return 0;
}
