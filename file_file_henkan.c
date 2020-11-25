#include <stdio.h>

void Conversion(){
	FILE *lf, *sf;
	int a, i = 0;

	if((lf = fopen("test.txt", "r")) != NULL){
		sf = fopen("Conversion_result.txt", "w");
		while((a = fgetc(lf)) != EOF){
			if(a > 0x40 && a < 0x5B) a = a;
			else if(a > 0x60 && a < 0x7B) a = a - 0x20;
			else if(a == 0x20 || a == 0x0A) a = a;
			else a = 0x7F;
			fputc(a, sf);
		}
		fclose(lf);
		fclose(sf);
	}else{
		printf("File open error!\n");
	}
}

int main(){
	Conversion();
	return 0;
}
