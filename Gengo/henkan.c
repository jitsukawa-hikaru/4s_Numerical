#include <stdio.h>

void Conversion(){
	FILE *rf, *wf;
	int a;

	if((rf = fopen("intext.txt", "r")) != NULL){
		wf = fopen("outtext.txt", "w");
		while((a = fgetc(rf)) != EOF){
			if('A' <= a && a <= 'Z') a = a;
			else if('a' <= a && a <= 'z') a = a - 0x20;
			else if(a == 0x0A) a = a;
			else a = 0x20;
			fputc(a, wf);
		}
		fclose(rf);
		fclose(wf);
	}else{
		printf("File open error!\n");
	}
}

int main(){
	Conversion();
	return 0;
}

