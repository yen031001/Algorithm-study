#if 1
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef struct _Node
{
	int x;
	int y;
	int num;
}Node;

int squ[9][9] = { 0, };
int map[9][9] = { 0, };
bool num[27][10] = { false, }; //0-8 9-17 18-26
vector<pair<int, int>>emp;

int find_square(int x, int y)
{
	if (x < 3)
	{
		if (y < 3)
		{
			return 0;
		}
		else if (y < 6)
		{
			return 1;
		}
		else
		{
			return 2;
		}
	}
	else if (x < 6)
	{
		if (y < 3)
		{
			return 3;
		}
		else if (y < 6)
		{
			return 4;
		}
		else
		{
			return 5;
		}
	}
	else
	{
		if (y < 3)
		{
			return 6;
		}
		else if (y < 6)
		{
			return 7;
		}
		else
		{
			return 8;
		}
	}
}

bool dfs(int idx)
{
	if (idx==emp.size())
	{
		return true;
	}

	pair<int, int>cur = emp[idx];
	bool pos_num[10] = { false, };
	vector<int>try_num;
	for (int i = 1; i < 10; i++)
	{
		if (!num[cur.first][i])
			pos_num[i] = true;

		if(!num[9+cur.second][i]&&pos_num[i])
			pos_num[i] = true;
		else
			pos_num[i] = false;

		if(!num[18+squ[cur.first][cur.second]][i] && pos_num[i])
			pos_num[i] = true;
		else
			pos_num[i] = false;

		if(pos_num[i])
			try_num.push_back(i);

	}

	if (!try_num.size())
		return false;
	
	for (int a=0;a<try_num.size();a++)
	{
		int i = try_num[a];
		map[cur.first][cur.second] = i;
		int bf_a = num[cur.first][i];
		int bf_b = num[9 + cur.second][i];
		int bf_c = num[18 + squ[cur.first][cur.second]][i];
		num[cur.first][i] = true;
		num[9 + cur.second][i] = true;
		num[18 + squ[cur.first][cur.second]][i] = true;
		if(dfs(idx+1))
			return true;
		num[cur.first][i] = bf_a;
		num[9 + cur.second][i] = bf_b;
		num[18 + squ[cur.first][cur.second]][i] = bf_c;
		map[cur.first][cur.second] = 0;
	}

	return false;

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	
	int sq;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			int tmp;
			cin >> tmp;

			map[i][j] = tmp;

			if (tmp)
			{
				num[i][tmp] = true;
				num[9 + j][tmp] = true;
				squ[i][j] = find_square(i, j);
				num[18 + squ[i][j]][tmp] = true;
			}
			else
			{
				emp.push_back({ i,j });
				squ[i][j] = find_square(i, j);
			}
		}
	}

	vector<int>not_use[27];

	for (int i = 0; i < 27; i++)
	{
		for (int j = 1; j < 10; j++)
		{
			if (!num[i][j])
			{
				not_use[i].push_back(j);
			}
		}
	}




	dfs(0);

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cout << map[i][j] << ' ';
		}
		cout << "\n";
	}


	
	/*
	for (int i = 0; i < 27; i++)
	{
		cout << i << ": ";
		for (int j = 0; j < not_use[i].size(); j++)
		{
			cout << not_use[i][j]<<' ';
		}
		cout << "\n";
	}

	for (int i = 0; i < emp.size(); i++)
	{
		cout << i+1<<": ("<<emp[i].first << "," << emp[i].second<<")" << "\n";
	}
	*/
	
}



#endif

/*
00 01 02 03 04 05 06 07 08
10 11 12 13 14 15 16 17 18
20 21 22 23 24 25 26 27 28
30 31 32 33 34 35 36 37 38
40 41 42 43 44 45 46 47 48
50 51 52 53 54 55 56 57 58
60 61 62 63 64 65 66 67 68
70 71 72 73 74 75 76 77 78
80 81 82 83 84 85 86 87 88
*/

