#include <iostream>
#include <algorithm>
using namespace std;

int a[4000], b[4000], c[4000], d[4000];
long long n;
long long ab[16000000], cd[16000000];

int main()
{
	cin >> n;
	long long cnt = 0;
	for (long long i = 0; i < n; i++)
	{
		cin >> a[i] >> b[i] >> c[i] >> d[i];
	}

	long long sz = 0;
	for (long long i = 0; i < n;i++)
	{
		for (int j = 0; j < n; j++)
		{
			ab[sz] = (long long)a[i] + (long long)b[j];
			cd[sz] = (long long)c[i] + (long long)d[j];
			sz++;
		}

	}

	sort(ab, ab + sz);
	sort(cd, cd + sz);

	for (int i = 0; i < sz; i++)
	{
		long long num = ab[i];
		long long lb = lower_bound(cd,cd+sz, -num)-cd;
		long long ub = upper_bound(cd, cd + sz, -num) - cd;
		cnt += ub - lb;
	}

	cout << cnt<<endl;
}