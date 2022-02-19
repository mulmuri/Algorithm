#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define endl "\n"
#define MOD 998232453
#define INF 1e9
#define SIZE 200001

int n;

bool isPrime(int num) {
    if (num == 2) return true;
    for (int i = 2; i*i <= num; i++) {
        if (num % i == 0) return false;
    }

    return true;
}

int main() {
    fastio;

    int a,b,c,d;
    cin >> a >> b >> c >> d;


    for (int i=a; i<=b; i++) {
        int flag = 1;
        for (int j=c; j<=d; j++) {
            if (isPrime(i+j) == 1) {
                flag = 0;
                break;
            }
        }
        if (flag == 1) {
            cout << "Takahashi";
            return 0;
        }
    }
    cout << "Aoki";
}