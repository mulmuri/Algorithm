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
int arr[SIZE];
int cnt[SIZE];

int main() {
    fastio;
    
    cin >> n;
    for (int i=1; i<=n; i++) cin >> arr[i];

    int target = -1;
    for (int i=1; i<n; i++) {
        if (arr[i] < arr[i-1]) {
            target = arr[i-1];
            break;
        }
    }

    if (target == -1) target = arr[n];

    for (int i=1; i<=n; i++) {
        if (arr[i] == target) continue;
        cout << arr[i] <<' ';
    }

    

}