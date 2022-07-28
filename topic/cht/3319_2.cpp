#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

#define SIZE 100010
#define TEMP SIZE-1



struct CHT {
	pair<long long, long long> stk[SIZE];
	long long top;

    pair<long long, long long> reserved[SIZE];
    int idx[SIZE];
    int pidx = 0;

    CHT() : top(0) {
		top = 0;
	}

    pair<double,double> cross(long long a, long long b){
		double t1 = (double)(stk[b].second - stk[a].second);
		double t2 = (double)(stk[a].first - stk[b].first);
		return {t1,t2};
	}

    bool comp(pair<double, double> a, pair<double, double> b) {
        return a.first/a.second > b.first/b.second;
    }

	void insert(long long a, long long b){
        pidx++;
        idx[pidx-1] = top;

        stk[TEMP] = {a,b};

        if (top >= 2) {
            int l = 2, r = top+1;
    		while(l < r) {
    			int m = (l + r)/2;
    			if (comp(cross(m-2, m-1) , cross(m-1, TEMP))) r = m;
    			else l = m + 1;
    		}
            top = l;
        } else {
            top++;
        }


        reserved[pidx-1] = stk[top-1];

        stk[top-1] = stk[TEMP];
	}

    void pop() {
        stk[top-1] = reserved[pidx-1];
        top = idx[pidx-1];
        pidx--;
    }

	pair<long long, long long> query(long long x) {
        if (top == 0) return {0,0};

        int l = 0, r = top - 1;
		while(l < r) {
			int m = (l + r)/2;
			if (comp( cross(m,m+1), {x,1}) ) r = m;
			else l = m + 1;
		}
        return stk[l];
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

void dfs(int t, int p) {
    auto[bj, cj] = cht.query(v[t]);
    dp[t] = v[t] * bj + cj + v[t]*l[t] + s[t];
    cht.insert(-l[t], dp[t]);

    for (auto [n, d]: adj[t]) {
        if (n == p) continue;
        dfs(n, t);
    }

    cht.pop();
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
    dfs(1, 0);

    for (int i=2; i<=n; i++) cout << dp[i] <<' ';
}