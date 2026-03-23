#if 1

#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

string ori;
string boom;
stack<char>comp;
stack<char>s;

int main()
{
	cin >> ori >> boom;
	

	int boom_s = boom.size() - 1;
	int cnt = 0;
	for (int i = 0; i < ori.size(); i++)
	{
		if (ori[i] == boom[boom_s])
		{
			for (int j = 1; j <= boom_s; j++)
			{
				if (!s.empty()&&(s.top() == boom[boom_s - j]))
				{
					comp.push(s.top());
					s.pop();
				}
				else
				{
					while (!comp.empty())
					{
						s.push(comp.top());
						comp.pop();
					}
					s.push(ori[i]);
					break;
				}
			}
			while (!comp.empty())
			{
				comp.pop();
			}

		}
		else
		{
			s.push(ori[i]);
		}
		
	}

	if (s.empty())
	{
		cout << "FRULA";
	}
	else
	{
		vector<char>ans;
		while (!s.empty())
		{
			ans.push_back(s.top());
			s.pop();
		}
		
		for (int i = ans.size()-1; i>=0; i--)
		{
			cout << ans[i];
		}

	}

}



#endif