#define _CRT_NO_SECURE_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

int L, C;
bool aeiou[20];
char alpha[20];
char answer[20];
int vowel = 0;
int cons = 0;


void dfs(int depth,int num)
{
	if (depth == L)
	{
		answer[depth] = '\0';
		if (vowel >= 1 && cons >= 2)
			cout << answer << endl;
		return;
	}
	for (int i = num; i < C; i++)
	{
		answer[depth] = alpha[i];
		if (aeiou[i] == true)
		{
			vowel++;
			dfs(depth + 1,i+1);
			vowel--;
		}
		else
		{
			cons++;
			dfs(depth + 1,i+1);
			cons--;
		}
	}
}



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> L >> C;


	for (int i = 0; i < C; i++)
	{
		cin >> alpha[i];
	}
	
	sort(alpha, alpha + C);
	for (int i = 0; i < C; i++)
	{
		if (alpha[i] == 'a' || alpha[i] == 'e' || alpha[i] == 'i' || alpha[i] == 'o' || alpha[i] == 'u')
			aeiou[i] = true;
	}
	dfs(0,0);
}