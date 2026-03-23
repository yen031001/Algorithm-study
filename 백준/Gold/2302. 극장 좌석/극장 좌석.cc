#if 1
#include <iostream>
using namespace std;

int N, M;

bool map[45] = { false, };
int ans[45] = { 0, };


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int tmp;
		cin >> tmp;

		map[tmp] = true;
	}

	ans[0] = 1;
	ans[1] = 1;

	int cnt = 2;

	while (cnt <= N)
	{
		if (map[cnt])
			ans[cnt] = ans[cnt - 1];
		else if (map[cnt - 1])
			ans[cnt] = ans[cnt - 1];
		else
			ans[cnt] = ans[cnt - 1] + ans[cnt - 2];

		cnt++;
	}
	
	cout << ans[N];
}





#endif