#include<stdio.h>

int main(int argc,char**argv){

	FILE *fs,*fd;
	char ch;

	if(argc!=3){
		printf("Usage:\na.out filename1 filename2\n");
		return 0;
	}


	fs=fopen(argv[1],"r");
	fd=fopen(argv[2],"w");

	if(fs==0 || fd==0){
		printf("failed to open the file\n");
		return 0;
	}

	while((ch=fgetc(fs))!=EOF){
		fputc(ch,fd);
	}

	fclose(fs);
	fclose(fd);

	return 0;

}
