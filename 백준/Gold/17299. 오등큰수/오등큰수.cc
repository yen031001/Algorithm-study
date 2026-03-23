#if 1
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int f_array[1000005] = { 0, };
stack<int>s;
vector<int>input;
vector<int>ans;

int main()
{
	int N;

	cin >> N;


	for (int i = 0; i < N; i++)
	{
		int tmp;
		cin >> tmp;
		input.push_back(tmp);
		f_array[tmp]++;
	}


	for (int i = N - 1; i >= 0; i--)
	{
		int cur = input[i];
		while (!s.empty() && f_array[cur] >= f_array[s.top()])
		{
			s.pop();
		}

		if (s.empty())
		{
			ans.push_back(-1);
		}
		else
		{
			ans.push_back(s.top());
		}

		s.push(cur);
	}

	for (int i = N - 1; i >= 0; i--)
	{
		cout << ans[i] << ' ';
	}


}
#endif