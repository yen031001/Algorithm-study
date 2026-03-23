#if 1

#include <iostream>
using namespace std;

int map[105][105][2][2] = { 0, };    //int [h][w]

int main()
{
	int w, h;
	cin >> w >> h;

	for (int i = 1; i <= h; i++)
	{
		map[i][1][1][1] = 1;
	}

	for (int i = 1; i <= w; i++)
	{
		map[1][i][0][1] = 1;
	}

	int temp = 0;
	for (int i = 2; i <= h; i++)
	{
		for (int j=2; j <= w; j++)
		{
			map[i][j][0][0] = map[i][j - 1][1][1];   //아꺾=왼S
			map[i][j][0][1] = (map[i][j - 1][0][1] + map[i][j - 1][0][0]) % 100000;  //아S=아S+아꺾
			map[i][j][1][0] = map[i - 1][j][0][1];//왼꺾=아S
			map[i][j][1][1]= (map[i - 1][j][1][0]+ map[i - 1][j][1][1]) % 100000;//왼S=왼꺾+왼S
		}
	}

	int result = (map[h][w][0][0] + map[h][w][0][1] + map[h][w][1][0] + map[h][w][1][1])%100000;
	cout << result;
}

#endif