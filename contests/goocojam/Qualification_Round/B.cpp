#include <iostream>
#include <algorithm>
using namespace std;


const int SIZE = 100001;


int n;
int arr[SIZE];

void solve(int tc) {
    cin >> n;
    for (int i=0; i<n; i++) cin >> arr[i];
    sort(arr, arr+n);

    int cnt = 0;
    for (int i=0; i<n; i++) {
        if (arr[i] >= cnt+1) {
            cnt++;
        }
    }

    cout << "Case #"<< tc << ": " << cnt << endl;
}

int main() {
    int t; cin >> t;
    for (int i=1; i<=t; i++) solve(i);
}