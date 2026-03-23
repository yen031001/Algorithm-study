#if 1
#include <iostream>;
using namespace std;

int map[1005][1005] = { 0, };
int dp[1005][1005] = { 0, };

int main()
{
	int H, W, N;

	cin >> H >> W >> N;

	for (int i = 1; i <= H; i++)
	{
		for (int j = 1; j <= W; j++)
		{
			cin >> map[i][j];
		}
	}

	dp[1][1] = N;

	for (int i = 1; i <= H; i++)
	{
		for (int j = 1; j <= W; j++)
		{
			if (map[i][j] == 0)  //아래쪽
			{
				if (dp[i][j] % 2 == 0)
				{
					dp[i + 1][j] = dp[i + 1][j] + (dp[i][j] / 2);
				}
				else
					dp[i + 1][j] = dp[i + 1][j] + (dp[i][j] / 2) + 1;
				dp[i][j + 1] = dp[i][j + 1]+dp[i][j] / 2;
			}
			else if (map[i][j] == 1)  //오른쪽
			{
				if (dp[i][j] % 2 == 0)
				{
					dp[i][j+1] = dp[i][j+1] + (dp[i][j] / 2);
				}
				else
					dp[i][j+1] = dp[i][j+1] + (dp[i][j] / 2) + 1;
				dp[i + 1][j] = dp[i + 1][j]+dp[i][j] / 2;
			}
		}
	}


	for (int i = 1; i <= H; i++)
	{
		for (int j = 1; j <= W; j++)
		{
			if (dp[i][j] %2== 0) 
			{
				map[i][j] = 1 - map[i][j];
			}
		}
	}


	int a=1, b=1;

	while (a != H + 1 && b != W + 1)
	{
		if (map[a][b] == 0)
			a = a + 1;
		else
			b = b + 1;
	}

	cout << a<<' '<< b;
}


#endif