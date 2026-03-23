#if 1
#include <iostream>
using namespace std;

int num[1000005];
int prefix[1000005];
int suffix[1000005];


long long gcd(long long a, long long b)
{
	long long c;
	while (1)
	{
		c = a % b;
		if (c == 0)
		{
			return b;
		}
		a = b;
		b = c;
	}
}




int main()
{
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> num[i];
	}


	
	prefix[0] = num[0];
	for (int i = 1; i < N; i++) {
		prefix[i] = gcd(prefix[i - 1], num[i]);
	}

	suffix[N - 1] = num[N - 1];
	for (int i = N - 2; i >= 0; i--) {
		suffix[i] = gcd(suffix[i + 1], num[i]);
	}

	int max_gcd = 0;
	int exclude_num = -1;

	for (int i = 0; i < N; i++) {
		int g;
		if (i == 0)
			g = suffix[1];
		else if (i == N - 1)
			g = prefix[N - 2];
		else
			g = gcd(prefix[i - 1], suffix[i + 1]);

		if (num[i] % g != 0 && g > max_gcd) {
			max_gcd = g;
			exclude_num = num[i];
		}
	}

	if (max_gcd == 0)
		cout << "-1\n";
	else
		cout << max_gcd << ' ' << exclude_num << '\n';

	return 0;

}

#endif