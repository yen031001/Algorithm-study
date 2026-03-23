#if 1

#include <iostream>
#include <string>
using namespace std;

int A, C, G, T;
int a = 0, c = 0, g = 0, t = 0;


void add(char alpha)
{
	switch (alpha)
	{
		case 'A':
			a++;
			break;
		case 'C':
			c++;
			break;
		case 'G':
			g++;
			break;
		default:
			t++;
			break;
	}
}

void sub(char alpha)
{
	switch (alpha)
	{
	case 'A':
		a--;
		break;
	case 'C':
		c--;
		break;
	case 'G':
		g--;
		break;
	default:
		t--;
		break;
	}
}

bool test()
{
	if (a < A)
		return false;

	if (c < C)
		return false;

	if (g < G)
		return false;
	if (t < T)
		return false;

	return true;

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int S, P;
	int ans=0;

	cin >> S >> P;

	string input;

	cin >> input;

	

	cin >> A >> C >> G >> T;

	int i = 0;
	for (i = 0; i < P; i++)
	{
		add(input[i]);
	}


	//int state = 0;

	if (test())
	{
		ans++;
		//state =1;
	}
		

	for (; i < S; i++)
	{
		/*if (input[i] == input[i - P])
		{
			ans = ans + state;
			continue;
		}*/

		add(input[i]);
		sub(input[i - P]);
		if (test())
		{
			ans++;
			//state = 1;
		}
		//else
			//state = 0;
	}


	cout << ans;

}

#endif