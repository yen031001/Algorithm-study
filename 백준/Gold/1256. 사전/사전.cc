#if 1
#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

long long memo[308][105] = { 1, };
int leng = 0;
int cant_flag = 0;
string result="";

void cal_memo(long long N)
{
	for (long long i = 1; i <= N; i++)
	{
		for (long long j = 0; j <= i; j++)
		{
			if (i == j)
				memo[i][j] = 1;
			else if (j == 0)
				memo[i][j] = 1;
			else
			{
				if (memo[i - 1][j - 1] + memo[i - 1][j] <= 1000000000)
					memo[i][j] = (memo[i - 1][j - 1] + memo[i - 1][j]);
				else
					memo[i][j] = 1000000000;
			}

		}
	}
}

long long dfs(long long M, long long N, long long K) {

	long long cnt = -1;
	if (K == 0 || (M == 0 && N == 0))
		return 0;
	else if (M <= 0)
	{
		for (int i = 0; i < N; i++)
			result.append("z");
		K--;
		return K;
	}
	else if (N <= 0)
	{
		for (int i = 0; i < M; i++)
			result.append("a");
		K--;
		return K;
	}

	if (memo[N + M-1][M - 1] >= K)
	{
		result.append("a");
		cnt=dfs(M - 1, N, K);
	}
	else
	{
		result.append("z");
		cnt=dfs(M, N - 1,K-memo[N + M-1][M - 1]);
	}

	return cnt;
	
}

int main()
{
	long long N, M, K;
	cin >> N >> M >> K;

	long long cnt = -1;
	leng = N + M;
	cal_memo(leng +10);
	cnt=dfs(N, M, K);


	if (cnt != 0)
		cout << "-1" << endl;
	else
		cout << result;
}

#endif