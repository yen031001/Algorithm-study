#if 1
#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

stack<long long>s;


bool NUM(long long x)
{
	s.push(x);
	return true;
}

bool POP()
{
	if (s.empty())
		return false;

	s.pop();
	return true;
}

bool INV()
{
	if (s.empty())
		return false;

	long long tmp = s.top();
	s.pop();
	s.push(tmp * (-1));
	return true;
}

bool DUP()
{
	if (s.empty())
		return false;
	long long tmp = s.top();
	s.push(tmp);
	return true;
}

bool SWP()
{
	if (s.size() < 2)
		return false;
	long long a, b;
	a = s.top();
	s.pop();
	b = s.top();
	s.pop();
	s.push(a);
	s.push(b);
	return true;
}

bool ADD()
{
	if (s.size() < 2)
		return false;
	long long a, b;
	a = s.top();
	s.pop();
	b = s.top();
	s.pop();
	if (a + b > 1000000000 || (a + b) < -1000000000)
		return false;
	s.push(a + b);
	return true;
}

bool SUB()
{
	if (s.size() < 2)
		return false;
	long long a, b;
	a = s.top();
	s.pop();
	b = s.top();
	s.pop();
	if ((b-a) > 1000000000 || (b-a) < -1000000000)
		return false;
	s.push(b-a);
	return true;
}

bool MUL()
{
	if (s.size() < 2)
		return false;
	long long a, b;
	a = s.top();
	s.pop();
	b = s.top();
	s.pop();
	if ((a*b) > 1000000000 || (a*b) < -1000000000)
		return false;
	s.push(a*b);
	return true;
}

bool DIV()
{
	if (s.size() < 2)
		return false;
	long long a, b;
	a = s.top();
	s.pop();
	b = s.top();
	s.pop();
	if (a == 0)
		return false;
	int cnt = 0;
	if (a < 0)
	{
		cnt++;
		a = a * (-1);
	}
	if (b < 0)
	{
		cnt++;
		b = b * (-1);
	}
	if ((b/a) > 1000000000 || (b/a) < -1000000000)
		return false;

	long long res = b / a;
	if (cnt == 1)
		res = res * (-1);
	s.push(res);
	return true;
}

bool MOD()
{
	if (s.size() < 2)
		return false;
	long long a, b;
	a = s.top();
	s.pop();
	b = s.top();
	s.pop();
	if (a == 0)
		return false;
	int cnt = 0;
	if (a < 0)
	{
		a = a * (-1);
	}
	if (b < 0)
	{
		cnt++;
		b = b * (-1);
	}
	if ((b % a) > 1000000000 || (b % a) < -1000000000)
		return false;

	long long res = b % a;
	if (cnt==1)
		res = res * (-1);
	s.push(res);
	return true;
}


bool find_func(string cmd, long long x)
{
	bool output=true;

	if (cmd == "NUM")
		output = NUM(x);
	else if (cmd == "POP")
		output = POP();
	else if (cmd == "INV")
		output = INV();
	else if (cmd == "DUP")
		output = DUP();
	else if (cmd == "SWP")
		output = SWP();
	else if (cmd == "ADD")
		output = ADD();
	else if (cmd == "SUB")
		output = SUB();
	else if (cmd == "MUL")
		output = MUL();
	else if (cmd == "DIV")
		output = DIV();
	else if (cmd == "MOD")
		output = MOD();

	if (!output)
		return false;
	else
		return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	vector<pair<string, long long>>prog;
	while (1)
	{

		string input;
		long long x_num;
	

		cin >> input;
		if (input == "NUM")
			cin >> x_num;
		if (input == "END")
		{
			int num_size;
			cin >> num_size;
			bool res=true;
			for (int i = 0; i < num_size; i++)
			{
				int num;
				cin >> num;
				s.push(num);
				for (int j = 0; j < prog.size(); j++)
				{
					res=find_func(prog[j].first, prog[j].second);
					if (!res)
					{
						cout << "ERROR" << "\n";
						break;
					}
				}
				if (res)
				{
					if (s.size() != 1)
						cout << "ERROR" << "\n";
					else
						cout << s.top() << "\n";
				}
				while (!s.empty())
				{
					s.pop();
				}
			}
			prog.clear();
			cout << "\n";
		}
		else if (input == "QUIT")
			break;
		else
		{
			prog.push_back({ input,x_num });
		}
	}

	
}



#endif


