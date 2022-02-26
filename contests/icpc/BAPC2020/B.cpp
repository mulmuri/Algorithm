#include <iostream>
#include <vector>
using namespace std;


int n;
vector<int> ans;

int getSize(int x) {
    int cnt = 0;
    while (x /= 10) cnt++;
    return cnt;
}

int pow(int x, int a) {

}

int main() {
    cin >> n;

    while (n) {
        if (getSize(n) >= 10) {
            
        }
    }
    
}