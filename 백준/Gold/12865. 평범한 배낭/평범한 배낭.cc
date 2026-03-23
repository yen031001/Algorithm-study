#if 1
#include <iostream>
using namespace std;



int valueFor[105][1000005] = {0,};
pair<int, int>item[105] = { {0,0} };

int MAX(int a, int b)
{
	if (a > b)
		return a;
	else
		return b;
}


int main()
{

	ios_base::sync_with_stdio(false);
	int N, K;
	cin >> N >> K;

	for (int i = 1; i <= N; i++)
	{
		int w, v;
		cin >> w >> v;
		item[i] = pair<int, int>(w, v);
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= K; j++)
		{
			int weight = item[i].first;
			int value = item[i].second;
			if (weight > j)
				valueFor[i][j] = valueFor[i - 1][j];
			else
			{
				valueFor[i][j] = MAX(valueFor[i - 1][j], valueFor[i - 1][j - weight] + value);
			}
		}
	}

	cout << valueFor[N][K];
}




#endif