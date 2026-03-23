#if 1


#include <iostream>
using namespace std;

long long numdiv = 1000000009;
int arr[1000001] = { 0, };

int main()
{

	arr[1] = 1;
	arr[2] = 2;
	arr[3] = 4;

	for (int i = 4; i <= 1000000;i++)
	{
		long long a = (long long)arr[i - 1];
		long long b = (long long)arr[i - 2];
		long long c = (long long)arr[i - 3];
		long long tmp =(a+b+c) % numdiv;
		arr[i] = tmp;
	}

	int T;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		int a;
		cin >> a;
		cout << arr[a] << "\n";
	}
	
}

#endif