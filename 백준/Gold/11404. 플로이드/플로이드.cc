#if 1
#include <iostream>
#include <climits>
using namespace std;


int N, M;
int dist[105][105];

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
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			dist[i][j] = INT_MAX;

		}
	}

	for (int i = 1; i <= N; i++)
	{
		dist[i][i] = 0;
	}
	
	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;

		if(c<dist[a][b])
			dist[a][b] = c;
	}

	for (int k = 1; k <= N; k++)
	{
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{

				if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX)
					dist[i][j] = MIN(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	


	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (dist[i][j] == INT_MAX)
				cout << "0 ";
			else 
				cout << dist[i][j] << ' ';
		}
		cout << "\n";
	}


}

#endif