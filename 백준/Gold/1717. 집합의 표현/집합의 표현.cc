#if 1
#include <iostream>
using namespace std;

int node[1000005] = { 0, };
int N, M;

int find(int p)
{
	if (node[p] == p)
		return p;
	else
	{
		return node[p] = find(node[p]);
	}
		
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;


	for (int i = 0; i <= N; i++)
	{
		node[i] = i;
	}

	for (int m = 0; m < M; m++)
	{
		int a, b, c;


		cin >> a >> b >> c;

		if (a == 0) //합
		{
			if (b == c)
				continue;
			b = find(b);
			c = find(c);
			node[b] = c;

		}
		else if (a == 1) //출력
		{
			int b_p, c_p;

			b_p = find(b);
			c_p = find(c);

			if (c_p == b_p)
				cout << "YES\n";
			else
				cout << "NO\n";
		}
	}
}



#endif