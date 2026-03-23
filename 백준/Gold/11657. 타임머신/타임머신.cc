#if 1
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX  1000000000000

typedef struct _Edge
{
	int start;
	int end;
	int weight;
}Edge;

int N, M;
vector<Edge>edge;
long long dist[505];
long long original[505];
long long r_dist[505];
bool round_flag = false;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		dist[i] = MAX;
		original[i] = MAX;
	}

	for (int i = 0; i < M; i++)
	{
		int a, b, c;

		cin >> a >> b >> c;

		edge.push_back({ a, b, c });
	}


	dist[1]= 0;
	original[1] = 0;

	for (int i = 1; i < N; i++)
	{

		for (int j = 0; j < M; j++)
		{
			int s = edge[j].start;
			int e = edge[j].end;
			int w = edge[j].weight;

			if (original[s]>=MAX)
				continue;
			if (dist[e] > (original[s] + w))
			{
				dist[e] = original[s] + w;
			}

		}

		for (int p = 1; p <= N; p++)
			original[p] = dist[p];

	}

	for (int i = 1; i <= N; i++)
	{
		r_dist[i] = dist[i];
	}


	for (int j = 0; j < M; j++)
	{
		int s = edge[j].start;
		int e = edge[j].end;
		int w = edge[j].weight;

		if (original[s] >= MAX)
			continue;
		if (r_dist[e] > (r_dist[s] + w))
		{
			r_dist[e] = r_dist[s] + w;
		}

		if (r_dist[e] != dist[e])
		{
			round_flag = true;
			break;
		}
	}

	
	if(round_flag)
		cout << "-1\n";
	else
	{
		for (int i = 2; i <= N; i++)
		{
			if (dist[i] == MAX)
				cout << "-1\n";
			else
				cout << dist[i] << "\n";
		}
	}

	
}

#endif