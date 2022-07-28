#include <bits/stdc++.h>
using namespace std;

#define SIZE 250010
#define TEMP SIZE-1

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define endl '\n'


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



int n, sz, t;
long long ldp[SIZE];
long long rdp[SIZE];

struct co {
    long long x,y;
};

co larr[SIZE];
co rarr[SIZE];



int32_t main() {
    cin >> n;
    sz = n/2-1;

    cin >> t >> t;

    for (int i=1; i<=sz; i++) {
        cin >> rarr[i].x >> larr[i].y;
        cin >> larr[i].x >> rarr[i].y;
    }
    cin >> t >> t;

    for (int i=1; i<=sz; i++) rarr[i].x = larr[sz].x - rarr[i].x;
    reverse(rarr+1, rarr+sz+1);

    {
        CHT cht;
        vector<pair<int,int>> stk;
        stk.push_back({0,0});
    
        for (int i=1; i<=sz; i++) {
            long long x = larr[i].x, y = larr[i].y;
            while (stk.back().first > y) {
                stk.pop_back();
                cht.pop();
            }
            
            cht.insert(-y, y * stk.back().second);
            stk.push_back({y, x});
    
            auto[bj, cj] = cht.query(x);
            ldp[i] = -(x*bj + cj);
        }
    }

    {
        CHT cht;
        vector<pair<int,int>> stk;
        stk.push_back({0,0});
        cht.insert(0, 0);
    
        for (int i=1; i<=sz; i++) {
            long long x = rarr[i].x, y = rarr[i].y;
    
            while (stk.back().first > y) {
                stk.pop_back();
                cht.pop();
            }
            
            cht.insert(-y, y * stk.back().second);
            stk.push_back({y, x});
    
            auto[bj, cj] = cht.query(x);
            rdp[i] = -(x*bj + cj);
        }
    }

    //for (int i=1; i<=sz; i++) cout << ldp[i] <<' '; cout << endl;
    //for (int i=1; i<=sz; i++) cout << rdp[i] <<' '; cout << endl;

    long long ans = 0;
    for (int i=0; i<=sz; i++) {
        ans = max(ans, ldp[i] + rdp[sz-i]);
    }
    cout << ans;
}