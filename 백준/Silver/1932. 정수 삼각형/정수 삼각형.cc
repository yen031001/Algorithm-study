#if 1
#include <iostream>
using namespace std;


int N;
int triangle[505][505] = { 0, };
int sum[505][505] = { 0, };

int MAX(int a, int b)
{
	if (a > b)
		return a;
	else
		return b;
}
int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < i + 1; j++)
		{
			int temp;
			cin >> temp;
			triangle[i][j] = temp;
		}
	}

	for (int i = 0; i < N; i++)
	{
		sum[N - 1][i] = triangle[N - 1][i];
	}

	for (int i = N-2; i >= 0; i--)
	{
		for (int j = 0; j < i + 1; j++)
		{
			sum[i][j] = MAX(sum[i + 1][j], sum[i + 1][j + 1])+triangle[i][j];
		}
	}

	cout << sum[0][0];



}





#endif