#if 1

#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

struct Node
{
	int x, y;
};

int N, M;
int house_num = 0;
int chicken_num = 0;
Node house[51 * 51];
Node chicken[51 * 51];
Node select_chicken[15];
bool c_flag[51*51];
int min_city=1000000000;

int find_distance()
{
	int* min_distance;
	int city=0;
	min_distance = (int*)malloc(house_num * sizeof(int));

	int temp = 0;
	
	for (int j = 0; j < house_num; j++)
	{
		min_distance[j] = abs(house[j].x - select_chicken[0].x) + abs(house[j].y - select_chicken[0].y);
	}

	for (int i = 1; i < M; i++)
	{
		for (int j = 0; j < house_num; j++)
		{
			temp = abs(house[j].x - select_chicken[i].x) + abs(house[j].y - select_chicken[i].y);
			if (temp < min_distance[j])
				min_distance[j] = temp;
		}
		
	}

	for (int i = 0; i < house_num; i++)
	{
		city = city + min_distance[i];
	}
	free(min_distance);

	return city;
}

void dfs_chicken(int depth,int min)
{
	if (depth == M)
	{
		int temp = find_distance();
		if (temp < min_city)
			min_city = temp;
		return;
	}

	for (int i = min; i < chicken_num; i++)
	{
		if (c_flag[i])continue;
		select_chicken[depth] = chicken[i];
		c_flag[i] = true;
		dfs_chicken(depth + 1, i);
		c_flag[i] = false;
	}
}

int main()
{
	cin >> N >> M;
	int temp;
	
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> temp;
			if (temp == 0)
			{
			}
			else if (temp == 1)
			{
				house[house_num].x = i;
				house[house_num].y = j;
				house_num++;
			}
			else if (temp == 2)
			{
				chicken[chicken_num].x = i;
				chicken[chicken_num].y = j;
				chicken_num++;
			}
		}
	}

	dfs_chicken(0, 0);

	cout << min_city << endl;
}

#endif