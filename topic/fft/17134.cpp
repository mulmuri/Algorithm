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
    if (inv) for(int i=0; i<n; i++) a[i] /= n; // skip for OR convolution.
}

vector<ll> multiply(vector<ll> &v, vector<ll> &w){
    vector<base> fv(v.begin(), v.end()), fw(w.begin(), w.end());
    int n = 2;
    while (n < v.size() + w.size()) n <<= 1;
    fv.resize(n); fw.resize(n);
    fft(fv,0); fft(fw,0);
    for (int i=0; i<n; i++) fv[i] *= fw[i];
    fft(fv,1);
    vector<ll> ret(n);
    for (int i=0; i<n; i++) ret[i] = (ll)round(fv[i].real());
    return ret;
}

vector<ll> multiply(vector<ll> &v, vector<ll> &w, ll mod){
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


const int SIZE = 1000001;
#define endl '\n'

int n;

int sieve[SIZE];

int main() {
    std::ios_base::sync_with_stdio(false);
std::cin.tie(nullptr);
std::cout.tie(nullptr);

    sieve[1] = 1;
    for (int i=2; i<SIZE; i++) {
        if (sieve[i] == 0) {
            for (int j=i*2; j<SIZE; j+=i) {
                sieve[j] = 1;
            }
        }
    }

    vector<ll> v1(SIZE);
    vector<ll> v2(SIZE);

    for (int i=1; i<SIZE; i++) {
        if (sieve[i] == 0) {
            v1[i] = 1;
        }
    }
    for (int i=2; i<SIZE; i+=2) {
        if (sieve[i/2] == 0) {
            v2[i] = 1;
        }
    }

    vector<ll> v3 = multiply(v1, v2);


    int q; cin >> q;
    while (q--) {
        int n; cin >> n;
        cout << v3[n] << endl;
    }

}