#include <iostream>
#include <vector>
#include <algorithm>
#include <complex>
using namespace std;

typedef long long ll;
const double pi = 3.14159265358979323846264;

typedef complex<double> base;

void fft(vector<base> &a, bool inv){
    int n = a.size(), j = 0;
    vector<base> roots(n/2);
    for (int i=1; i<n; i++){
        int bit = (n >> 1);
        while (j >= bit){
            j -= bit;
            bit >>= 1;
        }
        j += bit;
        if(i < j) swap(a[i], a[j]);
    }
    double ang = 2 * acos(-1) / n * (inv ? -1 : 1);
    for (int i=0; i<n/2; i++){
        roots[i] = base(cos(ang * i), sin(ang * i));
    }

    for (int i=2; i<=n; i<<=1){
        int step = n / i;
        for (int j=0; j<n; j+=i){
            for (int k=0; k<i/2; k++){
                base u = a[j+k], v = a[j+k+i/2] * roots[step * k];
                a[j+k] = u+v;
                a[j+k+i/2] = u-v;
            }
        }
    }
    if (inv) for(int i=0; i<n; i++) a[i] /= n;
}

vector<ll> conv(vector<ll> &v, vector<ll> &w, ll mod){
    int n = 2;
    while (n < v.size() + w.size()) n <<= 1;
    vector<base> v1(n), v2(n), r1(n), r2(n);
    for (int i=0; i<v.size(); i++){
        v1[i] = base(v[i] >> 15, v[i] & 32767);
    }
    for (int i=0; i<w.size(); i++){
        v2[i] = base(w[i] >> 15, w[i] & 32767);
    }
    fft(v1,0);
    fft(v2,0);
    for (int i=0; i<n; i++){
        int j = (i ? (n - i) : i);
        base ans1 = (v1[i] + conj(v1[j])) * base(0.5,0);
        base ans2 = (v1[i] - conj(v1[j])) * base(0,-0.5);
        base ans3 = (v2[i] + conj(v2[j])) * base(0.5,0);
        base ans4 = (v2[i] - conj(v2[j])) * base(0,-0.5);
        r1[i] = (ans1 * ans3) + (ans1 * ans4) * base(0,1);
        r2[i] = (ans2 * ans3) + (ans2 * ans4) * base(0,1);
    }
    fft(r1,1);
    fft(r2,1);
    vector<ll> ret(n);
    for (int i=0; i<n; i++){
        ll av = (ll)round(r1[i].real());
        ll bv = (ll)round(r1[i].imag()) + (ll)round(r2[i].real());
        ll cv = (ll)round(r2[i].imag());
        av %= mod, bv %= mod, cv %= mod;
        ret[i] = (av << 30) + (bv << 15) + cv;
        ret[i] %= mod;
        ret[i] += mod;
        ret[i] %= mod;
    }
    return ret;
}



const int SIZE = 200010;
const ll MOD = 1000003;



ll n, a, b, c;
ll l[SIZE];
ll t[SIZE];

ll fact[SIZE*2];
ll invf[SIZE*2];
ll powa[SIZE];
ll powb[SIZE];


ll power(ll a, ll e) {
    ll r = 1, b = a % MOD;
    while (e > 0) {
        if (e & 1)
            r = r * b % MOD;
        b = b * b % MOD;
        e >>= 1;
    }
    return r;
}

ll inv(ll x) {
    return power(x, MOD-2);
}

ll comb(int n, int k) {
    return fact[n] * invf[k] % MOD * invf[n-k] % MOD;
}


int main() {
    cin >> n >> a >> b >> c;
    for (int i=0; i<n; i++) cin >> l[n-1-i];
    for (int i=0; i<n; i++) cin >> t[n-1-i];


    powa[0] = powb[0] = 1;
    for (int i=1; i<n; i++) {
        powa[i] = powa[i-1] * a % MOD;
        powb[i] = powb[i-1] * b % MOD;
    }

    fact[0] = 1;
    for (int i=1; i<n*2; i++) fact[i] = fact[i-1] * i % MOD;
    invf[n*2-1] = inv(fact[n*2-1]);
    for (int i=n*2-2; i>=0; i--) invf[i] = invf[i+1] * (i+1) % MOD;


    ll asum = 0, bsum = 0;
    for (int i=0; i<n-1; i++) {
        asum = (asum + powb[i] * l[i] % MOD * comb(n-2+i, i)) % MOD;
        bsum = (bsum + powa[i] * t[i] % MOD * comb(n-2+i, i)) % MOD;
    }
    asum = asum * powa[n-1] % MOD;
    bsum = bsum * powb[n-1] % MOD;


    vector<ll> va(n-1), vb(n-1);
    for (int i=0; i<n-1; i++) va[i] = powa[i] * invf[i] % MOD;
    for (int i=0; i<n-1; i++) vb[i] = powb[i] * invf[i] % MOD;

    vector<ll> vc = conv(va, vb, MOD);


    ll csum = 0;
    for (int i=0; i<n*2-3; i++) csum = (csum + vc[i] * fact[i]) % MOD;
    csum = csum * c % MOD;

    cout << (asum + bsum + csum) % MOD;
}