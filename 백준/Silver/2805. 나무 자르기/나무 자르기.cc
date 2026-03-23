#if 1
#include <iostream>
#include <cstdio>
using namespace std;

int N;
long long M;
int list[1000001];

long long cal_wood(long leng)
{
	long long sum = 0;
	for (int i = 0; i < N; i++)
	{
		long long temp = list[i] - leng;
		if (temp > 0)
			sum += temp;
	}
	return sum;
}

int find_div(int high)
{
	int mid = 0;
	int big=0;
	int low = 0;

	while (low <= high)
	{
		mid = (high + low) / 2;
		long long sum_temp = cal_wood(mid);
		if (sum_temp >= M)
		{
			if(mid>big)
				big = mid;
			low = mid + 1;
		}
		else if (sum_temp < M)
		{
			high = mid - 1;
			
		}
	}
	
	return big;
}

int main()
{
	cin >> N >> M;
	int max_wood=0;


	for (int i = 0; i < N; i++)
	{
		scanf("%d", &list[i]);
		if (list[i] > max_wood)
			max_wood = list[i];
	}


	int result=find_div(max_wood);

	cout << result << endl;

}


#endif