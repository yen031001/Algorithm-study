#if 1
#include <string>
#include <iostream>
#include <vector>
using namespace std;


string A;
string B;
vector<char> ans;

int LCS_size[1005][1005];  //N x M
int LCS_route[1005][1005] = { 0, }; //1은 같은거 2는 A 줄인거 3은 B줄인거



int main()
{
	int N, M;
	
	cin >> A >> B;

	N = A.length();
	M = B.length();

	for (int i = 0; i <= N; i++)
	{
		LCS_size[i][0] = 0;
	}

	for (int i = 0; i <= M; i++)
	{
		LCS_size[0][i] = 0;
	}

	//인덱스 -1 해야할듯

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (A[i - 1] == B[j - 1])
			{
				LCS_size[i][j] = LCS_size[i - 1][j - 1] + 1;
				LCS_route[i][j] = 1;

			}
			else
			{
				if (LCS_size[i - 1][j] > LCS_size[i][j - 1])
				{
					LCS_size[i][j] = LCS_size[i - 1][j];
					LCS_route[i][j] = 2;
				}
				else
				{
					LCS_size[i][j] = LCS_size[i][j - 1];
					LCS_route[i][j] = 3;
				}
				
			}
		}
	}

	cout << LCS_size[N][M]<<"\n";
	
	if (LCS_size[N][M] == 0)
		return 0;

	int count = LCS_size[N][M];
	int a = N, b = M;

	while (count)
	{
		if (LCS_route[a][b] == 1)
		{
			ans.push_back(A[a - 1]);
			a--;
			b--;
			count--;
		}
		else if (LCS_route[a][b] == 2)
		{
			a--;
		}
		else if (LCS_route[a][b] == 3)
		{
			b--;
		}
	}

	for (int i = ans.size() - 1; i >= 0; i--)
	{
		cout << ans[i];
	}




}



#endif