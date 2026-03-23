#include <iostream>
using namespace std;


int main()
{
	long long num;

	cin >> num;

	long long* table;
	

	table = (long long*)malloc((num + 1) * sizeof(long long));

	
	for (int i = 0; i < num + 1; i++)
	{
		table[i] = 0;
	}


	for (long long i = 1; i < num+1; i++)
	{
		table[i] += i;

		for (long long j = i*2; j < num+1; j+=i)
		{
			table[j] += i;
		}
	}
	
	for (long long i = 1; i < num + 1; i++)
	{
		table[i] = table[i - 1] + table[i];
	}

	cout << table[num]<<endl;

	free(table);
}
