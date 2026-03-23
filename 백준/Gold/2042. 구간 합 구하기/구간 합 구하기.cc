#include <iostream>
using namespace std;

int N, M, K;
long long arr[1000005];
long long tree[2097152] = { 0, };  
int leafStart = 1048576; 

void update(int loca, long long number)
{
	int idx= leafStart + loca-1;
	tree[idx] =number;

	while (idx>=1)
	{
		idx = idx / 2;
		tree[idx] = tree[2 * idx] + tree[2 * idx + 1];
	}

}

long long get(int l, int r)
{
	long long ret = 0;

	while (l<=r)
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


int main()
{
	cin >> N >> M >> K;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		tree[leafStart + i] = arr[i];
	}

	for (int i = leafStart - 1; i >= 1; i--)
	{
		tree[i] = tree[i * 2] + tree[i * 2 + 1];
	}

	for (int i = 0; i < M + K; i++)
	{
		long long x, y, z;
		cin >> x >> y >> z;

		if (x == 1)
		{
			update(y, z);
		}
		else {
			long long result = get(leafStart + y-1, leafStart + z-1);
			cout << result<<'\n';
		}
	
	}

}