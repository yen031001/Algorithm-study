#if 1

#include <iostream>
#include <queue>
using namespace std;

priority_queue<long long, vector<long long>, greater<long long>>pq;



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;

	cin >> N>>M;

	for (int i = 0; i < N; i++)
	{
		long long tmp;
		cin >> tmp;
		pq.push(tmp);
	}


	for (int i = 0; i < M; i++)
	{
		long long a = pq.top();
		pq.pop();
		long long b = pq.top();
		pq.pop();

		a = a + b;

		pq.push(a);
		pq.push(a);
	}

	long long ans = 0;
	while (!pq.empty())
	{
		ans += pq.top();
		pq.pop();
	}

	cout << ans;
}



#endif