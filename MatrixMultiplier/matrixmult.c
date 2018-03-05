#include <stdio.h>

#define M 2
#define N 2
#define K 2

void fillWithRandom(int *matrix, int x, int y)
{
	int i, j;

	for (i = 0; i < x; i++)
	{
		for (j = 0; j < y; j++)
		{
			*((matrix + i * y) + j) = rand() % 10;
		}
	}
}

void printMatrix(int *matrix, int x, int y)
{
	int i, j;

	for (i = 0; i < x; i++)
	{
		for (j = 0; j < y; j++)
		{
			printf("%d \t", *((matrix + i * y) + j));
		}

		printf("\n");
	}
}

void multiplyMatrix(int *mC, int *mA, int *mB, int mm, int nn, int kk)
{
	int i, j, k, sum;

	for (i = 0; i < mm; i++)
	{
		for (j = 0; j < nn; j++)
		{
			sum = 0;

			for (k = 0; k < kk; k++)
			{
				sum += *((mA + i * nn) + k) * *((mB + k * kk) + j);
			}

			*((mC + i * kk) + j) = sum;
		}
	}
}

int main()
{
	int a[M][N], b[N][K], c[M][K];

	srand(time(NULL));
	
	printf("Matrix A:\n");
	fillWithRandom(a, M, N);
	printMatrix(a, M, N);
	
	printf("\nMatrix B:\n");
	fillWithRandom(b, N, K);
	printMatrix(b, N, K);
	
	printf("\nMatrix C (A * B):\n");
	multiplyMatrix(c, a, b, M, N, K);
	printMatrix(c, M, K);

	return 0;
}