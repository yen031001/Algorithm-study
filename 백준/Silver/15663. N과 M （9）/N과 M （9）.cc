#if 1

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int M, N;
vector<int>input;

void print_ans(vector<int>answer)
{
	for (int i = 0; i < answer.size(); i++)
	{
		cout << answer[i] << ' ';
	}
}


void find_ans(int* use_now,vector<int>ans)
{
	int bf;
	if (ans.size() == (M - 1))
	{
		bf = -1; //중복 방지 로직 추가해야함
		for (int i = 0; i < N; i++)
		{
			if (!use_now[i] && bf != input[i])
			{
				print_ans(ans);
				cout << input[i] << "\n";
				bf = input[i];
			}
		}
	}
	else
	{
		bf = -1;
		for (int i = 0; i < N; i++)
		{
			if (!use_now[i]&&bf!=input[i])
			{
				ans.push_back(input[i]);
				use_now[i] = true;
				find_ans(use_now, ans);
				ans.pop_back();
				use_now[i] = false;
				bf = input[i];
			}
		}
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	cin >> N >> M;
	int tmp;
	for (int i = 0; i < N;i++)
	{
		cin >> tmp;
		input.push_back(tmp);
	}

	//오름차순 정렬
	sort(input.begin(), input.end(), less<int>());
	int used[10] = { false, };
	
	vector<int>fin_ans;

	find_ans(used, fin_ans);
}






#endif