#if 1

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int N;
	int ans = 0;
	vector<int> input;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int tmp;
		cin >> tmp;
		input.push_back(tmp);
	}

	sort(input.begin(), input.end());

	for (int i = 0; i < N; i++)
	{
		bool find = false;
		int l = 0;
		int r = i - 1;

		while (l < r)
		{
			if (input[l] + input[r] == input[i])
			{
				ans = ans + 1;
				find = true;
				break;
			}
			else if (input[l] + input[r] < input[i])
				l++;
			else
				r--;
		}

		if (find)
			continue;
		l = i + 1;
		r = N - 1;

		while (l < r)
		{
			if (input[l] + input[r] == input[i])
			{
				ans = ans + 1;
				find = true;
				break;
			}
			else if (input[l] + input[r] < input[i])
				l++;
			else
				r--;
		}

		if (find)
			continue;
		l = 0;
		r = N - 1;

		while (l <i && r>i)
		{
			if (input[l] + input[r] == input[i])
			{
				ans = ans + 1;
				find = true;
				break;
			}
			else if (input[l] + input[r] < input[i])
				l++;
			else
				r--;
		}
	}

	cout << ans;
}

#endif