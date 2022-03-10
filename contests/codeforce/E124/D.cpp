#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <map>

using namespace std;
#define int long long
#define endl '\n'
#define SIZE 200001

typedef pair<int,int> co;

int n;

co arr[SIZE];
set<co> point;
map<co, co> ans;

int dy[] = {1,0,-1,0};
int dx[] = {0,1,0,-1};

set<co> vis;
queue<tuple<int, co, co>> q;



int32_t main() {
    cin >> n;
    
    for (int i=0; i<n; i++) {
        int x,y;
        cin >> x >> y;

        arr[i] = {x,y};
        point.insert({x,y});
    }

    for (int i=0; i<n; i++) {
        for (int k=0; k<4; k++) {
            int nx = arr[i].first + dx[k];
            int ny = arr[i].second + dy[k];

            if (point.find({nx,ny}) == point.end()) {
                q.push({0, {nx,ny}, {nx,ny}});
            }
        }
    }

    while (!q.empty()) {
        tuple<int, co, co> t = q.front();
        q.pop();
        
        for (int k=0; k<4; k++) {
            int nx = get<1>(t).first + dx[k];
            int ny = get<1>(t).second + dy[k];

            if (point.find({nx,ny}) == point.end()) continue;
            if (vis.find({nx,ny}) != vis.end()) continue;
            vis.insert({nx,ny});
            ans[{nx, ny}] = get<2>(t);

            q.push({get<0>(t)+1, {nx, ny}, get<2>(t)});
        }
    }

    for (int i=0; i<n; i++) {
        co tmp = ans[arr[i]];
        cout << tmp.first <<' '<< tmp.second << endl;
    }

}