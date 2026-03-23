#if 1

#include <iostream>
using namespace std;
#include <queue>
#include <vector>

typedef struct Node_
{
	int x, y;
	int siz;
}Node;

int N, M;
vector<int> input[505];

queue<Node>q;
bool map[505][505] = {false,}; 
int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
int total_num = 0;
int biggest_size = 0;

int main()
{
	cin >> N >> M;
	int tmp;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> tmp;
			input[i].push_back(tmp);
		}
	}


	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (!map[i][j]&&input[i][j]==1)
			{
				q.push({ i,j,1 });
				map[i][j] = true;
				int cnt = 0;
				while (!q.empty())
				{
					Node cur = q.front();
					q.pop();
					cnt++;
					for (int d = 0; d < 4; d++)
					{	
						int nxt_x = cur.x + dir[d][0];
						int nxt_y = cur.y + dir[d][1];
						if (nxt_x < 0 || nxt_x >= N|| nxt_y < 0 || nxt_y >= M)
							continue;
						if (!map[nxt_x][nxt_y] && input[nxt_x][nxt_y] == 1)
						{
							q.push({ nxt_x,nxt_y,cur.siz + 1 });
							map[nxt_x][nxt_y] = true;
						}

					}
				}
				total_num++;
				if (biggest_size < cnt)
					biggest_size = cnt;
			}
		}
	}


	cout << total_num<<"\n" << biggest_size;
	
}






#endif