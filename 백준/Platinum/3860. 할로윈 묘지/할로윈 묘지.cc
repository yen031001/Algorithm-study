#if 1
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX  1000000000000

typedef struct _Edge
{
	int start_x;
	int start_y;
	int end_x;
	int end_y;
	int weight;
}Edge;

int W,H,G,E;
int dir[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (1)
	{
		cin >> W >> H;
		if (W == 0 && H == 0)
			break;

		vector<Edge>edge;
		long long dist[35][35];
		long long original[35][35]; 
		int EdgeNum = 0;
		int isPoss[35][35] = { 0, };
		bool round_flag = false;
		

		cin >> G;

		for (int i = 0; i < G; i++)
		{
			int a, b;
			cin >> a >> b;
			isPoss[a][b] = -1;
		}

		cin >> E;
		for (int i = 0; i < E; i++)
		{
			int x1, y1, x2, y2, t;
			cin >> x1 >> y1 >> x2 >> y2 >> t;
			isPoss[x1][y1] = 1;
			edge.push_back({ x1,y1,x2,y2,t });
			EdgeNum++;
		}


		for (int i = 0; i < W; i++)
		{
			for (int j = 0; j < H; j++)
			{
				int next_x, next_y;
				if (isPoss[i][j]!=0)
					continue;
				if (i == W - 1 && j == H - 1)
					continue;
				for (int k = 0; k < 4; k++)
				{
					next_x = i + dir[k][0];
					next_y = j + dir[k][1];
					if (next_x < 0 || next_y < 0 || next_x >= W || next_y >= H)
						continue;
					else if (isPoss[next_x][next_y] == -1)
						continue;
					else
					{
						edge.push_back({ i,j,next_x,next_y,1});
						EdgeNum++;
					}
				}
				
			}
		}

		for (int i = 0; i < W; i++)
		{
			for (int j = 0; j < H; j++)
			{
				dist[i][j] = MAX;
				original[i][j] = MAX;
			}
		}

		dist[0][0] = 0;
		original[0][0] = 0;

		int WH = W * H;
		
		for (int i = 1; i < WH; i++)
		{
			for (int j = 0; j < EdgeNum; j++)
			{
				int s_x = edge[j].start_x;
				int s_y = edge[j].start_y;
				int e_x = edge[j].end_x;
				int e_y = edge[j].end_y;
				int w = edge[j].weight;

				if (dist[s_x][s_y] >= MAX)
					continue;
				if (dist[e_x][e_y] > (dist[s_x][s_y] + w))
				{
					dist[e_x][e_y] = dist[s_x][s_y] + w;
				}

			}
		}

		for (int p = 0; p < W; p++)
		{
			for (int q = 0; q < H; q++)
			{
				original[p][q] = dist[p][q];
			}
		}

		for (int j = 0; j < EdgeNum; j++)
		{
			int s_x = edge[j].start_x;
			int s_y = edge[j].start_y;
			int e_x = edge[j].end_x;
			int e_y = edge[j].end_y;
			int w = edge[j].weight;

			if (original[s_x][s_y] >= MAX)
				continue;
			if (dist[e_x][e_y] > (original[s_x][s_y] + w))
			{
				dist[e_x][e_y] = original[s_x][s_y] + w;
			}
			if (e_x == W - 1 && e_y == H - 1)
				continue;
			if (dist[e_x][e_y] != original[e_x][e_y])
			{
				round_flag = true;
				break;
			}
		}



		if (round_flag)
		{
			cout << "Never\n";
			round_flag = false;
		}
		else if (original[W - 1][H - 1] == MAX)
			cout << "Impossible\n";
		else
			cout << original[W - 1][H - 1] << "\n";
	}

}

#endif