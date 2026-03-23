#if 1

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int N, K;
	cin >> N >> K;

	int prev;
	int now;
	vector<int>dif;
	cin >> prev;


	for (int i = 1; i < N; i++)
	{
		cin >> now;
		dif.push_back(now - prev);
		prev = now;
	}

	sort(dif.begin(), dif.end(), greater<int>());

	int notsel = K - 1;
	long long ans = 0;
	for (int i = notsel; i < dif.size(); i++)
	{
		ans += dif[i];
	}


	cout << ans;
}





#endif