#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

priority_queue<int> max_pq;
priority_queue<int,vector<int>,greater<int>> min_pq;
int N;
int sz = 0;
int max_sz = 0, min_sz = 0;
int mid;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	
	while (N--)
	{
		int x;
		cin >> x;

		if (min_pq.size() == max_pq.size())
		{
			max_pq.push(x);
		}
		else
		{
			min_pq.push(x);
		}

		if (!max_pq.empty() && !min_pq.empty() && max_pq.top() > min_pq.top())
		{
			int x1 = max_pq.top();
			int x2 = min_pq.top();
			max_pq.pop();
			min_pq.pop();
			max_pq.push(x2);
			min_pq.push(x1);
		}

		cout << max_pq.top() << '\n';
	}

}
