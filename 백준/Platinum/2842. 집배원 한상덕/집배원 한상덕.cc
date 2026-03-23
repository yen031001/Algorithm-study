#if 1
#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;

string map[51];
int height[51][51];
int N;
int MIN=1000001,MAX=0;
int dir[8][2] = { {1,1},{1,-1},{1,0},{0,1},{0,-1},{-1,-1},{-1,0},{-1,1} };
int ans = 1000001;
int house = 0;
vector<int> h_s;


int search(int x,int y,int l, int r)
{
	queue <pii>q;
	bool visit[51][51] = { false };
	int cnt = 0;
	q.push(pii(x, y));
	if (height[x][y]<l || height[x][y]>r)
		return 0;
	visit[x][y] = true;

	while (!q.empty() && cnt < house)
	{
		pii cur = q.front();
		q.pop();
		x = cur.first;
		y = cur.second;

		for (int i = 0; i < 8; i++)
		{
			int newX = x + dir[i][0];
			int newY = y + dir[i][1];

			if (newX<0 || newY<0 || newX>=N || newY>=N)
				continue;
			else if (height[newX][newY]<l || height[newX][newY] >r)
				continue;
			else if (visit[newX][newY] == true)
				continue;
			
			if (map[newX][newY] == 'K')
				cnt++;

			visit[newX][newY] = true;
			q.push(pii(newX, newY));
		}
	}

	return cnt;

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	int x, y;

	for (int i = 0; i < N; i++)
	{
		cin >> map[i];
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (map[i][j] == 'P')
			{
				x = i;
				y = j;
			}
			if (map[i][j] == 'K')
				house++;
		}
	}



	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> height[i][j];
			h_s.push_back(height[i][j]);

			if (map[i][j] == 'P' || map[i][j] == 'K')
			{
				if (height[i][j] > MAX)
					MAX = height[i][j];
				if (height[i][j] < MIN)
					MAX = height[i][j];
			}
		}
	}

	sort(h_s.begin(), h_s.end());
	h_s.erase(unique(h_s.begin(), h_s.end()), h_s.end());

	
	int l = 0;
	int r = 0;

	int limit =h_s.size()-1;

	while (l<=r &&r<=limit&&l<=limit)
	{
		if (h_s[r] < MAX)
		{
			r++;
			continue;
		}
		if (h_s[l] > MIN)
			break;
		int cnt=search(x, y,h_s[l], h_s[r]);
		if (cnt==house)
		{
			if ((h_s[r] - h_s[l]) < ans)
				ans = h_s[r] - h_s[l];
			l++;
			
		}
		else
		{
			r++;
			
		}
	}

	cout << ans;


}




#endif