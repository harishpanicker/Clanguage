#include<stdio.h>
#define MAX 1024

int main(int argc,char**argv){

	FILE *fp;
	char ch,buf[MAX];
	int count;

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
		count++;
	}
	printf("Number of characters = %d\n",count);
	rewind(fp);
	count=0;
	
	while(fscanf(fp,"%s",buf)!=EOF){
		count++;
	}
	printf("Number of words = %d\n",count);
	rewind(fp);
	count=0;
	
	while(fgets(buf,MAX,fp)){
		count++;
	}
	printf("Number of lines = %d\n",count);
	rewind(fp);


	fclose(fp);

	return 0;

}
