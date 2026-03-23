#if 1

#include <iostream>
using namespace std;

int num[1005] = { 0, };

int main()
{
	int N, K;
	cin >> N >> K;
	int count = 0;
	int k = 1;

	for (int i = 2; i < N + 1;)
	{
		num[i] = 1;
		count++;
		if (count == K)
		{
			cout << i;
			return 0;
		}
		k++;
		i = 2 * k;
	}
	while (count<K)
	{
		for (int i = 3; i < N+1;)
		{
			if (num[i] == 0)
			{
				num[i] == 1;
				count++;
				if (count == K)
				{
					cout << i;
					return 0;
				}
				for (int j = i + 1; j < N + 1; j++)
				{
					if (j%i == 0&&num[j]==0)
					{
						num[j] = 1;
						count++;
						if (count == K)
						{
							cout << j;
							return 0;
						}
					}
				}
			}

			i = i + 2;
		}
	}
	
}

#endif