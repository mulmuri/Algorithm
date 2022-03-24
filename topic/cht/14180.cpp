#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define SIZE 200001
#define double long double


template<typename T>
struct CHT {
	vector<pair<T,T>> stk;
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
        int l = 0, r = stk.size() - 1;
		while(l < r) {
			int m = (l + r)/2;
			if (comp( cross(m,m+1), {x,1}) ) r = m;
			else l = m + 1;
		}
        return {stk[l].first, stk[l].second};
    }

	pair<T,T> query2(T x){
		while(idx+1 < stk.size() && !comp( cross(idx, idx+1) , {x,1} ) ) {
			idx++;
		}
        return {stk[idx].first, stk[idx].second};
	}

};



int n;

long long a[SIZE];
long long psum[SIZE];
long long dp1[SIZE];
long long dp2[SIZE];

int main() {
    cin >> n;

    for (int i=1; i<=n; i++) cin >> a[i];
    for (int i=1; i<=n; i++) psum[i] = psum[i-1] + a[i];

    CHT<long long> cht1;

    dp1[1] = 0;
    cht1.insert(1, -psum[0]);

    for (int i=2; i<=n; i++) {
        auto[bj, cj] = cht1.query(a[i]);
        dp1[i] = a[i] * bj + cj - a[i]*i + psum[i-1];
        cht1.insert(i, -psum[i-1]);
    }


    CHT<long long> cht2;

    dp2[n] = 0;
    cht2.insert(-n, -psum[n]);

    for (int i=n-1; i>=1; i--) {
        auto[bj, cj] = cht2.query(-a[i]);
        dp2[i] = -a[i] * bj + cj + psum[i] - a[i]*i;
        cht2.insert(-i, -psum[i]);
    }


    long long sum = 0, dif1 = 0, dif2 = 0;

    for (int i=1; i<=n; i++) sum += a[i]*i;
    for (int i=1; i<=n; i++) dif1 = max(dif1, dp1[i]);
    for (int i=1; i<=n; i++) dif2 = max(dif2, dp2[i]);

    cout << sum + max(dif1, dif2);
}