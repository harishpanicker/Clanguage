/*WAP to multiply two matrix using pointers */

#include <stdio.h>

#define ROWS 3
#define COLS 3


/* Function declaration to input, add and print matrix */
void matrixInput(int mat[][COLS]);
void matrixPrint(int mat[][COLS]);
void matrixMul(int mat1[][COLS], int mat2[][COLS], int res[][COLS]);


int main()
{
    int mat1[ROWS][COLS], mat2[ROWS][COLS], res[ROWS][COLS];

    // Input elements in first matrix
    printf("Enter elements in first matrix of size %dx%d: \n", ROWS, COLS);
    matrixInput(mat1);

    // Input element in second matrix
    printf("\nEnter elemetns in second matrix of size %dx%d: \n", ROWS, COLS);
    matrixInput(mat2);

    // Find multiplication of both matrices and print result
    matrixMul(mat1, mat2, res);

    printf("\nSum of first and second matrix: \n");
    matrixPrint(res);
    

    return 0;
}



/**
 * Function to read input from user and store in matrix.
 * 
 * @mat     Two dimensional integer array to store input.
 */
void matrixInput(int mat[][COLS])
{
    int i, j;


    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            // (*(mat + i) + j) is equal to &mat[i][j]
            scanf("%d", (*(mat + i) + j));
        }
    }
}



/**
 * Function to print elements of matrix on console.
 * 
 * @mat     Two dimensional integer array to print.
 */
void matrixPrint(int mat[][COLS])
{
    int i, j;

    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            // *(*(mat + i) + j) is equal to mat[i][j]
            printf("%d ", *(*(mat + i) + j));
        }
        printf("\n");
    }
}



/**
 * Function to multiply two matrices and store their result in given res
 * matrix.
 * 
 * @mat1    First matrix to multiply.
 * @mat2    Second matrix to multiply.
 * @res     Resultant matrix to store multiplication of mat1 and mat2.
 */
void matrixMul(int mat1[][COLS], int mat2[][COLS], int res[][COLS])
{
    int i, j,k, sum;

    // Iterate over each matrix elements 
    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
	    sum=0;
	    for(k=0; k<COLS; k++)
		    sum+= *(*(mat1+i)+k) * *(*(mat2+k)+j);
	    *(*(res+i)+j) = sum;
        }

    }
}
