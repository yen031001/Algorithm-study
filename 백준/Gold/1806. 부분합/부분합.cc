#include <iostream>
using namespace std;

int N, S;
int list[100005];

int main()
{
	cin >> N >> S;
	for (int i = 0; i < N; i++)
		cin >> list[i];

	int l=0, r=0;
	int minlen=100005;
	int sum = 0;
	int templen = 0;

	while (1)
	{
		sum += list[r];
		while (1)
		{
			if (l > r || sum < S)
				break;
			if (sum >= S)
			{
				templen = r - l+1;
				if (templen < minlen)
				{
					minlen = templen;
				}
				sum -= list[l++];
			}
		}
		r++;

		if (r == N)
			break;
	}

	if (minlen == 100005)
		minlen = 0;
	cout << minlen;
}