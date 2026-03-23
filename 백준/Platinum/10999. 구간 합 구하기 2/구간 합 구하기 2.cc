#if 1 

#include <iostream>
using namespace std;

long long seg[2097153] = { 0, };
long long lazy[2097153] = { 0, };
int leaf_start = 1048576;
int N, M, K;

int H = 20;

void apply(int p, long long val, int len)
{
	seg[p] += val * (long long)len;
	if (p < leaf_start)
		lazy[p] += val;
}

void push(int p)
{
	for (int s = H; s > 0; --s)
	{
		int i = p >> s;
		if (lazy[i] != 0)
		{
			long long v = lazy[i];
			int child_len = 1 << (s - 1);
			apply(i << 1, v, child_len);
			apply(i << 1 | 1, v, child_len);
			lazy[i] = 0;
		}
	}
}

void pull(int p)
{
	int len = 1;

	for (p >>= 1; p >= 1; p >>= 1)
	{
		len <<= 1;

		seg[p] = seg[p << 1] + seg[p << 1 | 1] + lazy[p] * (long long)len;
	}
}


void update(int a, int b, long long c)
{
	
	push(a);
	push(b);

	int L = a, R = b;
	int len = 1;

	while (L <= R)
	{
		if (L % 2 == 1)
		{
			apply(L++, c, len);
		}
		if (R % 2 == 0)
		{
			apply(R--, c, len);
		}

		L >>= 1;
		R >>= 1;
		len <<= 1;
	}

	pull(a);
	pull(b);


	
}

void find(int a, int b)
{
	push(a);
	push(b);


	long long sum = 0;
	while (a <= b)
	{
		if (a % 2 == 1)
		{
			sum += seg[a];
			a++;
		}
		if (b % 2 == 0)
		{
			sum += seg[b];
			b--;
		}
		a /= 2;
		b /= 2;
	}

	cout << sum << "\n";
}

int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> K;

	for (int i = 0; i < N; i++)
	{
		long long tmp;
		cin >> tmp;
		seg[leaf_start + i] = tmp;
	}

	for (int i = leaf_start - 1; i > 0; i--)
	{
		seg[i] = seg[i * 2] + seg[i * 2 + 1];
	}

	int m = M, k = K;
	for (int i = 0; i < M + K; i++)
	{
		int cate;
		cin >> cate;
		int a, b;
		long long c;

		if (cate == 1)
		{
			cin >> a >> b >> c;
			update(a + leaf_start - 1, b + leaf_start - 1, c);
		}
		else if (cate == 2)
		{
			cin >> a >> b;
			find(a + leaf_start - 1, b + leaf_start - 1);
			k--;
		}

		if (k == 0)
			break;
	}

}


#endif