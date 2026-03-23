#if 1
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int>Edge[32005];
int reference[32005] = { 0, };
vector<int>ans;
queue<int>q;


int main()
{
	int N, M;

	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;

		Edge[a].push_back(b);
		reference[b]++;
	}


	for (int i = 1; i <= N; i++)
	{
		if (reference[i] != 0)
			continue;
		q.push(i);

	}

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		ans.push_back(cur);

		for (int i = 0; i < Edge[cur].size(); i++)
		{
			int next = Edge[cur][i];
			if((reference[next]-1)==0)
				q.push(next);
			reference[next]--;
		}
	}

	for (int i = 0; i < N; i++)
	{
		cout << ans[i] << ' ';
	}
}



#endif