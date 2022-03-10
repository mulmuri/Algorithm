#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL)
#define endl '\n'
#define MOD 998232453
#define INF 1e8
#define SIZE 200001



typedef pair<int,int> co;

int n;
co arr[SIZE];
set<co> vis;
set<co> point;

map<co, pair<int, co>> dp[4];

pair<int, co> dfs_ur(int x, int y) {
    if (dp[0].find({x,y}) != dp[0].end()) return dp[0][{x,y}];
    if (point.find({x,y}) == point.end()) return {
        0,
        {x,y}
    };

    cout << 0 <<' '<< x <<' '<< y << endl;

    pair<int, co> ret[2];
    ret[0] = dfs_ur(x, y+1);
    ret[1] = dfs_ur(x+1, y);
    sort(ret, ret+2);

    ret[0].first++;
    return dp[0][{x,y}] = ret[0];
}


pair<int, co> dfs_rd(int x, int y) {
    if (dp[1].find({x,y}) != dp[1].end()) return dp[1][{x,y}];
    if (point.find({x,y}) == point.end()) return {
        0,
        {x,y}
    };

    cout << 1 <<' '<< x <<' '<< y << endl;

    pair<int, co> ret[2];
    ret[0] = dfs_rd(x+1, y);
    ret[1] = dfs_rd(x, y-1);
    sort(ret, ret+2);

    ret[0].first++;
    return dp[0][{x,y}] = ret[0];
}


pair<int, co> dfs_dl(int x, int y) {
    if (dp[2].find({x,y}) != dp[2].end()) return dp[2][{x,y}];
    if (point.find({x,y}) == point.end()) return {
        0,
        {x,y}
    };

    cout << 2 <<' '<< x <<' '<< y << endl;

    pair<int, co> ret[2];
    ret[0] = dfs_dl(x, y-1);
    ret[1] = dfs_dl(x-1, y);
    sort(ret, ret+2);

    ret[0].first++;
    return dp[0][{x,y}] = ret[0];
}

pair<int, co> dfs_lu(int x, int y) {
    if (dp[3].find({x,y}) != dp[2].end()) return dp[3][{x,y}];
    if (point.find({x,y}) == point.end()) return {
        0,
        {x,y}
    };

    cout << 3 <<' '<< x <<' '<< y << endl;

    pair<int, co> ret[2];
    ret[0] = dfs_lu(x-1, y);
    ret[1] = dfs_lu(x, y+1);
    sort(ret, ret+2);

    ret[0].first++;
    return dp[0][{x,y}] = ret[0];
}

pair<int, pair<int,int>> ans[SIZE];


int32_t main() {
    cin >> n;
    for (int i=0; i<n; i++) cin >> arr[i].first >> arr[i].second;
    for (int i=0; i<n; i++) point.insert(arr[i]);

    for (int i=0; i<n; i++) {
        dfs_ur(arr[i].first, arr[i].second);
        dfs_rd(arr[i].first, arr[i].second);
        dfs_dl(arr[i].first, arr[i].second);
        dfs_lu(arr[i].first, arr[i].second);
    }

    for (int i=0; i<n; i++) ans[i].first = INF;

    for (int i=0; i<n; i++) {
        for (int j=0; j<4; j++) {
            cout << dp[j][arr[i]].first;
            ans[i] = min(ans[i], dp[j][arr[i]]);
        }
    }

    for (int i=0; i<n; i++) {
        cout << ans[i].second.first <<' '<< ans[i].second.second << endl;
    }
    
}