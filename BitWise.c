#include "HEADER.H"

int main(){

	int num1,num2,choice;
	char hex[10],oct[10];
	while(1){

		printOptions();
		printf("Enter from above option = ");
		scanf("%d",&choice);
		switch(choice){

			case LSBSETCLEAR:
				printf("Enter the number = ");
				scanf("%d",&num1);
				LsbSetClear(num1);
				break;
			case MSBSETCLEAR:
				printf("Enter the number = ");
				scanf("%d",&num1);
				MsbSetClear(num1);
				break;
			case GET:
				printf("Enter the number = ");
				scanf("%d",&num1);
				Get(num1);
				break;
			case SET:
				printf("Enter the number = ");
				scanf("%d",&num1);
				Set(num1);
				break;
			case CLEAR:
				printf("Enter the number = ");
				scanf("%d",&num1);
				Clear(num1);
				break;
			case TOGGLE:
				printf("Enter the number = ");
				scanf("%d",&num1);
				Toggle(num1);
				break;
			case DECIMALBINARY:
				printf("Enter the number = ");
				scanf("%d",&num1);
				DecimalBinary(num1);
				break;
			case SWAP:
				printf("Enter two numbers = ");
				scanf("%d %d",&num1,&num2);
				printf("Before Swapping num1 = %d num2 = %d\n",num1,num2);
				Swap(&num1,&num2);
				printf("After Swapping num1 = %d num2 = %d\n",num1,num2);
				break;
			case ODDEVEN:
				printf("Enter the number = ");
				scanf("%d",&num1);
				OddEven(num1);
				break;
			case HIGHESTSETBIT:
				printf("Enter the number = ");
				scanf("%d",&num1);
				HighestSetBit(num1);
				break;
			case LOWESTSETBIT:
				printf("Enter the number = ");
				scanf("%d",&num1);
				LowestSetBit(num1);
				break;
			case ONESZEROS:
				printf("Enter the number = ");
				scanf("%d",&num1);
				OnesZeros(num1);	
				break;
			case FLIP:
				printf("Enter the number = ");
				scanf("%d",&num1);
				Flip(num1);
				break;
			case REVERSE:
				printf("Enter the number = ");
				scanf("%d",&num1);
				Reverse(num1);
				break;
			case SWAP_ADJ:
				printf("Enter the number = ");
				scanf("%d",&num1);
				Swap_adj(num1);
				break;
			case ROTATE_LEFT:
				printf("Enter the number = ");
				scanf("%d",&num1);
				Rotate_left(num1);
				break;
			case ROTATE_RIGHT:
				printf("Enter the number = ");
				scanf("%d",&num1);
				Rotate_right(num1);
			case HEX_BIN:
				printf("Enter the Hex : ");
				scanf("%s",hex);
				hex_bin(hex);
				break;
			case OCT_BIN:
				printf("Enter the Oct : ");
				scanf("%s",oct);
				oct_bin(oct);
				break;
			case EXIT:
				printf("Bye.. Visit Again !! Thanks !!\n");
				exit(0);
			default: printf("Entered option is Incorrect!!!\n");
		}
	}

	return 0;

}

void printOptions()
{
	unsigned int numOptions = (sizeof(MenuOptions)/sizeof(*MenuOptions));
	printf("\n**********************************************\n");
	for(int i = 0;i!=numOptions;i++)
	{
		printf("\t%d) %s\n",i,MenuOptions[i]);
	}
	printf("**********************************************\n\n");
}


void LsbSetClear(int num){

	if(num&1 == 1)
		printf("LSB is set !!!\n");
	else
		printf("LSB is clear !!!\n");

}

void MsbSetClear(int num){

	if((num>>31)&1 == 1)
		printf("MSB is set !!!\n");
	else
		printf("MSB is clear !!!\n");

}

void Get(int num){

	int pos;

	printf("Enter the position of the bit = ");
	scanf("%d",&pos);

	printf("Bit in the given position = %d\n",num>>pos&1);

}

void Set(int num){

	int pos;

	printf("Enter the position of the bit to set = ");
	scanf("%d",&pos);

	printf("Before setting the bit position = ");
	DecimalBinary(num);
	num=num|1<<pos;
	printf("After setting the bit position = ");
	DecimalBinary(num);

}

void Clear(int num){

	int pos;

	printf("Enter the position of the bit to set = ");
	scanf("%d",&pos);

	printf("Before clearing the bit position = ");
	DecimalBinary(num);
	num=num&~(1<<pos);
	printf("After clearing the bit position = ");
	DecimalBinary(num);

}

void Toggle(int num){

	int pos;

	printf("Enter the position of the bit to set = ");
	scanf("%d",&pos);

	printf("Before Toggling the bit position = ");
	DecimalBinary(num);
	num=num^1<<pos;
	printf("After Toggling the bit position = ");
	DecimalBinary(num);
}

void DecimalBinary(int num){

	int pos;

	for(pos=31;pos>=0;pos--)
		printf("%d",num>>pos&1);

	printf("\n");

}

void Swap(int *num1,int* num2){

	*num1=*num1^*num2;
	*num2=*num1^*num2;
	*num1=*num1^*num2;

}

void OddEven(int num){

	num&1?printf("Is Odd\n"):printf("Is Even\n");

}

void HighestSetBit(int num){

	int pos;

	for(pos=31;pos>=0;pos--)
		if(num>>pos&1 == 1)
			break;

	printf("Highest Set Bit of a number is at postion = %d\n",pos);

}

void Flip(int num){

	DecimalBinary(num);
	num=~num;
	DecimalBinary(num);

}

void OnesZeros(int num){

	int ones=0,zeros=0,pos;

	for(pos=31;pos>=0;pos--)
		if(num>>pos&1 == 1)
			ones++;
		else
			zeros++;

	printf("Number of 1's = %d and 0's = %d\n",ones,zeros);

}

void LowestSetBit(int num){

	int pos;

	for(pos=0;pos<=31;pos++)
		if(num>>pos&1 == 1)
			break;

	printf("Lowest Set Bit of a number is at postion = %d\n",pos);

}

void Reverse(int num){

	int i,j,m,n;

	printf("Before Reversing = ");
	DecimalBinary(num);

	for(i=0,j=31;i<j;i++,j--){
		m=num>>i&1;
		n=num>>j&1;		/*checking the bit is set or clear & storing*/
		if(m!=n){
			num=num^1<<i;
			num=num^1<<j;
		}
	}

	printf("After Reversing = ");
	DecimalBinary(num);

}

void Swap_adj(int num)
{

	num=((num & 0xAAAAAAAA) >> 1) | ((num & 0x55555555) << 1);
	DecimalBinary(num);
}

void Rotate_left(int num)
{
	int rot;
	printf("Enter the number of rotation : ");
	scanf("%d",&rot);

	num=num<<rot | num>>(32-rot);
	DecimalBinary(num);

}

void Rotate_right(int num)
{

	int rot;
	printf("Enter the number of rotation : ");
	scanf("%d",&rot);

	num=num>>rot | num<<(32-rot);
	DecimalBinary(num);

}
void hex_bin(char* hex)
{
	for(int i=0;hex[i];i++){

		switch(hex[i]){

			case '0' : printf("0000 ");
				   break;
			case '1' : printf("0001 ");
				   break;
			case '2' : printf("0010 ");
				   break;
			case '3' : printf("0011 ");
				   break;
			case '4' : printf("0100 ");
				   break;
			case '5' : printf("0101 ");
				   break;
			case '6' : printf("0110 ");
				   break;
			case '7' : printf("0111 ");
				   break;
			case '8' : printf("1000 ");
				   break;
			case '9' : printf("1001 ");
				   break;
			case 'A' : printf("1010 ");
				   break;
			case 'B' : printf("1011 ");
				   break;
			case 'C' : printf("1100 ");
				   break;
			case 'D' : printf("1101 ");
				   break;
			case 'E' : printf("1110 ");
				   break;
			case 'F' : printf("1111 ");
				   break;
		}
	}
	printf("\n");

}

void oct_bin(char* oct)
{
	for(int i=0;oct[i];i++){

		switch(oct[i]){

			case '0' : printf("000 ");
				   break;
			case '1' : printf("001 ");
				   break;
			case '2' : printf("010 ");
				   break;
			case '3' : printf("011 ");
				   break;
			case '4' : printf("100 ");
				   break;
			case '5' : printf("101 ");
				   break;
			case '6' : printf("110 ");
				   break;
			case '7' : printf("111 ");
				   break;
		}
	}
	printf("\n");
}
