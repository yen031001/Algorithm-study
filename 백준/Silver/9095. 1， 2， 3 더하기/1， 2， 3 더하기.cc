#include <iostream>
using namespace std;

int main()
{
	int test_num;
	int* test_case;
	int max=0;

	cin >> test_num;

	test_case = (int*)malloc((test_num) * sizeof(int));

	for (int i = 0; i < test_num; i++)
	{
		cin >> test_case[i];
		if (test_case[i] > max)
			max = test_case[i];
	}

	int* table = (int*)malloc((max + 1) * sizeof(int));

	for (int i = 0; i < max + 1; i++)
	{
		if (i == 1)
		{
			table[i] = 1;
			continue;
		}
		else if (i == 2)
		{
			table[i] = 2;
			continue;
		}
		else if (i == 3)
		{
			table[i] = 4;
			continue;
		}

		table[i] = table[i - 1] + table[i - 2] + table[i - 3];
	}

	for (int i = 0; i < test_num; i++)
	{
		int a = test_case[i];
		cout << table[a] << endl;
	}

	free(table);
	free(test_case);
}