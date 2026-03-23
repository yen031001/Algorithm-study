#if 1

#include <iostream>
#include <vector>

using namespace std;

vector<int> line[52];
int N, M;
int dir[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
long long num_max[51][51];
bool visit[51][51];
bool circle = false;

long long find_max(long long a, long long b)
{
	if (a > b)
		return a;
	else
		return b;
}

long long dfs(int x, int y)
{
	if (x >= N ||y >= M || x < 0 || y < 0)
		return 0;
	else if (line[x][y] == -1)
		return 0;
	else if (visit[x][y] == true)
	{
		circle = true;
		return 0;
	}
	else if (num_max[x][y] != -1)
		return num_max[x][y];

	visit[x][y] = true;

	for (int i = 0; i < 4; i++)
	{
		int nextX = x + (dir[i][0] * line[x][y]);
		int nextY = y + (dir[i][1] * line[x][y]);
		num_max[x][y] = find_max(num_max[x][y],dfs(nextX, nextY)+1);
	}
	visit[x][y] = false;

	return num_max[x][y];
}

int main()
{
	cin >> N >> M;
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			char temp;
			cin >> temp;
			if (temp == 'H')
				line[i].push_back(-1);
			else
				line[i].push_back(temp - '0');

			num_max[i][j] = -1;
		}

	}


	dfs(0, 0);
	if (circle)
		cout << "-1";
	else
		cout << num_max[0][0];
}





#endif