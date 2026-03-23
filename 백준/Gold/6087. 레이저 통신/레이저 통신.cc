#if 1

#include <iostream>
#include <string>
#include <deque>
using namespace std;

int MAXNUM = 1000000000;

typedef struct _Node
{
	int x;
	int y;
	int cur_dir;
	int mirror;
}Node;

int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

int map[105][105] = { 0, };
int visit[105][105][4] = { 0, };
deque<Node>dq;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int W, H;
	pair<int, int>cplace[2];
	int cnum = 0;

	cin >> W >> H;

	for (int i = 0; i < 105; i++)
	{
		for (int j = 0; j < 105; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				visit[i][j][k] = MAXNUM;
			}
		}
	}

	string input;
	for (int i = 0; i < H; i++)
	{
		cin >> input;

		for (int j = 0; j < W; j++)
		{
			if (input[j] == 'C'&&cnum==0)
			{
				cplace[cnum].first = j;
				cplace[cnum].second = i;
				map[j][i] = 1;
				cnum++;
			}
			else if (input[j] == 'C' && cnum == 1)
			{
				cplace[cnum].first = j;
				cplace[cnum].second = i;
				map[j][i] = 2;
				cnum++;
			}
			else if (input[j] == '*')
			{
				map[j][i] = -1;
			}
		}
	}

	bool find = false;

	for (int i = 0; i < 4; i++)
	{
		int nxt_x = cplace[0].first + dir[i][0];
		int nxt_y = cplace[0].second + dir[i][1];
		if (nxt_x >= W || nxt_y >= H || nxt_x < 0 || nxt_y < 0||map[nxt_x][nxt_y]==-1)
		{
			continue;
		}
		else if(map[nxt_x][nxt_y]==2)
		{
			cout << "0";
			find = true;
			break;
		}
		visit[nxt_x][nxt_y][i] = 0;
		dq.push_front({ nxt_x,nxt_y,i,0 });
	}

	if (!find)
	{
		while (!dq.empty())
		{
			Node cur = dq.front();
			dq.pop_front();

			if (map[cur.x][cur.y] == 2) {
				cout << cur.mirror;
				return 0;
			}

			if (cur.mirror > visit[cur.x][cur.y][cur.cur_dir])
			{
				continue;
			}

			for (int i = 0; i < 4; i++)
			{
				if (i == (cur.cur_dir ^ 1))
				{
					continue;
				}


				int nxt_x = cur.x + dir[i][0];
				int nxt_y = cur.y + dir[i][1];
				int mirror_cnt=cur.mirror;

				if (cur.cur_dir != i)
					mirror_cnt++;

				if (nxt_x >= W || nxt_y >= H || nxt_x < 0 || nxt_y < 0 || map[nxt_x][nxt_y] == -1||map[nxt_x][nxt_y]==1)
				{
					continue;
				}


				if (mirror_cnt < visit[nxt_x][nxt_y][i])
				{
					visit[nxt_x][nxt_y][i] = mirror_cnt;
					if (mirror_cnt != cur.mirror)
						dq.push_back({ nxt_x,nxt_y,i,mirror_cnt });
					else
						dq.push_front({ nxt_x,nxt_y,i,mirror_cnt });
				}
			}
		}
	}


	
}


#endif