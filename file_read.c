#include<stdio.h>

int main(int argc,char**argv){

	FILE *fp;
	char ch;

	if(argc!=2){
		printf("Usage:\na.out file name\n");
		return 0;
	}


	fp=fopen(argv[1],"r");

	if(fp==0){
		printf("failed to open the file\n");
		return 0;
	}

	while((ch=fgetc(fp))!=EOF){
	printf("%c",ch);
	}

	fclose(fp);

	return 0;

}
