#include <iostream>
#include <cstdio>
#include <deque>
using namespace std;

int N, L;
int list[5000005];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	deque<int>d;

	cin >> N>>L;
	for (int i = 0; i < N; i++)
	{
		cin >> list[i];
	}

	

	for (int i = 0; i < N; i++)
	{
		if (!d.empty()&&d.front() < i - L + 1)d.pop_front();
		int el = list[i];
		while (!d.empty()&&list[d.back()] >= el)
		{
			d.pop_back();
		}
		
		d.push_back(i);
		cout<<list[d.front()]<<' ';
	}
}