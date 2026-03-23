#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

int N, M;
int list[10005];


int main()
{
	scanf("%d %d", &N, &M);
	for(int i = 0; i < N; i++)
		scanf("%d", list + i);

	int l = 0, r = 0;
	int sum = 0;
	int result=0;
	
	while (1)
	{
		sum += list[r];
		while (1)
		{
			if (l > r||sum<M)
				break;
			if (sum == M)
				result++;
			if (sum >= M)
			{
				sum -= list[l++];
			}
			
		}
		r++;

		if (r == N)
			break;
	}

	printf("%d", result);
}