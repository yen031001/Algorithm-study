#include <iostream>
#include <stdio.h>
using namespace std;


void search(int depth, int M, int N, int* flag, int* arr);
int total = 0;
int MAX = 1;

int main()
{
	int N, M;

	cin >> N >> M;

	int* flag;
	flag = (int*)malloc((N + 1) * sizeof(int));

	int* arr;
	arr = (int*)malloc(M * sizeof(int));

	int a = 0;
	for (int i = 0; i < M; i++)
	{
		MAX = MAX * N;
	}

	for (int i = 0; i < N + 1; i++)
	{
		flag[i] = 0;
	}



	int depth = 0;
	int prv = 1;
	search(depth, M, N, flag, arr);


	free(flag);
	free(arr);





}



void search(int depth, int M, int N, int* flag, int* arr)
{
	if (depth == M)
	{
		total++;
		for (int j = 0; j < M - 1; j++)
		{
			printf("%d ", arr[j]);
		}
		printf("%d", arr[M - 1]);
		if (MAX > total)
		{
			printf("\n");
		}
		return;
	}

	for (int i = 1; i <= N; i++)
	{
		if (flag[i] == 0)
		{
			arr[depth] = i;
			search(depth + 1, M, N, flag, arr);
			flag[i] = 0;
		}
	}
}