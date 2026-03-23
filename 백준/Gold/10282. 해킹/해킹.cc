#if 1

#include <iostream>
#include <queue>
#include <vector>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int T;
	cin >> T;


	for (int testcase = 0; testcase < T; testcase++)
	{
		vector<pair<int,int>>dep[10005];
		bool hacked[10005] = { false, };
		priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
		int N, D, C;
		int max_time = 0;
		int cnt = 0;

		cin >> N >> D >> C;

		hacked[C] = true;
		cnt++;

		for (int i = 0; i < D; i++)
		{
			int a, b, c;

			cin >> a >> b >> c;
			dep[b].push_back(pair<int, int>{a, c});
		}


		for (int i = 0; i < dep[C].size(); i++)
		{
			int nxt = dep[C][i].first;
			int tim = dep[C][i].second;
			q.push(pair<int, int>{tim, nxt});
		}

		int ans = 0;
		while (!q.empty())
		{
			pair<int,int>cur = q.top();
			q.pop();

			if (hacked[cur.second])
				continue;

			hacked[cur.second] = true;
			cnt++;
			ans = cur.first;

			for (int i = 0; i < dep[cur.second].size(); i++)
			{
				int nxt = dep[cur.second][i].first;
				int tim = dep[cur.second][i].second;

				if (hacked[nxt] == false)
				{
					int nxt_tim = cur.first + tim;
					q.push(pair<int, int>{nxt_tim, nxt});
				}
				
			}
		}




		cout << cnt << ' ' << ans << "\n";
	}
	

}


#endif