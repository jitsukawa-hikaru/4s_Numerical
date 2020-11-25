#include <stdio.h>

int main(){
	FILE *lf, *sf;
	char str[1000];
	int a;
	int i = 0;

	printf("Read file\n-->");
	lf = fopen("test.txt", "r");
	sf = fopen("Conversion_result.txt","w");
	while(fgets(str,1000,lf)){
		printf("%s", str);
	}
	i = 0;
	printf("Conversion result\n-->");
	do{
		if(str[i] > 0x40 && str[i] < 0x5B) a = str[i];
		else if(str[i] > 0x60 && str[i] < 0x7B) a = str[i] - 0x20;
		else if(str[i] == 0x20 || str[i] == 0x0A) a = str[i];
		else a = 0x7F;
		printf("%c", a);
		fputc(a, sf);
	}while(str[i++] != 0x0A);
	return 0;
}
