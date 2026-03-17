#if 1
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef struct _Node
{
	int num;
	int idx;
	bool is_there;
}Node;

bool cmp1(const Node& x, const Node& y)
{
	if (x.num < y.num)
		return true;
	else
		return false;
}

bool cmp2(const Node& x, const Node& y)
{
	if (x.idx < y.idx)
		return true;
	else
		return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N;
	vector<int>existed;

	for (int i = 0; i < N; i++)
	{
		int tmp;
		cin >> tmp;
		existed.push_back(tmp);
	}

	sort(existed.begin(), existed.end());

	cin >> M;
	vector<Node>input;

	for (int i = 0; i < M; i++)
	{
		int tmp;
		cin >> tmp;
		input.push_back({ tmp,i,false });
	}

	sort(input.begin(), input.end(), cmp1);


	int i = 0;
	int j = 0;
	while (i < M && j<N)
	{
		if (input[i].num == existed[j])
		{
			input[i].is_there = true;
			i++;
		}
		else if (input[i].num < existed[j])
		{
			i++;
		}
		else if (input[i].num > existed[j])
		{
			j++;
		}
	}


	sort(input.begin(), input.end(), cmp2);

	for (int k = 0; k < M; k++)
	{
		cout << input[k].is_there <<"\n";
	}

}





#endif