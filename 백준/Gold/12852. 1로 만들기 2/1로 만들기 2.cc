#if 1
#include <iostream>
using namespace std;

int num[1000005] = { 0, };
int pre[1000005] = { 0, };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int start;
	cin >> start;

	num[0] = 0;
	num[1] = 0;
	pre[1] = -1;

	int cnt = 2;

	while (cnt <= start)
	{
		int min = 1000000000;

		if (!(cnt % 2))
		{
			if (num[cnt / 2] < min)
			{
				min = num[cnt / 2];
				pre[cnt] = cnt / 2;
			}
		}

		if (!(cnt % 3))
		{
			if (num[cnt / 3] < min)
			{
				min = num[cnt / 3];
				pre[cnt] = cnt / 3;
			}
		}

		if (num[cnt-1] < min)
		{
			min = num[cnt-1];
			pre[cnt] = cnt-1;
		}

		num[cnt] = min + 1;	
		cnt++;
	}
	
	cout << num[start] << "\n";
	
	int now = start;
	cout << now << ' ';
	while (pre[now] != -1)
	{
		cout << pre[now]<<' ';
		now = pre[now];
	}

	
}





#endif