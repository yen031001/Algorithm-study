#if 1

#include <iostream>
#include <vector>
using namespace std;

bool know[55] = { false, };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	int S;
	int ans=0;
	vector<int>mem[55];

	cin >> N >> M;
	cin >> S;


	if (S == 0)
	{
		ans = M;
	}
	else
	{
		for (int i = 0; i < S; i++)
		{
			int tmp;
			cin >> tmp;
			know[tmp] = true;
		}
		
		for (int i = 0; i < M; i++)
		{
			int K;
			cin >> K;
			bool caught = false;
			for (int j = 0; j < K; j++)
			{
				
				int num;
				cin >> num;


				if (caught)
				{
					know[num] = true;
				}

				if (know[num])
				{
					caught = true;
					for (int k = 0; k < mem[i].size(); k++)
					{
						know[mem[i][k]] = true;
					}
				}
				else
				{
					mem[i].push_back(num);
				}

			}
		}

		bool chg = true;
		while (chg)
		{
			chg = false;
			for (int i = M - 1; i >= 0; i--)
			{
				if (mem[i].size() <= 0)
					continue;
				for (int j = 0; j < mem[i].size(); j++)
				{
					if (know[mem[i][j]])
					{
						for (int k = 0; k < mem[i].size(); k++)
						{
							if (know[mem[i][k]] == false)
							{
								know[mem[i][k]] = true;
								chg = true;
							}
						}
						break;
					}
				}

			}
		}


		for (int i = M-1; i >= 0; i--)
		{
			bool flg = false;
			if (mem[i].size() <= 0)
				continue;
			for (int j = 0; j < mem[i].size(); j++)
			{
				if (know[mem[i][j]])
				{
					flg = true;
					break;
				}
			}
			if (!flg)
				ans++;
			
		}
	}

	cout << ans;
}



#endif