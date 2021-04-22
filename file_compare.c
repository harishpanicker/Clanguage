#include<stdio.h>

int main(int argc,char**argv){

	FILE *fp1,*fp2;
	char ch1,ch2;

	if(argc!=3){
		printf("Usage:\na.out filename1 filename2\n");
		return 0;
	}


	fp1=fopen(argv[1],"r");
	fp2=fopen(argv[2],"r");

	if(fp1==0||fp2==0){
		printf("failed to open the file\n");
		return 0;
	}


	do
	{
		ch1 = fgetc(fp1);
		ch2 = fgetc(fp2);


		if (ch1 != ch2){
			printf("Both the file contents are not same..\n");
			break;
		}

	} while (ch1 != EOF && ch2 != EOF);


	if(ch1==ch2){
		printf("Both the file contents are same..\n");
	}

	fclose(fp1);
	fclose(fp2);

	return 0;

}
