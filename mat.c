#define N 512
#include <stdio.h>
#include <sys/time.h>
#include <mpi.h>

void enterData(int firstMatrix[][N], int secondMatrix[][N]);
void multiplyMatrices(int firstMatrix[][N], int secondMatrix[][N], int multResult[][N]);
void display(int mult[][N]);

int main()
{
	double elapsed_time;
        struct timeval tv1, tv2;
	gettimeofday(&tv1,NULL);
	int firstMatrix[N][N] = {1}, secondMatrix[N][N] = {1}, mult[N][N];

        // Function to multiply two matrices.
        multiplyMatrices(firstMatrix, secondMatrix, mult);

       // Function to display resultant matrix after multiplication.
        display(mult);
        gettimeofday(&tv2,NULL);
	elapsed_time = (tv2.tv_sec - tv1.tv_sec) + ((tv2.tv_usec - tv1.tv_usec) / 1000000.0);
                printf ("elapsed_time=\t%lf (seconds)\n", elapsed_time);
	return 0;
}

void multiplyMatrices(int firstMatrix[][N], int secondMatrix[][N], int mult[][N])
{
	int i, j, k;

	// Initializing elements of matrix mult to 0.
	for(i = 0; i < N; ++i)
	{
		for(j = 0; j < N; ++j)
		{
			mult[i][j] = 0;
		}
	}
	
	// Multiplying matrix firstMatrix and secondMatrix and storing in array mult.
	for(i = 0; i < N; ++i)
	{
		for(j = 0; j < N; ++j)
		{
			for(k=0; k < N; ++k)
			{
				mult[i][j] += firstMatrix[i][k] * secondMatrix[k][j];																		
			}
		}
	}
}

void display(int mult[][N])
{
	int i, j;
//	printf("\nOutput Matrix:\n");
	for(i = 0; i < N; ++i)
	{
		for(j = 0; j < N; ++j)
		{
		//	printf("%d  ", mult[i][j]);
		//	if(j == N-1)
		//		printf("\n\n");
		}
	}
}
