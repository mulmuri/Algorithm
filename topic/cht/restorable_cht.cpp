#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define SIZE 100001



template<typename T>
struct CHT {
	pair<T, T> stk[SIZE];
	long long idx;

    CHT() : idx(0) {
		idx = 0;
	}

    pair<double,double> cross(long long a, long long b) {
		double t1 = (double)(stk[b].second - stk[a].second);
		double t2 = (double)(stk[a].first - stk[b].first);
		return {t1,t2};
	}

    bool comp(pair<double, double> a, pair<double, double> b) {
        return a.first/a.second > b.first/b.second;
    }

	void insert(T a, T b){
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

        stk[idx-1] = stk[SIZE-1];
	}

	pair<T,T> query(T x) {
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

long long a[SIZE];
long long b[SIZE];
long long dp[SIZE];



int main() {
    cin >> n;
    for (int i=0; i<n; i++) cin >> a[i];
    for (int i=0; i<n; i++) cin >> b[i];

    CHT<long long> cht; 

    for (int i=0; i<n; i++) {
        auto[bj, cj] = cht.query(a[i]); // a(i)
        dp[i] = a[i] * bj + cj; // dp(i) = a(i) * b(j) + c(j) + d(i)
        cht.insert(b[i], dp[i]); // b(i), c(i)
    };

    cout << dp[n-1];
}