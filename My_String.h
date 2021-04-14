#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define ARRAY_SIZE 100

const char *myStringMenuOptions[] ={
							"myStringLength",
							"myStringCopy",
							"myStringNCopy",
							"myStringConcat",
							"myStringNConcat",
							"myStringCompare",
							"myStringNCompare",
							"myStringReverse",
							"myStringfirstoccuranceChar",
							"myStringlastoccuranceChar",
							"myStrCountNumberOfAlphabetsDigitsSpecialCharacters",
							"myStringCountVowelConstants",
							"myStringWords",
							"myStringPalindrome",
							"myOccuranceOfCharacter",
							"myStringExit",
							};

enum{
					MYSTRINGLEN,
					MYSTRINGCOPY,
					MYSTRINGNCOPY,
					MYSTRCAT,
					MYSTRNCAT,
					MYSTRCOMPARE,
					MYSTRNCOMPARE,
					MYSTRREVERSE,
					MYSTRINGCHAR,
					MYSTRINGRCHAR,
					MYSTRCHARACTERCOUNT,
					MYSTRVOWEL_CONSTANTS_COUNT,
					MYSTRINGWORDS,
					MYSTRINGPALINDROME,
					MYOCCURANCEOFCHARACTER,
					EXIT,
};

size_t MyStrlen(const char*);
char* MyStrcpy(char*,char*);
char* MyStrncpy(char*,char*,int);
const char* MyStrchr(const char*,char);
const char* MyStrrchr(const char*,char);
int Mystrcmp(const char*,const char*);
int Mystrncmp(const char*,const char*,size_t);
void Mystrrev(char*);
char* Mystrcat(char*,const char*);
char* Mystrncat(char*,const char*,size_t);
static void printOptions(void);
void MyStrCountNumberOfAlphabetsDigitsSpecialCharacters(const char*);
void MyStrVowelConsonantsCount(const char*);
void MyStrWordCount(const char*);
void MystrPalindrome(char*);
void MyOccuranceOfCharacter(const char*,char);
