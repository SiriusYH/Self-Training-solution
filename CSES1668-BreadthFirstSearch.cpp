#include <bits/stdc++.h>
using namespace std;
 
const long long MOD = 1000000007;
int main()
{
    int n, m; cin >> n >> m;
    vector<int> graph[n+1];
    vector<pair<int, int> > edges(m);
    for (int i = 0; i < m; i++)
    {
        int u, v; cin >> u >> v;
        edges[i] = {u, v};
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    vector<int> used(n+1);
    vector<int> dist(n+1);
    list<int> q;
    for (int i = 1; i <= n; i++){
        if (used[i] == 1) continue;
        q.push_back(i);
        while (!q.empty())
        {
            int u = q.front(); q.pop_front();
            used[u] = 1;
            for (int v : graph[u])
            {
                if (used[v] == 1) continue;
                dist[v] = dist[u] + 1;
                used[v] = 1;
                q.push_back(v);
            }
        }
    }
    bool sol = true;
    for (int i = 0; i < m; i++)
    {
        if (dist[edges[i].first] % 2 == dist[edges[i].second] % 2)
        {
            sol = false; break;
        }
    }
    if (sol)
    {
        for (int i = 1; i <= n; i++)
        {
            cout << dist[i] % 2 + 1 << " ";
        }
        cout << '\n';
    }
    else cout << "IMPOSSIBLE" << '\n';
}
