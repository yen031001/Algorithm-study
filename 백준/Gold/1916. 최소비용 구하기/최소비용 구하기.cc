#if 1

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX 1000000000

vector<pair<int,int>>city[1005];
int dist[1005] = { 0, };
priority_queue<pair<int, int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;

		city[a].push_back(pair<int, int>(b, c));
	}

	int dept, dest;
	cin >> dept >> dest;

	for (int i = 0; i <= N; i++)
	{
		dist[i] = MAX;
	}

	
	pq.push(pair<int, int>(0, dept));
	dist[dept] = 0;


	while (!pq.empty())
	{
		int cur = pq.top().second;
		int w = pq.top().first;
		pq.pop();

		if (w > dist[cur])
			continue;

		for (int i = 0; i < city[cur].size(); i++)
		{
			int nxt = city[cur][i].first;
			int weight = city[cur][i].second;
			int tmp = weight + dist[cur];

			if (tmp < dist[nxt])
			{
				dist[nxt] = tmp;
				pq.push(pair<int, int>(dist[nxt], nxt));
			}

		}


	}

	cout << dist[dest];
}



#endif