#include <stdio.h>
#include <stdlib.h>

int main(){
	FILE *fp;
	int i, c, count[28];
	for(i = 0; i < 28; i++) count[i] = 0;
	fp = fopen("Conversion_result.txt", "r");
	
	while((c = fgetc(fp)) != EOF){
		if('A' <= c && c <= 'Z') count[c-'A']++;
		else if(c == 0x20) count[26]++;
		else if(c == 0x0A) count[27]++;
	}
	for(i = 0; i < 26; i++) printf("%c  : %d\n", i+65, count[i]);
	printf("SPC: %d\n", count[26]);
	printf("LF : %d\n", count[27]);
	return 0;
}
