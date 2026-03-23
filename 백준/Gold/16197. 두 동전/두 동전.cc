#if 1


#include <iostream>
#include <queue>
#include <string>
using namespace std;

typedef struct _Node
{
	int x_1;
	int y_1;
	int x_2;
	int y_2;
	int cnt;
}Node;

queue<Node>q;
bool visit[21][21][21][21] = { false, };
bool map[21][21] = { false, };
int dir[4][2]= { {1,0},{-1,0},{0,-1},{ 0,1 } };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int N, M;
	cin >> N >> M;
	int start_p[2][2];
	int start_i = 0;

	for (int i = 0; i < N; i++)
	{
		string tmp;
		cin >> tmp;
		for (int j = 0; j < M; j++)
		{
			if (tmp[j] == '#')
				map[j][i] = true;
			else if (tmp[j] == 'o')
			{
				start_p[start_i][0] = j;
				start_p[start_i][1] = i;
				start_i++;
			}
		}
	}

	q.push({ start_p[0][0],start_p[0][1],start_p[1][0],start_p[1][1],0 });
	visit[start_p[0][0]][start_p[0][1]][start_p[1][0]][start_p[1][1]] = true;

	bool find = false;

	while (!q.empty())
	{
		Node cur = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int n_x1, n_y1, n_x2, n_y2;
			n_x1 = cur.x_1 + dir[i][0];
			n_y1 = cur.y_1 + dir[i][1];
			n_x2 = cur.x_2 + dir[i][0];
			n_y2 = cur.y_2 + dir[i][1];

			if (n_x1 < 0 || n_x1 >= M || n_y1 < 0 || n_y1 >= N)
			{
				if (n_x2 < 0 || n_x2 >= M || n_y2 < 0 || n_y2 >= N)
					continue;
				else
				{
					cout << ++cur.cnt;
					find = true;
					break;
				}
			}

			if (n_x2 < 0 || n_x2 >= M || n_y2 < 0 || n_y2 >= N)
			{
				if (n_x1 < 0 || n_x1 >= M || n_y1 < 0 || n_y1 >= N)
					continue;
				else
				{
					cout << ++cur.cnt;
					find = true;
					break;
				}
			}

			if (map[n_x1][n_y1])
			{
				n_x1 = cur.x_1;
				n_y1 = cur.y_1;
			}

			if (map[n_x2][n_y2])
			{
				n_x2 = cur.x_2;
				n_y2 = cur.y_2;
			}

			if (cur.cnt <9 && !visit[n_x1][n_y1][n_x2][n_y2])
			{
				q.push({ n_x1,n_y1,n_x2,n_y2,cur.cnt + 1 });
				visit[n_x1][n_y1][n_x2][n_y2] = true;
			}

		}

		if (find)
			break;

	}

	if (!find)
		cout << "-1";
}



#endif
