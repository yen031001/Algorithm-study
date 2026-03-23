#if 1
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX 10000000

int V, E;
int start;
vector<pair<int, int>>Edge[20005];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
int dist[20005];
bool visit[20005];


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> V >> E;
	cin >> start;

	for (int i = 0; i <= V; i++)
	{
		dist[i] = MAX;
	}

	for (int i = 0; i < E; i++)
	{
		int a, b, c;

		cin >> a >> b >> c;

		Edge[a].push_back(pair<int, int>(b, c));
	}

	q.push(pair<int, int>(0, start));
	dist[start] = 0;
	while (!q.empty())
	{
		int cur = q.top().second;
		int w = q.top().first;
		q.pop();

		if (w > dist[cur])
			continue;

		for (int i = 0; i < Edge[cur].size();i++)
		{
			int next_node = Edge[cur][i].first;
			int weight = Edge[cur][i].second;

			int temp = weight + dist[cur];

			if (temp < dist[next_node])
			{
				dist[next_node] = temp;
				q.push(pair<int, int>(dist[next_node], next_node));
			}
			
		}
	}


	for (int i = 1; i <= V; i++)
	{
		if (dist[i] == MAX)
			cout << "INF\n";
		else
			cout << dist[i] << "\n";
	}
}

#endif