#if 1
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


int N;
string word[10];
int cnt[26][9] = { 0, };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> word[i];
		int idx = 0;
		for (int j = word[i].length(); j>0; j--)
		{
			cnt[word[i][idx] - 'A'][j]++;
			idx++;
		}
	}

	vector<int>sum;

	for (int i = 0; i < 26; i++)
	{
		int ten = 1;
		int tmp=0;
		for (int j = 1; j < 9; j++)
		{
			if (cnt[i][j])
			{
				tmp = tmp + (cnt[i][j] * ten);
			}
			ten = ten * 10;
		}
		if (tmp)
		{
			sum.push_back(tmp);
		}
	}

	

	sort(sum.begin(), sum.end(),greater<int>());

	/*
	for (int i = 0; i < sum.size(); i++)
	{
		cout << sum[i] << "\n";
	}
	*/

	int pnum = 9;
	int ans = 0;
	for (int i = 0; i < sum.size(); i++)
	{
		ans = ans + sum[i] * pnum;
		pnum--;
	}
	cout << ans;

}




#endif