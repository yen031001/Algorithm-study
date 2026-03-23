#if 1
#include <iostream>
#include <vector>
using namespace std;

int visitOrder[10005];
bool isCut[10005];
vector<int>EdgeList[10005];
int order = 0;
int V, E;
int allSpan = 0;

int MIN(int a, int b)
{
	if (a < b)
		return a;
	else
		return b;
}

int dfs(int curr, int parent)
{
	if (visitOrder[curr] != 0)
		return visitOrder[curr];

	order++;
	visitOrder[curr] = order;
	allSpan++;

	int minOrder = visitOrder[curr]; //일단 자기자신이 min

	int child = 0; //연결된 자식의 수

	for (int i = 0; i < EdgeList[curr].size(); i++)
	{
		int next = EdgeList[curr][i];

		if (next == parent)
			continue;
		if (visitOrder[next] == 0)  //방문한적 없는 노드면 child++ (DFS 트리에 추가)
		{
			child++;
			int low = dfs(next, curr); //자식에 대해 dfs -> low(자식이 갈 수 있는 최소) 받아오기
			
			//cout << "curr: " << curr << " low: " << low << " visitOrder: " << visitOrder[curr] << endl;
			if (parent != -1 && low >= visitOrder[curr]) 
				isCut[curr] = true; //부모가 아닐 때 단절점 조건
			minOrder = MIN(minOrder, low); //뒤에서 minOrder return 하면 그게 부모 텀에서 low로 쓰임-> 자기 자식까지 반영한 low로 바꿔야함 
		}
		else
		{
			minOrder = MIN(minOrder, visitOrder[next]); //방문한 적 있는 노드면 back edge라는 얘기 -> min 업데이트
		}

	}

	if (parent == -1 && child > 1) //부모고 자식이 2개 이상이면 단절점
		isCut[curr] = true;

	return minOrder;

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> V >> E;

	for (int i = 0; i < E; i++)
	{
		int a, b;
		cin >> a >> b;

		EdgeList[a].push_back(b);
		EdgeList[b].push_back(a);
	}

	while (allSpan != V)
	{
		for (int i = 1; i <= V; i++)
		{
			if (visitOrder[i] == 0)
			{
				order = 0;
				dfs(i, -1);
			}
		}
	}

	vector<int>ans;

	for (int i = 1; i <= V; i++)
	{
		if (isCut[i] == true)
			ans.push_back(i);
	}

	cout << ans.size()<<"\n";

	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << ' ';
	}
}

#endif