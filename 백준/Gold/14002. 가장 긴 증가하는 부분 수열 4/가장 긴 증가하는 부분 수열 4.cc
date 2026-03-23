#if 1
#include <iostream>
using namespace std;

int N;
int num[1005];
int max_len[1005] = { 0, };
int prev_num[1005] = { 0, };
bool USED[1005] = { false, };

int main()
{
	cin >> N;

	int total_max = 0;
	int max_idx;
	
	for (int i = 1; i <= N; i++)
	{
		cin >> num[i];
		max_len[i] = 1;

		for (int j = i; j > 0; j--)
		{
			if (num[i] > num[j])
			{
				if (max_len[j] + 1 > max_len[i])
				{
					max_len[i] = max_len[j] + 1;
					prev_num[i] = j;
				}
					
			}
		}

		if (max_len[i] > total_max)
		{
			total_max = max_len[i];
			max_idx = i;
		}
	}


	while (max_idx != 0)
	{
		USED[max_idx] = true;
		max_idx = prev_num[max_idx];
	}

	cout << total_max<<"\n";
	for (int i = 1; i <= N; i++)
	{
		if (USED[i])
			cout << num[i] << ' ';
	}

}


#endif