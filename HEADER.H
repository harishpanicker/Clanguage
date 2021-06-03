#include<stdio.h>
#include<stdlib.h>

const char *MenuOptions[] ={
							"LsbSetClear",
							"MsbSetClear",
							"Get",
							"Set",
							"Clear",
							"Toggle",
							"DecimalBinary",
							"Swap",
							"OddEven",
							"HighestSetBit",
							"LowestSetBit",
							"OnesZeros",
							"Flip",
							"Reverse",
							"Swap_adj",
							"Rotate_left",
							"Rotate_right",
							"Hex_binary",
							"Oct_binary",
							"Exit"
							};


enum  {
					LSBSETCLEAR=0,
					MSBSETCLEAR,
					GET,
					SET,
					CLEAR,
					TOGGLE,
					DECIMALBINARY,
					SWAP,
					ODDEVEN,
					HIGHESTSETBIT,
					LOWESTSETBIT,
					ONESZEROS,
					FLIP,
					REVERSE,
					SWAP_ADJ,
					ROTATE_LEFT,
					ROTATE_RIGHT,
					HEX_BIN,
					OCT_BIN,
					EXIT
};

void LsbSetClear(int);
void MsbSetClear(int);
void Get(int);
void Set(int);
void Clear(int);
void Toggle(int);
void DecimalBinary(int);
void Swap(int*,int*);
void OddEven(int);
void HighestSetBit(int);
void LowestSetBit(int);
void OnesZeros(int);
void Flip(int);
void Reverse(int);
void printOptions(void);
void Swap_adj(int);
void Rotate_left(int);
void Rotate_right(int);
void hex_bin(char*);
void oct_bin(char*);
