#if 1
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int>Edge[100005];
int sparse[18][100005];
int depth[100005] = { 0, };
queue<int>q;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N,M;

	cin >> N;

	for (int i = 0; i < N - 1; i++)
	{
		int a, b;
		cin >> a >> b;

		Edge[a].push_back(b);
		Edge[b].push_back(a);
	}

	depth[1] = 1;
	for (int i = 0; i < Edge[1].size(); i++)
	{
		int next = Edge[1][i];
		depth[next] = depth[1] + 1;
		sparse[0][next] = 1;
		q.push(next);
	}

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		for (int i = 0; i < Edge[cur].size(); i++)
		{
			int next = Edge[cur][i];
			if (depth[next] != 0)
				continue;
			depth[next] = depth[cur] + 1;
			sparse[0][next] = cur;
			q.push(next);
		}
	}

	for (int i = 1; i <= 17; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			sparse[i][j] = sparse[i - 1][sparse[i - 1][j]];
		}
	}

	cin >> M;

	for (int c = 0; c < M; c++)
	{
		int a, b;

		cin >> a >> b;

		if (depth[a] < depth[b])
		{
			int tmp = a;
			a = b;
			b = tmp;
		}

		int diff = depth[a] - depth[b];

		int idx = 0;
		while (diff != 0)
		{
			if (diff % 2 != 0)
			{
				a = sparse[idx][a];
			}
			idx++;
			diff = diff / 2;
		}

		if (a == b)
		{
			cout << a << "\n";
			continue;
		}

		for (int i = 17; i >= 0; i--)
		{
			if (sparse[i][a] == sparse[i][b])
				continue;
			
			a = sparse[i][a];
			b = sparse[i][b];
		}

		a = sparse[0][a];
		cout << a << "\n";
	}

}




#endif