/* Sione Daniels
 * EECS 348 - Friday 3pm
 * 10/13/2024
 * KUID: 3133752
 * Purpose: to handle matrix's 
 * */
#include <stdio.h>
#define SIZE 5

//Print's the matrix
void print_matrix(int matrix[SIZE][SIZE]){
	for (int y = 0; y < SIZE; y++){ //all double for loops are used to moving across the rows and colums
		printf("[ ");
		for (int x = 0; x < SIZE; x++){
			printf("%d ", matrix[x][y]);
		}
	printf("]\n");
	}
printf("-----\n");//formating
}

//Adds the matrix's together
void add(int m1[SIZE][SIZE], int m2[SIZE][SIZE], int sum[SIZE][SIZE]){
	for (int y = 0; y < SIZE; y++){
		for (int x = 0; x < SIZE; x++){
			sum[y][x] = (m1[y][x] + m2[y][x]); //adds the two values in the matrix's together and assigns them to the position of sum matrix
		}
	}
	printf("-----\nAddition: \n");//formating
	print_matrix(sum);
}

//multiplies the matrix's
void multi_matrix(int m1[SIZE][SIZE],int m2[SIZE][SIZE],int multi[SIZE][SIZE]){
	for (int y = 0; y < SIZE; y++){
                for (int x = 0; x < SIZE; x++){
			multi[y][x] = 0;
		}
	}
	for (int y = 0; y < SIZE; y++){
		for (int x = 0; x < SIZE; x++){
			for (int z = 0; z < SIZE; z++){//third for loop is used to properly multiply matrix's
				multi[y][x] += (m1[y][z] * m2[z][x]);
			}
		}	
	}
	printf("-----\nMultiplication: \n");//formatting
	print_matrix(multi);
}

//rotates the matrix
void transpose_matrix(int matrix[SIZE][SIZE]){
	int transpose[SIZE][SIZE];
	for (int y = 0; y < SIZE; y++){
                for (int x = 0; x < SIZE; x++){
			transpose[x][y] = matrix[y][x]; //flipping the x and y creates the the transpose
		}
	}
	print_matrix(transpose);
}

int main(){//Main handles the input of the matrix's and checks if they're empty or incorrect sized
	int m1[SIZE][SIZE] = {
		{1, 2, 3, 4, 5},
		{6, 7, 8, 9, 10},
		{11, 12, 13, 14, 15},
		{16, 17, 18, 19, 20},
		{21, 22, 23, 24, 25}
		};
	int m2[SIZE][SIZE] = {
		{25, 24, 23, 22, 21},
		{20, 19, 18, 17, 16},
		{15, 14, 13, 12, 11},
		{10, 9, 8, 7, 6},
		{5, 4, 3, 2, 1}
		};
	int sum[SIZE][SIZE];
	int multi[SIZE][SIZE];
	if ((m1 == NULL) || (m2 == NULL)){ //checks if they're empty
		printf("Invalid Inputed Matrix");
		return 0;
	}
	add(m1, m2, sum); //calls the add function
	multi_matrix(m1, m2, multi); //calls the multi function
	printf("Transpose: Matrix m1\n");
	transpose_matrix(m1);//calls the transpose function
	printf("Transpose: Matrix m2\n");
	transpose_matrix(m2); //calls the transpose function
	return 0;
}

