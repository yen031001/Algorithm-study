#if 1
#include <iostream>
#include <string>
using namespace std;

int N, M;

string input[1005];
int sum[1005][1005] = { 0, };
int max_num = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		cin >> input[i];
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			sum[i][j] = input[i - 1][j - 1] - '0';
			if (sum[i][j] == 1 && max_num == 0)
				max_num = 1;
		}
	}

	for (int i = 2; i <= N; i++)
	{
		for (int j = 2; j <= M; j++)
		{
			if (sum[i][j] == 1)
			{
				if (sum[i - 1][j - 1] && sum[i - 1][j] && sum[i][j - 1])
				{
					int temp;
					if (sum[i - 1][j - 1] < sum[i][j - 1])
						temp = sum[i - 1][j - 1];
					else
						temp = sum[i][j - 1];

					if (temp > sum[i - 1][j])
						temp = sum[i - 1][j];

					sum[i][j] = temp+1;

					if (sum[i][j] > max_num)
						max_num = sum[i][j];
				}
			}

		}
	}


	cout << max_num*max_num;


}





#endif