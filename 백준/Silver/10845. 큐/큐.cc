#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

queue<int>dq;
char cmd[10];
int com_input;

void com_func()
{
	if (!strcmp(cmd, "push"))
	{
		dq.push(com_input);
	}
	else if (!strcmp(cmd, "pop"))
	{
		if (dq.empty())
		{
			cout << "-1" << endl;
		}
		else
		{
			cout << dq.front() << endl;
			dq.pop();
		}
	}
	else if (!strcmp(cmd, "size"))
	{
		cout << dq.size() << endl;
	}
	else if (!strcmp(cmd, "empty"))
	{
		if (dq.empty())
		{
			cout << "1" << endl;
		}
		else
		{
			cout << "0" << endl;
		}
	}
	else if (!strcmp(cmd, "front"))
	{
		if (dq.empty())
		{
			cout << "-1" << endl;
		}
		else
		{
			cout << dq.front() << endl;
		}
	}
	else if (!strcmp(cmd, "back"))
	{
		if (dq.empty())
		{
			cout << "-1" << endl;
		}
		else
		{
			cout << dq.back() << endl;
		}
	}

}

int main()
{
	int com_num;

	cin >> com_num;
	int com_cnt = 0;

	while (com_cnt < com_num)
	{
		cin >> cmd;
		if (!strcmp(cmd, "push"))
			cin >> com_input;

		com_func();
		com_cnt++;
	}

}