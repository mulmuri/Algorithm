#include <bits/stdc++.h>
using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL)
#define endl '\n'
#define int long long

const int MOD = 998244353;
const int INF = 1e18;
const int SIZE = 300001;


int n,m;
int arr[SIZE] = {0,};
bool visited[SIZE] = {0,};

void dfs(int num, int cnt)
{
    if(cnt == m)
    {
        for(int i = 0; i < m; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }
    for(int i = num; i <= n; i++)
    {
        if(!visited[i])
        {
            visited[i] = true;
            arr[cnt] = i;
            dfs(i+1,cnt+1);
            visited[i] = false;
        }
    }
}

int32_t main() {
    fastio;
    
    cin >> m >> n;
    dfs(1, 0);
}