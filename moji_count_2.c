#include <stdio.h>
#include <stdlib.h>

int main(){
	FILE *fp, *wf;
	int i, c;
	double count[28], total = .0;
	for(i = 0; i < 28; i++) count[i] = .0;
	fp = fopen("Conversion_result.txt", "r");
	wf = fopen("result.txt", "w");

	while((c = fgetc(fp)) != EOF){
		if('A' <= c && c <= 'Z') count[c-'A']++;
		else if(c == 0x20) count[26]++;
		else if(c == 0x0A) count[27]++;
		if(c != 0x0A)total++;
	}
	printf("%g\n", total);
	for(i = 0; i < 26; i++) printf("%c  : %g : %lf\n", i+65, count[i], count[i]/total);
	for(i = 0; i < 27; i++) fprintf(wf, " %lf\n", count[i]/total);
	printf("SPC: %g\n", count[26]);
	printf("LF : %g\n", count[27]);
	return 0;
}
