#if 1

#include <iostream>
#include <queue>
using namespace std;

typedef struct _Node
{
	int clip;
	int screen;
	int t;
}Node;

queue<Node>q;
int S;
bool visit[1005][1005] = {false,};

void bfs()
{
	q.push({ 1,1,1 });

	while (!q.empty())
	{
		Node cur = q.front();
		q.pop();

		int next_c, next_s, next_t;

		next_t = cur.t + 1;

		if (cur.clip != cur.screen && cur.screen<1001)
		{
			next_c = cur.screen;
			if (!visit[cur.screen][next_c])
			{
				visit[cur.screen][next_c] = true;
				q.push({ next_c,cur.screen,next_t });
			}
		}

		
		if (cur.screen < S)
		{
			next_s = cur.screen + cur.clip;
			if (next_s == S)
			{
				cout << next_t;
				break;
			}
			else
			{
				if (next_s<1005&&!visit[next_s][cur.clip])
				{
					visit[next_s][cur.clip] = true;
					q.push({ cur.clip,next_s,next_t });
				}
			}
		}
		

		if (cur.screen != 0)
		{
			next_s = cur.screen-1;

			if (next_s == S)
			{
				cout << next_t;
				break;
			}
			else
			{
				if (!visit[next_s][cur.clip])
				{
					visit[next_s][cur.clip] = true;
					q.push({ cur.clip,next_s,next_t });
				}
			}
		}
		

	}
}

int main()
{
	cin >> S;
	visit[0][0] = true;
	visit[1][0] = true;
	visit[1][1] = true;
	if (S == 1)
		cout << 0;
	else
		bfs();
}



#endif