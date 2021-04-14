#include"My_String.h"

int main(){

	char str1[ARRAY_SIZE],str2[ARRAY_SIZE],character;
	int len,idx,Ret,option;

	//string = (char *)malloc(sizeof(char)*100);
	//dest = (char *)malloc(sizeof(char)*100);
	

	while(1)
	{
		printOptions();		
		printf("Enter the option = ");
		scanf("%d",&option);
		switch(option)
		{
			case MYSTRINGLEN:
				printf("Enter the string = ");
				scanf(" %[^\n]s",str1);
				len=MyStrlen(str1);
				printf("String Length = %d\n",len);
				break;
			case MYSTRINGCOPY:
				printf("Enter the string = ");
				scanf(" %[^\n]s",str1);
				MyStrcpy(str2,str1);
				printf("Destination string = %s\n",str2);	
				break;
			case MYSTRINGNCOPY:
				printf("Enter the first string = ");
				scanf(" %[^\n]s",str1);
				printf("Enter the Index from which you need to copy = ");
				scanf("%d",&idx);
				MyStrncpy(str2,str1,idx);
				printf("Destination string = %s\n",str2);	
				break;
			case MYSTRCAT:
				printf("Enter the first string = ");
				scanf(" %[^\n]s",str1);
				printf("Enter the second string = ");
				scanf(" %[^\n]s",str2);
				Mystrcat(str2,str1);
				printf("String after concartination = %s\n",str2);
				break;
			case MYSTRNCAT:
				printf("Enter the first string = ");
				scanf(" %[^\n]s",str1);
				printf("Enter the second string = ");
				scanf(" %[^\n]s",str2);
				printf("Enter the Index from which you need to concat = ");
				scanf("%d",&idx);
				Mystrncat(str2,str1,idx);
				printf("String after concartination = %s\n",str2);
				break;
			case MYSTRCOMPARE:
				printf("Enter the first string = ");
				scanf(" %[^\n]s",str1);
				printf("Enter the second string = ");
				scanf(" %[^\n]s",str1);
				Ret=Mystrcmp(str2,str1);
				if(Ret<0){
					printf("String1 is smaller than string2...\n");
				}
				else if(Ret>0){
					printf("String1 is Greater than string2...\n");
				}
				else{
					printf("Strings are Equal...\n");
				}
				break;
			case MYSTRNCOMPARE:
				printf("Enter the first string = ");
				scanf(" %[^\n]s",str1);
				printf("Enter the second string = ");
				scanf(" %[^\n]s",str2);
				printf("Enter the index from where you need to compare = ");
				scanf("%d",&idx);
				Ret=Mystrncmp(str2,str1,idx);
				if(Ret<0){
					printf("String1 is smaller than string2...\n");
				}
				else if(Ret>0){
					printf("String1 is Greater than string2...\n");
				}
				else{
					printf("Strings are Equal...\n");
				}				
				break;		
			case MYSTRREVERSE:
				printf("Enter the string = ");
				scanf(" %[^\n]s",str1);
				Mystrrev(str1);
				printf("String Reverse = %s\n",str1);
				break;
			case MYSTRINGCHAR:
				printf("Enter the string = ");
				scanf(" %[^\n]s",str1);
				printf("Enter the character you find to find in the string = ");
				scanf(" %c",&character);
				if(MyStrchr(str1,character)!=NULL){
					printf("Character is found !!!\n");
				}
				else{
					printf("Character is not found !!!\n");
				}
				break;
			case MYSTRINGRCHAR:
				printf("Enter the string = ");
				scanf(" %[^\n]s",str1);
				printf("Enter the character you find to find in the string = ");
				scanf(" %c",&character);
				if(MyStrrchr(str1,character)!=NULL){
					printf("Character is found !!!\n");
				}
				else{
					printf("Character is not found !!!\n");
				}
				break;
			case MYSTRCHARACTERCOUNT:
				printf("Enter the string = ");
				scanf(" %[^\n]s",str1);
				MyStrCountNumberOfAlphabetsDigitsSpecialCharacters(str1);
				break;
			case MYSTRVOWEL_CONSTANTS_COUNT:
				printf("Enter the string = ");
				scanf(" %[^\n]s",str1);
				MyStrVowelConsonantsCount(str1);
				break;
			case MYSTRINGWORDS:
				printf("Enter the string = ");
				scanf(" %[^\n]s",str1);
				MyStrWordCount(str1);
				break;
			case MYSTRINGPALINDROME:
				printf("Enter the string = ");
				scanf(" %[^\n]s",str1);
				MystrPalindrome(str1);
				break;
			case MYOCCURANCEOFCHARACTER:
				printf("Enter the string = ");
				scanf(" %[^\n]s",str1);
				printf("Enter the character you find to find in the string = ");
				scanf(" %c",&character);
				MyOccuranceOfCharacter(str1,character);
				break;
			case EXIT:
				exit(0);			
				break;
			default:
				printf("Invalid my string options exit the loop\n");
				break;

		}

	}

	return 0;
}

static void printOptions()
{
	unsigned int numOptions = (sizeof(myStringMenuOptions)/sizeof(*myStringMenuOptions));
	printf("******************************************\n");
	for(int i = 0;i!=numOptions;i++)
	{
		printf("\t%d) %s\n",i,myStringMenuOptions[i]);
	}
	printf("******************************************\n\n");
}


size_t MyStrlen(const char* str){

	int len;

	for(len =0;str[len]!='\0';len++);

	return len; 
}

char* MyStrcpy(char*dest,char*src){

	while(*src!='\0'){
		*dest=*src;
		src++;
		dest++;
	}

	return dest;

}

char* MyStrncpy(char*dest,char*src,int num){

	src=src+num;
	while(*src!='\0'){
		*dest=*src;
		src++;
		dest++;
	}

	return dest;
}

const char* MyStrchr(const char* src,char select){

	while(*src!='\0'){
		if(*src==select)
			return src;
		src++;

	}

	return NULL;

}

const char* MyStrrchr(const char*src,char select){

	int length;
	while(*src!='\0')
	{	src++;
		length++;
	}
	printf("length = %d\n",length);
	src--;
	while(length!=0 && *src!='\0'){

		if(*src==select)
			return src;
		src--;
		length--;
	}

	return NULL;

}

int Mystrcmp(const char* dest,const char* src){

	while(*src!='\0' || *dest!='\0'){
		if(*src!=*dest)
			break;
		src++;
		dest++;
	}
	if(*src==*dest)
		return 0;
	else if(*src>*dest)
		return 1;
	else
		return -1;

}

int Mystrncmp(const char* dest,const char* src,size_t n){

	src=src+n;
	dest=dest+n;

	while(*src!='\0' || *dest!='\0'){
		if(*src!=*dest)
			break;
		src++;
		dest++;
	}
	if(*src==*dest)
		return 0;
	else if(*src>*dest)
		return 1;
	else
		return -1;


}

void Mystrrev(char* src){

	int len,i,j;
	char temp;
	len=MyStrlen(src);

	for(i=len-1,j=0;i>j;i--,j++)
	{
		temp=src[i];
		src[i]=src[j];
		src[j]=temp;
	}

}

char* Mystrcat(char*dest,const char*src){

	if(*src=='\0')
	{
		printf("source is null\n");
		return 0;
	}
	else 
	{
		while(*dest++!='\0');
		dest--;
		while(*src!='\0')
		{
			*dest++ = *src++;
		}
		*dest = '\0';
		return dest;
	}

}

char* Mystrncat(char* dest,const char* src,size_t n){

	src=src+n;
	
	if(*src=='\0')
	{
		printf("source is null\n");
		return 0;
	}
	else 
	{
		while(*dest++!='\0');
		dest--;
		while(*src!='\0')
		{
			*dest++ = *src++;
		}
		*dest = '\0';
		return dest;
	}
}

void MyStrCountNumberOfAlphabetsDigitsSpecialCharacters(const char*str){


	int Alphabets=0,Digits=0,Special=0;

	while(*str!='\0'){
		if((*str>='A' && *str<='Z') || (*str>='a' && *str<='z'))
			Alphabets++;
		else if(*str>='0' && *str<='9')
			Digits++;
		else
			Special++;
		str++;
	}

	printf("Number of Alphabets = %d  Digits = %d Special Character= %d\n",Alphabets,Digits,Special);

}

void MyStrVowelConsonantsCount(const char*str){


	int Vowels=0,Consonants=0;

	while(*str!='\0'){
		if(*str=='a' || *str=='e' || *str=='i' || *str=='o' || *str=='u')
			Vowels++;
		else
			Consonants++;
		str++;
	}

	printf("Number of Consonants = %d  & Vowels = %d\n",Consonants,Vowels);


}

void MyStrWordCount(const char*str){

	int count=1;

	while(*str!='\0'){
		if(*str==' ')
			count++;
		str++;
	}

	printf("Number of words = %d\n",count);
}

void MystrPalindrome(char*str){

	char temp[ARRAY_SIZE];
	int ret;

	MyStrcpy(temp,str);
	Mystrrev(temp);


	ret=Mystrcmp(temp,str);

	if(ret==0)
		printf("String is Palindrome !!!!\n");
	else
		printf("String is not Palindrome !!!\n");

}

void MyOccuranceOfCharacter(const char*str,char ch){

	int count=0;

	while(*str!='\0'){
		if(*str==ch)
			count++;
		str++;
	}

	printf("Number of times the character : %c occured in string is %d times\n",ch,count);
}
