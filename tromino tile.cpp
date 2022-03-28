#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <iostream>
#define MAX 1024
int key = 1;




void recursion(int **matrix, int size, int centerX, int centerY, int x, int y) {
	/*��и� 1,2,3,4*/
	int quart = size / 4;
	size = size / 2;
	if (size <= 0)
		return;
	else {
		if (x > centerX && y <= centerY) {//1��и�
			matrix[centerY - 1][centerX - 1] = key;//2��и�
			matrix[centerY][centerX - 1] = key;//3��и�
			matrix[centerY][centerX] = key;//4��и�
			key++;
			recursion(matrix, size, centerX + quart, centerY - quart, x, y); //�ڱ� ��и�
			recursion(matrix, size, centerX - quart, centerY - quart, centerX, centerY); //2��и�
			recursion(matrix, size, centerX - quart, centerY + quart, centerX, centerY + 1); //3��и�
			recursion(matrix, size, centerX + quart, centerY + quart, centerX + 1, centerY + 1); //4��и�
		}

		else if (x <= centerX && y <= centerY) { //2��и�
			matrix[centerY - 1][centerX] = key;//1��и�
			matrix[centerY][centerX - 1] = key;//3��и�
			matrix[centerY][centerX] = key;//4��и�
			key++;
			recursion(matrix, size, centerX + quart, centerY - quart, centerX + 1, centerY);//1��и�
			recursion(matrix, size, centerX - quart, centerY - quart, x, y); //2��и�
			recursion(matrix, size, centerX - quart, centerY + quart, centerX, centerY + 1); //3��и�
			recursion(matrix, size, centerX + quart, centerY + quart, centerX + 1, centerY + 1); //4��и�
		}
		else if (x <= centerX && y > centerY) { //3��и�
			matrix[centerY - 1][centerX] = key;//1��и�
			matrix[centerY - 1][centerX - 1] = key;//2��и�
			matrix[centerY][centerX] = key;//4��и�
			key++;
			recursion(matrix, size, centerX + quart, centerY - quart, centerX + 1, centerY);//1��и�
			recursion(matrix, size, centerX - quart, centerY - quart, centerX, centerY); //2��и�
			recursion(matrix, size, centerX - quart, centerY + quart, x, y); //3��и�
			recursion(matrix, size, centerX + quart, centerY + quart, centerX + 1, centerY + 1); //4��и�
		}

		else if (x > centerX && y > centerY) {//4��и�
			matrix[centerY - 1][centerX] = key;//1��и�
			matrix[centerY - 1][centerX - 1] = key;//2��и�
			matrix[centerY][centerX - 1] = key;//3��и�
			key++;
			recursion(matrix, size, centerX + quart, centerY - quart, centerX + 1, centerY);//1���
			recursion(matrix, size, centerX - quart, centerY - quart, centerX, centerY); //2��и�
			recursion(matrix, size, centerX - quart, centerY + quart, centerX, centerY + 1); //3��и�
			recursion(matrix, size, centerX + quart, centerY + quart, x, y); //4��и�
		}
	}
}

int main(void) {
	int k, x, y;
	int i, j;
	scanf("%d", &k);
	scanf("%d %d", &x, &y);
	int size = (int)pow(2, k);


	int** matrix = new int*[MAX];
	for (int i = 0; i < MAX; i++) {
		matrix[i] = new int[MAX];
	}





	recursion(matrix, size, size / 2, size / 2, y, x);

	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			if (i == x-1 && j == y-1) {
			printf("%d", 0);
			}
			else {
				printf("%d", matrix[i][j]);
			}
		}
		printf("\n");
	}
	system("pause");
	return 0;
}