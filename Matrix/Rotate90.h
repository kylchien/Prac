#pragma once

#include "Matrix.h"
#include "../test.h"

/*
Given an image represented by an NxN matrix, where each pixel in the image is 4
bytes, write a method to rotate the image by 90 degrees.Can you do this in place ?
*/


void rotate(int** matrix, int n) 
{
	for(int layer=0; layer < n/2; ++layer){
		int first = layer;
		int last = n - 1 - layer;
		for (int i = first; i < last; ++i) {
			int offset = i - first;
			int top = matrix[first][i]; //save top

			//left -> top
			matrix[first][i] = matrix[last - offset][first];

			//bottom->left
			matrix[last - offset][first] = matrix[last][last - offset];

			//right->bottom
			matrix[last][last - offset] = matrix[i][last];

			//top->right
			matrix[i][last] = top; //right <-saved top
		}
	}
}


void rotateOuter(int** matrix, int row, int col, int n)
{
	int max = n - 1;
	for (int i = 0; i < n; ++i) {
		int top = matrix[row][col+i];

		//left rotates to top
		matrix[row][col+i] = matrix[row + n - i][col];

		//bottom rotates to left
		matrix[row+n-i][col] = matrix[row+n][col + n - i];

		//right rotates to bottom
		matrix[row + n][col + n - i] = matrix[row+i][col+n];

		//cout << "[" << row+n-i << "][" << col + n << "]=" << top <<"\n";
		//top rorates to right
		matrix[row + i][col + n] = top;
	}
}

void myRotate(int** matrix, int n)
{
	int row = 0, col = 0;
	for (int i = n; i > 1; i -= 2) {
		rotateOuter(matrix, row++, col++, i-1);
	}
}


void testRotate(int n)
{
	int** mat = allocMatrix(n);
	int count = 1;
	for (int i = 0; i < n;i++)
		for (int j = 0; j < n;j++)
			mat[i][j] = count++;

	printMatrix(mat, n, n);
	myRotate(mat, n);
	printMatrix(mat, n, n);
}
