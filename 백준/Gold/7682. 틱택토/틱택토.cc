#if 1

#include <iostream>
#include <string>
using namespace std;




int main()
{
	string sen;


	while (1)
	{	
		cin >> sen;
		if (sen == "end")
			break;
		int map[3][3] = { 0, };
		bool x_three = false;
		bool o_three = false;
		int x_num = 0;
		int o_num = 0;
		int emp = 0;

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (sen[i * 3 + j] == 'X')
				{
					map[i][j] = -1;
					x_num++;
				}
				else if (sen[i * 3 + j] == 'O')
				{
					map[i][j] = 1;
					o_num++;
				}
				else
					emp++;

			}
		}

		if (o_num > x_num)
		{
			cout << "invalid\n";
			continue;
		}
		else if (x_num - o_num > 1)
		{
			cout << "invalid\n";
			continue;
		}
		else
		{
			for (int i = 0; i < 3; i++)
			{
				if (map[i][0] + map[i][1] + map[i][2] == 3)
					o_three = true;
				else if (map[i][0] + map[i][1] + map[i][2] == -3)
					x_three = true;

				if (map[0][i] + map[1][i] + map[2][i] == 3)
					o_three = true;
				else if (map[0][i] + map[1][i] + map[2][i] == -3)
					x_three = true;
			}

			if (map[0][0] + map[1][1] + map[2][2] == 3 || map[2][0] + map[1][1] + map[0][2] == 3)
				o_three = true;
			else if (map[0][0] + map[1][1] + map[2][2] == -3 || map[2][0] + map[1][1] + map[0][2] == -3)
				x_three = true;

			if (o_three && x_three)
			{
				cout << "invalid\n";
				continue;
			}
			else if (o_three)
			{
				if (o_num < x_num)
				{
					cout << "invalid\n";
					continue;
				}
			}
			else if(!x_three)
			{
				if (emp)
				{
					cout << "invalid\n";
					continue;
				}
			}
			else
			{
				if (o_num == x_num)
				{
					cout << "invalid\n";
					continue;
				}
			}
		}
		cout << "valid\n";
	}
}



#endif