#if 1
#include <iostream>
using namespace std;

long long memo[32][32] = { 0, };

long long cal(long long a, long long b)
{
	if (b == 0)
		return 1;
	else if (a == b)
		return 1;
	else
	{
		if (memo[a][b] == 0)
		{
			long long temp = cal(a - 1, b - 1) + cal(a - 1, b);
			memo[a][b] = temp;
		}
		
		return memo[a][b];
	}

}

int main()
{
	long long T,M, N;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		cin >> N >> M;
		long long ans = cal(M, N);
		cout << ans << "\n";
	}
	
}




#endif