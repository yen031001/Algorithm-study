#if 1

#include <iostream>
using namespace std;

long long dp[105][22] = { 0, };
int num_arr[105] = { 0, };


int main()
{
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> num_arr[i];
	}


	int a = num_arr[0];
	dp[0][a] = 1;

	for (int i = 1; i < N - 1; i++)
	{
		for (int j = 0; j <= 20; j++)
		{

			if (j + num_arr[i] <= 20)
			{
				dp[i][j + num_arr[i]] += dp[i - 1][j];
			}
			if (j - num_arr[i] >= 0)
				dp[i][j - num_arr[i]] += dp[i - 1][j];

		}
	}

	cout << dp[N - 2][num_arr[N - 1]];
}

#endif