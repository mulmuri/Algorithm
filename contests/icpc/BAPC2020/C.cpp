#include <iostream>
using namespace std;

const int SIZE = 10001;

int n,p;
int arr[SIZE];
int ans[SIZE];

int main() {
    cin >> n >> p;
    for (int i=n; i; i--) cin >> arr[i];

    for (int i=1; i<=n; i++) {
        if (arr[i] > arr[i-1]) ans[i] = ans[i-1]+1;
        else ans[i] = ans[i-1];
    }

    if (ans[n] == p) {
        for (int i=n; i; i--) cout << ans[i] << endl;
    } else {
        for (int i=1; i<=n; i++) if (arr[i] != 0) {
            cout << "ambiguous";
            return 0;
        }
        else for (int i=n; i; i--) cout << 0 << endl;
    }
}