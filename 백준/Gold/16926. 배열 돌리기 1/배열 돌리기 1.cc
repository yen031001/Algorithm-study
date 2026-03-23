#include <iostream>
using namespace std;



void turn_matrix(int* Matrix,int c_num,int N,int M);


int main()
{
	int N, M, R;
	int* Matrix;
	int c_num;

	cin >> N >> M >> R;

	Matrix = (int*)malloc(N * M * sizeof(int));

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> Matrix[i * M + j];
		}
	}

	int min;
	if (N < M)
		min = N;
	else
		min = M;

	c_num = min / 2;

	for (int i = 0; i < R; i++)
	{
		turn_matrix(Matrix, c_num, N, M);
	}
	

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
	
	free(Matrix);
}




void turn_matrix(int* Matrix,int c_num,int N,int M)
{
	int* temp;
	temp= (int*)malloc(N * M * sizeof(int));
	for (int a = 0; a < c_num; a++) //left
	{
		for (int j = 1 + a; j < M - a; j++)
		{
			temp[a * M + j - 1] = Matrix[a * M + j];
		}

		for (int i = a; i<N-a-1; i++) //down
		{
			temp[(i+1)*M+a] = Matrix[i*M+a];
		}

		int k = N - 1 - a;
		for (int j = a; j < M - a - 1; j++) //right
		{
			temp[k * M + j + 1] = Matrix[k * M + j];
		}
		k = M - 1 - a;
		for (int i = N - 1 - a; i >a; i--) //up
		{
			temp[(i - 1) * M + k] = Matrix[i * M + k];
		}
	}


	copy(temp,temp+N*M,Matrix);

	free(temp);
}