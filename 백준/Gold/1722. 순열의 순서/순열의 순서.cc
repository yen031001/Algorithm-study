#if 1
#include <iostream>
using namespace std;

int N;

bool num[22];
long long fact[22];
int num_list[22];
long long ans=0;

void make_fact(int n)
{
	fact[0] = 1;
	fact[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		fact[i] =i*fact[i-1];
	}
}

int find_num(int a)
{
	for (int i = 1; i <= N; i++)
	{
		if (num[i] == true)
		{
			a--;
		}
		if (a == 0)
		{
			num[i] = false;
			return i;
		}
	}
}

void solve_one(int n, long long k)

{
	while (n > 1)
	{
		int i = 1;
		long long a = fact[n - 1];

		while (1)
		{
			if (k <= a)
			{
				cout << find_num(i) << ' ';
				break;
			}
			else
			{
				i++;
				a = fact[n - 1]*i;
			}

		}
		a -= fact[n - 1];
		n--;
		k = k - a;
	}

	if (n == 1)
	{
		cout << find_num(1);
	}

}

void solve_two(int n)
{
	for (int idx = 0; idx < N; idx++)
	{
		int k = 0;
		for (int i = 1; i <= N; i++)
		{
			if (num[i] == true && num_list[idx] == i)
			{
				ans += (fact[n - 1] * k);
				num[i] = false;
				break;
			}
			else if (num[i] == true)
				k++;
		}
		n--;
	}
	
	ans++;
}


int main()
{
	
	int small;

	cin >> N>>small;

	for (int i = 1; i <= N; i++)
		num[i] = true;

	if (small == 1)
	{
		make_fact(N);
		long long k;
		cin >> k;
		solve_one(N, k);
	}
	else if (small == 2)
	{
		for (int i = 0; i < N; i++)
		{
			int temp = 0;
			cin >> temp;
			num_list[i]=temp;
			
		}
		make_fact(N);
		solve_two(N);
		cout << ans;
	}


	

}




#endif