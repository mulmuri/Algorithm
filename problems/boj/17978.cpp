#include <iostream>
#include <tuple>
using namespace std;


const int SIZE = 101;

int n,q;

typedef tuple<int,int,int> co;
co arr[SIZE];

int side[SIZE];



void f(int i, int j, int k, int bit, int lv) {
    if (lv == 3) return;

    f(int i, int j, int k, )
    
} 



int main() {
    cin >> n >> q;

    for (int i=0; i<n-2; i++) {
        for (int j=i+1; j<n-1; j++) {
            for (int k=j+1; k<n; k++) {
                int a,b;
                auto [x1, y1, z1] = arr[i];
                auto [x2, y2, z2] = arr[j];
                auto [x3, y3, z3] = arr[k];

                int a = y1*(z2-z3) + y2*(z3-z1) + y3*(z1-z2);
                int b = z1*(x2-x3) + z2*(x3-x1) + z3*(x1-x2);
                int c = x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2);
                int d = -(x1*(y2*z3 - y3*z2) + x2*(y3*z1 - y1*z3) + x3*(y1*z2 - y2*z1));

                for (int w=0; w<n; w++) {
                    auto [x, y, z] = arr[w];
                    side[w] = (a*x + b*y + c*z + d > 0);
                }
                side[i] = side[j] = side[k] = 2;
            }
        }
    }
}