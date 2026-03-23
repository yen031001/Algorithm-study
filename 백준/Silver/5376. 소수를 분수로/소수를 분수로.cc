#if 1

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

long long gcd(long long a, long long b)
{
	while (1)
	{
		long long c = a % b;
		if (c == 0)
		{
			return b;
		}
		a = b;
		b = c;
	}
}

long long d_ten(int a)
{
	long long result = 1;

	for (int i = 0; i < a; i++)
	{
		result *= 10;
	}

	return result;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	char temp='0';

	for (int i = 0; i < N; i++)
	{
		string input;
		cin >> input;

		long long r_number = 0;
		long long rn_number = 0;
		int repeat = 0;
		char number[20];
		char not_number[10];
		int idx = 0;
		int not_idx = 0;
		
		for (int j = 2; j < input.length(); j++)
		{
			temp = input[j];
			if (temp == '(')
			{
				repeat = 1;
			}
			else if (temp == ')')
			{
				break;
			}
			else
			{
				if (repeat)
				{
					number[idx] = temp;
					idx++;
				}
				else
				{
					number[idx] = temp;
					not_number[not_idx] = temp;
					idx++;
					not_idx++;
				}
			}
		}
		number[idx] = '\0';
		not_number[not_idx] = '\0';

		r_number = stoll(number);

		if(not_idx!=0 && repeat)
			rn_number = stoll(not_number);

		long long child;
		if (repeat&&not_idx!=0)
		{
			child=r_number - rn_number;

		}
		else
		{
			child = r_number;
		}


		long long parent;

		if (repeat&&not_idx!=0)
		{
			parent = d_ten(idx) -d_ten(not_idx);
		}
		else if(!repeat)
		{
			parent = d_ten(idx);
		}
		else if (repeat&&not_idx == 0)
		{
			parent = d_ten(idx) - 1;
		}


		long long GCD = gcd(child, parent);
		child = child / GCD;
		parent = parent / GCD;

		cout << child << "/" << parent << "\n";
	}



}

#endif