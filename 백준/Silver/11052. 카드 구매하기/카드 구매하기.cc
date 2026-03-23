#if 1

#include <iostream>
#include <vector>
using namespace std;

int mp[10005] = { 0, };
int price[10005] = { 0, };

int main()
{
	int N;
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		cin >> price[i];
	}

	mp[1] = price[1];
	for (int i = 2; i <= N; i++)
	{
		int limt = i / 2;
		int max_p = price[i];

		while (limt > 0)
		{
			int tmp = mp[limt] + mp[i - limt];
			if (tmp > max_p)
				max_p = tmp;
			limt--;
		}

		mp[i] = max_p;
	}

	cout << mp[N];
}


#endif