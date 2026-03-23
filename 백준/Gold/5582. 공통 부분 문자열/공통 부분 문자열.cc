#if 1
#include <string>
#include <iostream>
#include <vector>
using namespace std;


string A;
string B;

int leng[4005][4005] = { 0, };
int MAX = 0;



int main()
{
	int N, M;

	cin >> A >> B;

	N = A.length();
	M = B.length();

	for (int i = 0; i <= N; i++)
	{
		leng[i][0] = 0;
	}

	for (int i = 0; i <= M; i++)
	{
		leng[0][i] = 0;
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (A[i - 1] == B[j - 1])
			{
				leng[i][j] = leng[i - 1][j - 1] + 1;
				if (leng[i][j] > MAX)
					MAX = leng[i][j];
			}
			else
				leng[i][j] = 0;
		}
	}
	

	cout << MAX;
}



#endif