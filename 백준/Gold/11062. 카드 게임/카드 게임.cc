#if 1
#include <iostream>
#include <vector>
using namespace std;

int score[1005][1005] = { 0, };

int MIN(int a, int b)
{
	if (a < b)
		return a;
	else
		return b;
}


int MAX(int a, int b)
{
	if (a > b)
		return a;
	else
		return b;
}


int main()
{
	int C;
	cin >> C;

	for (int c = 0; c < C; c++)
	{
		vector<int>card;
		int N;

		
		cin >> N;




		for (int n = 0; n < N; n++)
		{
			int tmp;
			cin >> tmp;
			card.push_back(tmp);
		}

		for (int i = 0; i < N; i++)
		{
			if (N%2==1)
				score[i][i] = card[i];
			else
				score[i][i] = 0;
		}

		for (int leng = 1; leng < N; leng++)
		{
			for (int i = 0; i < N - leng; i++)
			{
				if ((N - leng) % 2 != 0)
				{
					score[i][i + leng] = MAX(score[i + 1][i + leng] + card[i], score[i][i + leng - 1] + card[i + leng]);
				}
				else
				{
					score[i][i + leng] = MIN(score[i + 1][i + leng], score[i][i + leng - 1]);
				}
			}
			
		}
		cout << score[0][N-1] << "\n";


	}
}


#endif