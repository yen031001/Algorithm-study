#if 1

#include <iostream>
using namespace std;

int max_tree[262145] = { 0, };
int min_tree[262145] = { 0, };
int leaf_start = 131072;

int N, M;
int BIG = 1000000005;

int Is_Max(int a, int b)
{
	if (a > b)
		return a;
	else
		return b;
}

int Is_Min(int a, int b)
{
	if (a < b)
		return a;
	else
		return b;
}

pair<int, int> find(int a, int b)
{
	int left_max = max_tree[a], right_max = max_tree[b];
	int left_min = min_tree[a], right_min = min_tree[b];
	while (a <= b)
	{
		if (a % 2 != 0)
		{
			left_max = Is_Max(left_max, max_tree[a]);
			left_min = Is_Min(left_min, min_tree[a]);
			a++;
		}
		a /= 2;

		if (b % 2 == 0)
		{
			right_max = Is_Max(right_max, max_tree[b]);
			right_min = Is_Min(right_min, min_tree[b]);
			b--;
		}
		b /= 2;

	}

	int f_min = Is_Min(right_min, left_min);
	int f_max = Is_Max(right_max, left_max);

	return pair<int, int>(f_min, f_max);

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = leaf_start; i < 262145; i++)
	{
		min_tree[i] = BIG;
	}

	for (int i = 0; i < N; i++)
	{
		int tmp;
		cin >> tmp;
		max_tree[leaf_start + i] = tmp;
		min_tree[leaf_start + i] = tmp;
	}

	for (int i = leaf_start - 1; i > 0; i--)
	{
		max_tree[i] = Is_Max(max_tree[i * 2], max_tree[i * 2 + 1]);
		min_tree[i] = Is_Min(min_tree[i * 2], min_tree[i * 2 + 1]);
	}


	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		pair<int, int> ans;

		ans = find(a + leaf_start - 1, b + leaf_start - 1);

		cout << ans.first << ' ' << ans.second << "\n";
	}

}

#endif