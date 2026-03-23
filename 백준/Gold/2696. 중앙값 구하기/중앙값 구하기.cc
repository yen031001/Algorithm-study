#if 1

#include <iostream>
#include <queue>
using namespace std;


int T, M;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	cin >> T;

	for (int i = 0; i < T; i++)
	{
		cin >> M;
		cout << (M + 1) / 2 << "\n";

		int cnt = 0;
		priority_queue<int, vector<int>, less<int>>pq_s; //maxheap
		priority_queue<int, vector<int>, greater<int>>pq_l; //minheap


		for (int j = 1; j < M+1; j++)
		{
			int tmp;
			cin >> tmp;

			if (pq_l.empty())
			{
				pq_l.push(tmp);
				cout << tmp<<' ';
				
			}
			else
			{
				if (pq_l.size() > pq_s.size())
				{
					if (tmp > pq_l.top())
					{
						int ch = pq_l.top();
						pq_l.pop();
						pq_s.push(ch);
						pq_l.push(tmp);
					}
					else
					{
						pq_s.push(tmp);
					}
				}
				else
				{
					if (tmp < pq_s.top())
					{
						int ch = pq_s.top();
						pq_s.pop();
						pq_l.push(ch);
						pq_s.push(tmp);
					}
					else
					{
						pq_l.push(tmp);
					}
					cout << pq_l.top()<<' ';
				}
			}
			cnt++;

			if (cnt == 19 && j!=M)
			{
				cout << "\n";
				cnt = -1;
			}
		
		}

		cout << '\n';
	}
}



#endif