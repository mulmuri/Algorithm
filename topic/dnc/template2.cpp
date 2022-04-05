#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

const int SIZE = 100001;



int n, d;

ll t[SIZE];
ll v[SIZE];

ll ans;



inline ll c(ll i, ll j){
	return (j - i) * t[j] + v[i];
}

void f(int s, int e, int l, int r){
	if(s > e) return;
	int m = (s + e)/2;
	int k = max(l, m - d);
	for(int i=k; i <= min(m, r); i++){
	    if(c(k, m) < c(i, m)) k = i;
	}
	ans = max(ans, c(k, m));
	f(s, m-1, l, k);
	f(m+1, e, k, r);
}

int main(){
	cin >> n >> d;

	for(int i=1; i<=n; i++) cin >> t[i];
	for(int i=1; i<=n; i++) cin >> v[i];
	f(1, n, 1, n);

	cout << ans;
}