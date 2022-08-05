#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int n, x, length = 0;
        bool flag;
        vector<int> succ = {};
        vector<bool> visited = {};

        // INPUT
        cin >> n;
        for (int i=0; i<n; i++) {
            cin >> x;
            succ.push_back(x-1);
            visited.push_back(false);
        }
        
        for (int i=0; i<n; i++) {
            // if already visited, pass
            if (visited[i]) continue;

            // Floyd's algorithm for Cycle detection (https://en.wikipedia.org/wiki/Cycle_detection#Floyd's_tortoise_and_hare)
            // init
            int a = succ[i], b = succ[succ[i]];
            flag = false;
            cout << a <<' ';
            while (a != b) {
                if (visited[a]) {
                    flag = true;
                    break;
                }
                a = succ[a];
                cout << a <<' ';
                b = succ[succ[b]];
            }
            cout << endl;
            if (flag | visited[a]) continue;

            // first node of cycle
            a = i;
            while (a != b) {
                a = succ[a];
                b = succ[b];
            }
            int first = a;
            
            // if already visited "cycle", pass
            if (visited[first]) continue;
            // length of cycle & visited?
            flag = false;
            for (int node=i; !(visited[node]); node = succ[node]) {
                visited[node] = true;
                if (node == first) flag = true;
                if (flag) length++;
            }
        }
        cout << n-length << "\n";
    }

    return 0;
}