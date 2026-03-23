#if 1

#include <iostream>
#include <vector>
using namespace std;

vector<int> ans;

int N;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	int tmp;
	cin >> tmp;
	ans.push_back(tmp);

	for (int i = 0; i < N-1; i++)
	{
		tmp;
		cin >> tmp;
		
		if (tmp > ans[ans.size() - 1])
		{
			ans.push_back(tmp);
		}
		else
		{
			int small;
			small = lower_bound(ans.begin(), ans.end(), tmp) - ans.begin();
			ans[small] = tmp;
		}
	}

	cout << ans.size();
	
}

#endif