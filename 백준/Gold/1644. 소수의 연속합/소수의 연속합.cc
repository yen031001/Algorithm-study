#if 1

#include <iostream>
#include <cmath>
using namespace std;

#define MAX 4000005
int primeList[MAX] = { 0, };
bool isNotPrime[MAX];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	

	int N;
	cin >> N;

	int sqrtN = sqrt(N+1);

	int i = 2;
	for (int j = 2 * i; j <= N; j += i)
	{
		isNotPrime[j] = true;
	}

	for (i = 3; i < sqrtN+1; i += 2)
	{
		for (int j = 3 * i; j <= N; j += (i * 2))
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




	int l = 0, r = 0;
	int sum=0;
	int result = 0;

	sum = primeList[0];

	while (primeList[r] <= N && l <= r && r<=primeCnt)
	{
		if (sum > N)
		{
			sum= sum - primeList[l];
			l++;
		}
		else if (sum < N)
		{
			r++;
			sum=sum + primeList[r];
		}
		else if (sum == N)
		{
			result++;
			sum = sum - primeList[l];
			l++;
		}
	}

	cout << result;
	



}

#endif