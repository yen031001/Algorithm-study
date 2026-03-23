#if 1

#include <iostream>
using namespace std;

#include <queue>
#include <string>

typedef struct Node_
{
	int x, y;
	int time;
}Node;

pair<int, int> J;
pair<int, int> F;
queue<Node>q;

int R, C;
int dir[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
int map[1005][1005] = { 0, };
int fire[1005][1005] = { 0, };

int main()
{
	cin >> R >> C;
	string tmp;
	int ans = -1;

	for (int i = 0; i < R; i++)
	{
		cin >> tmp;
		for (int j = 0; j < C; j++)
		{
			fire[i][j] = -1;
			if (tmp[j] == '#')
				map[i][j] = -1; //벽이면 map에 -1
			else if (tmp[j] == 'J')
			{
				J.first = i;
				J.second = j;
			}
			else if (tmp[j] == 'F')
			{
				q.push({ i,j,0 });
				fire[i][j] = 0;
			}

		}
	}

	// 불지도 만들기
	Node fire_cur;
	while (!q.empty())
	{
		fire_cur = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			Node fire_nxt;
			fire_nxt.x = fire_cur.x + dir[i][0];
			fire_nxt.y = fire_cur.y + dir[i][1];
			fire_nxt.time = fire_cur.time + 1;

			if (fire_nxt.x < 0 || fire_nxt.x >= R || fire_cur.y < 0 || fire_cur.y >= C)
				continue;

			if (map[fire_nxt.x][fire_nxt.y] == -1)
				continue;
			
			if (fire[fire_nxt.x][fire_nxt.y] != -1)
				continue;
			else
			{
				fire[fire_nxt.x][fire_nxt.y] = fire_nxt.time;
				q.push({ fire_nxt.x,fire_nxt.y,fire_nxt.time });
			}

		}
	}

	// 디버깅 불지도 프린트
	/*
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cout << fire[i][j];
		}
		cout << "\n";
	}
	*/


	//bfs
	q.push({ J.first,J.second,0 });
	map[J.first][J.second] = -1; //방문 표시
	Node j_cur;
	while (!q.empty())
	{
		j_cur = q.front();
		q.pop();

		if (j_cur.x == 0 || j_cur.x == (R - 1) || j_cur.y == 0 || j_cur.y == (C - 1))
		{
			ans = j_cur.time;
			break;
		}

		for (int i = 0; i < 4; i++)
		{
			Node j_nxt;
			j_nxt.x = j_cur.x + dir[i][0];
			j_nxt.y = j_cur.y + dir[i][1];
			j_nxt.time = j_cur.time + 1;

			if (j_nxt.x < 0 || j_nxt.x >= R || j_nxt.y < 0 || j_nxt.y >= C)
				continue;

			if (map[j_nxt.x][j_nxt.y] == -1) //이미 방문이나 벽은 못감
				continue;

			if (fire[j_nxt.x][j_nxt.y]!=-1&&fire[j_nxt.x][j_nxt.y] <= j_nxt.time) //불난데 못감
				continue; 

			q.push({ j_nxt.x,j_nxt.y,j_nxt.time });
			map[j_nxt.x][j_nxt.y] = -1; //방문처리

		}
	}

	if (ans >= 0)
		cout << ans+1;
	else
		cout << "IMPOSSIBLE";
}




#endif