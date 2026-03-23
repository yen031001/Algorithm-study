#if 1
#include <iostream>
using namespace std;

int N, M;

pair<int, int> appli[105];   //메모리 바이트 , cost
int cost[2][10005] = { 0, };
int total_cost = 0;
int total_byte = 0;
int MIN = 200000;

int main()
{
	cin >> N >> M;

	for (int i = 1; i <= N; i++)  //memory byte
	{
		cin >> appli[i].first;
		total_byte += appli[i].first;
	}

	for (int i = 1; i <= N; i++)  //cost
	{
		cin >> appli[i].second;
		total_cost += appli[i].second;
	}


	int idx = 1;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j <= total_cost; j++)
		{
			cost[idx][j] = cost[1 - idx][j];
		}
		int b = appli[i].first;
		int c = appli[i].second;
		if (cost[1 - idx][c] < b)
		{
			cost[idx][c] = b;
			if (cost[idx][c] >= M)
			{
				if(c<MIN)
					MIN = c;
			}

		}

		for (int j = 0; j <=total_cost; j++)
		{
			if (j + c > total_cost)
				break;

			if (cost[1 - idx][j] != 0)
			{
				if (cost[1 - idx][j + c] < cost[1 - idx][j] + b)
					cost[idx][j + c] = cost[1 - idx][j] + b;
				else
					cost[idx][j + c] = cost[1 - idx][j + c];
				if (cost[idx][j + c] >= M)
				{
					if(j+c<MIN)
						MIN = j + c;
				}
			}
		}
		idx = 1 - idx;
	}

	cout << MIN;


}



#endif