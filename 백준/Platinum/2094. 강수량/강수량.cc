#if 1
#include <iostream>
#include <algorithm>
using namespace std;

typedef struct _Rain
{
	int rain_much;
	int year;
}Rain;


int N, M;
Rain tree[131072] = { 0, };
int year[50005] = { 0, };
int start_leaf = 65536;
int idx = 0;  //leaf 개수
int MIN, MAX;

int find_max(int a, int b)
{
	if (tree[a].rain_much > tree[b].rain_much)
		return a;
	else
		return b;
}

bool tree_max(int x, int y,int limit)
{
	while (x <= y )
	{
		if (x % 2 != 0)
		{
			if (limit <= tree[x].rain_much)
				return false;
			x++;
		}

		if (y % 2 == 0)
		{
			if (limit <= tree[y].rain_much)
				return false;
			y--;
		}
		x = x / 2;
		y = y / 2;

	}

	return true;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int temp_year, temp_rain;
		cin >> temp_year >> temp_rain;
		idx++;
		int tree_idx = start_leaf + idx - 1;
		tree[tree_idx].year = temp_year;
		tree[tree_idx].rain_much = temp_rain;
		year[i] = temp_year;
	}

	for (int i = start_leaf - 1; i >= 1; i--)
	{
		int big = find_max(i * 2, i * 2 + 1);
		tree[i].year = tree[big].year;
		tree[i].rain_much = tree[big].rain_much;
	}

	cin >> M;
	int X ,Y;
	int x_min;
	int y_max;
	for (int i = 0; i < M; i++)
	{
		cin >> Y >> X;


		int x_find = upper_bound(year,year+N,X)-year;
		
		x_find--;
		
		int y_find=lower_bound(year, year + N, Y) - year;
		
		int x_idx = start_leaf + x_find;
		int y_idx= start_leaf + y_find;

		if(x_find<0)
		{
			cout << "maybe\n";
			continue;
		}
		
		if (tree[x_idx].year !=X && tree[y_idx].year != Y)
		{
			cout << "maybe\n";
			continue;
		}
		else if (tree[x_idx].year !=X)
		{
			if (tree_max(y_idx + 1, x_idx, tree[y_idx].rain_much))
			{
				cout << "maybe\n";
				continue;
			}
			else
			{
				cout << "false\n";
				continue;
			}
		}
		else if (tree[y_idx].year !=Y)
		{
			if (tree_max(y_idx, x_idx - 1, tree[x_idx].rain_much))
			{
				cout << "maybe\n";
				continue;
			}
			else
			{
				cout << "false\n";
				continue;
			}
		}
		else
		{
			if (tree[x_idx].rain_much > tree[y_idx].rain_much)
			{
				cout << "false\n";
				continue;
			}
			else if((tree[x_idx].year- tree[y_idx].year)==(x_idx-y_idx))
			{
				if (tree_max(y_idx + 1, x_idx - 1, tree[x_idx].rain_much))
				{
					cout << "true\n";
					continue;
				}
				else
				{
					cout << "false\n";
					continue;
				}
			}
			else
			{
				if (tree_max(y_idx + 1, x_idx - 1, tree[x_idx].rain_much))
				{
					cout << "maybe\n";
					continue;
				}
				else
				{
					cout << "false\n";
					continue;
				}
			}
		}
	}

}
#endif