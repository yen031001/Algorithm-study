#include <iostream>
using namespace std;

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

int main()
{
	int a, b; //a/b
	int c, d; //c/d

	cin >> a >> b >> c >> d;

	long long temp;
	temp = int(gcd(a, b));
	a = a / temp;
	b = b / temp;

	temp = int(gcd(c, d));
	c = c / temp;
	d = d / temp;

	long long new_child, new_mom;

	new_mom = b * d;
	new_child = (a*d) + (c*b);

	temp = gcd(new_child, new_mom);

	new_child = new_child / temp;
	new_mom = new_mom / temp;

	cout << new_child << ' ' << new_mom << endl;


}