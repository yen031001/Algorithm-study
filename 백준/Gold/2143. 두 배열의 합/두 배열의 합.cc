#if 1
#include <iostream>
#include <algorithm>
using namespace std;

int map_A[1005] = { 0, };
int map_B[1005] = { 0, };
long long sum_A[1000002] = {0,};
long long sum_B[1000002] = { 0, };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, N, M;
	int size_A = 0, size_B = 0;
	long long ans = 0;

	cin >> T;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> map_A[i];
	}

	cin >> M;

	for (int i = 0; i < M; i++)
	{
		cin >> map_B[i];
	}

	for (int i = 0; i < N; i++)
	{
		sum_A[size_A] = map_A[i];
		size_A++;
		for (int j = i + 1; j < N; j++)
		{
			sum_A[size_A] = sum_A[size_A-1]+ map_A[j];
			size_A++;
		}
	}

	for (int i = 0; i < M; i++)
	{
		sum_B[size_B] = map_B[i];
		size_B++;
		for (int j = i + 1; j < M; j++)
		{
			sum_B[size_B] = sum_B[size_B - 1] + map_B[j];
			size_B++;
		}
	}

	sort(sum_A, sum_A + size_A);
	sort(sum_B, sum_B + size_B);
	int left = 0;
	int right = 0;

	for (int i = 0; i < size_A; i++)
	{
		int token = sum_A[i];
		long long find = T - sum_A[i];

		int left = lower_bound(sum_B, sum_B + size_B, find)-sum_B;
		int right = upper_bound(sum_B, sum_B + size_B, find) - sum_B;

		int num = right - left;
		ans += num;
	}
	cout << ans;
	
}
#endif