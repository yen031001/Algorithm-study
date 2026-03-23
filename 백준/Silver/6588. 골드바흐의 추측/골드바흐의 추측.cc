#if 1

#include <iostream>
#include <cmath>
using namespace std;

#define MAX 1000000
int primeList[1000005] = { 0, };
bool isNotPrime[1000005];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N=MAX;
	int sqrtN = sqrt(N);

	int i = 2;
	for (int j = 2 * i; j <= N; j += i)
	{
		isNotPrime[j] = true;
	}

	for (i = 3; i < sqrtN; i+=2)
	{
		for (int j = 3* i; j <= N; j += (i*2))
		{
			isNotPrime[j] = true;
		}
	}

	int primeCnt = 0;
	for (int i = 2; i <= N; i++)
	{
		if (!isNotPrime[i])
			primeList[primeCnt++] = i;
	}

	int input=1;

	cin >> input;
	while (input!=0)
	{
		int i = 0;
		int out = 0;
		for (i = 0; i <(input/2); i++)
		{
			int a, b;
			a = primeList[i];
			b = input - a;
			if (!isNotPrime[b])
			{
				cout << input << " = " << a << " + " << b << "\n";
				out = 1;
				break;
			}

		}
		
		if (out==0)
		{
			cout << "Goldbach's conjecture is wrong.\n";
		}
		cin >> input;
	}

}

#endif