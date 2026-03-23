#if 1

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--)
    {
        int N, M;
        cin >> N;

        vector<int> last_rank(N);
        vector<int> adj[505];
        int in_degree[505] = { 0, };

        for (int i = 0; i < N; i++)
        {
            cin >> last_rank[i];
        }


        for (int i = 0; i < N; i++)
        {
            for (int j = i + 1; j < N; j++)
            {
                adj[last_rank[i]].push_back(last_rank[j]);
                in_degree[last_rank[j]]++;
            }
        }

        cin >> M;
        for (int i = 0; i < M; i++)
        {
            int a, b;
            cin >> a >> b;


            bool found = false;

            for (int j = 0; j < adj[a].size(); j++) {
                if (adj[a][j] == b) {
                    adj[a].erase(adj[a].begin() + j);
                    in_degree[b]--;

                    adj[b].push_back(a);
                    in_degree[a]++;
                    found = true;
                    break;
                }
            }

            if (!found) {
                for (int j = 0; j < adj[b].size(); j++) {
                    if (adj[b][j] == a) {
                        adj[b].erase(adj[b].begin() + j);
                        in_degree[a]--;

                        adj[a].push_back(b);
                        in_degree[b]++;
                        break;
                    }
                }
            }
        }

        queue<int> q;
        vector<int> ans;


        for (int i = 1; i <= N; i++)
        {
            if (in_degree[i] == 0)
            {
                q.push(i);
            }
        }

        bool is_ambiguous = false;

        while (!q.empty())
        {

            if (q.size() > 1)
            {
                is_ambiguous = true;
                break;
            }

            int cur = q.front();
            q.pop();
            ans.push_back(cur);

            for (int nxt : adj[cur])
            {
                in_degree[nxt]--;
                if (in_degree[nxt] == 0)
                {
                    q.push(nxt);
                }
            }
        }

        if (is_ambiguous)
        {
            cout << "?\n";
        }
        else if (ans.size() < N)
        {
            cout << "IMPOSSIBLE\n";
        }
        else
        {
            for (int i = 0; i < ans.size(); i++)
            {
                cout << ans[i] << ' ';
            }
            cout << "\n";
        }
    }
    return 0;
}

#endif