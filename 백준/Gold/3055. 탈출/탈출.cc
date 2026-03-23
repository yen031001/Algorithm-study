#include <iostream>
#include <utility>
#include <queue>
using namespace std;

int R, C;
char map[50 * 50];
int start[2];
int dest[2];
int way = 0;

struct Item {
	int r, c;
	int type; 
	int depth;
};

queue<Item>q;


int dir[4][2] = { {0,-1},{0,1},{1,0},{-1,0} };

void bfs()
{
	q.push({ start[0],start[1],1,0});
	way = way + 1;
	while (!q.empty())
	{
		if (way == 0)
			break;
		Item now=q.front();
		q.pop();

		if (now.type == 0)
		{
			for (int i = 0; i < 4; i++)
			{
				int newR = now.r + dir[i][0];
				int newC = now.c + dir[i][1];

				if (newR < 0 || newR >= R || newC < 0 || newC >= C) continue;
				if (newR == dest[0] && newC == dest[1]) continue;
				if (map[newR*C + newC] == '*') continue;
				if (map[newR*C + newC] == 'X') continue;
				if (map[newR*C + newC] == 'V') continue;
				map[newR*C + newC] = '*';
				q.push({ newR,newC,0,now.depth+1 });
			}
		}
		else if (now.type == 1)
		{
			way = way - 1;
			
			for (int i = 0; i < 4; i++)
			{
				int newR = now.r + dir[i][0];
				int newC = now.c + dir[i][1];

				if (newR < 0 || newR >= R || newC < 0 || newC >= C) continue;
				if (newR == dest[0] && newC == dest[1])
				{
					cout << now.depth+1;
					return;
				}
				if (map[newR*C + newC] == '.')
				{
					q.push({ newR,newC,1,now.depth + 1 });
					map[newR*C + newC] = 'V';
					way = way + 1;
				}
					
			}
			
		}

	}
	cout << "KAKTUS";
}




int main()
{
	cin >> R >> C;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cin >> map[i*C + j];
			if (map[i*C + j] == 'S')
			{
				start[0] = i;
				start[1] = j;
			}
			else if (map[i*C + j] == 'D')
			{
				dest[0] = i;
				dest[1] = j;
			}
			else if (map[i*C + j] == '*')
			{
				q.push({ i,j,0,0 });
			}
		}
	}

	bfs();
}
