#if 1
#include <iostream>
using namespace std;

int N;
int score[305] = { 0, };
int sum[305][2] = { 0, };

int MAX(int a, int b)
{
	if (a > b)
		return a;
	else
		return b;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		cin >> score[i];
	}

	sum[0][0] = 0;
	sum[0][1] = 0;
	sum[1][0] = score[1];
	sum[1][1] = score[1];

	for (int i = 2; i <= N; i++)
	{
		sum[i][0] = MAX(sum[i - 2][0], sum[i - 2][1]) + score[i];
		sum[i][1] = sum[i - 1][0] + score[i];
	}

	int ans = MAX(sum[N][0], sum[N][1]);
	
	cout << ans;
	
}





#endif