#if 1
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX 1000000000000


int N,M,K;
vector<pair<int, int>>edge[1005];
priority_queue<int>prev_dist[1005];
priority_queue<pair<int,int>,vector<pair<int, int>>,greater<pair<int, int>>>q;

int main()
{
	cin >> N >> M >> K;

	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		edge[a].push_back({ c,b });

	}

	q.push(pair<long long, long long>(0, 1));
	prev_dist[1].push(0);

	while (!q.empty())
	{
		long long cur = q.top().second;
		long long cur_weight = q.top().first;
		q.pop();

		for (int i = 0; i < edge[cur].size(); i++)
		{
			int next = edge[cur][i].second;
			int next_weight = edge[cur][i].first;
			int cost = cur_weight + next_weight;

			if (prev_dist[next].size() == K && cur_weight+next_weight<prev_dist[next].top())
			{
				prev_dist[next].pop();
				prev_dist[next].push(cost);
				q.push(pair<long long, long long>(cost, next));
			}
			else if(prev_dist[next].size()< K)
			{
				prev_dist[next].push(cost);
				q.push(pair<long long, long long>(cost, next));
			}

		}
	}



	
	
	for (int i = 1; i <= N; i++)
	{
		if (prev_dist[i].size() < K)
			cout<<"-1\n";
		else
			cout << prev_dist[i].top() << "\n";
	}


}




#endif