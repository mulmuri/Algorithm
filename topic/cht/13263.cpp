#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define SIZE 100001



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

	pair<T,T> query(T x){
		while(idx+1 < stk.size() && !comp( cross(idx, idx+1) , {x,1} ) ) {
			idx++;
		}
        return {stk[idx].first, stk[idx].second};
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

    CHT<long long> cht; // dp(i) = a(i) * b(j) + c(j) + d(i)

    dp[0] = 0;
    cht.insert(b[0], dp[0]);

    for (int i=1; i<n; i++) {
        auto[bj, cj] = cht.query(a[i]);
        dp[i] = a[i] * bj + cj;
        cht.insert(b[i], dp[i]);
    };

    cout << dp[n-1];
}