#if 1
#include <iostream>
#include <cstdio>
using namespace std;


long long X, Y;


int main()
{
	cin >> X >> Y;

	long long Z = 0;
	long long newZ = 0;
	Z = (Y*100) / X;
	

	if (Z == 100||Z==99)
	{
		cout << "-1" << endl;
		return 0;
	}

	long long max = 1000000000;
	long long old_max=max;
	long long min = 1;
	int answer;
	
	while (min<=max)
	{
		long long mid = (max + min) / 2;
		newZ = ((Y + mid)*100) / (X + mid);

		if (newZ != Z)
		{
			max = mid - 1;
			answer = mid;
		}
		else if (newZ== Z)
		{
			min = mid + 1;
		}
		
	}

	cout << answer << endl;


	

}


#endif