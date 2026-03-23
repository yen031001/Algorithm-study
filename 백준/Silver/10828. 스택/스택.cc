#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

stack<int>st;
char cmd[10];
int com_input;

void com_func()
{
	if (!strcmp(cmd, "push"))
	{
		st.push(com_input);
	}
	else if (!strcmp(cmd, "pop"))
	{
		if (st.empty())
		{
			cout << "-1" << endl;
		}
		else
		{
			cout << st.top() << endl;
			st.pop();
		}
	}
	else if (!strcmp(cmd, "size"))
	{
		cout << st.size() << endl;
	}
	else if (!strcmp(cmd, "empty"))
	{
		if (st.empty())
		{
			cout << "1" << endl;
		}
		else
		{
			cout << "0" << endl;
		}
	}
	else if (!strcmp(cmd, "top"))
	{
		if (st.empty())
		{
			cout << "-1" << endl;
		}
		else
		{
			cout << st.top() << endl;
		}
	}
	
}

int main()
{
	int com_num;

	cin >> com_num;
	int com_cnt=0;

	while (com_cnt < com_num)
	{
		cin >> cmd;
		if (!strcmp(cmd,"push"))
			cin >> com_input;

		com_func();
		com_cnt++;
	}

}