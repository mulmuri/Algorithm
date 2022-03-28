#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define SIZE 200001



template<typename T>
struct CHT {
	vector< pair<T, T> > stk;
	long long idx;

    CHT() : idx(0) {
		idx = 0; stk.clear();
	}

    pair<double,double> cross(long long a, long long b){
		double t1 = (double)(stk[b].second - stk[a].second);
		double t2 = (double)(stk[a].first - stk[b].first);
		return {t1,t2};
	}

    bool comp(pair<double, double> a, pair<double, double> b) {
        return a.first/a.second > b.first/b.second;
    }

	void insert(T a, T b){
		stk.emplace_back(a, b);
		while(stk.size() > 2 &&
		comp( cross(stk.size()-3, stk.size()-2) , cross(stk.size()-2, stk.size()-1)) ) {
			stk[stk.size()-2] = stk.back();
			stk.pop_back();
		}
	}

	pair<T,T> query(T x) {
        if (stk.size() == 0) return {0,0};

        int l = 0, r = stk.size() - 1;
		while(l < r) {
			int m = (l + r)/2;
			if (comp( cross(m,m+1), {x,1}) ) r = m;
			else l = m + 1;
		}
        return {stk[l].first, stk[l].second};
    }

	pair<T,T> query2(T x){
        if (stk.size() == 0) return {0,0};

		while(idx+1 < stk.size() && !comp( cross(idx, idx+1) , {x,1} ) ) {
			idx++;
		}
        return {stk[idx].first, stk[idx].second};
	}

};




int n;

long long s[SIZE];
long long cum[SIZE];
long long cum2[SIZE];
long long dp[SIZE];



int main() {
    cin >> n;
    for (int i=1; i<=n; i++) cin >> s[i];
    for (int i=1; i<=n; i++) cum[i] = cum[i-1] + s[i];
    for (int i=1; i<=n; i++) cum2[i] = cum2[i-1] + cum[i];
    for (int i=1; i<=n; i++) cum2[i] = (i+1)*cum[i] - cum2[i];

    CHT<long long> cht;

    for (int i=0; i<=n; i++) {
        auto[j, cj] = cht.query(-cum[i]);
        dp[i] = -cum[i] * j + cj + cum2[i];
        cht.insert(i, i*cum[i] - cum2[i]);
    };

    long long ans = 0;
    for (int i=1; i<=n; i++) ans = max(ans, dp[i]);
    cout << ans;
}