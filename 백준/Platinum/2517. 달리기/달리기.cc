#include <iostream>
#include <algorithm>
using namespace std;


typedef struct _Ath
{
	int  speed;
	int cur_p;
	int rank;
}Ath;

bool cmp_speed(const Ath& a, const Ath& b)
{
	if (a.speed >= b.speed)
		return true;
	else
		return false;
}

bool cmp_cur(const Ath& a, const Ath& b)
{
	if (a.cur_p < b.cur_p)
		return true;
	else
		return false;
}

int N;

Ath arr[500005];
int tree[2097152] = { 0, };
int leafStart = 1048576;

void update(int loca)
{
	int idx = leafStart + loca;
	tree[idx] = 1;

	while (idx >= 1)
	{
		idx = idx / 2;
		tree[idx] = tree[2 * idx] + tree[2 * idx + 1];
	}

}

int get(int l, int r)
{
	int ret = 0;

	while (l <= r)
	{
		if (l % 2 == 1)
			ret += tree[l++];
		if (r % 2 == 0)
			ret += tree[r--];
		l /= 2;
		r /= 2;
	}

	return ret;
}

void insert(Ath person,int order)
{
	update(person.rank);
	int f_rank = get(leafStart, leafStart + person.rank);
	arr[order].rank = f_rank;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i].speed;
		arr[i].cur_p = i;
	}

	sort(arr, arr + N, cmp_speed);

	for (int i = 0; i < N; i++)
	{
		arr[i].rank = i;
	}

	sort(arr, arr + N, cmp_cur);


	for (int i = 0; i < N; i++)
	{
		insert(arr[i],i);
	}


	for (int i = 0; i < N; i++)
	{
		cout << arr[i].rank << '\n';
	}

}