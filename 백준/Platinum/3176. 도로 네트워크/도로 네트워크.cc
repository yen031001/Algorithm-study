#if 1
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector <pair<int,int>> child[100005];
bool flag[100005];
int depth[100005];
int sparse[18][100005][3] = {0,}; //0은 직전 노드 1은 그걸 잇는 weight
queue<pair<int,int>>q;

int MIN(int a, int b)
{
	if (a < b)
		return a;
	else
		return b;
}

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

	int N;
	cin >> N;


	for (int i = 0; i < N - 1; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;

		child[a].push_back(pair<int, int>(b, c));
		child[b].push_back(pair<int, int>(a, c));
	}

	flag[1] = true;

	for (int i = 0; i < child[1].size(); i++)
	{
		int next_node = child[1][i].first;
		int next_weight = child[1][i].second;
		q.push(pair<int, int>(next_node, next_weight));
		depth[next_node] = 1;
		flag[next_node] = true;
		sparse[0][next_node][0] = 1;
		sparse[0][next_node][1] = next_weight;
		sparse[0][next_node][2] = next_weight;
	}

	while (!q.empty())
	{
		int cur_node = q.front().first;
		int cur_weight = q.front().second;
		q.pop();

		for (int i = 0; i < child[cur_node].size(); i++)
		{
			int next_node = child[cur_node][i].first;
			int next_weight = child[cur_node][i].second;
			if (flag[next_node])
				continue;
			q.push(pair<int, int>(next_node, next_weight));
			depth[next_node] = depth[cur_node]+1;
			flag[next_node] = true;
			sparse[0][next_node][0] = cur_node;
			sparse[0][next_node][1] = next_weight;
			sparse[0][next_node][2] = next_weight;
		}

	}

	for (int i = 0; i < 17; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			sparse[i + 1][j][0] = sparse[i][sparse[i][j][0]][0];

			int min_w = MIN(sparse[i][j][1], sparse[i][sparse[i][j][0]][1]);
			int max_w = MAX(sparse[i][j][2], sparse[i][sparse[i][j][0]][2]);
			sparse[i + 1][j][1] = min_w;
			sparse[i + 1][j][2] = max_w;
		}
	}

	int M;
	cin >> M;

	for (int c = 0; c < M; c++)
	{
		int A, B;
		cin >> A >> B;
		if (A == 9)
		{
			int dumi = 0;
		}
		int ans, ans_min=1000005, ans_max=0;

		if (depth[A] < depth[B])
		{
			int temp = A;
			A = B;
			B = temp;
		}

		int before_A;

		int diff = depth[A] - depth[B];

		if (diff != 0) //시작 높이 조정 ->이진수 나누기
		{
			int tmp_diff = diff;
			int idx = 0;
			while (diff != 0)
			{
				if (diff % 2)
				{
					before_A = A;
					ans_min = MIN(sparse[idx][A][1], ans_min);
					ans_max = MAX(sparse[idx][A][2], ans_max);
					A = sparse[idx][A][0];
				}
				diff = diff / 2;
				idx++;
			}
		}

		if (A == B)
		{
			ans = A;
			ans_min = MIN(sparse[0][before_A][1],ans_min);
			ans_max = MAX(sparse[0][before_A][2],ans_max);
			cout <<  ans_min << ' ' << ans_max << "\n";
			continue;
		}

		int tmp_min, tmp_max;
		for (int i = 17; i >= 0; i--)
		{
			if (sparse[i][A][0] != sparse[i][B][0])
			{
		
				tmp_min = MIN(sparse[i][A][1], sparse[i][B][1]);
				tmp_max = MAX(sparse[i][A][2], sparse[i][B][2]);

				ans_min = MIN(ans_min, tmp_min);
				ans_max = MAX(ans_max, tmp_max);
				A = sparse[i][A][0];
				B = sparse[i][B][0];
			}
		}


		ans = sparse[0][A][0];
		tmp_min = MIN(sparse[0][A][1], sparse[0][B][1]);
		tmp_max = MAX(sparse[0][A][2], sparse[0][B][2]);
		ans_min = MIN(ans_min, tmp_min);
		ans_max = MAX(ans_max, tmp_max);

		cout <<ans_min << ' ' << ans_max << "\n";

	}

}



#endif