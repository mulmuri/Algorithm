#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

#define SIZE 100002





struct CHT {
	pair<long long, long long> stk[SIZE];
	long long idx;

    CHT() : idx(0) {
		idx = 0;
	}

    pair<double,double> cross(long long a, long long b){
		double t1 = (double)(stk[b].second - stk[a].second);
		double t2 = (double)(stk[a].first - stk[b].first);
		return {t1,t2};
	}

    bool comp(pair<double, double> a, pair<double, double> b) {
        return a.first/a.second > b.first/b.second;
    }

	pair<long long, long long> insert(long long a, long long b){
        stk[SIZE-1] = {a,b};

        if (idx >= 2) {
            int l = 2, r = idx+1;
    		while(l < r) {
    			int m = (l + r)/2;
    			if (comp(cross(m-2, m-1) , cross(m-1, SIZE-1))) r = m;
    			else l = m + 1;
    		}
            idx = l;
        } else {
            idx++;
        }

        pair<long long, long long> ret_val = stk[idx-1];
        stk[idx-1] = stk[SIZE-1];
        return ret_val;
	}

	pair<long long, long long> query(long long x) {
        if (idx == 0) return {0,0};

        int l = 0, r = idx - 1;
		while(l < r) {
			int m = (l + r)/2;
			if (comp( cross(m,m+1), {x,1}) ) r = m;
			else l = m + 1;
		}
        return {stk[l].first, stk[l].second};
    }

};



int n;
vector<pair<int, long long>> adj[SIZE];

CHT cht;

long long dp[SIZE];
long long l[SIZE];
long long s[SIZE];
long long v[SIZE];


void make_l(int t, int p) {
    for (auto [n, d]: adj[t]) {
        if (n == p) continue;
        
        l[n] = l[t] + d;
        make_l(n, t);
    }
}

void bfs(int t, int p) {
    int tmp_size = cht.idx;
    auto[bj, cj] = cht.query(v[t]);
    dp[t] = v[t] * bj + cj + v[t]*l[t] + s[t];
    pair<long long, long long> tmp_elm = cht.insert(-l[t], dp[t]);
    int tmp_size2 = cht.idx;


    for (auto [n, d]: adj[t]) {
        if (n == p) continue;
        bfs(n, t);
    }

    cht.idx = tmp_size;
    cht.stk[tmp_size2-1] = tmp_elm;
}


int main() {
    cin >> n;

    for (int i=1; i<n; i++) {
        int u,v,d; cin >> u >> v >> d;
        adj[u].push_back({v, d});
        adj[v].push_back({u, d});
    }

    for (int i=2; i<=n; i++) {
        cin >> s[i] >> v[i];
    }

    make_l(1, 0);
    bfs(1, 0);

    for (int i=2; i<=n; i++) cout << dp[i] <<' ';
}