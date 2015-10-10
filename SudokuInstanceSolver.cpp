******************************************************************************
******************************************************************************
***                                                                        ***
***                 Script Name: Sudoku Instance Solver                    ***
***                 Author: Sourav Badami                                  ***
***                 Website: www.souravbadami.com                          ***
***                 Email: hey@souravbadami.com                            ***
***                 Language: C++                                          ***
***                                                                        ***
******************************************************************************
******************************************************************************

#include <stdio.h>
#define empty 0
#define N 9

//Prototypes!
bool EmptyLoc(int matrix[N][N], int &row, int &col);
bool SafeCheck(int matrix[N][N], int row, int col, int num);
bool implement(int matrix[N][N])
{
    int row, col;
 
    if (!EmptyLoc(matrix, row, col))
       return true;
    for (int num = 1; num <= 9; num++)
    {
        if (SafeCheck(matrix, row, col, num))
        {
            matrix[row][col] = num;
            if (implement(matrix))
                return true;
            matrix[row][col] = empty;
        }
    }
    return false;
}
bool EmptyLoc(int matrix[N][N], int &row, int &col) // Checks if the location is blank (empty).
{
    for (row = 0; row < N; row++)
        for (col = 0; col < N; col++)
            if (matrix[row][col] == empty)
                return true;
    return false;
}
bool PIC(int matrix[N][N], int col, int num) // Checks if the number is present in a specific column.
{
    for (int row = 0; row < N; row++)
        if (matrix[row][col] == num)
            return true;
    return false;
}
bool PIR(int matrix[N][N], int row, int num) // Checks if the number is present in a specific row.
{
    for (int col = 0; col < N; col++)
        if (matrix[row][col] == num)
            return true;
    return false;
}
bool PIB(int matrix[N][N], int boxStartRow, int boxStartCol, int num) // Checks if the number is present in a specific sub-matrix.
{
    for (int row = 0; row < 3; row++)
        for (int col = 0; col < 3; col++)
            if (matrix[row+boxStartRow][col+boxStartCol] == num)
                return true;
    return false;
}
bool SafeCheck(int matrix[N][N], int row, int col, int num) // Checks if it is safe for a number to get placed.
{
    return !PIR(matrix, row, num) &&
           !PIC(matrix, col, num) &&
           !PIB(matrix, row - row%3 , col - col%3, num);
}
main() //MAIN
{
    int sepR=0,sepC=0;
    // Place your sudoku instance here.
    int matrix[N][N] = {{0, 7, 5, 0, 9, 0, 0, 0, 6},
                        {0, 2, 3, 0, 8, 0, 0, 4, 0},
                        {8, 0, 0, 0, 0, 3, 0, 0, 1},
                        {5, 0, 0, 7, 0, 2, 0, 0, 0},
                        {0, 4, 0, 8, 0, 6, 0, 2, 0},
                        {0, 0, 0, 9, 0, 1, 0, 0, 3},
                        {9, 0, 0, 4, 0, 0, 0, 0, 7},
                        {0, 6, 0, 0, 7, 0, 5, 8, 0},
                        {7, 0, 0, 0, 1, 0, 3, 9, 0}};
    if (implement(matrix) == true)
    {
    	for (int row = 0; row < N; row++)
    	{
        	for (int col = 0; col < N; col++)
		{
			sepC++;
             		printf("%2d", matrix[row][col]);
			if(sepC==3)
			{
				printf(" ");
				sepC=0;
			}
		}
		sepR++;
        	if(sepR==3)
			{
				printf("\n");
				sepR=0;
			}
		printf("\n");
        }
    }
    else
         printf("Unable to solve!");
 
}
