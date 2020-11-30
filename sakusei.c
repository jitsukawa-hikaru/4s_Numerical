#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	FILE *rf;
	double sum, a, kakuritu[27];
	int i = 0, n;

	srand(time(NULL));
	rf = fopen("result.txt", "r");
	while (! feof(rf)){
		fscanf(rf, "%lf\n", &kakuritu[i]);
		i++;
	}
	for(i =0; i < 27; i++) printf("%lf\n", kakuritu[i]);

	for(i = 0; i < 100; i++){
		a = (rand() % 1000000+1);
		a /= 1000000;
//		printf("%lf\n", a);
		for(sum = n = 0; sum < 1; n++){
			sum += kakuritu[n];
			if(a < sum){
				printf("%c", n+65);
				break;
			}
		}
	}
	printf("\n");
	return 0;
}
