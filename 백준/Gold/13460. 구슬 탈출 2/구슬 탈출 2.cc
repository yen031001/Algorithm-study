#if 1

#include <iostream>
#include <queue>
#include <string>
using namespace std;


typedef struct _Node
{
	pair <int, int> r;
	pair <int, int> b;
	int count;
}Node;


bool visit[10][10][10][10] = { false, };
string map[11];
int N, M;
pair<int, int>R;
pair<int, int>B;
pair<int, int>O;

queue<Node>q;

int dir[4][2] = { {0,-1},{0,1},{1,0},{-1,0} };

void bfs()
{
	q.push({ R, B, 0 });
	visit[R.first][R.second][B.first][B.second] = true;

	while (!q.empty())
	{
		Node cur = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int tempR_x=cur.r.first, tempR_y=cur.r.second;
			int tempB_x = cur.b.first, tempB_y = cur.b.second;

			bool out_f = false;
			bool dropR = false;

			while (1)
			{
				bool change = false;

				if (tempR_x != -1)
				{
					if (map[tempR_x + dir[i][0]][tempR_y + dir[i][1]] != '#' && ((tempR_x + dir[i][0] != tempB_x) || (tempR_y + dir[i][1] != tempB_y)))
					{
						tempR_x = tempR_x + dir[i][0];
						tempR_y = tempR_y + dir[i][1];

						if (tempR_x == O.first && tempR_y == O.second)
						{
							dropR = true;
							tempR_x = -1;
							tempR_y = -1;
						}

						change = true;
					}

				}
				
				if (map[tempB_x + dir[i][0]][tempB_y + dir[i][1]] != '#' && ((tempR_x!= tempB_x + dir[i][0]) || (tempR_y != tempB_y + dir[i][1])))
				{
					tempB_x = tempB_x + dir[i][0];
					tempB_y = tempB_y + dir[i][1];
					if (tempB_x == O.first && tempB_y == O.second)
					{
						out_f = true;
						break;
					}

					change = true;
				}

				if (!change)
					break;
				
			}

			if (out_f)
				continue;

			if (dropR)
			{
				cout << cur.count + 1;
				return;
			}

			if (cur.count == 9)
				continue;

			if (!visit[tempR_x][tempR_y][tempB_x][tempB_y])
			{
				visit[tempR_x][tempR_y][tempB_x][tempB_y] = true;
				q.push({ { tempR_x,tempR_y }, { tempB_x,tempB_y }, cur.count + 1 });
			}


		}
	}

	cout << "-1";
}

int main()
{
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		cin >> map[i];
		for (int j = 0; j < M; j++)
		{
			if (map[i][j] == 'R')
				R = { i, j };
			else if (map[i][j] == 'B')
				B = { i,j };
			else if (map[i][j] == 'O')
				O = { i,j };
		}
	}

	
	bfs();

}


#endif