#if 1
#include <iostream>
#include <algorithm>
using namespace std;

typedef struct _Edge
{
	int start, end;
	int cost;
}Edge;

int node[1005] = { 0, };
Edge edge[1000005];
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

void union_node(int a, int b)
{
	a = find(a);
	b = find(b);
	node[b] = a;
}

bool op_edge(const Edge &a,const Edge &b)
{
	return a.cost < b.cost;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	int cost = 0;


	for (int i = 0; i <= N; i++)
	{
		node[i] = i;
	}

	for (int m = 0; m < M; m++)
	{
		int a, b, c;
		cin >> a >> b >> c;

		edge[m].start = a;
		edge[m].end = b;
		edge[m].cost = c;

	}

	sort(edge, edge + M, op_edge);

	int select_edge = 0;

	for (int i = 0; i < M; i++)
	{
		if (select_edge == N - 1)
			break;

		Edge cur = edge[i];

		if (find(cur.start) != find(cur.end))
		{
			select_edge++;
			cost += cur.cost;
			union_node(cur.start, cur.end);
		}
	}
	
	cout << cost;

}



#endif