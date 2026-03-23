#if 1


#include <iostream>
#include <cmath>
#include <queue>
using namespace std;

int N;

//홀수만 보면됨

bool is_prime(int a)
{
	int thres = sqrt(a);

	for (int i = 3; i <= thres; i = i + 2)
	{
		if (a % i == 0)
			return false;
	}

	return true;
}
void find_prime(int cnt,queue<int>pre_answer)
{
	queue<int>now_answer;

	if (cnt == N)
	{
		while (!pre_answer.empty())
		{
			int output = pre_answer.front();
			pre_answer.pop();
			cout << output << "\n";
		}
	}
	else
	{
		while (!pre_answer.empty())
		{
			int cur = pre_answer.front();
			pre_answer.pop();

			for (int i = 1; i <= 9; i = i + 2)
			{
				int tmp = cur * 10 + i;
				if (is_prime(tmp))
					now_answer.push(tmp);
			}
		}

		find_prime(cnt + 1, now_answer);
	}

	
}




int main()
{
	cin >> N;

	queue<int> ans;

	ans.push(2);
	ans.push(3);
	ans.push(5);
	ans.push(7);

	find_prime(1, ans);


}



#endif