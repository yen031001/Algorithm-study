#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<stdio.h>
using namespace std;
#define MAX_NUM 1000000

int main()
{
	long long N;
	cin >> N;

	long long num = MAX_NUM;


	long long* table;
	

	table = (long long*)malloc((num + 1) * sizeof(long long));

	
	for (int i = 0; i < num + 1; i++)
	{
		table[i] = 0;
	}


	for (long long i = 1; i < num+1; i++)
	{

		for (long long j = i; j < num+1; j+=i)
		{
			table[j] += i;
		}
	}
	
	for (long long i = 1; i < num + 1; i++)
	{
		table[i] = table[i - 1] + table[i];
	}

	long long index=0;
	for (int i = 0; i < N; i++)
	{
		scanf("%lld", &index);
		printf("%lld\n", table[index]);
	}


	free(table);
}