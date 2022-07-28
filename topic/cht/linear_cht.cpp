#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define SIZE 100001



struct CHT {
	pair<long long, long long> stk[SIZE];
	long long idx;

    CHT() : idx(0) {
		idx = 0;
	}

    double cross(int a, int b) {
		double t1 = (double)(stk[b].second - stk[a].second);
		double t2 = (double)(stk[a].first - stk[b].first);
		return t1/t2;
	}

	void insert(long long a, long long b){
        stk[idx++] = {a,b};
		while(idx > 2 &&
		cross(idx-3, idx-2) > cross(idx-2, idx-1) ) {
			stk[idx-2] = stk[idx-1];
			idx--;
		}
	}

	pair<long long, long long> query(long long x) {
        int l = 0, r = idx - 1;
		while(l < r) {
			int m = (l + r)/2;
			if (cross(m,m+1) > x) r = m;
			else l = m + 1;
		}
        return stk[l];
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

    CHT cht;
    cht.insert(0, 0);

    for (int i=0; i<n; i++) {
        auto[bj, cj] = cht.query(a[i]); // a(i)
        dp[i] = a[i] * bj + cj; // dp(i) = a(i) * b(j) + c(j) + d(i)
        cht.insert(b[i], dp[i]); // b(i), c(i)
    };

    cout << dp[n-1];
}