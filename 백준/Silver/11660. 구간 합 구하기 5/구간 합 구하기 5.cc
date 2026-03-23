#if 1
#include <iostream>
using namespace std;

int sum[1030][1030] = { 0, };
int num[1030][1030] = { 0, };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;

	cin >> N>>M;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> sum[i][j];
			num[i][j] = sum[i][j];
		}
	}


	for (int i = 1; i <= N; i++)
	{
		for (int j = 2; j <= N; j++)
		{
			sum[i][j] = sum[i][j]+sum[i][j-1];
		}
	}


	for (int i = 1; i <= N; i++)
	{
		for (int j = 2; j <= N; j++)
		{
			sum[j][i] = sum[j][i] + sum[j-1][i];
		}
	}
	
	for (int re = 0; re < M; re++)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		int ans;

		if(x1 == x2 && y1 == y2)
			ans = num[x1][y1];
		else
			ans = sum[x2][y2] - sum[x2][y1 - 1] - sum[x1 - 1][y2] + sum[x1 - 1][y1 - 1];


		cout << ans << "\n";
	}
}





#endif