#if 1
#include <iostream>
using namespace std;

#include <queue>
#include <vector>

typedef struct Node_
{
	int first, second, time;
}Node;

int map[1005][1005] = { 0, };
bool visit[1005][1005] = { false, };
int M, N;
int dir[4][2] = { {1,0},{-1,0},{0,-1},{0,1} };

queue<Node>q;

void print_map()
{
	for (int n = 0; n < N; n++)
	{
		for (int m = 0; m < M; m++)
			cout << map[m][n] << ' ';
		cout << "\n";
	}
}
int main()
{
	cin >> M >> N;
	int tmp;
	int cnt = 0;
	int complete_cnt=0;
	int max_time = 0;

	for (int j = 0; j < N; j++)
	{
		for (int i = 0; i < M; i++)
		{
			cin >> tmp;
			map[i][j] = tmp;
			if (tmp != (-1))
				cnt++;
			if (tmp == 1)
			{
				q.push({ i,j,0 });
				visit[i][j] = true;
				complete_cnt++;
			}
		}

	}

	//print_map();

	Node cur;

	if (complete_cnt == cnt)
		cout << 0;
	else
	{
		while (!q.empty())
		{
			cur = q.front();
			q.pop();

			for (int i = 0; i < 4; i++)
			{
				int x, y;
				x = cur.first + dir[i][0];
				y = cur.second + dir[i][1];

				if (x < 0 || y < 0 || x >= M || y >= N)
					continue;
				
				if (visit[x][y])
					continue;

				if (map[x][y] != (0))
					continue;

				q.push({x,y,cur.time+1});
				visit[x][y] = true;
				complete_cnt++;
				map[x][y] = 1;

				if (cur.time + 1 > max_time)
					max_time = cur.time + 1;
			}

		
		}

		if (complete_cnt != cnt)
			cout << "-1";
		else
			cout << max_time;
	}
}





#endif