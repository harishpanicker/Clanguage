#include<stdio.h>

int main(int argc,char**argv){

	FILE *fp;

	if(argc!=3){
		printf("Usage:\na.out file name string\n");
		return 0;
	}


	fp=fopen(argv[1],"w");

	if(fp==0){
		printf("failed to open the file\n");
		return 0;
	}

	while(*argv[2]!='\0'){
		fputc(*argv[2],fp);
		argv[2]++;
	}

	fclose(fp);

	return 0;

}
