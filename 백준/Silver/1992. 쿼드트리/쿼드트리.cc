#if 1

#include <iostream>
#include <string>
using namespace std;

int N;
int map[65][65] = { 0, };


int cal_cor(int row_start, int row_end, int col_start, int col_end, int siz)
{
	int is_one = 1;
	int is_zero = 0;
	for (int i = row_start; i < row_end; i++)
	{
		for (int j = col_start; j < col_end; j++)
		{
			is_one *= map[i][j];
			is_zero += map[i][j];
		}
	}

	if (is_one)
		return 1;
	else if (!is_zero)
		return 0;
	else
		return -1;
}

void cal_quad_tree(int row_start, int row_end, int col_start, int col_end, int siz)
{
	cout << "(";
	int start = 0;
	int stride = (siz / 2);

	//왼쪽 위
	int a = cal_cor(row_start, row_start + stride, col_start, col_start + stride, siz);
	if (a != (-1))
		cout << a;
	else
		cal_quad_tree(row_start, row_start + stride, col_start, col_start + stride, siz / 2);

	//오른쪽 위
	int b = cal_cor(row_start, row_start + stride, col_start+stride, col_end, siz);
	if (b != (-1))
		cout << b;
	else
		cal_quad_tree(row_start, row_start + stride, col_start + stride, col_end, siz / 2);

	//왼쪽 아래
	int c = cal_cor(row_start+stride, row_end, col_start, col_start + stride, siz);
	if (c != (-1))
		cout << c;
	else
		cal_quad_tree(row_start + stride, row_end, col_start, col_start + stride, siz / 2);

	//오른쪽 아래
	int d = cal_cor(row_start+stride, row_end, col_start+stride, col_end, siz);
	if (d != (-1))
		cout << d;
	else
		cal_quad_tree(row_start + stride, row_end, col_start + stride, col_end, siz / 2);

	cout << ")";
	
}

int main()
{
	string tmp;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> tmp;
		for (int j = 0; j < N; j++)
		{
			map[i][j] = int(tmp[j])-'0';
		}
	}
	
	int all_same = cal_cor(0, N, 0, N, N);
	if (all_same != (-1))
		cout << all_same;
	else
		cal_quad_tree(0, N, 0, N, N);

}



#endif