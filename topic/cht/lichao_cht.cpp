#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

const int SIZE = 100001;




int n;

long long a[SIZE];
long long b[SIZE];
long long dp[SIZE];




struct CHT {
    int size;
    struct node { int v, l, r; };
    vector<node> T;
    int id=1;

    CHT(int n) : size(n) {
        T.resize(n);
    }

    ll f(int j, int i) { return dp[j] + 1LL*a[i]*b[j]; }
    bool cmp(int i, int j, int x) { return f(i, x) < f(j, x); }


    void insert(int a) {
    	int s=1, e=n-1, i=1;
    	while (i) {
    		int m=s+e>>1, &b=T[i].v;
    		if (cmp(a, b, m)) swap(a, b);
    		if (cmp(a, b, s)) e=m-1, i=T[i].l=T[i].l?:++id;
    		else if (cmp(a, b, e)) s=m+1, i=T[i].r=T[i].r?:++id;
    		else break;
    	}
    }

    int query(int x) {
    	int s=1, e=n-1, i=1, a=0;
    	while (i) {
    		int m=s+e>>1, b=T[i].v;
    		if (cmp(b, a, x)) a=b;
    		if (x<m) e=m-1, i=T[i].l;
    		else if (x>m) s=m+1, i=T[i].r;
    		else break;
    	}
    	return a;
    }

};





int main() {
    cin >> n;
    for (int i=0; i<n; i++) cin >> a[i];
    for (int i=0; i<n; i++) cin >> b[i];

    CHT cht;
    cht.insert(0, 0);

    for (int i=0; i<n; i++) {
        int j = cht.query(a[i]); // a(i)
        dp[i] = a[i] * b[j]; // dp(i) = a(i) * b(j) + c(j) + d(i)
        cht.insert(b[i], dp[i]); // b(i), c(i)
    };

    cout << dp[n-1];
}