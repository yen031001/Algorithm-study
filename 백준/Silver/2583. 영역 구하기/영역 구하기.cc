#if 1

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int M, N, K;

int map[105][105] = { 0, };

int num[10050] = { 0, };

int dir[4][2] = { {1,0},{-1,0},{0,-1},{ 0,1 } };

void print_map()
{
	for (int j = M - 1; j >= 0; j--)
	{
		for (int i = 0; i < N; i++)
		{
			cout << map[i][j] << ' ';
		}
		cout << "\n";
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> M >> N >> K;
	
	int ini = 0;
	for (int j = M - 1; j >= 0; j--)
	{
		for (int i = 0; i < N; i++)
		{
			map[i][j] = ini;
			num[ini] = 1;
			ini++;
		}
	}

	for (int i = 0; i < K; i++)
	{
		int a, b, c, d;

		cin >> a >> b >> c >> d;

		for (int x = a; x < c; x++)
		{
			for (int y = b; y < d; y++)
			{
				num[map[x][y]] = 0;
				map[x][y] = -1;
			}
		}
	}

	for (int j = M - 1; j >= 0; j--)
	{
		for (int i = 0; i < N; i++)
		{
			if (map[i][j] == -1)
				continue;


			for (int CNT = 0; CNT <4 ; CNT++)
			{
				int n_x, n_y;

				n_x = i + dir[CNT][0];
				n_y = j + dir[CNT][1];


				if (n_x < 0 || n_x >= N || n_y < 0 || n_y >= M)
					continue;

				if (map[n_x][n_y] == -1)
					continue;

				if (map[n_x][n_y] != map[i][j])
				{
					if (map[n_x][n_y] < map[i][j])
					{
						num[map[n_x][n_y]] += num[map[i][j]];
						num[map[i][j]] = 0;

						map[i][j] = map[n_x][n_y];
					}
					else
					{
						num[map[i][j]] += num[map[n_x][n_y]];
						num[map[n_x][n_y]] = 0;
						map[n_x][n_y] = map[i][j];
					}
				}
			}
		}
	}

	vector<int>ans;

	for (int i = 0; i < ini; i++)
	{
		if (num[i] != 0)
		{
			ans.push_back(num[i]);
		}
		
	}


	sort(ans.begin(), ans.end());

	cout << ans.size() << "\n";
	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << ' ';
	}


}


#endif