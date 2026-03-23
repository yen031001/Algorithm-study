#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

int N, M;
int ans[10];
bool visit[10];

void dfs(int depth,int num)
{
	if (depth == M)
	{
		for (int i = 0; i < M; i++) printf("%d ", ans[i]);
		printf("\n");
		return;
	}

	for (int i = num; i <= N; i++)
	{
		if (visit[i]) continue;
		ans[depth] = i;
		visit[i] = true;
		num = i+1;
		dfs(depth + 1,num);
		visit[i] = false;
	}
}

int main()
{
	scanf("%d %d", &N,&M);
	dfs(0,1);
}