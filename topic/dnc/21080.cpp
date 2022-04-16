#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

const int SIZE = 1000002;



int n;

ll h[SIZE];
ll hl[SIZE];
ll hr[SIZE];

ll ans;



inline ll c(ll i, ll j){
	return (j - i) * (hl[i] + hr[j]);
}

void f(int s, int e, int l, int r){
	if(s > e) return;
	int m = (s + e)/2;
	int k = l;
	for(int i=k; i <= r; i++){
	    if(c(k, m) < c(i, m)) k = i;
	}
	ans = max(ans, c(k, m));
	f(s, m-1, l, k);
	f(m+1, e, k, r);
}

int main(){
	cin >> n;

	for (int i=1; i<=n; i++) cin >> h[i];
	for (int i=1; i<=n; i++) hl[i] = max(h[i], hl[i-1]);
	for (int i=n; i; i--) hr[i] = max(h[i], hr[i+1]);

	f(1, n, 1, n);

	cout << ans;
}