#if 1

#include <iostream>
#include <queue>
#include <string>
using namespace std;

typedef struct _Pos
{
	int x;
	int y;
	int smash;
	int route;
}Pos;

int N, M, K;
int MIN_ROUTE = 1000000000;
int map[1003][1003] = { 0, };
bool visit[1001][1001][10] = {false,};
int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
queue<Pos>q;

int main()
{
	cin >> N >> M >> K;

	for (int i = 0; i < N; i++)
	{
		string tmp;
		cin >> tmp;

		for (int j = 0; j < M; j++)
		{
			int num = int(tmp[j]) - '0';
			map[i][j] = num;
		}
	}

	q.push({ 0, 0, 0, 1 });
	visit[0][0][0] = true;


	while (!q.empty())
	{
		Pos cur = q.front();
		q.pop();

		if (cur.x == (N - 1) && cur.y == (M - 1))
		{
			if (MIN_ROUTE > cur.route)
				MIN_ROUTE = cur.route;
			continue;
		}

		for (int i = 0; i < 4; i++)
		{
			int nxt_x = cur.x + dir[i][0];
			int nxt_y = cur.y + dir[i][1];

			if (nxt_x < 0 || nxt_y < 0 || nxt_x >= N || nxt_y >= M)
				continue;

			if (visit[nxt_x][nxt_y][cur.smash])
				continue;

			if (map[nxt_x][nxt_y]) //벽일 때
			{
				if (cur.smash < K)
				{
					q.push({ nxt_x,nxt_y,cur.smash + 1,cur.route + 1 });
					visit[nxt_x][nxt_y][cur.smash+1] = true;
				}
			}
			else //벽이 아닐 때
			{
				q.push({ nxt_x,nxt_y,cur.smash,cur.route + 1 });
				visit[nxt_x][nxt_y][cur.smash] = true;
			}
			
		}
	}


	if (MIN_ROUTE != 1000000000)
		cout << MIN_ROUTE;
	else
		cout << -1;

}





#endif