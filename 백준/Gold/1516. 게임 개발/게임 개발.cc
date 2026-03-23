#if 1
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;
int building[505];
int total[505];
int flag[505] = { 0, };
int child_size[505] = { 0, };
queue<int>q;
vector<int>child[505];
vector<int>parent[505];


int MAX(int a, int b)
{
	if (a > b)
		return a;
	else
		return b;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	int p_one;

	for (int i = 1; i <= N; i++)
	{
		cin >> building[i];
		total[i] = 50000005;
		while (1)
		{
			int temp;
			cin >> temp;
			if (temp == -1)
				break;
			else
			{
				child[temp].push_back(i);
				parent[i].push_back(temp);
				flag[i]++;
				child_size[temp]++;

			}
		}
	}

	for (int i = 1; i <= N; i++)
	{
		if (flag[i] == 0)
		{
			q.push(i);
			total[i] = building[i];
		}
	}

	while (!q.empty())
	{

		int cur = q.front();
		q.pop();

		for (int i = 0; i < child_size[cur]; i++)
		{
			int next = child[cur][i];
			flag[next]--;
			if (flag[next] == 0)
			{
				int max = 0;
				q.push(next);
				for (int j = 0; j < parent[next].size(); j++)
				{
					max = MAX(max, total[parent[next][j]]);
				}
				total[next] = max + building[next];
			}
		}
	}


	for (int i = 1; i <= N; i++)
	{
		cout << total[i] << "\n";
	}
}



#endif