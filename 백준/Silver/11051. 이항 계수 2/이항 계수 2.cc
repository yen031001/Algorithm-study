#include <iostream>
using namespace std;

int memo[1005][1005] = { 0, };

int main()
{
	int N, K;
	cin >> N >> K;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (i == j)
				memo[i][j] = 1;
			else if (j == 0)
				memo[i][j] = 1;
			else
				memo[i][j] = (memo[i - 1][j - 1] + memo[i - 1][j])%10007;

			if (i == N && j == K)
			{
				cout << memo[N][K];
				return 0;
			}
				
		}
	}

}