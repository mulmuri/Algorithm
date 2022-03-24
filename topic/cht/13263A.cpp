#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template<typename T>

class LinearCHT{
	public:
		vector< pair<T, T> > stk;
		long long idx;

        pair<double,double> cross(long long a, long long b){
			double t1 = (double)(stk[b].second - stk[a].second);
			double t2 = (double)(stk[a].first - stk[b].first);
			return {t1,t2};
		}

        bool comp(pair<double, double> a, pair<double, double> b) {
            return a.first/a.second > b.first/b.second;
        }

/*
		double cross(long long a, long long b){
			double t1 = (double)(stk[b].second - stk[a].second);
			double t2 = (double)(stk[a].first - stk[b].first);
			return t1/t2;
		}
*/
		void insert(T a, T b){
			stk.emplace_back(a, b);
			while(stk.size() > 2 &&
			comp( cross(stk.size()-3, stk.size()-2) , cross(stk.size()-2, stk.size()-1)) ) {
				stk[stk.size()-2] = stk.back();
				stk.pop_back();
			}
		}

		T query(T x){
			while(idx+1 < stk.size() && !comp( cross(idx, idx+1) , {x,1} ) ) {
				idx++;
			}
            cout << 
			return x*stk[idx].first + stk[idx].second;
		}

		LinearCHT(){
			idx = 0; stk.clear();
		}
};

typedef long long ll;
typedef pair<ll, ll> p;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	LinearCHT<ll> cht;

	int n; cin >> n;
	vector<p> v(n);
	for(int i=0; i<n; i++) cin >> v[i].first;
	for(int i=0; i<n; i++) cin >> v[i].second;

	vector<ll> dp(n);
	cht.insert(v[0].second, 0);
	for(int i=1; i<n; i++){
		dp[i] = cht.query(v[i].first);
		cht.insert(v[i].second, dp[i]);
	}
	cout << dp[n-1];
}
