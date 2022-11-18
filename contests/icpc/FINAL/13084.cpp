#include <bits/stdc++.h>
using namespace std;

const int SIZE = 1001;



int n;
int len[SIZE];
int ness[SIZE];

int main() {
    cin >> n;

    for (int i=0; i<n; i++) {
        char d; int l;
        cin >> d >> l;
        ness[i] = ((d == 'y'));
        len[i] = l;
    }

    int cnt = 0;

    int r = SIZE;
    int l = 0;

    for (int i=0; i<n; i++) {
        if (ness[i]) r = min(r, len[i]);
        else {
            
        }
    }

}