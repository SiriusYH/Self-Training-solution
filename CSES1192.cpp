#include <bits/stdc++.h>
using namespace std;
 
const long long MOD = 1000000007;
int main()
{
    int n, m; cin >> n >> m;
    vector<string> S(n);
    for (int i = 0; i < n; i++) cin >> S[i];
    int used[n][m]; memset(used, 0, sizeof(used));
    int cnt = 0;
    list<pair<int, int> > q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (S[i][j] == '#') continue;
            if (used[i][j] == 1) continue;
            cnt++;
            q.push_back({i, j});
            while (!q.empty())
            {
                pair<int, int> p = q.front(); q.pop_front();
                int x = p.first; int y = p.second;
                if (x > 0)
                {
                    if (used[x-1][y] == 0 && S[x-1][y] == '.'){
                        q.push_back({x-1, y}); used[x-1][y] = 1;
                    }
                }
                if (x < n-1)
                {
                    if (used[x+1][y] == 0 && S[x+1][y] == '.'){
                        q.push_back({x+1, y}); used[x+1][y] = 1;
                    }
                }
                if (y > 0)
                {
                    if (used[x][y-1] == 0 && S[x][y-1] == '.'){
                        q.push_back({x, y-1}); used[x][y-1] = 1;
                    }
                }
                if (y < m-1)
                {
                    if (used[x][y+1] == 0 && S[x][y+1] == '.'){
                        q.push_back({x, y+1}); used[x][y+1] = 1;
                    }
                }
            }
        }
    }
    cout << cnt << '\n';
}
