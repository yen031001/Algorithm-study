#if 1
#include <iostream>
using namespace std;




int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	int sum[100005];
	int num[100005];
	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		cin >> num[i];
	}

	sum[0] = 0;
	sum[1] = num[1];

	for (int i = 2; i <= N; i++)
	{
		sum[i] = sum[i - 1] + num[i];
	}


	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;

		int ans = sum[b] - sum[a - 1];
		cout << ans << "\n";

	}

}





#endif