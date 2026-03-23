#if 1
#include <iostream>
#include <vector>
#include <queue>

using namespace std;


int N, M;
vector<int>child[505];
int child_num[505] = { 0, };
bool possible[505][505];

void bfs(int i)
{
	bool cango = false;
	bool flag[505] = { false, };

	queue<int>q;

	for (int j = 0; j < child_num[i]; j++)
	{
		q.push(child[i][j]);
		flag[child[i][j]] = true;
		possible[i][child[i][j]] = true;
	}

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for (int k = 0; k < child_num[cur]; k++)
		{
			int next = child[cur][k];
			if (!flag[next])
			{
				q.push(next);
				flag[next] = true;
				possible[i][next] = true;
			}
		}
	}
}

int main()
{
	cin >> N >> M;

	int final = 0;

	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;

		child[a].push_back(b);
		child_num[a]++;
		possible[a][b] = true;
	}

	for (int i = 1; i <= N; i++)
	{
		possible[i][i] = true;
		bfs(i);
	}

	for (int i = 1; i <= N; i++)
	{
		bool cango = true;
		for (int j = 1; j <= N; j++)
		{
			if (!possible[i][j] && !possible[j][i])
			{
				cango = false;
				break;
			}
		}
		if (cango == true)
			final++;
	}
	cout << final;
}



#endif