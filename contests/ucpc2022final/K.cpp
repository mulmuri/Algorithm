#include <bits/stdc++.h>

using namespace std;

int main(){
    int N;
    cin >> N;
    vector<vector<int>> adj((1 << N) + 5);
    vector<int> depth((1 << N) + 5, 0);
    vector<int> cnt((1 << N) + 5, 0);
    vector<int> lose((1 << N) + 5, 0);
    vector<int> irregular;

    int flag1 = false;
    int flag2 = false;
    int founderror = false;
    int flag = 0;
    int P[2] = {0}, IRR[2] = {0};

    for (int i = 0; i < (1 << N) - 2; ++i){
        int ui, vi;
        cin >> ui >> vi;
        adj[ui].push_back(vi);
        lose[vi]++;
    }

    function<void (int)> dfs1 = [&](int now){

        for (auto p : adj[now]){
            cnt[now]++;
            dfs1(p);
            depth[now] = max(depth[p]+1, depth[now]);
        }
        if (!founderror){
            if (cnt[now] < depth[now]){
                flag1 = true;
                irregular.push_back(now);
                IRR[flag] = 1;
                founderror = true;
            }
            if (cnt[now] > depth[now]){
                flag2 = true;
                IRR[flag] = 1;
                for (auto p : adj[now]){
                    if (depth[p] == depth[now] - 1)
                        irregular.push_back(p);
                }
                founderror = true;
            }
        }
    };

    function<void (int, int)> dfs2 = [&](int now, int h){
        if (depth[now] != h) irregular.push_back(now);
        for (auto p : adj[now]) dfs2(p, h - 1);
    };

    for (int i = 1; i <= (1 << N); ++i){
        if (lose[i] == 0){
            P[flag] = i;
            dfs1(i);
            flag++;
        }
    };

    if (!flag1 && !flag2){
        int mn = min(P[0], P[1]);
        int mx = max(P[0], P[1]);
        cout << mn << ' ' << mx << '\n';
        cout << mx << ' ' << mn << '\n';
    }
    else{
        int norm;
        if (!IRR[0]) norm = P[0];
        if (!IRR[1]) norm = P[1];
        sort(irregular.begin(), irregular.end());
        for (int p : irregular){
            cout << p << ' ' << norm << '\n';
        }
    }
        
    
}