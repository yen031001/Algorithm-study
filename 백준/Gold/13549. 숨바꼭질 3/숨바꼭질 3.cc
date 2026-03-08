#if 1
#include <iostream>
#include<queue>
using namespace std;

bool visit[200005] = { false, }; //0:-1, 1:+1, 2:*2

int N, K;
int MIN_ANS = 1000000000;

priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> K;

	if (N == K)
	{
		cout << 0;
		return 0;
	}

	if (N - 1 >= 0)
	{
		q.push({ 1,N - 1 });
	}
	if (N + 1 <= 100000)
	{
		q.push({ 1, N + 1 });
	}
	if (N != 0)
	{
		q.push({0, N * 2 });
	}

	while (!q.empty())
	{
		pair<int,int> cur = q.top();
		q.pop();

		if (visit[cur.second])
			continue;

		visit[cur.second] = true;

		if (cur.second == K)
		{
			if (MIN_ANS > cur.first)
				MIN_ANS = cur.first;
			break;
		}
		
		if (cur.second - 1 >= 0 && !visit[cur.second - 1])
		{
			q.push({cur.first + 1, cur.second - 1 });
		}
		if (cur.second +1 <= 2*K && !visit[cur.second + 1])
		{
			q.push({ cur.first + 1, cur.second + 1 });
		}
		if (cur.second * 2<=2*K&&!visit[cur.second * 2] && cur.second != 0)
		{
			q.push({ cur.first,cur.second * 2 });
		}


	}

	cout << MIN_ANS;
}





#endif