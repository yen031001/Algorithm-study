#if 1

#include <iostream>
using namespace std;

int INTMAX = 1000000005;

int dist[405][405] = { 0, };


int MIN(int a, int b)
{
	if (a < b)
		return a;
	else
		return b;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	int V, E;

	cin >> V >> E;

	for (int i = 0; i < 405; i++)
	{
		for (int j = 0; j < 405; j++)
			dist[i][j] = INTMAX;
	}

	for (int i = 0; i < E; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		dist[a][b] = c;
	}

	for (int k = 1; k <= V; k++)
	{
		for (int i = 1; i <= V; i++)
		{
			for (int j = 1; j <= V; j++)
			{
				if (dist[i][k] != INTMAX && dist[k][j] != INTMAX)
					dist[i][j] = MIN(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}

	int ans = INTMAX;

	for (int i = 1; i <= V; i++)
	{
		ans = MIN(ans, dist[i][i]);
	}


	if (ans == INTMAX)
		cout << "-1";
	else
		cout << ans;


}



#endif