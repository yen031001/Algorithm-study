#if 1
#include <iostream>
using namespace std;

int sum_min[3][3] = { 0, };
int sum_max[3][3] = { 0, };


int find_max(int A, int B)
{
	if (A > B)
		return A;
	else
		return B;
}
int find_min(int A, int B)
{
	if (A < B)
		return A;
	else
		return B;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;

	cin >> N;

	int a, b, c;
	cin >> a >> b >> c;
	sum_max[0][0] = a;
	sum_max[0][1] = b;
	sum_max[0][2] = c;

	sum_min[0][0] = a;
	sum_min[0][1] = b;
	sum_min[0][2] = c;

	int MAX, MIN;

	for (int i = 1; i < N; i++)
	{

		cin >> a >> b >> c;

		//left
		MAX = find_max(sum_max[0][0], sum_max[0][1]);
		MIN = find_min(sum_min[0][0], sum_min[0][1]);

		sum_max[1][0] = MAX + a;
		sum_min[1][0] = MIN + a;

		//right
		MAX = find_max(sum_max[0][2], sum_max[0][1]);
		MIN = find_min(sum_min[0][2], sum_min[0][1]);

		sum_max[1][2] = MAX + c;
		sum_min[1][2] = MIN + c;

		//MID
		MAX = find_max(MAX, sum_max[0][0]);
		MIN = find_min(MIN, sum_min[0][0]);

		sum_max[1][1] = MAX + b;
		sum_min[1][1] = MIN + b;

		for (int i = 0; i < 3; i++)
		{
			sum_max[0][i] = sum_max[1][i];
			sum_min[0][i] = sum_min[1][i];
		}

	}

	MAX = find_max(sum_max[0][2], sum_max[0][1]);
	MAX = find_max(MAX, sum_max[0][0]);
	MIN = find_min(sum_min[0][2], sum_min[0][1]);
	MIN = find_min(MIN, sum_min[0][0]);

	cout << MAX << ' ' << MIN;
}
#endif