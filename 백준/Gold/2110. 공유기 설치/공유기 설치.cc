#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, C;
	cin >> N >> C;

	vector<int> house(N);
	for (int i = 0; i < N; i++)
	{
		cin >> house[i];
	}

	sort(house.begin(), house.end());

	int l = 1; 
	int r = house[N - 1] - house[0];
	int ans = 0;

	
	while (l <= r)
	{
		
		int mid = l + (r - l) / 2;

		int count = 1;
		int last_pos = house[0];

		
		for (int i = 1; i < N; i++)
		{
			if (house[i] - last_pos >= mid)
			{
				count++;
				last_pos = house[i]; 
			}
		}

		
		if (count >= C)
		{
			ans = mid; 
			l = mid + 1;
		}
		else
		{
			r = mid - 1;
		}
	}

	cout << ans;
	return 0;
}