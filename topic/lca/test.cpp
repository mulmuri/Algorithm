#include <iostream>
#include <vector>

using namespace std;




vector<int> arr[3] = {{1}, {2}, {3}};

void change(vector<int>* p) {
    vector<int>* t;
    t = p;
    for (int i=0; i<3; i++) t[i][0]++;
}

int main() {
    change(arr);
    for (int i=0; i<3; i++) cout << arr[i][0];
}