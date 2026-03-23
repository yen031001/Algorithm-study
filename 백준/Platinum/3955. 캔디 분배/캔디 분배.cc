#include <iostream>
using namespace std;


long long s0, s1, t0, t1, r0, r1, q;
//s->a의 계수
//t->b의 계수

long long gcd(long long a, long long b)
{
	long long c;
	while (1)
	{
		c = a % b;
		if (c == 0)
		{
			return b;
		}
		a = b;
		b = c;
	}
}

long long extended(int a, int b)
{
	s0 = 1;
	s1 = 0;
	t0 = 0;
	t1 = 1;
	r0 = a;
	r1 = b;

	while (r0%r1 != 0)
	{
		long long q = r0 / r1;
		long long sNext = s0 - q * s1;
		long long tNext = t0 - q * t1;
		long long rNext = r0 % r1;

		s0 = s1;
		t0 = t1;
		r0 = r1;
		s1 = sNext;
		t1 = tNext;
		r1 = rNext;

	}

	while(t1 < 0)
	{
		t1 = t1 + a;
	}
	return t1;
}

int main()
{
	int N;
	int a, b;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		long long temp;
		cin >> a >> b;

		if (b == 1)
		{
			temp = a + 1;
			if (temp > 1000000000)
				cout << "IMPOSSIBLE\n";
			else
				cout << temp << endl;
			continue;
		}
		if (a == 1)
		{
			if (b == 1)
			{
				cout << a + 1 << endl;
				continue;
			}
			else
			{
				cout << a << endl;
				continue;
			}
		}
		if (gcd(a, b) != 1)
		{
			cout << "IMPOSSIBLE\n";
		}
		else
		{
			temp = extended(a, b);
			if (temp > 1000000000)
				cout << "IMPOSSIBLE\n";
			else
				cout << temp << endl;
		}
			
	}
 }