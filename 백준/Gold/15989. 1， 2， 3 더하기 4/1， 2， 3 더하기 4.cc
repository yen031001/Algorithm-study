#if 1


#include <iostream>
using namespace std;

long long arr[10001][3] = {0,};

int main()
{

	arr[1][0] = 1;
	arr[1][1] = 0;
	arr[1][2] = 0;
	arr[2][0] = 1;
	arr[2][1] = 1;
	arr[2][2] = 0;
	arr[3][0] = 1;
	arr[3][1] = 1;
	arr[3][2] = 1;

	for (int i = 4; i <= 10000; i++)
	{
		arr[i][0] = arr[i - 1][0];
		arr[i][1] = arr[i - 2][0] + arr[i - 2][1];
		arr[i][2] = arr[i - 3][0] + arr[i - 3][1] + arr[i - 3][2];
	}

	int T;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		int a;
		cin >> a;
		cout << arr[a][0]+arr[a][1]+arr[a][2] << "\n";
	}
	
}

#endif