#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define endl "\n"
#define MOD 998232453
#define INF 1e9
#define SIZE 200001

int n;
long long x;
int arr[SIZE];

int main() {
    fastio;
    
    cin >> n;
    for (int i=0; i<n; i++) cin >> arr[i];
    cin >> x;

    long long sum = 0;
    for (int i=0; i<n; i++) sum += arr[i];

    long long dinom = x%sum;
    for (int i=0; i<n; i++) {
        dinom -= arr[i];
        if (dinom < 0) {
            cout << x/sum*n + i+1;
            return 0;
        }
    }

}