#if 1

#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

int alpha[30] = { 0, };
string fst;
string cmp[105];
int num;
int ans=0;



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	cin >> num;
	cin >> fst;

	for (int i = 0; i < num - 1; i++)
	{
		cin >> cmp[i];
	}

	sort(fst.begin(), fst.end());

	for (int i = 0; i < fst.size(); i++)
	{
		alpha[fst[i] - 'A']++;
	}

	for (int i = 0; i < num-1; i++)
	{
		sort(cmp[i].begin(), cmp[i].end());


		if (cmp[i] == fst)
			ans++;
		else if (cmp[i].size() == fst.size())
		{
			int ctmp[30] = { 0, };
			for (int j = 0; j < fst.size(); j++)
			{
				ctmp[cmp[i][j] - 'A']++;
			}
			int sum = 0;
			for (int j = 0; j < 27; j++)
			{
				sum = sum + (abs(ctmp[j] - alpha[j]));
			}

			if (sum == 2)
				ans++;
		}
		else if (cmp[i].size() - fst.size() == 1)
		{
			string tmp = fst;
			for (int j = 0; j < cmp[i].size(); j++)
			{
				if (cmp[i][j] != tmp[j])
					tmp.push_back(cmp[i][j]);

				sort(tmp.begin(), tmp.end());
			}
			if (tmp == cmp[i])
				ans++;
		}
		else if (cmp[i].size() - fst.size() == -1)
		{
			string tmp = cmp[i];
			for (int j = 0; j < fst.size(); j++)
			{
				if (tmp[j] != fst[j])
					tmp.push_back(fst[j]);

				sort(tmp.begin(), tmp.end());
			}
			if (tmp == fst)
				ans++;
		}
			
	}

	cout << ans;
}




#endif