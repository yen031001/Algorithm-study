#if 1

#include <iostream>
using namespace std;

int N, M, K;
bool map[42][42] = { false, };


bool find_space(bool sticker[11][11],int n, int m)
{
	// 0부터 시작이니까 1씩 늘려줘야 함
	int row_diff= N - n+1;
	int col_diff = M - m+1;
	bool find = false;

	for (int r = 0; r < row_diff; r++)
	{
		for (int c = 0; c < col_diff; c++)
		{
			// 매칭 계산
			bool poss = true;
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < m; j++)
				{
					if (sticker[i][j] && map[i + r][j + c])
					{
						poss = false;
						break;
					}
				}
				if (!poss)
					break;
			}
			if (poss)
			{
				find = true;
				for (int i = 0; i < n; i++)
				{
					for (int j = 0; j < m; j++)
					{
						if(sticker[i][j])
							map[i + r][j + c] = sticker[i][j];
					}
				}
				return true;
			}
		}
	}

	return find;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> K;

	for (int k = 0; k < K; k++)
	{
		bool sticker[2][11][11] = { false, };
		int sticker_now = 0;
		int n;
		int m;
		cin >> n >> m;
		int tmp;

		// 스티커 정보 받기
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cin >> tmp;
				if (tmp)
					sticker[0][i][j] = true;
				else
					sticker[0][i][j] = false;
			}
		}

		if(find_space(sticker[0], n, m))
			continue;

		for (int cnt = 0; cnt < 3; cnt++)
		{
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < m; j++)
				{
					// N이랑 혼동하지 않기, 기준은 n
					sticker[1-sticker_now][j][n - 1 - i] = sticker[sticker_now][i][j];
					
				}
			}

			sticker_now = 1 - sticker_now;

			// 가로 세로 바꿔줘야 함
			int tmp_t=n;
			n = m;
			m = tmp_t;

			if (find_space(sticker[sticker_now], n, m))
				break;
			
		}
		
	}

	int total_cnt = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (map[i][j])
			{
				total_cnt++;
			}
		}
	}

	cout << total_cnt;
}



#endif