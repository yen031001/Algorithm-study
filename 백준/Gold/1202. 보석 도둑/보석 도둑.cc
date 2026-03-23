#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

typedef struct _Gem
{
	int price;
	int weight;
}Gem;

struct cmp {
	bool operator()(const Gem &a, const Gem&b) {
		return a.price < b.price;
	}
};

bool cmp_weight(const Gem &a, const Gem&b) {
	return a.weight < b.weight;
}
priority_queue<Gem,vector<Gem>, cmp>GemPrice;

int N, K;
int bag[300001];
Gem gem[300001];


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long total_gem = 0;

	cin >> N >> K;

	for (int i = 0; i < N; i++)
	{
		Gem temp_gem;
		cin >>gem[i].weight >> gem[i].price;
	}

	sort(gem, gem + N, cmp_weight);


	for (int i = 0; i < K; i++)
	{
		
		cin >> bag[i];
	
	}

	sort(bag, bag + K);

	

	int j = 0;
	for (int i = 0; i < K; i++)
	{
		int limit = bag[i];
		for (j; j < N; j++)
		{
			if (gem[j].weight <= limit)
			{
				GemPrice.push(gem[j]);
			}
			else
				break;
		}

		if (!GemPrice.empty())
		{
			total_gem += GemPrice.top().price;
			GemPrice.pop();
		}
		

	}

	cout << total_gem;
}