#include <bits/stdc++.h>
using namespace std;


const int SIZE = 1e5;

int n;
int l,r;

int cnt[SIZE];



int main(){
    for (int i=2; i<SIZE; i++) {
        for (int j=i*2; j<SIZE; j+=i) {
            cnt[j]++;
        }
    }

    cin >> l >> r;
}