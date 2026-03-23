#include <iostream>
#include <cstring>
using namespace std;



void turn_matrix(int* Matrix,int* temp,int c_num,int N,int M, int* term);


int main()
{
	int N, M, R;
	int* Matrix;
	int c_num;

	cin >> N >> M >> R;

	Matrix = (int*)malloc(N * M * sizeof(int));


	int min;
	if (N < M)
		min = N;
	else
		min = M;

	c_num = min / 2;

	int a, b;
	int count = 0;
	int* term;
	term = (int*)malloc(c_num * sizeof(int));

	a = M - 1;
	b = N - 1;

	for (int i = 0; i < c_num; i++)
	{
		if (i == 0)
		{
			term[i] = (2 * a) + (2 * b);
			term[i] = R % term[i];
		}
			
		else
		{
			a = a - 2;
			b = b - 2;
			term[i] = (2 * a) + (2 * b);
			term[i] = R % term[i];
		}
	}


	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> Matrix[i * M + j];
		}
	}

	int* temp;
	temp = (int*)malloc(N * M * sizeof(int));
	copy(Matrix, Matrix + N * M, temp);


	turn_matrix(Matrix, temp, c_num, N, M, term);
	

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << Matrix[i * M + j] ;
			if (j != M - 1)
				cout << ' ';
		}
		cout << '\n';
	}
	
	free(temp);
	free(Matrix);
	free(term);
}




void turn_matrix(int* Matrix,int* temp,int c_num,int N,int M, int* term)
{
	
	
	
	for (int a = 0; a < c_num; a++) //left
	{
		
		for (int b = 0; b < term[a]; b++)
		{
			for (int j = 1 + a; j < M - a; j++)
			{
				temp[a * M + j - 1] = Matrix[a * M + j];
			}

			for (int i = a; i < N - a - 1; i++) //down
			{
				temp[(i + 1) * M + a] = Matrix[i * M + a];
			}

			int k = N - 1 - a;
			for (int j = a; j < M - a - 1; j++) //right
			{
				temp[k * M + j + 1] = Matrix[k * M + j];
			}
			k = M - 1 - a;
			for (int i = N - 1 - a; i > a; i--) //up
			{
				temp[(i - 1) * M + k] = Matrix[i * M + k];
			}

			memcpy(Matrix, temp, N * M * sizeof(int));

		}

		
	}


	
	
}