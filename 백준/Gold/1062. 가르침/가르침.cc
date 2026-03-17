#if 1
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int N, K;
int ANSWER = 0;
bool word[50][26] = { false, };

void dfs(int word_num[50],bool candidate[26],int remain,int ans,int idx)
{
	if (remain <= 0 ||ans>=N)
	{
		if (ANSWER < ans)
			ANSWER = ans;
		return;
	}

	for (int i = idx; i < 26; i++)
	{
		int cur_ans = ans;
		if (candidate[i])
		{
			for (int j = 0; j < N; j++)
			{
				if (word[j][i])
				{
					word_num[j]--;
					if (word_num[j] == 0)
						cur_ans++;
				}
			}
			candidate[i] = false;
			dfs(word_num, candidate, remain-1, cur_ans,i+1);
			candidate[i] = true;
			for (int j = 0; j < N; j++)
			{
				if (word[j][i])
				{
					word_num[j]++;
				}
			}

		}
	}

	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int alpha[26] = { false, };
	int word_num[50] = { 0, };
	bool candidate[26] = { false, };

	cin >> N >> K;

	if (K < 5)
	{
		cout << '0';
		return 0;
	}

	int remain = K - 5;

	alpha['a' - 'a'] = true;
	alpha['n' - 'a'] = true;
	alpha['t' - 'a'] = true;
	alpha['i' - 'a'] = true;
	alpha['c' - 'a'] = true;
	
	
	for (int i = 0; i < N; i++)
	{
		string tmps;
		cin >> tmps;
		
		string cattmp = tmps.substr(4, tmps.length()-8);

		
		int tmp_len = cattmp.length();
		for (int j = 0; j < cattmp.length(); j++)
		{
			if (alpha[cattmp[j] - 'a'])
			{
				tmp_len--;
			}
			if (!word[i][cattmp[j] - 'a'] && !alpha[cattmp[j] - 'a'])
			{
				word[i][cattmp[j] - 'a'] = true;
				word_num[i]++;
				candidate[cattmp[j] - 'a'] = true;
			}
			
		}
		if (tmp_len == 0|| cattmp.length() == 0)
		{
			ANSWER = ANSWER + 1;
		}
	}

	int cand_num = 0;
	for (int i = 0; i < 26; i++)
	{
		if (candidate[i])
			cand_num++;
	}

	if (remain >= cand_num)
	{
		cout << N;
		return 0;
	}

	dfs(word_num, candidate, remain, ANSWER,0);


	cout << ANSWER;

}





#endif