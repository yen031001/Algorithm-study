#if 1


#include <iostream>
using namespace std;

int N, R, C;
//map을 그릴 수는 없을듯 32768x32768





int cal_z(int cnt,int row, int col,int n)
{
	int nxt_cnt;
	if (n == 2)
	{
		//왼위
		if (R==(row-1) && (col-1) == C)
		{
			cout << cnt;
		}

		//오위
		if (R == (row-1) && (col) == C)
		{
			cout << cnt+1;
		}
		//왼아
		if (R == row && (col-1) == C)
		{
			cout << cnt+2;
		}
		//오아
		if (R == (row) && (col) == C)
		{
			cout << cnt+3;
		}

		return cnt+4;
	}
	else
	{	
		int how = (n/2)*(n/2);

		if (R <= row - (n / 2) && C <= col - (n / 2))
		{
			nxt_cnt = cal_z(cnt, row - (n / 2), col - (n / 2), n / 2);
			return nxt_cnt;
		}
		else
			nxt_cnt = cnt + how;

		if (R <= row - (n / 2))
		{
			nxt_cnt = cal_z(nxt_cnt, row - (n / 2), col, n / 2);
			return nxt_cnt;
		}
		else
			nxt_cnt = nxt_cnt + how;

		if ( C <= col - (n / 2))
		{
			nxt_cnt = cal_z(nxt_cnt, row, col - (n / 2), n / 2);
			return nxt_cnt;
		}
		else
			nxt_cnt = nxt_cnt + how;

		nxt_cnt = cal_z(nxt_cnt, row, col, n / 2);
		return nxt_cnt;

	}
}

int main()
{
	cin >> N >> R >> C;

	int siz = 1;
	for (int i = 0; i < N; i++)
	{
		siz = siz * 2;
	}
	int dum = cal_z(0, siz - 1, siz - 1, siz);
}





#endif