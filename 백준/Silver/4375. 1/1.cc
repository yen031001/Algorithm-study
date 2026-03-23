#include <iostream>
using namespace std;


int main()
{
	long long input;

	
	while (cin >> input)
	{
		long long remain = 1 % input;
		int num = 1;

		while (remain != 0)
		{
			remain = (remain * 10 + 1) % input;
			num++;
		}
		cout << num << endl;

	}
}
