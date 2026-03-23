#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>


int N;
int ans=0;
int col[20];
bool row[20]; 



void dfs(int colNum)
{
	if (colNum == N+1)
	{
		return;
	}

	for (int i = 1; i <= N; i++)
	{
		bool cango=true;

		if (row[i])
			cango = false;
		int k = 1;
		for (int j = colNum-1; j > 0; j--)
		{
			if (col[j] == i - k || col[j] == i + k)
				cango = false;
			k++;
		}
		if (!cango)continue;
		col[colNum] = i;
		if (colNum == N)
			ans++;
		row[i] = true;
		dfs(colNum + 1);
		row[i] = false;
	}

	
}

int main()
{
	scanf("%d", &N);
	dfs(1);
	printf("%d\n", ans);
}