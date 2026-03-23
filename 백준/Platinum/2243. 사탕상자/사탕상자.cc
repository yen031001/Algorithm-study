#if 1
#include <iostream>
using namespace std;

int tree[2097152] = { 0, };
int leafStart = 1048576;


void update(int idx, int number)
{
	idx = leafStart + idx - 1;
	tree[idx] += number;

	while (idx > 1)
	{
		idx /= 2;
		tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
	}
}

int search(int rank)
{
	int cur = 1;

	while (cur < leafStart)
	{
		if (tree[cur * 2] >= rank)
			cur = cur * 2;
		else
		{
			rank = rank - tree[cur * 2];
			cur = cur * 2 + 1;
		}
	}

	return cur-leafStart+1;
}


int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int C;

	cin >> C;

	for (int commandCount = 0; commandCount < C; commandCount++)
	{
		int a, b, c;
		cin >> a;

		if (a == 1)
		{
			cin >> b;
			int ans=search(b);
			cout << ans<<"\n";
			update(ans, -1);

		}
		else if (a == 2)
		{
			cin >> b >> c;
			update(b, c);
		}
	}
}




#endif